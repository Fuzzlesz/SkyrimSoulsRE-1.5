#include "EngineFixesChecker.h"
#undef MessageBox

#include "HookUtils.h"
#include "SkyrimSoulsRE.h"

 constexpr auto MESSAGEBOX_WARNING = 0x00001030L;  // MB_OK | MB_ICONWARNING | MB_SYSTEMMODAL

namespace
{
	void CheckEngineFixes(SkyrimSoulsRE::Settings* a_settings)
	{
		bool engineFixesPresent = REX::W32::GetModuleHandleA("EngineFixes.dll") &&
		                          SkyrimSoulsRE::EngineFixesConfig::load_config("Data/SKSE/Plugins/EngineFixes.toml") &&
		                          SkyrimSoulsRE::EngineFixesConfig::patchMemoryManager &&
		                          SkyrimSoulsRE::EngineFixesConfig::fixGlobalTime;

		if (engineFixesPresent)
		{
			SKSE::log::info("SSE Engine Fixes detected.");
			return;
		}

		SKSE::log::warn("SSE Engine Fixes not detected, or certain features are not enabled.");
		SKSE::log::warn("To ensure best functionality, the following Engine Fixes features must be enabled : Memory Manager patch, Global Time Fix");
		if (!a_settings->hideEngineFixesWarning)
		{
			REX::W32::MessageBoxA(nullptr, "SSE Engine Fixes not detected, or certain features are not enabled. This will not prevent Skyrim Souls RE from running, but to ensure best functionality, the following Engine Fixes features must be enabled:\n\n- Memory Manager patch\n- Global Time Fix\n\nThe Memory Manager patch prevents the false save corruption bug that tends to happen with this mod, and the Global Time fix fixes the behaviour of some menus when using the slow-motion feature.\n\nYou can disable this warning in the .ini.", "Skyrim Souls RE - Warning", MESSAGEBOX_WARNING);
		}
	}

	void CheckModCompatibility(SkyrimSoulsRE::Settings* a_settings)
	{
		if (REX::W32::GetModuleHandleA("DialogueMovementEnabler.dll"))
		{
			SKSE::log::info("Dialogue Movement Enabler detected. Enabling compatibility.");
			a_settings->isUsingDialogueMovementEnabler = true;
		}
		else
		{
			SKSE::log::info("Dialogue Movement Enabler not detected. Disabling compatibility.");
			a_settings->isUsingDialogueMovementEnabler = false;
		}

		if (REX::W32::GetModuleHandleA("gotobed.dll"))
		{
			SKSE::log::info("Go To Bed detected. Enabling compatibility.");
			a_settings->isUsingGoToBed = true;
		}
		else
		{
			SKSE::log::info("Go To Bed not detected. Disabling compatibility.");
			a_settings->isUsingGoToBed = false;
		}
	}

	// This will run immediately after SKSE::MessagingInterface::kDataLoaded
	void (*_PostDataLoaded)(RE::MemoryManager*) = nullptr;
	void PostDataLoaded_Hook(RE::MemoryManager* a_this)
	{
		_PostDataLoaded(a_this);

		SkyrimSoulsRE::InstallMenuHooks();
		SKSE::log::info("Menu hooks installed.");
		SkyrimSoulsRE::HookUtils::LogHooks();
	}
}

static void MessageHandler(SKSE::MessagingInterface::Message* a_msg)
{
	switch (a_msg->type)
	{
	case SKSE::MessagingInterface::kPostLoad:
		{
			SkyrimSoulsRE::Settings* settings = SkyrimSoulsRE::Settings::GetSingleton();
			CheckEngineFixes(settings);
			CheckModCompatibility(settings);
		}
		break;
	}
}

	void InitializeLog()
{
#ifndef NDEBUG
	auto sink = std::make_shared<spdlog::sinks::msvc_sink_mt>();
#else
	auto path = logger::log_directory();
	if (!path) {
		util::report_and_fail("Failed to find standard logging directory"sv);
	}

	*path /= fmt::format("{}.log"sv, Plugin::NAME);
	auto sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(path->string(), true);
#endif

#ifndef NDEBUG
	const auto level = spdlog::level::trace;
#else
	const auto level = spdlog::level::info;
#endif

	auto log = std::make_shared<spdlog::logger>("global log"s, std::move(sink));
	log->set_level(level);
	log->flush_on(level);

	spdlog::set_default_logger(std::move(log));
	spdlog::set_pattern("%s(%#): [%^%l%$] %v"s);
}

extern "C" DLLEXPORT bool SKSEAPI
	SKSEPlugin_Query(const SKSE::QueryInterface* a_skse, SKSE::PluginInfo* a_info)
{
	a_info->infoVersion = SKSE::PluginInfo::kVersion;
	a_info->name = Plugin::NAME.data();
	a_info->version = Plugin::VERSION[0];

	if (a_skse->IsEditor()) {
		logger::critical("Loaded in editor, marking as incompatible"sv);
		return false;
	}

	const auto ver = a_skse->RuntimeVersion();
	if (ver < SKSE::RUNTIME_SSE_1_5_39) {
		logger::critical(FMT_STRING("Unsupported runtime version {}"), ver.string());
		return false;
	}

	return true;
}

extern "C" DLLEXPORT bool SKSEAPI SKSEPlugin_Load(SKSE::LoadInterface* a_skse)
{
		InitializeLog();
		SKSE::AllocTrampoline(1 << 9, true);
		SKSE::Init(a_skse, false);

		const SKSE::MessagingInterface* messaging = SKSE::GetMessagingInterface();
		if (messaging->RegisterListener("SKSE", MessageHandler))
		{
			SKSE::log::info("Messaging interface registration successful.");
		}
		else
		{
			SKSE::log::critical("Messaging interface registration failed.");
			return false;
		}

		SkyrimSoulsRE::LoadSettings();

		SkyrimSoulsRE::InstallHooks();
		_PostDataLoaded = reinterpret_cast<decltype(_PostDataLoaded)>(SkyrimSoulsRE::HookUtils::WriteCall<5>(Offsets::Main::InitData.address() + 0x421, (std::uintptr_t)PostDataLoaded_Hook));

		SKSE::log::info("Hooks installed.");

		SKSE::log::info("Skyrim Souls RE loaded.");

		return true;
	};

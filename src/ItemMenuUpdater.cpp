#include "ItemMenuUpdater.h"
#include "HookUtils.h"

#include <xbyak\xbyak.h>

namespace SkyrimSoulsRE::ItemMenuUpdater
{
	// These hooks are used to send update events to the item menus when something occurs.
	// By default the game sends no updates for these events, causing the lists to retain old data (and possibly crash because of unloaded 3D models).
	// This is especially problematic when unpaused as external events can add or remove objects at any time.
	// Note: this does not necessarily cover all cases.

	RE::TESObjectREFR* GetTargetReference()
	{
		RE::TESObjectREFR* targetRef = nullptr;

		RE::UI* ui = RE::UI::GetSingleton();
		if (ui->IsMenuOpen(RE::ContainerMenu::MENU_NAME))
		{
			RE::ContainerMenu* menu = static_cast<RE::ContainerMenu*>(ui->GetMenu(RE::ContainerMenu::MENU_NAME).get());

			RE::RefHandle handle = menu->GetTargetRefHandle();
			RE::TESObjectREFRPtr refptr = nullptr;
			if (RE::TESObjectREFR::LookupByHandle(handle, refptr))
			{
				targetRef = refptr.get();
			}
		}
		else if (ui->IsMenuOpen(RE::BarterMenu::MENU_NAME))
		{
			RE::BarterMenu* menu = static_cast<RE::BarterMenu*>(ui->GetMenu(RE::BarterMenu::MENU_NAME).get());

			RE::RefHandle handle = menu->GetTargetRefHandle();
			RE::TESObjectREFRPtr refptr = nullptr;
			if (RE::TESObjectREFR::LookupByHandle(handle, refptr))
			{
				targetRef = refptr.get();
			}
		}
		else if (ui->IsMenuOpen(RE::GiftMenu::MENU_NAME))
		{
			RE::GiftMenu* menu = static_cast<RE::GiftMenu*>(ui->GetMenu(RE::GiftMenu::MENU_NAME).get());

			RE::RefHandle handle = menu->IsPlayerGifting() ? menu->GetReceiverRefHandle() : menu->GetGifterRefHandle();
			RE::TESObjectREFRPtr refptr = nullptr;
			if (RE::TESObjectREFR::LookupByHandle(handle, refptr))
			{
				targetRef = refptr.get();
			}
		}

		return targetRef;
	}

	static void RequestItemListUpdate(RE::TESObjectREFR* a_ref, RE::TESForm* a_unk)
	{
		using func_t = decltype(&RequestItemListUpdate);
		REL::Relocation<func_t> func(Offsets::ItemMenuUpdater::RequestItemListUpdate);
		return func(a_ref, a_unk);
	}

	// Update after RemoveAllItems
	static void RemoveAllItems_Hook(RE::BSExtraData* a_unk1, RE::TESObjectREFR* a_containerRef, void* a_unk3, std::uint64_t a_unk4, std::uint32_t a_unk5, void* a_unk6, void* a_unk7)
	{
		using func_t = decltype(&RemoveAllItems_Hook);
		REL::Relocation<func_t> func(Offsets::ItemMenuUpdater::RemoveAllItems);
		func(a_unk1, a_containerRef, a_unk3, a_unk4, a_unk5, a_unk6, a_unk7);

		RE::PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();

		RE::TESObjectREFR* targetRef = GetTargetReference();

		if (a_containerRef == player || a_containerRef == targetRef)
		{
			// Some items might still remain in the list. Updating twice in a row seems to fix it for some reason.
			RequestItemListUpdate(a_containerRef, nullptr);
			RequestItemListUpdate(a_containerRef, nullptr);
		}
	}

	static void ResetInventory_TESObjectREFR_Hook(RE::TESObjectREFR* a_containerRef)
	{
		RequestItemListUpdate(a_containerRef, nullptr);
	}

	void InstallHook()
	{
		HookUtils::WriteCall<5>(Offsets::ItemMenuUpdater::RemoveAllItems_Hook1.address() + 0x16, (std::uintptr_t)RemoveAllItems_Hook);  // VERIFIED
		HookUtils::WriteCall<5>(Offsets::ItemMenuUpdater::RemoveAllItems_Hook2.address() + 0x36, (std::uintptr_t)RemoveAllItems_Hook);  // VERIFIED
		HookUtils::WriteCall<5>(Offsets::ItemMenuUpdater::RemoveAllItems_Hook3.address() + 0xBA, (std::uintptr_t)RemoveAllItems_Hook);  // VERIFIED
		HookUtils::WriteCall<5>(Offsets::ItemMenuUpdater::RemoveAllItems_Hook4.address() + 0x230, (std::uintptr_t)RemoveAllItems_Hook);  // VERIFIED
		HookUtils::WriteCall<5>(Offsets::ItemMenuUpdater::RemoveAllItems_Hook5.address() + 0x46, (std::uintptr_t)RemoveAllItems_Hook);  // VERIFIED

		struct TESObjectREFR_ResetInventory_Code : Xbyak::CodeGenerator
		{
			TESObjectREFR_ResetInventory_Code(uintptr_t a_hookAddr)
			{
				Xbyak::Label hookAddress;

				mov(rcx, rbx);
				call(ptr[rip + hookAddress]);

				mov(rbx, qword[rsp + 0x48]);  // unchanged
				mov(rbp, qword[rsp + 0x50]);  // unchanged
				mov(rsi, qword[rsp + 0x58]);  // unchanged
				add(rsp, 0x30);  // unchanged
				pop(rdi);
				ret();

				L(hookAddress);
				dq(a_hookAddr);
			}
		};

		TESObjectREFR_ResetInventory_Code code{ std::uintptr_t(ResetInventory_TESObjectREFR_Hook) };
		void* codeLoc = REL::GetTrampoline().allocate(code);

		HookUtils::WriteBranch<5>(Offsets::ItemMenuUpdater::ResetInventory_TESObjectREFR_Hook.address() + 0x226, codeLoc);  // VERIFIED
	}
}

#pragma once
#include "REL/Relocation.h"

namespace Offsets
{
	namespace BGSTerrainManager
	{
		static constexpr REL::ID TerrainManager_UpdateFunc(static_cast<std::uint64_t>(38145));  // + 0x5D  // VERIFIED
	}

	namespace BSAudioManager
	{
		static constexpr REL::ID Hook(static_cast<std::uint64_t>(39377));  // + 0xBC; + 0x124  // VERIFIED
		static constexpr REL::ID SetListenerPosition(static_cast<std::uint64_t>(66445));  // VERIFIED
		static constexpr REL::ID SetListenerRotation(static_cast<std::uint64_t>(66446));  // VERIFIED
	}

	namespace BSWin32KeyboardDevice
	{
		static constexpr REL::ID Process(static_cast<std::uint64_t>(67472));  // + 0x20D  // VERIFIED
	}

	namespace GlobalTimescaleMultiplier
	{
		static constexpr REL::ID Value1(static_cast<std::uint64_t>(511882));  // VERIFIED
		static constexpr REL::ID Value2(static_cast<std::uint64_t>(511883));  // VERIFIED
	}

	namespace ImageSpaceManager
	{
		static constexpr REL::ID MapWeatherFunc1(static_cast<std::uint64_t>(105684));  // TODO: 1.6 1413BE470
		static constexpr REL::ID MapWeatherFunc2(static_cast<std::uint64_t>(105687));  // TODO: 1.6 1413BE580
		static constexpr REL::ID MapWeatherFunc3(static_cast<std::uint64_t>(105690));  // TODO: 1.6 1413BE670

		static constexpr REL::ID WeatherUpdateBaseData(static_cast<std::uint64_t>(401110));  // TODO: 1.6 142F9A100
	}

	namespace ItemMenuUpdater
	{
		static constexpr REL::ID RequestItemListUpdate(static_cast<std::uint64_t>(51911));  // VERIFIED

		static constexpr REL::ID RemoveAllItems(static_cast<std::uint64_t>(15878));  // VERIFIED
		static constexpr REL::ID RemoveAllItems_Hook1(static_cast<std::uint64_t>(15881));  // + 0x16  // VERIFIED
		static constexpr REL::ID RemoveAllItems_Hook2(static_cast<std::uint64_t>(19382));  // + 0x36  // VERIFIED
		static constexpr REL::ID RemoveAllItems_Hook3(static_cast<std::uint64_t>(21523));  // + 0xBA  // VERIFIED
		static constexpr REL::ID RemoveAllItems_Hook4(static_cast<std::uint64_t>(36496));  // + 0x230  // VERIFIED
		static constexpr REL::ID RemoveAllItems_Hook5(static_cast<std::uint64_t>(55684));  // + 0x46  // VERIFIED

		static constexpr REL::ID ResetInventory_TESObjectREFR_Hook(static_cast<std::uint64_t>(19802));  // + 0x204  // TODO: 1.6 1402AB300
	}

	namespace Job
	{
		static constexpr REL::ID UI(static_cast<std::uint64_t>(39042));  // + 0xB  // TODO: 1.6 140666270
		static constexpr REL::ID Sky(static_cast<std::uint64_t>(36584));  // TODO: 1.6 1405DB8D0
	}

	namespace MagicItemList
	{
		static constexpr REL::ID Reset(static_cast<std::uint64_t>(52086));  // + 0x3B  // TODO: 1.6 1408CFFC0
	}

	namespace Main
	{
		static constexpr REL::ID Update(static_cast<std::uint64_t>(36564));        // + 0xADF  // TODO: 1.6 1405D9F50
		static constexpr REL::ID UpdatePlayer(static_cast<std::uint64_t>(36581));  // + 0x7A  // TODO: 1.6 1405DB560
		static constexpr REL::ID Render(static_cast<std::uint64_t>(36555));        // + 0x5CA  // TODO: 1.6 1405D7CB0
		static constexpr REL::ID InitData(static_cast<std::uint64_t>(36553));  // TODO: 1.6 1405D6C90
	}

	namespace Menus
	{
		namespace BookMenu
		{
			static constexpr REL::ID ProcessMessage(static_cast<std::uint64_t>(51049));  // TODO: 1.6 1408843C0
		}

		namespace ContainerMenu
		{
			static constexpr REL::ID UpdateBottomBar(static_cast<std::uint64_t>(50214));  // VERIFIED
		}

		namespace DialogueMenu
		{
			static constexpr REL::ID UpdateAutoCloseTimer_Hook(static_cast<std::uint64_t>(36540));  // + 0x4F9  // VERIFIED
		}

		namespace FavoritesMenu
		{
			static constexpr REL::ID CanProcess(static_cast<std::uint64_t>(50644));  // VERIFIED
		}

		namespace HUDMenu
		{
			static constexpr REL::ID ProcessMessage(static_cast<std::uint64_t>(51612));  // + 0x990  // TODO: 1.6 1408AD130
		}

		namespace InventoryMenu
		{
			static constexpr REL::ID UpdateBottomBar(static_cast<std::uint64_t>(50986));  // VERIFIED
		}

		namespace MagicMenu
		{
			static constexpr REL::ID UpdateBottomBar(static_cast<std::uint64_t>(51162));  // VERIFIED
		}

		namespace MapMenu
		{
			static constexpr REL::ID Ctor(static_cast<std::uint64_t>(52206));  // + 0x538  // VERIFIED
			static constexpr REL::ID Dtor(static_cast<std::uint64_t>(53094));  // TODO: 1.6 140912E80

			static constexpr REL::ID LocalMapUpdaterFunc(static_cast<std::uint64_t>(52225));  // + 0x53; + 0x9D; + 0x9F  // VERIFIED

			static constexpr REL::ID UpdateClouds_Hook(static_cast<std::uint64_t>(52258));  // + 0x107  // VERIFIED
			static constexpr REL::ID UpdateClouds_UpdateValue(static_cast<std::uint64_t>(513265));  // VERIFIED

			static constexpr REL::ID PlayerMarkerRefHandle(static_cast<std::uint64_t>(520103));  // VERIFIED
			static constexpr REL::ID SetMarkerPosition(static_cast<std::uint64_t>(52136));  // VERIFIED

			static constexpr REL::ID EnableMapModeTerrainRendering(static_cast<std::uint64_t>(52262));  // VERIFIED

			static constexpr REL::ID EnableMapMode(static_cast<std::uint64_t>(53146));  // TODO: 1.6 140917EB0
			static constexpr REL::ID DisableMapMode(static_cast<std::uint64_t>(53147));  // TODO: 1.6 1409180D0
		}

		namespace StatsMenu
		{
			static constexpr REL::ID Ctor(static_cast<std::uint64_t>(52508));  // TODO: 1.6 1408EDF70
			static constexpr REL::ID Dtor(static_cast<std::uint64_t>(52509));  // TODO: 1.6 1408EE4C0

			static constexpr REL::ID ProcessMessage(static_cast<std::uint64_t>(51638));  // + 0xAEC; + 0xF3C; + 0xF45; + 0xFA9  // VERIFIED
			static constexpr REL::ID CanProcess(static_cast<std::uint64_t>(51645));      // + 0x46; + 0x4A  // VERIFIED

			static constexpr REL::ID OpenStatsMenuAfterSleep_Hook(static_cast<std::uint64_t>(39346));  // + 0x65; + 0x69; + 0x6A  // VERIFIED

			static constexpr REL::ID UpdateSkillList(static_cast<std::uint64_t>(52525));  // TODO: 1.6 1408F16A0
			static constexpr REL::ID SetPlayerInfo(static_cast<std::uint64_t>(52536));  // TODO: 1.6 1408F5920
		}

		namespace TweenMenu
		{
			static constexpr REL::ID ProcessMessage(51833);  // + 0x5A5  // VERIFIED
		}
	}

	namespace Misc
	{
		static constexpr REL::ID ScreenEdgeCameraMoveHook(static_cast<std::uint64_t>(41259));  // + 0x241  // VERIFIED

		static constexpr REL::ID GetExecuteConsoleCommandsSingleton(static_cast<std::uint64_t>(52950));  // TODO: 1.6 14090A510
		static constexpr REL::ID ExecuteConsoleCommands(static_cast<std::uint64_t>(52952));  // TODO: 1.6 14090A6C0

		static constexpr REL::ID RequestSaveScreenshot(static_cast<std::uint64_t>(403755));  // TODO: 1.6 142FD3640

	}

	namespace Papyrus::IsInMenuMode
	{
		static constexpr REL::ID Hook(static_cast<std::uint64_t>(56476));  // VERIFIED
		static constexpr REL::ID Value1(static_cast<std::uint64_t>(516934));  // VERIFIED
		static constexpr REL::ID Value2(static_cast<std::uint64_t>(516935));  // VERIFIED
	}

	namespace Sky
	{
		static constexpr REL::ID UpdatePartial(static_cast<std::uint64_t>(26230));  // TODO: 1.6 1403C97B0
		static constexpr REL::ID UpdateSunGlareLensFlare(static_cast<std::uint64_t>(26246));  // TODO: 1.6 1403CC6C0
	}

	namespace TESFurniture
	{
		static constexpr REL::ID Activate(static_cast<std::uint64_t>(17420));  // + 0x16A  // TODO: 1.6 140228450
	}

	namespace UI
	{
		static constexpr REL::ID ProcessMessages(static_cast<std::uint64_t>(82082));  // TODO: 1.6 140F04C90
		static constexpr REL::ID AdvanceMovies(static_cast<std::uint64_t>(82083));  // TODO: 1.6 140F05980
	}

	namespace UIBlurManager
	{
		static constexpr REL::ID IncrementBlurCount(static_cast<std::uint64_t>(51899));  // VERIFIED
	}
}

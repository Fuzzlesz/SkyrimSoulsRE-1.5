#pragma once
#include "REL/Relocation.h"

namespace Offsets
{
	namespace BGSSaveLoadFileEntry
	{
		static constexpr REL::ID Save(static_cast<std::uint64_t>(34613));  // + 0x3E; + 0x60                                      // VERIFIED
	}

	namespace BGSSaveLoadManager
	{
		static constexpr REL::ID ProcessEvents(static_cast<std::uint64_t>(34862));                                                // VERIFIED
		static constexpr REL::ID RequestSave(static_cast<std::uint64_t>(34859));                                                  // VERIFIED
	}

	namespace BGSTerrainManager
	{
		static constexpr REL::ID TerrainManager_UpdateFunc(static_cast<std::uint64_t>(38145));  // + 0x5D                         // VERIFIED
	}

	namespace BSAudioManager
	{
		static constexpr REL::ID Hook(static_cast<std::uint64_t>(39377));  // + 0xBC; + 0x124                                     // VERIFIED
		static constexpr REL::ID SetListenerPosition(static_cast<std::uint64_t>(66445));                                          // VERIFIED
		static constexpr REL::ID SetListenerRotation(static_cast<std::uint64_t>(66446));                                          // VERIFIED
	}

	namespace BSWin32KeyboardDevice
	{
		static constexpr REL::ID Process(static_cast<std::uint64_t>(67472));  // + 0x20D                                          // VERIFIED
	}

	namespace GlobalTimescaleMultiplier
	{
		static constexpr REL::ID Value1(static_cast<std::uint64_t>(511882));                                                      // VERIFIED
		static constexpr REL::ID Value2(static_cast<std::uint64_t>(511883));                                                      // VERIFIED
	}

	namespace ImageSpaceManager
	{
		static constexpr REL::ID MapWeatherFunc1(static_cast<std::uint64_t>(99033));                                              // VERIFIED
		static constexpr REL::ID MapWeatherFunc2(static_cast<std::uint64_t>(99036));                                              // VERIFIED
		static constexpr REL::ID MapWeatherFunc3(static_cast<std::uint64_t>(99039));                                              // VERIFIED

		static constexpr REL::ID WeatherUpdateBaseData(static_cast<std::uint64_t>(514970));                                       // VERIFIED
	}

	namespace ItemMenuUpdater
	{
		static constexpr REL::ID RequestItemListUpdate(static_cast<std::uint64_t>(51911));                                        // VERIFIED

		static constexpr REL::ID RemoveAllItems(static_cast<std::uint64_t>(15878));                                               // VERIFIED
		static constexpr REL::ID RemoveAllItems_Hook1(static_cast<std::uint64_t>(15881));  // + 0x16                              // VERIFIED
		static constexpr REL::ID RemoveAllItems_Hook2(static_cast<std::uint64_t>(19382));  // + 0x36                              // VERIFIED
		static constexpr REL::ID RemoveAllItems_Hook3(static_cast<std::uint64_t>(21523));  // + 0xBA                              // VERIFIED
		static constexpr REL::ID RemoveAllItems_Hook4(static_cast<std::uint64_t>(36496));  // + 0x230                             // VERIFIED
		static constexpr REL::ID RemoveAllItems_Hook5(static_cast<std::uint64_t>(55684));  // + 0x46                              // VERIFIED

		static constexpr REL::ID ResetInventory_TESObjectREFR_Hook(static_cast<std::uint64_t>(19375));  // + 0x226                // VERIFIED
	}

	namespace Job
	{
		static constexpr REL::ID UI(static_cast<std::uint64_t>(38088));  // + 0xB                                                 // VERIFIED
		static constexpr REL::ID Sky(static_cast<std::uint64_t>(529360));                                                         // VERIFIED
	}

	namespace MagicItemList
	{
		static constexpr REL::ID Reset(static_cast<std::uint64_t>(51183));  // + 0x30                                             // VERIFIED
	}

	namespace Main
	{
		static constexpr REL::ID Update(static_cast<std::uint64_t>(35565));        // + 0x61A                                     // VERIFIED
		static constexpr REL::ID UpdatePlayer(static_cast<std::uint64_t>(35578));  // + 0x77                                      // VERIFIED
		//static constexpr REL::ID Render(static_cast<std::uint64_t>(36555));      // + 0x5CA                                     // NOT USED
		static constexpr REL::ID InitData(static_cast<std::uint64_t>(35554));                                                     // VERIFIED
	}

	namespace Menus
	{
		namespace BookMenu
		{
			static constexpr REL::ID ProcessMessage(static_cast<std::uint64_t>(50118));                                           // VERIFIED
		}

		namespace Console
		{
			static constexpr REL::ID SaveGameHandler(static_cast<std::uint64_t>(22465));  // + 0xC4                               // VERIFIED
		}

		namespace ContainerMenu
		{
			static constexpr REL::ID UpdateBottomBar(static_cast<std::uint64_t>(50214));                                          // VERIFIED
		}

		namespace DialogueMenu
		{
			static constexpr REL::ID UpdateAutoCloseTimer_Hook(static_cast<std::uint64_t>(36540));  // + 0x4F9                    // VERIFIED
		}

		namespace FavoritesMenu
		{
			static constexpr REL::ID CanProcess(static_cast<std::uint64_t>(50644));                                               // VERIFIED
		}

		namespace HUDMenu
		{
			static constexpr REL::ID ProcessMessage(static_cast<std::uint64_t>(50718));  // + 0x96C                               // VERIFIED
		}

		namespace InventoryMenu
		{
			static constexpr REL::ID UpdateBottomBar(static_cast<std::uint64_t>(50986));                                          // VERIFIED
		}

		namespace MagicMenu
		{
			static constexpr REL::ID UpdateBottomBar(static_cast<std::uint64_t>(51162));                                          // VERIFIED
		}

		namespace MapMenu
		{
			static constexpr REL::ID Ctor(static_cast<std::uint64_t>(52206));  // + 0x538                                         // VERIFIED
			static constexpr REL::ID Dtor(static_cast<std::uint64_t>(52207));                                                     // VERIFIED

			static constexpr REL::ID LocalMapUpdaterFunc(static_cast<std::uint64_t>(52225));  // + 0x53; + 0x9D; + 0x9F           // VERIFIED

			static constexpr REL::ID UpdateClouds_Hook(static_cast<std::uint64_t>(52258));  // + 0x107                            // VERIFIED
			static constexpr REL::ID UpdateClouds_UpdateValue(static_cast<std::uint64_t>(513265));                                // VERIFIED

			static constexpr REL::ID PlayerMarkerRefHandle(static_cast<std::uint64_t>(520103));                                   // VERIFIED
			static constexpr REL::ID SetMarkerPosition(static_cast<std::uint64_t>(52136));                                        // VERIFIED

			static constexpr REL::ID EnableMapModeTerrainRendering(static_cast<std::uint64_t>(52262));                            // VERIFIED

			static constexpr REL::ID EnableMapMode(static_cast<std::uint64_t>(52256));                                            // VERIFIED
			static constexpr REL::ID DisableMapMode(static_cast<std::uint64_t>(52257));                                           // VERIFIED
		}

		namespace StatsMenu
		{
			static constexpr REL::ID Ctor(static_cast<std::uint64_t>(51636));                                                     // VERIFIED
			static constexpr REL::ID Dtor(static_cast<std::uint64_t>(51637));                                                     // VERIFIED

			static constexpr REL::ID ProcessMessage(static_cast<std::uint64_t>(51638));  // + 0xAEC; + 0xF3C; + 0xF45; + 0xFA9    // VERIFIED
			static constexpr REL::ID CanProcess(static_cast<std::uint64_t>(51645));      // + 0x46; + 0x4A                        // VERIFIED

			static constexpr REL::ID OpenStatsMenuAfterSleep_Hook(static_cast<std::uint64_t>(39346));  // + 0x65; + 0x69; + 0x6A  // VERIFIED

			static constexpr REL::ID UpdateSkillList(static_cast<std::uint64_t>(51652));                                          // VERIFIED
			static constexpr REL::ID SetPlayerInfo(static_cast<std::uint64_t>(51663));                                            // VERIFIED
		}

		namespace TweenMenu
		{
			static constexpr REL::ID ProcessMessage(51833);  // + 0x5A5                                                           // VERIFIED
		}
	}

	namespace Misc
	{
		static constexpr REL::ID ScreenEdgeCameraMoveHook(static_cast<std::uint64_t>(41259));  // + 0x241                         // VERIFIED

		static constexpr REL::ID GetExecuteConsoleCommandsSingleton(static_cast<std::uint64_t>(52063));                           // VERIFIED
		static constexpr REL::ID ExecuteConsoleCommands(static_cast<std::uint64_t>(52065));                                       // VERIFIED
	}

	namespace Papyrus::IsInMenuMode
	{
		static constexpr REL::ID Hook(static_cast<std::uint64_t>(56476));                                                         // VERIFIED
		static constexpr REL::ID Value1(static_cast<std::uint64_t>(516934));                                                      // VERIFIED
		static constexpr REL::ID Value2(static_cast<std::uint64_t>(516935));                                                      // VERIFIED
	}

	namespace Sky
	{
		static constexpr REL::ID UpdatePartial(static_cast<std::uint64_t>(25683));                                                // VERIFIED
		static constexpr REL::ID UpdateSunGlareLensFlare(static_cast<std::uint64_t>(25699));                                      // VERIFIED
	}

	namespace TESFurniture
	{
		static constexpr REL::ID Activate(static_cast<std::uint64_t>(17034));  // + 0x160                                         // VERIFIED
	}

	namespace UI
	{
		static constexpr REL::ID ProcessMessages(static_cast<std::uint64_t>(79945));                                              // VERIFIED
		static constexpr REL::ID AdvanceMovies(static_cast<std::uint64_t>(79946));                                                // VERIFIED
	}

	namespace UIBlurManager
	{
		static constexpr REL::ID IncrementBlurCount(static_cast<std::uint64_t>(51899));                                           // VERIFIED
	}

	namespace UISaveLoadManager
	{
		static constexpr REL::ID SaveGame(static_cast<std::uint64_t>(52037));  // + 0x2B                                          // VERIFIED
	}
}

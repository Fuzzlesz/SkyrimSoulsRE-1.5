#include "Menus/FavoritesMenuEx.h"
#include "HookUtils.h"

namespace SkyrimSoulsRE
{
	RE::IMenu* FavoritesMenuEx::Creator()
	{
		return CreateMenu(RE::FavoritesMenu::MENU_NAME);
	}

	void FavoritesMenuEx::InstallHook()
	{
		//Fix for hotkeys not working
		HookUtils::SafeWrite(Offsets::Menus::FavoritesMenu::CanProcess.address() + 0x15, std::uint16_t(0x9090));  // unchanged
	}
}

#pragma once

namespace Offsets {
	const RelocAddr <uintptr_t *> FavoritesMenu_Hook = 0x8781D5; //1.5.80
	const RelocAddr <uintptr_t *> BookMenu_Hook = 0x85764E; //1.5.80
	const RelocAddr <uintptr_t *> LockpickingMenu_Hook = 0x8963E0; //1.5.80
	const RelocAddr <uintptr_t *> TweenMenu_Hook = 0x8D0C85; //1.5.80
	const RelocAddr <uintptr_t *> MessageBoxMenu_ServeTime_Hook = 0x21A915; //1.5.80
	const RelocAddr <uintptr_t *> JournalMenu_Hook = 0x586DE0; //1.5.80
	const RelocAddr <uintptr_t *> SleepWaitMenuControls_Hook = 0x5B35B1; //1.5.80
	const RelocAddr <uintptr_t *> StartSleepWait_Original = 0x8BDD60; //1.5.80
	const RelocAddr <uintptr_t *> IsInMenuMode_Hook = 0x9B8750; //1.5.80

	const RelocAddr <uintptr_t *> LockpickingMenu_Target = 0x2F4E240; //1.5.80
	const RelocAddr <uintptr_t *> IsInMenuMode_Original = 0x2F26B75; //1.5.80
	const RelocAddr <uintptr_t *> ContainerMenu_Mode = 0x2F4C328; //1.5.80
	const RelocAddr <uintptr_t *> ContainerMenu_Target = 0x2F4C3F0; //ContainerMenu_Mode + 0xC8 //1.5.80
	const RelocAddr <uintptr_t *> DrawNextFrame_Hook = 0xECD489; //1.5.80
}
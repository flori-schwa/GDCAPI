//
// Created by Florian on 12.07.2020.
//

#include "include/__gd_ptr.h"

gdcapi::GameInfo::GameInfo(GdHandle* gd) : handle(gd) {}

// Pointers stolen from NeKit's gd.py

DEF_PTR(PTR_IS_IN_LEVEL, 0x3222D0, 0x164, 0x22C, 0x114)

// Thanks to SMJS for the pointer

DEF_PTR(PTR_IS_MENU_SHOWN, 0x3222D0, 0x760, 0x1CC)

DEF_PTR(PTR_IS_FINISH_SCREEN_SHOWN, 0x322290, 0xCC, 0x28, 0x00, 0x8, 0x4BD)

bool gdcapi::GameInfo::isInLevel() {
    return handle->read<bool>(Get_PTR_IS_IN_LEVEL(handle));
}

bool gdcapi::GameInfo::isInMenu() {
    return handle->read<bool>(Get_PTR_IS_MENU_SHOWN(handle));
}

bool gdcapi::GameInfo::isOnEndOfAttemptScreen() {
    return handle->read<bool>(Get_PTR_IS_FINISH_SCREEN_SHOWN(handle));
}
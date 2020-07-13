//
// Created by Florian on 12.07.2020.
//

#include "include/__gd_ptr.h"

gdcapi::GameInfo::GameInfo(GdHandle* gd) : handle(gd) {}

// Pointers stolen from NeKit's gd.py

DEF_PTR(PTR_IS_IN_LEVEL, 0x3222D0, 0x164, 0x22C, 0x114)

bool gdcapi::GameInfo::isInLevel() {
    return handle->read<bool>(Get_PTR_IS_IN_LEVEL(handle));
}

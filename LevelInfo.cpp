//
// Created by Florian on 12.07.2020.
//

#include "include/__gd_ptr.h"

gdcapi::LevelInfo::LevelInfo(GdHandle* gd) : handle(gd) {}

// Pointers stolen from NeKit's gd.py

DEF_PTR(PTR_LEVEL_LENGTH, 0x3222D0, 0x164, 0x3B4)

DEF_PTR(PTR_OBJ_COUNT, 0x3222D0, 0x168, 0x3A0)

float gdcapi::LevelInfo::getCurrentLevelLength() {
    return this->handle->read<float>(Get_PTR_LEVEL_LENGTH(this->handle));
}

int gdcapi::LevelInfo::getObjectCount() {
    return this->handle->read<int>(Get_PTR_OBJ_COUNT(this->handle));
}
//
// Created by Florian on 12.07.2020.
//

#include "include/__gd_ptr.h"

gdcapi::LevelInfo::LevelInfo(GdHandle* gd) : handle(gd) {}

// Pointers stolen from NeKit's gd.py

DEF_PTR(PTR_LEVEL_LENGTH, 0x3222D0, 0x164, 0x3B4)

DEF_PTR(PTR_OBJ_COUNT, 0x3222D0, 0x168, 0x3A0)

DEF_PTR(PTR_TOTAL_ATTEMPTS, 0x3222D0, 0x164, 0x22C, 0x114, 0x218)

DEF_PTR(PTR_LEVEL_ID_ACCURATE, 0x3222D0, 0x164, 0x22C, 0x114, 0xF8)

DEF_PTR(PTR_LEVEL_NAME_PTR, 0x3222D0, 0x164, 0x22C, 0x114)

DEF_PTR(PTR_TOTAL_JUMPS, 0x3222D0, 0x164, 0x22C, 0x114, 0x224)

DEF_PTR(PTR_BEST_PERC_NORMAL, 0x3222D0, 0x164, 0x22C, 0x114, 0x248)

float gdcapi::LevelInfo::getCurrentLevelLength() {
    return handle->read<float>(Get_PTR_LEVEL_LENGTH(handle));
}

int gdcapi::LevelInfo::getObjectCount() {
    return handle->read<int>(Get_PTR_OBJ_COUNT(handle));
}

int gdcapi::LevelInfo::getTotalAttempts() {
    return handle->read<int>(Get_PTR_TOTAL_ATTEMPTS(handle));
}

int gdcapi::LevelInfo::getLevelId() {
    return handle->read<int>(Get_PTR_LEVEL_ID_ACCURATE(handle));
}

std::string & gdcapi::LevelInfo::getLevelName() {
    std::size_t levelNamePtr = handle->read<std::size_t>(Get_PTR_LEVEL_NAME_PTR(handle));

    return readString(handle, levelNamePtr, 0xFC);
}

int gdcapi::LevelInfo::getTotalJumps() {
    return handle->read<int>(Get_PTR_TOTAL_JUMPS(handle));
}

int gdcapi::LevelInfo::getBestNormalPercent() {
    return handle->read<int>(Get_PTR_BEST_PERC_NORMAL(handle));
}
//
// Created by Florian on 12.07.2020.
//

#include "include/PlayerInfo.h"
#include "include/__gd_ptr.h"

gdcapi::PlayerInfo::PlayerInfo(GdHandle* gd) : handle(gd) {}

// Pointers stolen from NeKit's gd.py

DEF_PTR(PTR_IS_PLAYER_DEAD, 0x3222D0, 0x164, 0x39C)

DEF_PTR(PTR_PLAYER_GAMEMODE, 0x3222D0, 0x164, 0x224, 0x638)

DEF_PTR(PTR_PLAYER_NAME_PTR, 0x3222D8)

DEF_PTR(PTR_PLAYER_X, 0x3222D0, 0x164, 0x224, 0x67C)

DEF_PTR(PTR_PLAYER_Y, 0x3222D0, 0x164, 0x224, 0x680)

DEF_PTR(PTR_CURRENT_ATTEMPT, 0x3222D0, 0x164, 0x4A8)

DEF_PTR(PTR_IS_PRACTICE_MODE, 0x3222D0, 0x164, 0x495)

bool gdcapi::PlayerInfo::isPlayerDead() {
    return this->handle->read<bool>(Get_PTR_IS_PLAYER_DEAD(this->handle));
}

gdcapi::Gamemode gdcapi::PlayerInfo::getGameMode() {
    bool buf[6];
    this->handle->read(Get_PTR_PLAYER_GAMEMODE(this->handle), buf, 6);

    for (int i = 0; i < 6; i++) {
        if (buf[i]) {
            return static_cast<Gamemode>(i);
        }
    }

    return Cube;
}

std::string& gdcapi::PlayerInfo::getPlayerName() {
    std::size_t playerNamePtr = handle->read<std::size_t>(Get_PTR_PLAYER_NAME_PTR(handle));

    return readString(handle, playerNamePtr, 0x108);
}

float gdcapi::PlayerInfo::getX() {
    return handle->read<float>(Get_PTR_PLAYER_X(handle));
}

float gdcapi::PlayerInfo::getY() {
    return handle->read<float>(Get_PTR_PLAYER_Y(handle));
}

int gdcapi::PlayerInfo::getCurrentAttempt() {
    return handle->read<int>(Get_PTR_CURRENT_ATTEMPT(handle));
}

bool gdcapi::PlayerInfo::isInPracticeMode() {
    return handle->read<bool>(Get_PTR_IS_PRACTICE_MODE(handle));
}

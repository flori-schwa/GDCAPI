//
// Created by Florian on 12.07.2020.
//

#include "include/GdHandle.h"

gdcapi::GdHandle::GdHandle() {
    this->handle = new HackIH();

    this->lvlInfo = new LevelInfo(this);
    this->playerInfo = new PlayerInfo(this);
    this->gameInfo = new GameInfo(this);
}

gdcapi::GdHandle::~GdHandle() {
    delete this->handle;

    delete this->lvlInfo;
    delete this->playerInfo;
    delete this->gameInfo;
}


bool gdcapi::GdHandle::bind() {
    return handle->bind("GeometryDash.exe");
}

bool gdcapi::GdHandle::isBound() {
    return handle->IsBound();
}

bool gdcapi::GdHandle::isGameRunning() {
    return handle->IsProcessRunning();
}

gdcapi::LevelInfo& gdcapi::GdHandle::getLevelInfo() {
    return *this->lvlInfo;
}

gdcapi::PlayerInfo& gdcapi::GdHandle::getPlayerInfo() {
    return *this->playerInfo;
}

gdcapi::GameInfo& gdcapi::GdHandle::getGameInfo() {
    return *this->gameInfo;
}

HackIH& gdcapi::GdHandle::getHandle() {
    return *this->handle;
}

bool gdcapi::GdHandle::read(PointerIH& ptr, void* buffer, std::size_t size) const {
    return this->handle->ReadRaw(ptr, buffer, size);
}
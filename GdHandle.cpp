//
// Created by Florian on 12.07.2020.
//

#include "include/GdHandle.h"

gdcapi::GdHandle::GdHandle() {
    this->handle = new HackIH();

//    this->handle->SetDebugOutput(std::cerr);

    this->lvlInfo = new LevelInfo(this);
    this->playerInfo = new PlayerInfo(this);
    this->gameInfo = new GameInfo(this);
}

bool gdcapi::GdHandle::bind() {
    return handle->bind("GeometryDash.exe");
}

bool gdcapi::GdHandle::isBound() {
    return handle->IsBound();
}

gdcapi::LevelInfo* gdcapi::GdHandle::getLevelInfo() {
    return this->lvlInfo;
}

gdcapi::PlayerInfo* gdcapi::GdHandle::getPlayerInfo() {
    return this->playerInfo;
}

gdcapi::GameInfo* gdcapi::GdHandle::getGameInfo() {
    return this->gameInfo;
}

HackIH * gdcapi::GdHandle::getHandle() {
    return this->handle;
}

bool gdcapi::GdHandle::read(PointerIH& ptr, void* buffer, std::size_t size) const {
    return this->handle->ReadRaw(ptr, buffer, size);
}
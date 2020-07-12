//
// Created by Florian on 12.07.2020.
//

#ifndef GDCAPI_GDHANDLE_H
#define GDCAPI_GDHANDLE_H

#include "__gdcapimain.h"

#include <iostream>
#include <Windows.h>
#include <tlhelp32.h>
#include <cstdio>
#include <vector>
#include "HAPIH.h"

#include "LevelInfo.h"
#include "PlayerInfo.h"
#include "GameInfo.h"
#include "MemoryReadException.h"

namespace gdcapi {
    class GdHandle {

    private:
        HackIH* handle;
        LevelInfo* lvlInfo = nullptr;
        PlayerInfo* playerInfo = nullptr;
        GameInfo* gameInfo = nullptr;

    public:

        explicit GdHandle();

        bool bind();

        bool isBound();

        LevelInfo* getLevelInfo();

        PlayerInfo* getPlayerInfo();

        GameInfo* getGameInfo();

        HackIH* getHandle();

        bool read(PointerIH& ptr, void* buffer, std::size_t size) const;

        template<typename T>
        T read(PointerIH& ptr) const {
            T t = 0;

            if (!read(ptr, &t, sizeof(T))) {
                throw MemoryReadException(ptr);
            }

            return t;
        }
    };
}

#endif //GDCAPI_GDHANDLE_H

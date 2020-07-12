//
// Created by Florian on 12.07.2020.
//

#ifndef GDCAPI_GAMEINFO_H
#define GDCAPI_GAMEINFO_H

#include "__gdcapimain.h"
#include "GdHandle.h"
#include "HAPIH.h"

namespace gdcapi {
    class GameInfo {
    private:
        GdHandle* handle;

    public:
        bool isInLevel();

        GameInfo(GdHandle* gd);
    };

//    static const PointerIH PTR_IS_IN_LEVEL(0x3222D0, 0x164, 0x22C, 0x114);
}

#endif //GDCAPI_GAMEINFO_H

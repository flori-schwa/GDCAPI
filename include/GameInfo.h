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
}

#endif //GDCAPI_GAMEINFO_H

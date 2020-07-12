//
// Created by Florian on 12.07.2020.
//

#ifndef GDCAPI_LEVELINFO_H
#define GDCAPI_LEVELINFO_H

#include "__gdcapimain.h"
#include "GdHandle.h"
#include "HAPIH.h"

namespace gdcapi {

    class LevelInfo {
    private:
        GdHandle* handle;

    public:
        float getCurrentLevelLength();

        int getObjectCount();

        LevelInfo(GdHandle* gd);
    };

//    static const PointerIH PTR_LEVEL_LENGTH(0x3222D0, 0x164, 0x3B4);
}

#endif //GDCAPI_LEVELINFO_H

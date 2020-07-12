//
// Created by Florian on 12.07.2020.
//

#include "include/GameInfo.h"

gdcapi::GameInfo::GameInfo(GdHandle* gd) : handle(gd) {}

PointerIH* getPtrIsInLvl(gdcapi::GdHandle* handle) {
    static PointerIH* PTR_IS_IN_LEVEL = nullptr;

    if (PTR_IS_IN_LEVEL == nullptr) {
        PTR_IS_IN_LEVEL = new PointerIH(handle->getHandle()->GetModuleAddress("GeometryDash.exe"), 0x3222D0, 0x164,
                                        0x22C, 0x114);
    }

    return PTR_IS_IN_LEVEL;
}

bool gdcapi::GameInfo::isInLevel() {
    return this->handle->read<bool>(*getPtrIsInLvl(this->handle));
}

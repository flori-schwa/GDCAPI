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
    /*
     * FIXME
     *  Addresses calculated by gd.py (Correct):
     *  - 0x140000
     *  - 0x4622D0
     *  - 0x2D2149C
     *  - 0x22C
     *  - 0x114
     *  -
     *  Addresses calculates by HAPIH:
     *  - 0x140000
     *  - 0x4622D0
     *  - 0x2D2149C
     *  - 0x22C
     *  - 0x340 <-- Error (299: ERROR_PARTIAL_COPY) here
     */
    return this->handle->read<bool>(*getPtrIsInLvl(this->handle));
}

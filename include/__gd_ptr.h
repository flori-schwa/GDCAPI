//
// Created by Florian on 12.07.2020.
//

#ifndef GDCAPI___GD_PTR_H
#define GDCAPI___GD_PTR_H

#include "GdHandle.h"

#define GD_STR_SIZE 16

//#define DEF_PTR(Name, ...) static const PointerIH Name("GeometryDash.exe", __VA_ARGS__);

#define DEF_PTR(Name, ...) PointerIH& Get_##Name(gdcapi::GdHandle* handle) {\
        static PointerIH* Name = nullptr; \
        if (Name == nullptr) {\
            Name = new PointerIH(handle->getHandle()->GetModuleAddress("GeometryDash.exe"), __VA_ARGS__);\
        }\
        return *Name;\
        }


std::string& readString(gdcapi::GdHandle* handle, std::size_t base, std::size_t offset);

#endif //GDCAPI___GD_PTR_H

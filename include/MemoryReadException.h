//
// Created by Florian on 12.07.2020.
//

#ifndef GDCAPI_MEMORYREADEXCEPTION_H
#define GDCAPI_MEMORYREADEXCEPTION_H

#include "__gdcapimain.h"
#include <exception>
#include "HAPIH.h"
#include <Windows.h>
#include <tlhelp32.h>

namespace gdcapi {
    class MemoryReadException : public std::exception {
    public:
        explicit MemoryReadException(const PointerIH& ptr);
    };
}

#endif //GDCAPI_MEMORYREADEXCEPTION_H

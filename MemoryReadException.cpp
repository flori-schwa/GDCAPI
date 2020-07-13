//
// Created by Florian on 12.07.2020.
//
#include <sstream>

#include "include/MemoryReadException.h"

std::unique_ptr<char*> getErrMsg(const PointerIH& ptr) {
    std::stringstream ptr_ss;

    for (int i = 0; i < ptr.GetOffsets().size(); i++) {
        ptr_ss << "[";
    }

    ptr_ss << "GeometryDash.exe+0x" << std::hex << ptr.GetBase();

    for (std::size_t offset : ptr.GetOffsets()) {
        ptr_ss << "]+0x" << offset;
    }

    std::stringstream ss;
    ss << "Failed to read memory at addr " << ptr_ss.str() << ": " << GetLastError() << std::endl;

    std::string* msg_cpp_str_ptr = new std::string(ss.str());
    const char* msg_c_str = msg_cpp_str_ptr->c_str();

    std::size_t size = sizeof(char) * (strlen(msg_c_str) + 1);
    char* msg_c_str_cpy = static_cast<char*>(malloc(size));

    strncpy_s(msg_c_str_cpy, size, msg_c_str, sizeof(char) * strlen(msg_c_str));
    msg_c_str_cpy[size - 1] = 0;

    delete msg_cpp_str_ptr;

    return std::make_unique<char*>(msg_c_str_cpy);
}

gdcapi::MemoryReadException::MemoryReadException(const PointerIH& ptr) : std::exception(*getErrMsg(ptr)) {}
//
// Created by Florian on 12.07.2020.
//

#include "include/__gd_ptr.h"

std::string& readString(gdcapi::GdHandle* handle, std::size_t base, std::size_t offset) {
    // Stolen from NeKit's gd.py

    PointerIH address = {base + offset};
    PointerIH size_address = {base + offset + GD_STR_SIZE};
    std::size_t str_size = handle->read<int>(size_address);

    char* name_buf = new char[str_size];

    if (str_size > GD_STR_SIZE) {
        PointerIH addr2 = {handle->read<std::size_t>(address)};
        address = addr2;
    }

    handle->read(address, name_buf, str_size);
    std::string* name = new std::string(name_buf);

    return *name;
}
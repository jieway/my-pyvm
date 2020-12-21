#include "hiString.hpp"
#include <string.h>


// 赋值
HiString::HiString(const char * x) {
    _length = strlen(x);
    _value = new char[_length];
    strcpy(_value, x);
}

// 赋值时提供长度
HiString::HiString(const char * x, const int length) {
    _length = length;
    _value = new char[length];

    for (int i = 0; i < length; i++) {
        _value[i] = x[i];
    }
}
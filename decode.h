//
// Created by Nicholas Ruiz on 2019-04-10.
//

#ifndef UNTITLED_DECODE_H
#define UNTITLED_DECODE_H
#include "Code.h"
#include <math.h>

class Decode: public Code {
private:

    int getDigit(std::string);

public:
    const std::string MAX = "7F7F";
    const std::string MIN = "0000";
    Decode();
    int decode(std::string);
};




#endif //UNTITLED_DECODE_H

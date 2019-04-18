

//
// Created by Nicholas Ruiz on 2019-04-09.
//

#ifndef UNTITLED_ENCODE_H
#define UNTITLED_ENCODE_H
#include "Code.h"
#include <iterator>
#include <sstream>


class Encode: public Code {
private:


public:
    const int MAX = 8191;
    const int MIN = -8192;

    Encode();
    std::string encode(int );
    void setHighLow(int num, std::vector<int> &, std::vector<int> &);
};


#endif //UNTITLED_ENCODE_H

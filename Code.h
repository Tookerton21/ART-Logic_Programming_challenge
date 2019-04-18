//
// Created by Nicholas Ruiz on 2019-04-11.
//

#ifndef UNTITLED_CODE_H
#define UNTITLED_CODE_H
#include <map>
#include <string>
#include <vector>
#include <iostream>

class Code {
public:
    Code();
protected:
    std::map<char, std::string> dec;
    std::map<std::string,char> hex;
    const int NUMBER = 8192;
    const int SIZE = 14;
    int* decToBin(int);
};

#endif //UNTITLED_CODE_H

//
// Created by Nicholas Ruiz on 2019-04-10.
//

#include "decode.h"

Decode::Decode(){

}

/**
 * Public function wrapper function take an String for the Hex and decode it based on the specifications
 * @param str
 * @return integer
 */
int Decode::decode(std::string str){

    return getDigit(str);

}

/**
 * Convert the base 16 number and decode based from the specifiactions requited.
 * @param str
 * @return integer
 */
int Decode::getDigit(std::string str) {
    std::string bin = "";

    for(int i=0; i<4; ++i){
      bin.append(dec[str[i]]);

    }

    int res = 0;
    int power = 0;

    for(int i=bin.length()-1; i>0; --i){
        if(i != 8) {
            res = res + (bin[i] - '0') * pow(2, power);
            ++power;

        }
    }
    res -= NUMBER;
    return res;
}
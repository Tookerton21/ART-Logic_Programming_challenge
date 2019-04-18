//
// Created by Nicholas Ruiz on 2019-04-11.
//

#include "Code.h"

Code::Code() {
    dec['0'] ="0000";
    dec['1'] = "0000";
    dec['2'] = "0010";
    dec['3'] = "0011";
    dec['4'] = "0100";
    dec['5'] = "0101";
    dec['6'] = "0110";
    dec['7'] = "0111";
    dec['8'] = "1000";
    dec['9'] = "1001";
    dec['A'] = "1010";
    dec['B'] = "1011";
    dec['C'] = "1100";
    dec['D'] = "1101";
    dec['E'] = "1110";
    dec['F'] = "1111";

    hex["0000"] = '0';
    hex["0001"] = '1';
    hex["0010"] = '2';
    hex["0011"] = '3';
    hex["0100"] = '4';
    hex["0101"] = '5';
    hex["0110"] = '6';
    hex["0111"] = '7';
    hex["1000"] = '8';
    hex["1001"] = '9';
    hex["1010"] = 'A';
    hex["1011"] = 'B';
    hex["1100"] = 'C';
    hex["1101"] = 'D';
    hex["1110"] = 'E';
    hex["1111"] = 'F';
}

/**
 * Take an base 10 number and convert that into a base 2 number.
 * Returns an array of integers
 */
int* Code::decToBin(int num) {
    //Add the VALUE 8192 To the Raw Value
    num += NUMBER;

    int *binNum = new int[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        binNum[i] = 0;
    }


    int i = SIZE-1;

    while (num > 0 && i >= 0) {
        binNum[i] = num % 2;
        num = num / 2;
        --i;
    }
    return binNum;
}
#include <iostream>
#include "Encode.h"
#include "decode.h"

bool checkOption(int op){
    if(op == 1 || op == 2)
        return true;
    else
        return false;
}

bool checkNumber(int number, Encode &encode){
    if(number < encode.MIN || number > encode.MAX)
        return false;
    else
        return true;
}

bool checkHex(std::string &str, Decode &decode){
    if(str.length() > 4 || str.length() < 1)
        return false;

    for(int i=0; i<str.length(); ++i){
        str[i] = toupper(str[i]);
        if(str[i] > decode.MAX[i] || str[i] < decode.MIN[0]) {
            return false;
        }
    }
    return true;
}

bool checkAgain(char c){
    if(toupper(c) == 'Y')
        return false;
    else
        return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    Encode encode;
    Decode decode;

    //std::vector<char> res = encode.encode(-4096);
    //encode.print();


    bool exit = false;
    bool check = false;
    int option;
    int number;
    char again;
    std::string hex;

    while(exit != true){
        do {
            printf("Would you like to \n1)Encode\2) Decode\n Options(1 or 2): ");
            std::cin >> option;

            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                option = 0;
            }

            check = checkOption(option);
            if(!check)
                printf("Incorrect input, Please try again \n\n");
        }while(!check);

            switch (option){
                case 1: {
                    while(true) {
                        std::cout << "Please Enter decimal Number to encode between [-8192..+8191]: ";
                        std::cin >> number;
                        if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore();
                            std::cout << "enter a valid number\n";
                        }
                        else if(!checkNumber(number, encode)){
                            std::cout << "enter a valid number\n";
                        }
                        else
                            break;
                    }
                        std::string res = encode.encode(number);
                        std::cout << "Encoded: " << res << std::endl;

                    break;
                }
                case 2: {
                    while(true) {
                        std::cout << "Please Enter Hex number to encode between [0000..7F7F]: ";
                        std::cin >> hex;
                        if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore();
                        }
                        bool isValid = checkHex(hex, decode);

                        if(isValid)
                            break;
                        else
                            std::cout << "Invalid Input, Please try again" << std::endl;
                    }
                    int res = decode.decode(hex);
                    std::cout << "Decoded: " << res << std::endl;
                    break;
                }
                default:
                    std::cout << "error";
            }

        std::cout << "Anything else to Encode of Decode? (Y or N): ";
        std::cin >> again;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            again = 'N';
        }
        exit = checkAgain(again);
    }


}
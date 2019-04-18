//
// Created by Nicholas Ruiz on 2019-04-09.
//

#include "Encode.h"
#include <iterator>

Encode::Encode() {

}

/**
 * Set the high and low numbers from the integer that the user passed in, to allow
 * to encode in base 2 form.
 * @param num
 * @param low
 * @param high
 */
void Encode::setHighLow(int num, std::vector<int> &low, std::vector<int> &high){
    int* binNum = decToBin(num);

    int i=SIZE-1;

    //Prime arrays with 0's at the front of each vector
    low.push_back(0);
    high.push_back(0);

    //Converting base 10 number into base 2
    while(num>0 && i<SIZE){
        binNum[i] = num%2;
        num = num / 2;
        --i;
    }

    high.insert(high.begin()+1, (binNum), (binNum)+(SIZE/2));
    low.insert(low.begin()+1, (binNum)+7, (binNum)+SIZE);

}

/**
 * Takes in the param num to encode based on the specifications
 * @param num
 * @return string
 */
std::string Encode::encode(int num) {
    std::vector<char> res;
    std::vector<int> low, high;

    setHighLow(num, low, high);

    std::ostringstream str1;
    std::ostringstream str2;

    //Converting base 2 to base 16 after encoding
    if(!low.empty() && !high.empty()){
        //for highs
        std::copy(high.begin(), high.begin()+4, std::ostream_iterator<int>(str1, ""));
        res.push_back( (hex[str1.str()]) );

        str1.str("");
        str1.clear();

        std::copy(high.begin()+4, high.end(), std::ostream_iterator<int>(str2, ""));

        res.push_back( (hex[str2.str()]) );
        str2.str("");
        str2.clear();

        //For Lows
        std::copy(low.begin(), low.begin()+4, std::ostream_iterator<int>(str1, ""));
        res.push_back( (hex[str1.str()]) );
        str1.str("");
        str1.clear();

        std::copy(low.begin()+4, low.end(), std::ostream_iterator<int>(str2, ""));
        res.push_back( (hex[str2.str()]) );
        str2.str("");
        str2.clear();

    }

    return std::string(res.begin(), res.end());
}


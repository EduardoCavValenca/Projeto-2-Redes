#include "bitHandler.h"
#include <math.h>

std::vector<bool> string_to_bits(std::string string) {
    std::vector<bool> bits;

    for (size_t i = 0; i < string.length(); i++) {
        std::bitset<8> byte(string[i]);

        for (size_t j = 8; j > 0; j--) {
            bits.push_back(byte[j - 1]);
        }
    }

    return bits;
}

std::string bits_to_string(std::vector<bool> bits) {
    std::string string;
    int auxint;

    for (size_t i = 0; i < bits.size(); i=i+8) {        
        auxint=0;
        for (size_t j = i; j < i+8; j++) {
            if(bits[j]) {
                auxint += 1*pow(2, 7- (j % 8));
            }
        }
        string += char(auxint);
    }

    return string;
}

void print_bits(std::vector<bool> bits) {
    for (size_t i = 1; i < bits.size() + 1; i++) {
        if (bits[i - 1]) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }

        if (i % 8 == 0) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}
#ifndef BITHANDLER_H
#define BITHANDLER_H

#include <iostream>
#include <bitset>
#include <vector>

std::vector<bool> string_to_bits(std::string string);
void print_bits(std::vector<bool> bits);
std::string bits_to_string(std::vector<bool> bits);

#endif
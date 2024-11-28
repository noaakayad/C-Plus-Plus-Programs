#include "int24.hpp"

int24 int24::int_to_int24(uint32_t value) {
    int24 int_reduced;
    int_reduced.bytes[0] = value & 0b11111111;        
    int_reduced.bytes[1] = (value >> 8) & 0b11111111; 
    int_reduced.bytes[2] = (value >> 16) & 0b11111111;
    return int_reduced;
}

uint32_t int24::int24_to_int(int24 int_reduced){
    return (int_reduced.bytes[2] << 16) | (int_reduced.bytes[1] << 8) | int_reduced.bytes[0];
}
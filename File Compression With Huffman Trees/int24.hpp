#ifndef INT24_H
#define INT24_H
#include <cstdint>
#include <vector>
using namespace std;

struct int24{
    uint8_t bytes[3];

    static int24 int_to_int24(uint32_t value);
    static uint32_t int24_to_int(int24 int_reduced);
};

#endif
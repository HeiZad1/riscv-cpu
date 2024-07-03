#include <iostream>
#include <vector>

#define size 4
#define bit  8

std::vector<uint8_t> input;
std::vector<std::vector<uint8_t>> g(4, std::vector<uint8_t>(4, 0));


void rram(uint8_t a,uint8_t b,uint8_t c,uint8_t d,uint8_t &x,uint8_t &y,uint8_t &z,uint8_t &o){
    x = a*g[0][0] + b*g[0][1]+ c*g[0][2]+ d*g[0][3];
    y = a*g[1][0] + b*g[1][1]+ c*g[1][2]+ d*g[1][3];
    z = a*g[2][0] + b*g[2][1]+ c*g[2][2]+ d*g[2][3];
    o = a*g[3][0] + b*g[3][1]+ c*g[3][2]+ d*g[3][3];
}



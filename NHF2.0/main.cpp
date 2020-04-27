#include <iostream>
#include "Graf.hpp"
#include "Csucs.hpp"
#include "memtrace.h"
#include "gtest_lite.h"

int main()
{
    int* t = new int[4];
    bool** m = new bool*[4];
    for(int i =0; i < 4; ++i)
        m[i] = new bool[4];

    int tempint[4] = {1,2,3,4};
    bool tempm[4][4] = {{false,true,true,true},{true,false,false,false},{true,false,false,true},{true,false,true,false}};

    for(int i = 0; i < 4; ++i){
        t[i] = tempint[i];
        for(int j = 0; j < 4; ++j)
            m[i][j] = tempm[i][j];
    }
    GTINIT(std::cin);
    Graf<int, (size_t)4> testGraf(t,m);
    TEST(testGraf, getCsucsdb) {
        EXPECT_EQ((size_t)4, testGraf.getCsucsdb()) << "getCsucsdb nem jo" << std::endl;
    } ENDM
}

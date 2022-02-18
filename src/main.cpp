
#include <iostream>
#include <gtest/gtest.h>
#include "hw1.h"

int main(int argc, char **argv)
{
    
    if (false) // make false to run unit-tests
    {   
        unsigned int n{3},m{4};
        Matrix z1;
         z1=algebra::random(n,m,1,2);
         std::cout <<z1[0].size() <<std::endl;
        for (size_t i{}; i < n; i++)
        {
            for (size_t j{}; j < m; j++)
            {
                std::cout << z1[i][j] << std::endl;
            }
        }
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}
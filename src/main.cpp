
#include <iostream>
#include <gtest/gtest.h>
#include "hw1.h"

int main(int argc, char **argv)
{

    if (false) // make false to run unit-tests
    {
        unsigned int n{3}, m{4};
        double c{3.5};
        // Matrix z1 =algebra::random(n,m,1,2);
        // Matrix z2 =algebra::random(m,n,1,2);
        // algebra::show(z1);
        // algebra::show (z2);
        Matrix x = {};
         std::cout<<x.size() <<" , "<<x[0].size()<<std::endl;
        // if (x.size() == x[0].size())
        // {
        //     // Matrix x2=algebra::multiply(x,x);
        //     std::cout << "bad";
        // }
        algebra::show(x);
        // Matrix r=algebra::random (n,m,2,1);
        //     for (size_t i{}; i < n; i++)
        //     {
        //         for (size_t j{}; j < m; j++)
        //         {
        //             std::cout << z1[i][j] << " ,"
        //             <<z2[i][j]<< std::endl;
        //         }
        //     }
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
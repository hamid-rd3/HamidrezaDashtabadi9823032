
#include <iostream>
#include <gtest/gtest.h>
#include "hw1.h"
#include <compare>
int main(int argc, char **argv)
{

    if (false) // make false to run unit-tests
    {
        unsigned int n{1}, m{1};
        // bool campare =(1 <=> 2);
         Matrix m1{{1, 2, 3}, {4, 5, 6}, {7, 8, 10}};
        Matrix m6 =algebra::ero_swap(m1,1,2);
        
        algebra:: show(m6);
    //     // for (auto & x:m6){
    //     //     for (auto& y:x)
    //     //         std::cout << y <<std::endl;
    //     // }
    //     // algebra::show (m1);
    //     Matrix m2{{3}};
    //     Matrix m3{{2, 3, 1.5}, {1, 1, 3}, {2, 0, 1}};
    //     Matrix x = {};

    //     // std::cout << algebra::determinant(m1) << m4 << std::endl;

    //      Matrix z1 =algebra::minor(m1,1,1);
        // algebra::show(z1);
        // Matrix z2 =algebra::random(m,n,1,2);
        // algebra::show(z1);
        // algebra::show (z2);

        //  std::cout<<x.size() <<" , "<<x[0].size()<<std::endl;
        // if (x.size() == x[0].size())
        // {
        //     // Matrix x2=algebra::multiply(x,x);
        //     std::cout << "bad";
        // }
        // algebra::show(x);
        // Matrix r=algebra::concatenate (m1,m6,1);
        // algebra::show(r);
            // for (size_t i{}; i < n; i++)
            // {
            //     for (size_t j{}; j <( m+2); j++)
            //     {
            //         std::cout << r[i][j] << " ," << std::endl;
            //     }
            // }
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

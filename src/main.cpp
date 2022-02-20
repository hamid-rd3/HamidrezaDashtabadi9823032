
#include <iostream>
#include <gtest/gtest.h>
#include "hw1.h"
#include <compare>
#include <cmath>
Matrix a1a(const Matrix &matrix)
{
    Matrix resultat = matrix;
    
    
    for (size_t i{}; i < matrix.size(); i++)
    {   
        
        for (size_t j{i + 1}; j < matrix[0].size(); j++)
        {
            if (resultat[j][i]!=0)
            {
                resultat = algebra::ero_swap(resultat, j, i); 
                break;
            }
        }
    }
    
    for (size_t i{}; i < matrix.size(); i++)
    {
        if (resultat[i][i] == 0)
        {
            break;
        } // nothing can happen if element on main diagonal is 0
        for (size_t j{i + 1}; j < resultat[0].size(); j++)
        {
            
            resultat =algebra::ero_sum(resultat, i, -resultat[j][i] / resultat[i][i], j);
            
        }
    }
    return resultat;
}

int main(int argc, char **argv)
{

    if (false) // make false to run unit-tests
    {
        unsigned int n{1}, m{1};
        // bool campare =(1 <=> 2);
        Matrix m1{{1, 2}, {5, 7}};
        // Matrix m6 =algebra::ero_swap(m1,1,0);
        Matrix m7 = algebra::upper_triangular(m1);
        algebra::show(m7);
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

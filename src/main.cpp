
#include <iostream>
#include <gtest/gtest.h>
#include "hw1.h"
double det(const Matrix &m1)
{
    if (m1.empty())
    {
        return 1.0;
    }
    std::vector<double> v1;
    if (m1.size() == 1)
    {
        return m1[0][0];
    }
    else
    {
        for (size_t i{}; i < m1[0].size(); i++)
        {
            double detminor1{det(algebra::minor(m1, 0, i))};
            v1.push_back(detminor1 * std::pow(-1.0, i) * m1[0][i]);
        }
    }
    return std::accumulate(v1.begin(), v1.end(), 0.0);
}
int main(int argc, char **argv)
{

    if (true) // make false to run unit-tests
    {
        unsigned int n{3}, m{4};
        Matrix m1{{1, 2, 3}, {4, 5, 6}, {7, 8, 10}};
        for (auto & x:m1){
            for (auto& y:x)
                std::cout << y <<std::endl;
        }
        Matrix m2{{3}};
        Matrix m3{{2, 3, 1.5}, {1, 1, 3}, {2, 0, 1}};
        Matrix x = {};
        double m4{det(m1)};
        std::cout << algebra::determinant(m1) << m4 << std::endl;

        //  Matrix z1 =algebra::minor(m1,1,1);
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

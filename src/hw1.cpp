#include "hw1.h"

Matrix algebra::zeros(size_t n, size_t m)
{

    Matrix zeros1(n, std::vector<double>(m, 0.0));
    return zeros1;
}
Matrix algebra::ones(size_t n, size_t m)
{

    Matrix ones1(n, std::vector<double>(m, 1.0));
    return ones1;
}
Matrix algebra::random(size_t n, size_t m, double min, double max)
{
    try
    {
        if (min < max)
        {
            Matrix r1;
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_real_distribution<double> dist(min, max);
            for (size_t i{}; i < n; i++)
            {
                std::vector<double> v1;
                for (size_t j{}; j < m; j++)
                {
                    v1.push_back(dist(mt));
                }
                r1.push_back(v1);
            }
            return r1;
        }
        else
        {
            throw(505);
        }
    }
    catch (int num)
    {
        std::cout << "error" << num
                  << "min argument must be smaller than the max "
                  << std::endl;
    }
}

void algebra::show(const Matrix &matrix)
{
    for (size_t i{}; i < matrix.size(); i++)
    {
        for (size_t j{}; j < matrix[0].size(); j++)
        {
            std::cout << std::setw(5) << std::setprecision(3) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

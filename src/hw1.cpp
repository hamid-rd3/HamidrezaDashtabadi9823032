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

    if (min < max)
    {

        Matrix r1;
        // give seed { rd } to mersenne_twister_engine
        std::random_device rd;
        std::mt19937 mt(rd());
        // bring numbers in continuous random distribution on the range [min, max)
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
        throw(std::logic_error("min must be smaller than max"));
    }
}

void algebra::show(const Matrix &matrix)
{
    for (size_t i{}; i < matrix.size(); i++)
    {
        for (size_t j{}; j < matrix[0].size(); j++)
        {
            std::cout << std::setw(7) << std::setprecision(3) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}
Matrix algebra::multiply(const Matrix &matrix, double c)
{
    Matrix resultat;
    if (matrix.empty())
    {
        Matrix empty;
        return empty;
    }
    else
    {
        for (size_t i{}; i < matrix.size(); i++)
        {
            std::vector<double> v1;
            for (size_t j{}; j < matrix[0].size(); j++)
            {
                v1.push_back(c * matrix[i][j]);
            }
            resultat.push_back(v1);
        }
        return resultat;
    }
}
Matrix algebra::multiply(const Matrix &matrix1, const Matrix &matrix2)
{

    Matrix resultat;
    if (matrix1.empty() || matrix2.empty())
    {
        Matrix empty;
        return empty;
    }

    else if (matrix1[0].size() != matrix2.size())
    {
        throw(std::logic_error("num c1 diffrent r2 !!"));
    }
    else
    {
        // ri :row of matrixi ,ci :columns if matrix i
        long unsigned int r1{matrix1.size()}, c1{matrix1[0].size()};
        long unsigned int r2{matrix2.size()}, c2{matrix2[0].size()};
        Matrix resultat;
        for (size_t i{}; i < r1; i++)
        {
            std::vector<double> v1{};
            for (size_t j{}; j < c2; j++)
            {
                double sum{};
                std::vector<double> v2{};
                for (size_t k{}; k < r2; k++)
                {
                    v2.push_back(matrix1[i][k] * matrix2[k][j]);
                }
                v1.push_back(std::accumulate(v2.begin(), v2.end(),
                                             decltype(v2)::value_type(0)));
            }
            resultat.push_back(v1);
        }
        return resultat;
    }
}

Matrix algebra::sum(const Matrix &matrix, double c)
{
    if (matrix.empty())
    {
        return matrix;
    }
    else
    {
        Matrix resultat;
        for (size_t i{}; i < matrix.size(); i++)
        {
            std::vector<double> v1;
            for (size_t j{}; j < matrix[0].size(); j++)
            {
                v1.push_back(c + matrix[i][j]);
            }
            resultat.push_back(v1);
        }
        return resultat;
    }
}
Matrix algebra::sum(const Matrix &matrix1, const Matrix &matrix2)
{
    if (matrix1.empty() && matrix2.empty())
    {
        Matrix empty;
        return empty;
    }
    else if(matrix1.empty() != matrix2.empty()){
        throw(std::logic_error("matrices with wrong dimensions cannot be summed"));
    }
    else
    {
        long unsigned int r1{matrix1.size()}, c1{matrix1[0].size()};
        long unsigned int r2{matrix2.size()}, c2{matrix2[0].size()};
        if (r1 != r2 || c1 != c2)
        {
            throw(std::logic_error("M1 and M2 dimansions are not compatible!"));
        }
        else
        {
            Matrix resultat;
            for (size_t i{}; i < r1; i++)
            {
                std::vector<double> v1;
                for (size_t j{}; j < c1; j++)
                {
                    v1.push_back(matrix1[i][j] + matrix2[i][j]);
                }
                resultat.push_back(v1);
            }
            return resultat;
        }
    }
}

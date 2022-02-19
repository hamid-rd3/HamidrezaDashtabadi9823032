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
    Matrix resultat;
    if (!(min < max))
    {
        throw(std::logic_error("min must be smaller than max"));
    }
    else
    {
        // give seed { rd } to mersenne_twister_engine
        std::random_device rd;
        std::mt19937 mt(rd());
        // bring numbers in continuous random distribution on  range[min, max)
        std::uniform_real_distribution<double> dist(min, max);
        for (size_t i{}; i < n; i++)
        {
            std::vector<double> v1;
            for (size_t j{}; j < m; j++)
            {
                v1.push_back(dist(mt));
            }
            resultat.push_back(v1);
        }
    }
    return resultat;
}

void algebra::show(const Matrix &matrix)
{
    for (auto &row_obj : matrix)
    {
        for (auto &elem : row_obj)
        {
            std::cout << std::setw(7) << std::setprecision(3) << elem;
        }
        std::cout << std::endl;
    }
}
Matrix algebra::multiply(const Matrix &matrix, double c)
{
    Matrix resultat;
    if (matrix.empty())
    {
        return matrix;
    }
    else
    {
        for (auto &row_obj : matrix)
        {
            std::vector<double> v1;
            for (auto &elem : row_obj)
            {
                v1.push_back(c * elem);
            }
            resultat.push_back(v1);
        }
    }
    return resultat;
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
                                             0.0));
            }
            resultat.push_back(v1);
        }
    }
    return resultat;
}

Matrix algebra::sum(const Matrix &matrix, double c)
{
    Matrix resultat;
    if (matrix.empty())
    {
        return matrix;
    }
    else
    {

        for (auto &row_obj : matrix)
        {
            std::vector<double> v1;
            for (auto &elem : row_obj)
            {
                v1.push_back(c + elem);
            }
            resultat.push_back(v1);
        }
    }
    return resultat;
}
Matrix algebra::sum(const Matrix &matrix1, const Matrix &matrix2)
{
    Matrix resultat;
    if (matrix1.empty() && matrix2.empty())
    {
        Matrix empty;
        return empty;
    }
    else if (matrix1.empty() != matrix2.empty())
    {
        throw(std::logic_error(" wrong dimensions"));
    }
    else if (matrix1.size() != matrix2.size())
    {
        throw(std::logic_error(" wrong dimensions"));
    }
    else if (matrix1[0].size() != matrix2[0].size())
    {
        throw(std::logic_error(" wrong dimensions"));
    }
    else
    {
        long unsigned int r1{matrix1.size()}, c1{matrix1[0].size()};
        long unsigned int r2{matrix2.size()}, c2{matrix2[0].size()};
        if (r1 != r2 || c1 != c2)
        {
            throw(std::logic_error("M1 and M2 dimansions arent compatible!"));
        }
        else
        {

            for (size_t i{}; i < r1; i++)
            {
                std::vector<double> v1;
                for (size_t j{}; j < c1; j++)
                {
                    v1.push_back(matrix1[i][j] + matrix2[i][j]);
                }
                resultat.push_back(v1);
            }
        }
    }
    return resultat;
}
Matrix algebra::transpose(const Matrix &matrix)
{
    Matrix resultat;
    if (matrix.empty())
    {
        return matrix;
    }
    else
    {

        for (size_t i{}; i < matrix[0].size(); i++)
        {
            std::vector<double> v1;
            for (size_t j{}; j < matrix.size(); j++)
            {
                v1.push_back(matrix[j][i]);
            }
            resultat.push_back(v1);
        }
    }
    return resultat;
}
Matrix algebra::minor(const Matrix &matrix, size_t n, size_t m)
{
    Matrix resultat;
    if (matrix.empty())
    {
        return matrix;
    }
    else if (matrix.size() != matrix[0].size())
    {
        throw(std::logic_error("matrix must be square"));
    }
    else
    {

        for (size_t i{}; i < matrix[0].size(); i++)
        {
            if (i == n)
                continue;
            std::vector<double> v1;
            for (size_t j{}; j < matrix.size(); j++)
            {
                if (j == m)
                    continue;
                v1.push_back(matrix[i][j]);
            }
            resultat.push_back(v1);
        }
    }
    return resultat;
}
double algebra::determinant(const Matrix &matrix)
{
    // co factor
    std::vector<double> v1;
    if (matrix.empty())
    {
        return 1.0;
    }
    else if (matrix.size() != matrix[0].size())
    {
        throw(std::logic_error("matrix must be square"));
    }
    else
    {
        if (matrix.size() == 1)
        {
            return matrix[0][0];
        }
        else
        {
            for (size_t i{}; i < matrix[0].size(); i++)
            {
                // dm : determinant of minor
                double dm{algebra::determinant(algebra::minor(matrix, 0, i))};
                v1.push_back(dm * std::pow(-1.0, i) * matrix[0][i]);
            }
        }
    }
    return std::accumulate(v1.begin(), v1.end(), 0.0);
}
Matrix algebra::inverse(const Matrix &matrix)
{
    // prmres:primitive resultat
    Matrix prmres;
    if (matrix.empty())
    {
        return matrix;
    }
    else if (matrix.size() != matrix[0].size())
    {
        throw(std::logic_error("matrix must be square"));
    }
    else if (algebra::determinant(matrix) == 0.0)
    {
        throw(std::logic_error("singular matrices have no inverse"));
    }
    else
    {

        for (size_t i{}; i < matrix.size(); i++)
        {
            std::vector<double> v1;
            for (size_t j{}; j < matrix[0].size(); j++)
            {
                // compute  determinant of minor of elements
                double detofmnr{algebra::determinant(minor(matrix, i, j))};
                v1.push_back(pow(-1.0, i + j) * detofmnr);
            }
            prmres.push_back(v1);
        }
    }
    // transpose of primitive resultat
    Matrix topr = algebra::transpose(prmres);
    return algebra::multiply(topr, 1 / algebra::determinant(matrix));
}
Matrix algebra::concatenate(const Matrix &m1, const Matrix &m2, int axis)
{
    Matrix resultat;
    if (m1.empty() && m2.empty())
    {
        Matrix empty;
        return empty;
    }
    else if (m1.empty() != m2.empty())
    {
        throw(std::logic_error(" wrong dimensions"));
    }
    else if ((m1.size() != m2.size()) && axis == 1)
    {
        throw(std::logic_error(" wrong dimensions"));
    }
    else if ((m1[0].size() != m2[0].size()) && axis == 0)
    {
        throw(std::logic_error(" wrong dimensions"));
    }
    else
    {
        if (axis == 1)
        {
            Matrix resultat;
            for (size_t i{}; i < m1.size(); i++)

            {
                std::vector<double> v1;
                std::vector<double> v2;
                for (size_t j{}; j < m1[0].size(); j++)
                {
                    v1.push_back(m1[i][j]);
                }
                for (size_t j{}; j < m2[0].size(); j++)
                {
                    v2.push_back(m2[i][j]);
                }
                v1.insert(v1.end(), v2.begin(), v2.end());
                resultat.push_back(v1);
            }
            return resultat;
        }
        else if (axis == 0)
        {

            for (auto &row_obj : m1)

            {
                std::vector<double> v1;
                for (auto &elem : row_obj)
                {
                    v1.push_back(elem);
                }
                resultat.push_back(v1);
            }
            for (auto &row_obj : m2)

            {
                std::vector<double> v2;
                for (auto &elem : row_obj)
                {
                    v2.push_back(elem);
                }
                resultat.push_back(v2);
            }
        }
    }
    return resultat;
}
Matrix algebra::ero_swap(const Matrix &matrix, size_t r1, size_t r2)
{
    Matrix resultat;
    if (matrix.empty())
    {
        return matrix;
    }
    else if (r1 >= matrix.size() || r2 >= matrix.size())
    {
        throw(std::logic_error("r1 or r2 inputs are out of range"));
    }
    else
    {

        for (size_t i{}; i < matrix.size(); i++)
        {

            if (i == r1)
            {

                resultat.push_back(matrix[r2]);
            }
            else if (i == r2)
            {
                resultat.push_back(matrix[r1]);
            }
            else
            {
                resultat.push_back(matrix[i]);
            }
        }
    }
    return resultat;
}
Matrix algebra::ero_multiply(const Matrix &matrix, size_t r, double c)
{
    Matrix resultat;
    if (matrix.empty())
    {
        return matrix;
    }
    else if (r >= matrix.size())
    {
        throw(std::logic_error("r is out of range"));
    }
    else
    {
        for (size_t i{}; i < matrix.size(); i++)
        {
            std::vector<double> v1;
            for (size_t j{}; j < matrix[0].size(); j++)
            {
                if (i == r)
                {
                    v1.push_back(c * matrix[i][j]);
                }
                else
                {
                    v1.push_back(matrix[i][j]);
                }
            }
            resultat.push_back(v1);
        }
    }
    return resultat;
}
Matrix algebra::ero_sum(const Matrix &matrix, size_t r1, double c, size_t r2)
{
    Matrix resultat;
    Matrix newmatrix = algebra::ero_multiply(matrix, r1, c);
    if (matrix.empty())
    {
        return matrix;
    }
    else if (r1 >= matrix.size() || r2 >= matrix.size())
    {
        throw(std::logic_error("r1 or r2 inputs are out of range"));
    }
    else
    {
        for (size_t i{}; i < matrix.size(); i++)
        {
            std::vector<double> v1;
            for (size_t j{}; j < matrix[0].size(); j++)
            {
                if (i != r2)
                {
                    v1.push_back(matrix[i][j]);
                }
                else
                {
                    v1.push_back(matrix[i][j] + newmatrix[r1][j]);
                }
            }
            resultat.push_back(v1);
        }
    }
    return resultat;
}
Matrix algebra::upper_triangular(const Matrix &matrix)
{
    Matrix resultat;
    if (matrix.empty())
    {
        return matrix;
    }

    else if (matrix.size() != matrix[0].size())
    {
        throw(std::logic_error("matrix must be square"));
    }
    else if (algebra::determinant(matrix) == 0.0)
    {
        throw(std::logic_error("singular matrices have no inverse"));
    }
    else
    {
        for (size_t i{}; i < matrix.size(); i++)
        {
            for (size_t j{}; j < matrix[0].size(); j++)
            {
                if ((i + j) < matrix.size())
                {
                    if (!matrix[j][j] == 0)
                        break;
                    algebra::ero_swap(matrix, i, i + j);
                }
            }
            if (matrix[i][i] == 0)
            {
                break;
            }
            else
            {
                matrix[i][i] / matrix[i][]
            }
        }
    }

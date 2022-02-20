#include "hw1.h"

Matrix algebra::zeros(size_t n, size_t m)
{
    return Matrix(n, std::vector<double>(m, 0.0));
}

Matrix algebra::ones(size_t n, size_t m)
{
    return Matrix(n, std::vector<double>(m, 1.0));
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
        // the engine generate random numbers unlimitedly
        std::mt19937 mt(rd());
        // bring numbers in continuous random distribution on  range[min, max)
        std::uniform_real_distribution<double> dist(min, max);

        for (size_t i{}; i < n; i++)
        {
            // define a empty vector v1 used to initialize resultat
            // useing same method for initilize  Matrixes in All functions
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
    // range base loop through rows(row_obj(object)) and elements of rwos (elem)
    for (auto &row_obj : matrix)
    {
        for (auto &elem : row_obj)
        {
            // print (3 decimal 7 place (space) for each element) in a line
            std::cout << std::setw(7) << std::setprecision(3) << elem;
        }
        // go to next line
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
        // rows(row_obj(object)) and elements of rwos (elem)
        for (auto &row_obj : matrix)
        {
            // define a empty vector v1 used to initialize resultat
            std::vector<double> v1;
            for (auto &elem : row_obj)
            {
                v1.push_back(c * elem);
            }
            // initilize resultat  rows with vector v1
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
        // ri :row of matrix(i) ,ci :columns if matrix (i)
        long unsigned int r1{matrix1.size()}, c1{matrix1[0].size()};
        long unsigned int r2{matrix2.size()}, c2{matrix2[0].size()};
        for (size_t i{}; i < r1; i++)
        {
            // define a empty vector v1 used to initialize resultat
            std::vector<double> v1{};
            for (size_t j{}; j < c2; j++)
            {
                // define a new vector (v2)to initilize  vector v1
                std::vector<double> v2{};
                for (size_t k{}; k < r2; k++)
                {
                    // multiply of matrix1 and matrix2
                    v2.push_back(matrix1[i][k] * matrix2[k][j]);
                }
                // accumilate(sum) elements of v2
                //  initialize v1 with sum of elements of v2
                v1.push_back(std::accumulate(v2.begin(), v2.end(), 0.0));
            }
            // initilize resultat  rows with vector v1
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
        // row object (vector 1D) of matrix
        for (auto &row_obj : matrix)
        {
            std::vector<double> v1;
            // column member( element) (double) of a row  of matrix
            for (auto &elem : row_obj)
            { // initilize v1 (to ininitialize resultat)with summation of c and elem
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
        // ri :row of matrix(i) ,ci :columns if matrix (i)
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
                    // like oneth sum but replacing c with element of matrix2
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
            { // initilize elemnt (i,j) with value of element (j,i) matrix
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
            // minor of the input matrix with respect to nth row and mth column
            // ignore nth row
            if (i == n)
                continue;
            // define a empty vector v1 used to initialize resultat
            std::vector<double> v1;
            for (size_t j{}; j < matrix.size(); j++)
            {
                // ignore mth column
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
    // co-factor
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
            // determinant of a scaler is value of scaler
            return matrix[0][0];
        }
        else
        {
            for (size_t i{}; i < matrix[0].size(); i++)
            {
                // dm : determinant of minor
                // using recursion function for determinint
                // proceed along the first row and ...
                // multiply each component by the determinant of its minor ...
                // and mulitply in -1 ^ (num of column)
                double dm{algebra::determinant(algebra::minor(matrix, 0, i))};
                v1.push_back(dm * std::pow(-1.0, i) * matrix[0][i]);
            }
        }
    }
    // return sum of co-factors as determinant
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
                // compute  determinant of minor of elements and ...
                // multiply in -1 ^(num of row+num of column)of element
                double detofmnr{algebra::determinant(minor(matrix, i, j))};
                v1.push_back(pow(-1.0, i + j) * detofmnr);
            }
            // initilize primitive resultat
            prmres.push_back(v1);
        }
    }
    // transpose of primitive resultat
    Matrix topr = algebra::transpose(prmres);
    // fourmula of inverse of matrix is to divide primitive resultat by ...
    // determinant of matrix
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

            for (size_t i{}; i < m1.size(); i++)

            {
                // want to concatenate v2 to v1
                // v1 :elements of matrix 1
                // v2 :elements of matrix 1
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
                // insert begin of v2 into end of v1 like a vector
                // then pushback(initialize row of matrix) ...
                // the vector into resultat
                v1.insert(v1.end(), v2.begin(), v2.end());
                resultat.push_back(v1);
            }
            // initilize resultat rows with vector v1
            return resultat;
        }
        else if (axis == 0)
        {
            // In this case first initialize resultat with matrix 1 then matrix 2

            // rows(row_obj(object)) and elements of rwos (elem)of matrix1
            for (auto &row_obj : m1)
            {
                // define a empty vector v1 used to initialize resultat
                std::vector<double> v1;
                for (auto &elem : row_obj)
                {
                    v1.push_back(elem);
                }
                resultat.push_back(v1);
            }
            // matrix1 is finished lets go for matrix2!!

            // rows(row_obj(object)) and elements of rwos (elem) matrix2
            for (auto &row_obj : m2)
            {
                // define a empty vector v2 used to initialize resultat
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
            // if in row r1 initilize resultat with row r2
            if (i == r1)
            {
                resultat.push_back(matrix[r2]);
            }
            // if in row r2 initilize resultat with row r1
            else if (i == r2)
            {
                resultat.push_back(matrix[r1]);
            }
            // if not row r2 or r1 initilize resultat normaly
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
            // define a empty vector v1 used to initialize resultat
            std::vector<double> v1;
            for (size_t j{}; j < matrix[0].size(); j++)
            {
                // just multiply ith row in c
                if (i == r)
                {
                    v1.push_back(c * matrix[i][j]);
                }
                else
                {
                    v1.push_back(matrix[i][j]);
                }
            }
            // initilize resultat rows with vector v1
            resultat.push_back(v1);
        }
    }
    return resultat;
}

Matrix algebra::ero_sum(const Matrix &matrix, size_t r1, double c, size_t r2)
{
    Matrix resultat;
    // multiply row r1 of matrix  in c and iinitilize new matrix with that
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
            // define a empty vector v1 used to initialize resultat
            std::vector<double> v1;
            for (size_t j{}; j < matrix[0].size(); j++)
            {
                // dont wanna change any row except r2
                if (i != r2)
                {
                    v1.push_back(matrix[i][j]);
                }
                else
                {
                    // sum row r2 and c*row r1 (saved in newmatrix)
                    v1.push_back(matrix[i][j] + newmatrix[r1][j]);
                }
            }
            // initilize resultat  rows with vector v1
            resultat.push_back(v1);
        }
    }
    return resultat;
}

Matrix algebra::upper_triangular(const Matrix &matrix)
{
    // cant change matrix becuase  its const type ...
    // so initilize resultat with matrix in first of the function and ...
    // change resultat during loops in 2 cases
    Matrix resultat = matrix;
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
        // case 1 pivot : make sure if main diagnol has no zero element
        for (size_t i{}; i < matrix.size(); i++)
        {
            // if ith element of matrix non-zero just go next elemnet
            if (matrix[i][i] != 0)
                continue;
            // chack lower rows to know if in there maybe ...
            // a nonzero elemennt exist to swap with ith row
            for (size_t j{i + 1}; j < matrix[0].size(); j++)
            {
                if (resultat[j][i] != 0)
                {
                    resultat = algebra::ero_swap(resultat, j, i);
                    // first nonzero element founded is enough ,no need to ...
                    // search other(lower) rows
                    break;
                }
            }
        }
        // case 2 :we did pivot to matrix before in case 1 so ...
        // matrix is ready to use gaussian elimination method ...
        // and being uptriangular
        for (size_t i{}; i < matrix.size(); i++)
        {
            // nothing can happen if element on main diagonal is 0
            if (resultat[i][i] == 0)
            {
                break;
            }
            // elminate (use trick to convert to zero ) lower elemnts ...
            //  without changing detminant,singular value and other properties

            for (size_t j{i + 1}; j < resultat[0].size(); j++)
            {
                double trick = -resultat[j][i] / resultat[i][i];
                resultat = algebra::ero_sum(resultat, i, trick, j);
            }
        }
    }
    return resultat;
}

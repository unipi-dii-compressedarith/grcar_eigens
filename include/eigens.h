#include <iostream>
#include "posit.h"
#include <cstdlib>
#include <iomanip>      // std::setprecision
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>
#include<cstdlib>
#include <boost/multiprecision/float128.hpp>
#include <boost/math/special_functions.hpp>

typedef Eigen::Matrix<float,Eigen::Dynamic,Eigen::Dynamic>MatrixXfloat;
typedef Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic>MatrixXdouble;
typedef Eigen::Matrix<boost::multiprecision::float128,Eigen::Dynamic,Eigen::Dynamic>MatrixXfloat128;

using Posit32e8 = posit::Posit<int32_t, 32,8, uint32_t, posit::PositSpec::WithNan>;
typedef Eigen::Matrix<Posit32e8,Eigen::Dynamic,Eigen::Dynamic>MatrixXp32e8;
using Posit32e2 = posit::Posit<int32_t, 32,2, uint32_t, posit::PositSpec::WithNan>;
typedef Eigen::Matrix<Posit32e2,Eigen::Dynamic,Eigen::Dynamic>MatrixXp32e2;
using Posit64e2 = posit::Posit<int64_t, 64,2, uint64_t, posit::PositSpec::WithNan>;
typedef Eigen::Matrix<Posit64e2,Eigen::Dynamic,Eigen::Dynamic>MatrixXp64e2;

using namespace std;

template<typename B, typename T>
int getGrcarMatrix(B& m,int n);

template <class MatrixType>
auto getEigens(MatrixType& m);  


extern template int getGrcarMatrix<MatrixXdouble,double>(MatrixXdouble& m,int n);

extern template int getGrcarMatrix<MatrixXp32e2,Posit32e2>(MatrixXp32e2& m,int n);

extern template int getGrcarMatrix<MatrixXp64e2,Posit64e2>(MatrixXp64e2& m,int n);
#include <eigens.h>

template
int getGrcarMatrix<MatrixXdouble,double>(MatrixXdouble& m,int n);

template
int getGrcarMatrix<MatrixXp32e2,Posit32e2>(MatrixXp32e2& m,int n);

template
int getGrcarMatrix<MatrixXp64e2,Posit64e2>(MatrixXp64e2& m,int n);

template<typename B, typename T>
int getGrcarMatrix(B& m,int n){
    int p = -1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if (j == p){
                m(i,j) = T(-1);
            }
            else if ((j>p) && (j<p+5)){
                m(i,j) = T(1);
            }
            else
                m(i,j) = T(0);
        }
        p++;
    }
    return 0;
}

template <class MatrixType>
auto getEigens(MatrixType& m) {
    return m.eigenvalues();
}




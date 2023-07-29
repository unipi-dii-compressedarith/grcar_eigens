#include <eigens.h>
#include <fstream>
int main(int argc, char* argv[]){
    if( argc < 3 ) {
        std::cout << "Usage: " << argv[0] << " <matrix size> <filename_out>" << std::endl;
        return -1;
    }

    unsigned int size = atoi(argv[1]);
    std::string fname{argv[2]};
    std::ofstream ofdouble{fname+"_double.txt"};
    std::ofstream ofp32{fname+"_p32.txt"};
    std::ofstream ofp64{fname+"_p64.txt"};

    MatrixXdouble mdouble(size,size);
    getGrcarMatrix<MatrixXdouble,double>(mdouble,size);
    auto eig_mdouble = mdouble.eigenvalues();
    auto eigt_mdouble = mdouble.transpose().eigenvalues();

    ofdouble<<eig_mdouble<<endl<<endl<<eigt_mdouble<<endl;

    MatrixXp32e2 mp32e2(size,size);
    getGrcarMatrix<MatrixXp32e2,Posit32e2>(mp32e2,size);
    auto eig_mp32e2 = mp32e2.eigenvalues();
    auto eigt_mp32e2 = mp32e2.transpose().eigenvalues();

    ofp32<<eig_mp32e2<<endl<<endl<<eigt_mp32e2<<endl;


    MatrixXp64e2 mp64e2(size,size);
    getGrcarMatrix<MatrixXp64e2,Posit64e2>(mp64e2,size);
    auto eig_mp64e2 = mp64e2.eigenvalues();
    auto eigt_mp64e2 = mp64e2.transpose().eigenvalues();
    ofp64<<eig_mp64e2<<endl<<endl<<eigt_mp64e2<<endl;

    return 0;
}






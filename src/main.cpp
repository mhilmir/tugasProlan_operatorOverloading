#include <iostream>
#include "../include/PersegiPanjang.hpp"

using namespace std;

int main(){
    double ctrArray_rect_A[2] = {2,4};
    PersegiPanjang rect_A = PersegiPanjang(ctrArray_rect_A, 4, 4);

    double ctrArray_rect_B[2] = {5,5};
    PersegiPanjang rect_B = PersegiPanjang(ctrArray_rect_B, 4, 4);

    cout << "Diketahui informasi sebagai berikut:" << endl;
    cout << "PersegiPanjang rect_A : ";
    cout << "xmin = " << rect_A[0] << endl;
    cout << "\t\t\txmax = " << rect_A[1] << endl;
    cout << "\t\t\tymin = " << rect_A[2] << endl;
    cout << "\t\t\tymax = " << rect_A[3] << endl << endl;

    cout << "PersegiPanjang rect_B : ";
    cout << "xmin = " << rect_B[0] << endl;
    cout << "\t\t\txmax = " << rect_B[1] << endl;
    cout << "\t\t\tymin = " << rect_B[2] << endl;
    cout << "\t\t\tymax = " << rect_B[3] << endl << endl;

    PersegiPanjang rect_C = rect_A + rect_B;
    cout << "Diberlakukan operasi; rect_A + rect_B = rect_C\nSehingga," << endl;
    cout << "PersegiPanjang rect_C : ";
    cout << "xmin = " << rect_C[0] << endl;
    cout << "\t\t\txmax = " << rect_C[1] << endl;
    cout << "\t\t\tymin = " << rect_C[2] << endl;
    cout << "\t\t\tymax = " << rect_C[3] << endl << endl;

    PersegiPanjang rect_D = rect_A - rect_B;
    cout << "Diberlakukan operasi; rect_A - rect_B = rect_D\nSehingga," << endl;
    cout << "PersegiPanjang rect_D : ";
    cout << "xmin = " << rect_D[0] << endl;
    cout << "\t\t\txmax = " << rect_D[1] << endl;
    cout << "\t\t\tymin = " << rect_D[2] << endl;
    cout << "\t\t\tymax = " << rect_D[3] << endl << endl;

    ++rect_C;
    cout << "Apabila luas rekt_C dijadikan dua kali lipat,\nMaka," << endl;
    cout << "PersegiPanjang rect_C : ";
    cout << "xmin = " << rect_C[0] << endl;
    cout << "\t\t\txmax = " << rect_C[1] << endl;
    cout << "\t\t\tymin = " << rect_C[2] << endl;
    cout << "\t\t\tymax = " << rect_C[3] << endl << endl;

    --rect_D;
    cout << "Apabila luas rekt_D dijadikan setengah kali lipat,\nMaka," << endl;
    cout << "PersegiPanjang rect_D : ";
    cout << "xmin = " << rect_D[0] << endl;
    cout << "\t\t\txmax = " << rect_D[1] << endl;
    cout << "\t\t\tymin = " << rect_D[2] << endl;
    cout << "\t\t\tymax = " << rect_D[3] << endl << endl;
    
    cout << "Digunakan operator == untuk menentukan apakah dua persegiPanjang beririsan atau tidak" << endl;
    cout << "rect_A == rect_B ---> ";
    if(rect_A == rect_B){
        cout << "Beririsan" << endl;
    } else{
        cout << "Tidak Beririsan" << endl;
    }

    return 0;
}
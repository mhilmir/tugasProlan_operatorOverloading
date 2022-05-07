#ifndef __PERSEGIPANJANG_HPP__
#define __PERSEGIPANJANG_HPP__

#include <iostream>

class PersegiPanjang{
private:
    double xmin, xmax, ymin, ymax;

public:
    PersegiPanjang(double ctr[2], double length_x, double length_y);
    PersegiPanjang operator+(PersegiPanjang const &sampel);
    PersegiPanjang operator-(PersegiPanjang const &sampel);
    void operator++();
    void operator--();
    double operator[](int n);
    bool operator==(PersegiPanjang const &sampel);
    void checkValue(){
        double ctr_x = (PersegiPanjang::xmax + PersegiPanjang::xmin) / 2;
        double ctr_y = (PersegiPanjang::ymax + PersegiPanjang::ymin) / 2;
        std::cout << "\nctr_x = " << ctr_x << std::endl;
        std::cout << "ctr_y = " << ctr_y << std::endl;
        std::cout << "xmin = " << PersegiPanjang::xmin << std::endl;
        std::cout << "xmax = " << PersegiPanjang::xmax << std::endl;
        std::cout << "ymin = " << PersegiPanjang::ymin << std::endl;
        std::cout << "ymax = " << PersegiPanjang::ymax << std::endl;
    }

};

#endif
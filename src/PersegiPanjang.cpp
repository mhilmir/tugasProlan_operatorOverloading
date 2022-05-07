#include <iostream>
#include <math.h>
#include "../include/PersegiPanjang.hpp"

PersegiPanjang::PersegiPanjang(double ctr[2], double length_x, double length_y){
    this->xmin = ctr[0] - (0.5 * length_x);
    this->xmax = ctr[0] + (0.5 * length_x);
    this->ymin = ctr[1] - (0.5 * length_y);
    this->ymax = ctr[1] + (0.5 * length_y);
}

PersegiPanjang PersegiPanjang::operator+(PersegiPanjang const &sampel){
    enum position{upRight, upLeft, downLeft, downRight, right, up, left, down, none};
    position whereSampel = none;
    bool isSlice = false;
    double lower_x = 0, lower_y = 0, upper_x = 0, upper_y = 0, length_x, length_y, ctr_x, ctr_y;
    double ctr_x_this = this->xmax - ((this->xmax - this->xmin) / 2);
    double ctr_y_this = this->ymax - ((this->ymax - this->ymin) / 2);
    double ctr_x_sampel = sampel.xmax - ((sampel.xmax - sampel.xmin) / 2);
    double ctr_y_sampel = sampel.ymax - ((sampel.ymax - sampel.ymin) / 2);
    
    if((ctr_x_this < ctr_x_sampel) && (ctr_y_this == ctr_y_sampel)){
        whereSampel = right;
    } else if((ctr_x_this < ctr_x_sampel) && (ctr_y_this < ctr_y_sampel)){
        whereSampel = upRight;
    } else if((ctr_x_this == ctr_x_sampel) && (ctr_y_this < ctr_y_sampel)){
        whereSampel = up;
    } else if((ctr_x_this > ctr_x_sampel) && (ctr_y_this < ctr_y_sampel)){
        whereSampel = upLeft;
    } else if((ctr_x_this > ctr_x_sampel) && (ctr_y_this == ctr_y_sampel)){
        whereSampel = left;
    } else if((ctr_x_this > ctr_x_sampel) && (ctr_y_this > ctr_y_sampel)){
        whereSampel = downLeft;
    } else if((ctr_x_this == ctr_x_sampel) && (ctr_y_this > ctr_y_sampel)){
        whereSampel = down;
    } else if((ctr_x_this < ctr_x_sampel) && (ctr_y_this > ctr_y_sampel)){
        whereSampel = downRight;
    }

    if(whereSampel == right){
        if(this->xmax > sampel.xmin){     
            isSlice = true;
        }
    } else if(whereSampel == upRight){
        if((this->xmax > sampel.xmin) && (this->ymax > sampel.ymin)){
            isSlice = true;
        }
    } else if(whereSampel == up){
        if(this->ymax > sampel.ymin){
            isSlice = true;
        }
    } else if(whereSampel == upLeft){
        if((this->xmin < sampel.xmax) && (this->ymax > sampel.ymin)){
            isSlice = true;
        }
    } else if(whereSampel == left){
        if(this->xmin < sampel.xmax){
            isSlice = true;
        }
    } else if(whereSampel == downLeft){
        if((this->xmin < sampel.xmax) && (this->ymin < sampel.ymax)){
            isSlice = true;
        }
    } else if(whereSampel == down){
        if(this->ymin < sampel.ymax){
            isSlice = true;
        }
    } else if(whereSampel == downRight){
        if((this->xmax > sampel.xmin) && (this->ymin < sampel.ymax)){
            isSlice = true;
        }
    }

    if(isSlice){
        if(this->xmin <= sampel.xmin){
            lower_x = this->xmin;
        } else if(this->xmin >= sampel.xmin){
            lower_x = sampel.xmin;
        }
        
        if(this->xmax >= sampel.xmax){
            upper_x = this->xmax;
        } else if(this->xmax <= sampel.xmax){
            upper_x = sampel.xmax;
        }
        
        if(this->ymin <= sampel.ymin){
            lower_y = this->ymin;
        } else if(this->ymin >= sampel.ymin){
            lower_y = sampel.ymin;
        }
        
        if(this->ymax >= sampel.ymax){
            upper_y = this->ymax;
        } else if(this->ymax <= sampel.ymax){
            upper_y = sampel.ymax;
        }

        length_x = upper_x - lower_x;
        length_y = upper_y - lower_y;
        ctr_x = (upper_x + lower_x) / 2;
        ctr_y = (upper_y + lower_y) / 2;
        double ctr[2] = {ctr_x, ctr_y};

        PersegiPanjang temp = PersegiPanjang(ctr, length_x, length_y);
        
        return temp;
    } else{
        std::cout << "bidang tidak beririsan" << std::endl;
        double ctr_void[2] = {0,0};
        PersegiPanjang poidd = PersegiPanjang(ctr_void, 0, 0);
        return poidd;
    }
}

PersegiPanjang PersegiPanjang::operator-(PersegiPanjang const &sampel){
    enum position{upRight, upLeft, downLeft, downRight, right, up, left, down, none};
    position whereSampel = none;
    bool isSlice = false;
    double lower_x = 0, lower_y = 0, upper_x = 0, upper_y = 0, length_x, length_y, ctr_x, ctr_y;
    double ctr_x_this = this->xmax - ((this->xmax - this->xmin) / 2);
    double ctr_y_this = this->ymax - ((this->ymax - this->ymin) / 2);
    double ctr_x_sampel = sampel.xmax - ((sampel.xmax - sampel.xmin) / 2);
    double ctr_y_sampel = sampel.ymax - ((sampel.ymax - sampel.ymin) / 2);
    
    if((ctr_x_this < ctr_x_sampel) && (ctr_y_this == ctr_y_sampel)){
        whereSampel = right;
    } else if((ctr_x_this < ctr_x_sampel) && (ctr_y_this < ctr_y_sampel)){
        whereSampel = upRight;
    } else if((ctr_x_this == ctr_x_sampel) && (ctr_y_this < ctr_y_sampel)){
        whereSampel = up;
    } else if((ctr_x_this > ctr_x_sampel) && (ctr_y_this < ctr_y_sampel)){
        whereSampel = upLeft;
    } else if((ctr_x_this > ctr_x_sampel) && (ctr_y_this == ctr_y_sampel)){
        whereSampel = left;
    } else if((ctr_x_this > ctr_x_sampel) && (ctr_y_this > ctr_y_sampel)){
        whereSampel = downLeft;
    } else if((ctr_x_this == ctr_x_sampel) && (ctr_y_this > ctr_y_sampel)){
        whereSampel = down;
    } else if((ctr_x_this < ctr_x_sampel) && (ctr_y_this > ctr_y_sampel)){
        whereSampel = downRight;
    }

    if(whereSampel == right){
        if(this->xmax > sampel.xmin){     
            isSlice = true;
        }
    } else if(whereSampel == upRight){
        if((this->xmax > sampel.xmin) && (this->ymax > sampel.ymin)){
            isSlice = true;
        }
    } else if(whereSampel == up){
        if(this->ymax > sampel.ymin){
            isSlice = true;
        }
    } else if(whereSampel == upLeft){
        if((this->xmin < sampel.xmax) && (this->ymax > sampel.ymin)){
            isSlice = true;
        }
    } else if(whereSampel == left){
        if(this->xmin < sampel.xmax){
            isSlice = true;
        }
    } else if(whereSampel == downLeft){
        if((this->xmin < sampel.xmax) && (this->ymin < sampel.ymax)){
            isSlice = true;
        }
    } else if(whereSampel == down){
        if(this->ymin < sampel.ymax){
            isSlice = true;
        }
    } else if(whereSampel == downRight){
        if((this->xmax > sampel.xmin) && (this->ymin < sampel.ymax)){
            isSlice = true;
        }
    }


    if(isSlice){
        if(this->xmin >= sampel.xmin){
            lower_x = this->xmin;
        } else if(this->xmin <= sampel.xmin){
            lower_x = sampel.xmin;
        }
        
        if(this->xmax <= sampel.xmax){
            upper_x = this->xmax;
        } else if(this->xmax >= sampel.xmax){
            upper_x = sampel.xmax;
        }
        
        if(this->ymin >= sampel.ymin){
            lower_y = this->ymin;
        } else if(this->ymin <= sampel.ymin){
            lower_y = sampel.ymin;
        }
        
        if(this->ymax <= sampel.ymax){
            upper_y = this->ymax;
        } else if(this->ymax >= sampel.ymax){
            upper_y = sampel.ymax;
        }

        length_x = upper_x - lower_x;
        length_y = upper_y - lower_y;
        ctr_x = (upper_x + lower_x) / 2;
        ctr_y = (upper_y + lower_y) / 2;
        double ctr[2] = {ctr_x, ctr_y};

        PersegiPanjang temp = PersegiPanjang(ctr, length_x, length_y);
        
        return temp;
    } else{
        std::cout << "bidang tidak beririsan" << std::endl;
        double ctr_void[2] = {0,0};
        PersegiPanjang poidd = PersegiPanjang(ctr_void, 0, 0);
        return poidd;
    }
}

void PersegiPanjang::operator++(){
    double ctr_x = (this->xmax + this->xmin) / 2;
    double ctr_y = (this->ymax + this->ymin) / 2;
    double length_x = this->xmax - this->xmin;
    double length_y = this->ymax - this->ymin;
    double newArea = 2 * (length_x * length_y);
    double new_length_x = sqrt(newArea / (length_y/length_x));
    double new_length_y = sqrt(newArea / (length_x/length_y));

    this->xmin = ctr_x - (0.5 * new_length_x);
    this->xmax = ctr_x + (0.5 * new_length_x);
    this->ymin = ctr_y - (0.5 * new_length_y);
    this->ymax = ctr_y + (0.5 * new_length_y);
}

void PersegiPanjang::operator--(){
    double ctr_x = (this->xmax + this->xmin) / 2;
    double ctr_y = (this->ymax + this->ymin) / 2;
    double length_x = this->xmax - this->xmin;
    double length_y = this->ymax - this->ymin;
    double newArea = 0.5 * (length_x * length_y);
    double new_length_x = sqrt(newArea / (length_y/length_x));
    double new_length_y = sqrt(newArea / (length_x/length_y));

    this->xmin = ctr_x - (0.5 * new_length_x);
    this->xmax = ctr_x + (0.5 * new_length_x);
    this->ymin = ctr_y - (0.5 * new_length_y);
    this->ymax = ctr_y + (0.5 * new_length_y);
}

double PersegiPanjang::operator[](int n){
    if(n == 0){
        return this->xmin;
    } else if(n == 1){
        return this->xmax;
    } else if(n == 2){
        return this->ymin;
    } else if(n == 3){
        return this->ymax;
    } else{
        return 0;
    }
}

bool PersegiPanjang::operator==(PersegiPanjang const &sampel){
    enum position{upRight, upLeft, downLeft, downRight, right, up, left, down, none};
    position whereSampel = none;
    bool isSlice = false;
    double ctr_x_this = this->xmax - ((this->xmax - this->xmin) / 2);
    double ctr_y_this = this->ymax - ((this->ymax - this->ymin) / 2);
    double ctr_x_sampel = sampel.xmax - ((sampel.xmax - sampel.xmin) / 2);
    double ctr_y_sampel = sampel.ymax - ((sampel.ymax - sampel.ymin) / 2);
    
    if((ctr_x_this < ctr_x_sampel) && (ctr_y_this == ctr_y_sampel)){
        whereSampel = right;
    } else if((ctr_x_this < ctr_x_sampel) && (ctr_y_this < ctr_y_sampel)){
        whereSampel = upRight;
    } else if((ctr_x_this == ctr_x_sampel) && (ctr_y_this < ctr_y_sampel)){
        whereSampel = up;
    } else if((ctr_x_this > ctr_x_sampel) && (ctr_y_this < ctr_y_sampel)){
        whereSampel = upLeft;
    } else if((ctr_x_this > ctr_x_sampel) && (ctr_y_this == ctr_y_sampel)){
        whereSampel = left;
    } else if((ctr_x_this > ctr_x_sampel) && (ctr_y_this > ctr_y_sampel)){
        whereSampel = downLeft;
    } else if((ctr_x_this == ctr_x_sampel) && (ctr_y_this > ctr_y_sampel)){
        whereSampel = down;
    } else if((ctr_x_this < ctr_x_sampel) && (ctr_y_this > ctr_y_sampel)){
        whereSampel = downRight;
    }

    if(whereSampel == right){
        if(this->xmax > sampel.xmin){     
            isSlice = true;
        }
    } else if(whereSampel == upRight){
        if((this->xmax > sampel.xmin) && (this->ymax > sampel.ymin)){
            isSlice = true;
        }
    } else if(whereSampel == up){
        if(this->ymax > sampel.ymin){
            isSlice = true;
        }
    } else if(whereSampel == upLeft){
        if((this->xmin < sampel.xmax) && (this->ymax > sampel.ymin)){
            isSlice = true;
        }
    } else if(whereSampel == left){
        if(this->xmin < sampel.xmax){
            isSlice = true;
        }
    } else if(whereSampel == downLeft){
        if((this->xmin < sampel.xmax) && (this->ymin < sampel.ymax)){
            isSlice = true;
        }
    } else if(whereSampel == down){
        if(this->ymin < sampel.ymax){
            isSlice = true;
        }
    } else if(whereSampel == downRight){
        if((this->xmax > sampel.xmin) && (this->ymin < sampel.ymax)){
            isSlice = true;
        }
    }

    if(isSlice){
        return true;
    }
    return false;
}
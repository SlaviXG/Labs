#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>

class ComplexNum
{
private:
    double real;
    double imag;

    constexpr static const double EPSILON = 1E-6;

public:

    ComplexNum(double real = 0.0, double imag = 0.0) {
        this->real = real;
        this->imag = imag;
    }

    double get_real()
    {
        return this->real;
    }

    double get_imag()
    {
        return this->imag;
    }


    bool isNull()
    {
        if (this->real == (double) 0 && this->imag == (double) 0) return true;

        return false;
    }

    void operator=(const ComplexNum& c1) {

        this->real = c1.real;
        this->imag = c1.imag;
    }

    ComplexNum operator +(const ComplexNum& c1)const {
        ComplexNum new_num;
        new_num.real = this->real + c1.real;
        new_num.imag = this->imag + c1.imag;
        return new_num;
    }

    ComplexNum operator -(const ComplexNum& c1)const {
        ComplexNum new_num;
        new_num.real = this->real - c1.real;
        new_num.imag = this->imag - c1.imag;
        return new_num;
    }

    ComplexNum operator *(const ComplexNum& c1)const {
        ComplexNum new_num;
        new_num.real = this->real * c1.real - this->imag * c1.imag;
        new_num.imag = this->imag * c1.real + this->real * c1.imag;
        return new_num;
    }

    ComplexNum operator /(const ComplexNum& c1)const {
        double div = c1.real * c1.real + c1.imag * c1.imag;
        ComplexNum new_num;
        new_num.real = this->real * c1.real + this->imag * c1.imag;
        new_num.real /= div;
        new_num.imag = this->imag * c1.real - this->real * c1.imag;
        new_num.imag /= div;
        return new_num;
    }

    bool operator ==(const ComplexNum& c1)const
    {
        if (fabs(this->real - c1.real) < EPSILON && fabs(this->imag - c1.imag) < EPSILON)
            return true;
        return false;
    }

    bool operator !=(const ComplexNum& c1)const
    {
        if (fabs(this->real - c1.real) < EPSILON && fabs(this->imag - c1.imag) < EPSILON)
            return false;
        return true;
    }

    friend std::ostream& operator<<(std::ostream& os, const ComplexNum& c) {
        if (c.real) {
            os << std::setprecision(3) << c.real;
        }
        if (c.imag >= 0) {
            os << "+" << std::setprecision(3) << c.imag << "i";
        }
        else {
            os << std::setprecision(3) << c.imag  << "i";
        }
        return os;
    }

};


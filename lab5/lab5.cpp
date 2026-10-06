#include <iostream>

class ComplexNumber {
 private:
        double real;
        double imaginary;
 public:
    ComplexNumber(): real(0), imaginary(0) {}
    ComplexNumber(int real): real(real), imaginary(0) {}
    ComplexNumber(int real, int imaginary): real(real), imaginary(imaginary) {}
};
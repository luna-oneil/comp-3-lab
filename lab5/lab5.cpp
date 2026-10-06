#include <iostream>

class ComplexNumber {
 private:
        double real;
        double imaginary;
 public:
    ComplexNumber(): real(0.0), imaginary(0.0) {}
    ComplexNumber(double real): real(real), imaginary(0.0) {}
    ComplexNumber(double real, double imaginary): real(real), imaginary(imaginary) {}
    double getReal() const;
    double getImaginary() const;
    void setReal(double real);
    void setImaginary(double imaginary);
};
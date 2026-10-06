#include <iostream>
#include <string>

using namespace std;

class ComplexNumber {
 private:
    double _real;
    double _imaginary;
 public:
    ComplexNumber(): real(0.0), imaginary(0.0) {}
    ComplexNumber(double real): real(_real), imaginary(0.0) {}
    ComplexNumber(double real, double imaginary): real(_real), imaginary(_imaginary) {}

    double getReal() const;
    double getImaginary() const;

    void setReal(double real);
    void setImaginary(double imaginary);

    ComplexNumber operator+(const ComplexNumber &right) const;
    ComplexNumber operator-(const ComplexNumber &right) const;
    ComplexNumber operator*(const ComplexNumber &right) const;
    ComplexNumber operator/(const ComplexNumber &right) const;
    ComplexNumber operator!() const;

    // friend functions
    friend ostream &operator<<(ostream &out, ComplexNumber complex);
};

double getReal() const {
       return _real;
}

double getImaginary() const {
       return _imaginary;
}

void setReal(double real) {
       _real = real;
}

void setImaginary(double imaginary){
       _imaginary = imaginary;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &right) const {
    ComplexNumber result(real + right.real, imaginary + right.imaginary);
    return result;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &right) const {
    ComplexNumber result(real - right.real, imaginary - right.imaginary);
    return result;
}

ostream &operator<<(ostream &out, ComplexNumber complex) {
    if (complex.imaginary >= 0.0) {
        out << complex.getReal() << " + " << complex.getImaginary() << endl;
    } else {
        out << complex.getReal() << " - " << complex.getImaginary() << endl;
    }
}

ComplexNumber ComplexNumber::operator!() const {
    ComplexNumber temp = ComplexNumber(real, -imaginary);
    return temp;
}
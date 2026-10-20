#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

    ComplexNumber operator+(const ComplexNumber &right) const;
    ComplexNumber operator-(const ComplexNumber &right) const;
    ComplexNumber operator*(const ComplexNumber &right) const;
    ComplexNumber operator/(const ComplexNumber &right) const;
    ComplexNumber operator!() const;

    // friend functions
    friend ostream &operator<<(ostream &out, ComplexNumber complex);
};

double ComplexNumber::getReal() const {
    return real;
}

double ComplexNumber::getImaginary() const {
    return imaginary;
}

void ComplexNumber::setReal(double r) {
    real = r;
}

void ComplexNumber::setImaginary(double imag){
    imaginary = imag;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &right) const {
    ComplexNumber result(real + right.real, imaginary + right.imaginary);
    return result;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &right) const {
    ComplexNumber result(real - right.real, imaginary - right.imaginary);
    return result;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& right) const {
    ComplexNumber result(real * right.real - imaginary * right.imaginary,
                         real * right.imaginary + imaginary * right.real);
    return result;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& right) const {
    double denominator = right.real * right.real + right.imaginary * right.imaginary;

    ComplexNumber result((real * right.real + imaginary * right.imaginary) / denominator,
                         (imaginary * right.real - real * right.imaginary) / denominator);
    return result;
}

ostream &operator<<(ostream &out, ComplexNumber complex) {
    out << complex.getReal() << " + " << complex.getImaginary() << "i" << endl;
    return out;
}

ComplexNumber ComplexNumber::operator!() const {
    ComplexNumber temp = ComplexNumber(real, -imaginary);
    return temp;
}

// Main function use for testing.
int main(){
    cout << "Value of c1 (default constructor): " << endl;

    ComplexNumber c1;
    // default should give real 0 and imaginary 0.
    cout << "c1.getReal() == " << c1.getReal() 
            << ", c1.getImaginary() == " << c1.getImaginary()
                << endl;
    // testing value constructor.
    cout << "Value of c2 (value constructor): " << endl;
    
    ComplexNumber c2(1, 2);
    cout << "c2.getReal() == " << c2.getReal()
            << ", c2.getImaginary() == " << c2.getImaginary()
                << endl;
    
    // tests between c2 and c3.
    ComplexNumber c3(3,4);

    // addition
    cout << "c2 + c3 (1+2i + 3+4i) == "
            << c2 + c3 << endl;
    // substraction
    cout << "c2 - c3 (1+2i - 3+4i) == "
            << c2 - c3 << endl;
    // multiplication
    cout << "c2 * c3 (1+2i * 3+4i) == "
            << c2 * c3 << endl;
    // division
    cout << "c2 / c3 (1+2i / 3+4i) == "
            << c2 / c3 << endl;
    // combined division and multiplication
    cout << "(c2/c3) + (c2*c3) == "
            << (c2 / c3) + (c2 * c3) << endl;

    // conjugate
    cout << "Conjugate of c2 (1+2i) == "
            << !c2 << endl;
    
    // Test mutators
    ComplexNumber c4;
    c4.setReal(5);
    c4.setImaginary(6);

    cout << "\nValue of c4 after mutators: "
            << c4 << endl;
    
    // Create a vector of 10 complex numbers
    vector<ComplexNumber> numbers;

    for (int n = 0; n < 10; n++){
        numbers.push_back(ComplexNumber(n, 2 * n));
    }

    // First loop using an integer index
    cout << "\nVector output using indexed for-loop:" << endl;

    for (int i = 0; i < numbers.size(); i++){
        cout << numbers[i] << endl;
    }

    // Second loop using an iterator
    cout << "\nVector output using an iterator in for-loop:" << endl;

    for (vector<ComplexNumber>::iterator it = numbers.begin(); it != numbers.end(); ++it){
        cout << *it << endl;
    }
}

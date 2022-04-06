#include <iostream>

using namespace std;

//represents a + ib
struct Complex {
    double real, imaginary;
};

//we can specify how each operator works 
//with this new user-defined type.
Complex operator+(Complex &first, Complex &second) {
   // given (a1,b1) + (a2,b2) = (a1+a2, b1+b2)
   Complex result;
   result.real = first.real + second.real;
   result.imaginary = first.imaginary + second.imaginary;
   return result;
}

//output
ostream& operator<<(ostream& stream, Complex& complex) {
    return stream << "(" << complex.real << "," << complex.imaginary << ")";
}

//input
istream& operator>>(istream& stream, Complex& complex) {
    return stream >> complex.real >> complex.imaginary;
}

Complex operator+=(Complex &first, Complex &second) {
   first.real += second.real;
   first.imaginary += second.imaginary;
   return first;; // this is support: c1 = c3 += c2;
}

//DO NOT MODIFY ANY CODE GIVEN BELOW.
int overloadOp() {
    Complex c1, c2, c3;
    cin >> c1;
    cin >> c2;

    c3 = c1 + c2;
    cout << c1 << " + " << c2 << " = " << c3 << endl;
    c3 += c2;
    cout << c3 << endl;
}



// https://www.programiz.com/cpp-programming/class-templates

// fail to compile
// C++ program to demonstrate the use of class templates

#include <iostream>
using namespace std;

// Class template
template <class T>
class Number {
   private:
    // Variable of type T
    T num;

   public:
    Number(T n) : num(n) {}   // constructor
;
    // T getNum() {
    //    return num;
    }
};

// Function definition outside
template <class T>
T Number<T>::getNum() {
    return num;
}


int main() {

    // create object with int type
    Number<int> numberInt(7);

    // create object with double type
    Number<double> numberDouble(7.7);

    cout << "int Number = " << numberInt.getNum() << endl;
    cout << "double Number = " << numberDouble.getNum() << endl;

    return 0;
}
#include <iostream>
using namespace std;

class DivisionByZero{};

class TerminateException{};

double division(double a, double b){
    if(b==0){
        throw DivisionByZero();
    }
    if(a==6789){
        throw TerminateException();
    }

    return a/b;
}

int main(){
    double a,b;
    while(true){
        cout << "Value of a: ";
        cin >> a;
        cout << "Value of b: ";
        cin >> b;
        double result;
        try{
            result = division(a,b);
            cout << "Result: " << result << endl;
        } catch(TerminateException) {
            cout << "Terminate requested!" << endl;
            return -1;
        } catch(DivisionByZero) {
            cout << "Can't divide by zero!" << endl;        
        } 
    }
    return 0;
}
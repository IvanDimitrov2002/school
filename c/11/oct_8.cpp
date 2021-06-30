#include <iostream>
using namespace std;

namespace firstSpace{
    void say_hello(){
        cout << "Hello from first namespace" << endl;
    }
    namespace innerSpace{
        void say_hello(){
            cout << "Hello from inner namespace" << endl;
        }
    }
}

namespace secondSpace{
    void say_hello(){
        cout << "Hello from second namespace" << endl;
    }
}

using namespace firstSpace::innerSpace;
int main(){
    say_hello();
    secondSpace::say_hello();
    return 0;
}
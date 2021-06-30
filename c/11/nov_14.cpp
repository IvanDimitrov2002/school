#include <iostream>
using namespace std;

class Fib{
    int *numbers;
    int firstNum = 0;
    int secondNum = 1;
    int size = 2;
    public:
        Fib(){}
        Fib(int n){
            if(n > 1){
                size = n;
                numbers = new int[size];
                numbers[0] = 0;
                numbers[1] = 1;
                for(int i = 2;i < n; i++){
                    numbers[i] = numbers[i-1] + numbers[i-2];
                }
            }
        }

        Fib(int n, int firstNum, int secondNum) : firstNum(firstNum), secondNum(secondNum){
            if(n > 1){
                size = n;
                numbers = new int[size];
                numbers[0] = firstNum;
                numbers[1] = secondNum;
                for(int i = 2;i < n; i++){
                    numbers[i] = numbers[i-1] + numbers[i-2];
                }
            }
        }

        void printNums(){
            for(int i = 0;i < size; i++){
                cout << numbers[i] << endl;
            }
        }

        Fib(const Fib& f){
            size = f.size;
            numbers = new int[size];
            for(int i = 0;i < size; i++){
                numbers[i] = f.numbers[i];
            }
        }

        void operator=(Fib f){
            size = f.size;
            numbers = new int[size];
            for(int i = 0;i < size; i++){
                numbers[i] = f.numbers[i];
            } 
        }

        void generate(){
            int i = size - 1;
            size *= 2;
            resize(size);
            for(;i < size; i++){
                numbers[i] = numbers[i-1] + numbers[i-2];
            }
        }

        private:
            void resize(int chunk){
                int* temp = numbers;
                numbers = new int[size + chunk];
                for(int i = 0; i< size; i++){
                    numbers[i] = temp[i];
                }

                size += chunk;
                delete temp;
            }

};

int main(){
    Fib numbers = Fib(5, 3, 5);
    numbers.printNums();
    // Fib numbers2;
    // numbers2 = numbers;
    // numbers2.printNums();

    return 0;
}

// class Point{
//     int x;
//     int y;

//     public:
//         Point(): x(0), y(0) {
//             cout << "empty constructore" << endl;
//         };
//         Point(int x, int y): x(x), y(y) {
//             cout << "empty with args" << endl;
//         };

//         ~Point(){
//             x = 0;
//             y = 0;
//             cout << "destructor called" << endl;
//         }

// };

// int main(){
//     Point p1;
//     Point p2 = Point(5, 10);
//     return 0;
// }
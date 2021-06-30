#include <iostream>
using namespace std;

class Point{
    int x;
    int y;
    public:
        Point(int x, int y): x(x), y(y){}

        Point(const Point& p){
            x = p.x;
            y = p.y;
        }

        void setX(int x){
            this->x = x;

        }

        int getX() const{
            return x;
        }

        void setY(int y){
            this->y = y;

        }

        int getY() const{
            return y;
        }
};

void printPoint(const Point& p){
    cout << "Point(" << p.getX() << ", " << p.getY() << ")" << endl;
}

int main(){
    Point p1 = Point(1, 2);
    Point p2 = Point(p1);

    printPoint(p1);
    printPoint(p2);
    return 0;
}

// class Stack{
//     static const int chunk = 2;
//     int size;
//     int* data;
//     int top;
//     public:
//         Stack(){
//             size = chunk;
//             data = new int[size];
//             top = -1;
//         }

//         void push(int v){
//             if(top >= (size - 1)){
//                 resize();
//             }

//             data[++top] = v;
//         }

//         int pop(){
//             if(top < 0){
//                 throw exception();
//             }

//             return data[top--];
//         }

//     private:
//         void resize(){
//             int* temp = data;
//             data = new int[size + chunk];
//             for(int i = 0; i< size; i++){
//                 data[i] = temp[i];
//             }

//             size += chunk;
//             delete temp;
//             cout << "New size: " << size << endl;
//         }
// };

// int main(){
//     Stack st;
//     st.push(1);
//     st.push(2);
//     st.push(3);

//     try{

//     } catch (const exception(e)){

//     }
//     return 0;
// }
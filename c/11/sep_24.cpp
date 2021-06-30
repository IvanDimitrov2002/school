#include <iostream>
#include <cmath>
using namespace std;

class Point {
    private:
        int x = 5;
        int y;
    public:
        //Ако имаме дори и един конструктор, то default–натия се overwrite-ва
        Point(int x, int y){
            this->x=x;
            this->y=y;
        }

        Point(int x){
            this->x=x;
        }

        void setX(int x);

        int getX(){
            return x;
        }
        
        int getY(){
            return y;
        }

        // void setX(int p){
        //     x=p;
        // }

        double distance(Point b){
            int dx = getX() - b.getX();
            int dy = getY() - b.getY();
            double distance = sqrt(dx*dx + dy*dy);
            return distance;
        }

};

void Point::setX(int x){
    this->x=x;
}

int main() {
    // cout << "Enter value: ";
    // int a;
    // cin >> a;
    // cout << "Value of a: " << a << endl;
    //Point p = {2,3};
    //Point p(2,3);
    //Point p{2,3};
    // Point p = Point(2,3);
    // p.setX(9);
    // Point* pointer = &p;
    //p.setX(8);
    //cout << "Value: " << pointer->getX();
    Point a = Point(2,3);
    Point b = Point(4,5);
    cout << "Distance: " << a.distance(b) << endl;
}
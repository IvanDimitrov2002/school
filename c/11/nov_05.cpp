#include <iostream>
using namespace std;

class Point{
    double x;
    double y;
    public:
        Point(){}
        Point(double x, double y) : x(x), y(y){}

        double getX() const {
            return x;
        }

        double getY() const {
            return y;
        }

        void setX(double x){
            this->x = x;
        }

        void setY(double y){
            this->y = y;
        }

        Point& add(const Point p){
            x += p.getX();
            y += p.getY();
            return *this;
        }

        Point& sub(const Point p){
            x -= p.getX();
            y -= p.getY();
            return *this;
        }

        Point& mul(int alpha){
            x *= alpha;
            y *= alpha;
            return *this;
        }

        Point operator+(const Point p){
            Point result = Point(x + p.getX(), y + p.getY());
            return result;
        }

        Point operator*(double alpha){
            Point result = Point(x * alpha, y * alpha);
            return result;
        }

        Point& operator+=(const Point p){
            x += p.getX();
            y += p.getY();
            return *this;
        }
};

ostream& operator<<(ostream& out, const Point p){
    out << "point(" << p.getX() << ", " << p.getY() << ")" << endl;
    return out;
}

Point operator-(const Point p1, const Point p2){
    Point result = Point(p1.getX() - p2.getX(), p1.getY() - p2.getY());
    return result;
}

Point operator-(const Point p){
    Point result = Point(-p.getX(), -p.getY());
    return result;
}

void printPoint(const Point p){
    cout << "point(" << p.getX() << ", " << p.getY() << ")" << endl;
}

int main(){
    Point p1 = Point(1, 2);
    Point p2 = Point(2, 3);

    p1.add(p2).sub(p2).mul(2);
    printPoint(p1);

    Point p3 = Point(3, 4);
    Point p4 = p2 + p3;
    printPoint(p4);

    Point p5 = p4 - p3;
    printPoint(p5);

    Point p6 = -p5;
    printPoint(p6);

    Point p7 = Point(1, 2);
    Point p8 = p7 * 2;
    printPoint(p8);

    cout << p8;
    return 0;
}
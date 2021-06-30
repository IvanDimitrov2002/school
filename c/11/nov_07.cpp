#include <iostream>
#include <cmath>
using namespace std;

class Rectangle{
    int x, y, w, h;
    public:
        Rectangle(){}
        Rectangle(int x, int y, int w, int h) : x(x), y(y), w(w), h(h){}
        Rectangle operator+(int num){
            return Rectangle(x + num, y + num, w + num, h + num);
        }

        Rectangle& operator+=(int num){
            x += num;
            y += num;
            w += num;
            h += num;
            return *this;
        }

        Rectangle& operator++(int){
            x++;
            y++;
            w++;
            h++;
            return *this;
        }

        Rectangle& operator++(){
            x++;
            y++;
            w++;
            h++;
            return *this;
        }

        Rectangle operator+(Rectangle rect){
            int xtl1, ytl1, xbr1, ybr1, xtl2, ytl2, xbr2, ybr2;
            xtl1 = x; ytl1 = y;
            xbr1 = x + w; ybr1 = y + h;
            xtl2 = rect.x; ytl2 = rect.y;
            xbr2 = rect.x + rect.w; ybr2 = rect.y + rect.h;
            Rectangle result = Rectangle(min(xtl1, xtl2), min(ytl1, ytl2), max(xbr1, xbr2), max(ybr1, ybr2));
            return result;
        }

        Rectangle operator-(int num){
            return Rectangle(x - num, y - num, w - num, h - num);
        }

        Rectangle& operator-=(int num){
            x -= num;
            y -= num;
            w -= num;
            h -= num;
            return *this;
        }

        Rectangle& operator--(int){
            x--;
            y--;
            w--;
            h--;
            return *this;
        }

        Rectangle& operator--(){
            x--;
            y--;
            w--;
            h--;
            return *this;
        }

        // Rectangle operator-(Rectangle rect){
        //     int xtl1, ytl1, xbr1, ybr1, xtl2, ytl2, xbr2, ybr2;
        //     xtl1 = x; ytl1 = y;
        //     xbr1 = x + w; ybr1 = y + h;
        //     xtl2 = rect.x; ytl2 = rect.y;
        //     xbr2 = rect.x + rect.w; ybr2 = rect.y + rect.h;
        //     Rectangle result = Rectangle(min(xtl1, xtl2), min(ytl1, ytl2), max(xbr1, xbr2), max(ybr1, ybr2));
        //     return result;
        // }

        void printRect(){
            cout << "x: " << x << ", y: " << y << ", w: " << w << ", h: " << h << endl;
        }
};

int main(){
    Rectangle rect1 = Rectangle(0,0,5,6);
    Rectangle rect2 = Rectangle(3,2,5,3);
    (rect1+5).printRect();
    rect1.printRect();
    rect1+=5;
    rect1.printRect();
    rect1++;
    rect1.printRect();
    Rectangle rect3 = rect1 + rect2;
    rect3.printRect();
    // (rect3 - rect2).printRect();
    return 0;
}
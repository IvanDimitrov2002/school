#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Point{
    public:
        int x;
        int y;
        string toString(){
            ostringstream out;
            out << "(" << x << ", " << y << ")";
            return out.str();
        }
};

class PointCollection{

    vector<Point> points;
    public:
        void readPoints(string coordinates){
            istringstream in(coordinates);
            Point point = Point();
            in.ignore();
            in >> point.x;
            in.ignore();
            in >> point.y;
            points.push_back(point);
        }

        string averageCoordinates(){
            float x=0, y=0;
            for(int i=0;i<points.size();i++){
                x+=points[i].x;
                y+=points[i].y;
            }          
            ostringstream out;
            out << "(" << x/points.size() << ", " << y/points.size() << ")\n";
            return out.str();
        }
};

int main(){
    PointCollection collection = PointCollection();    
    collection.readPoints("(2, 3)");
    collection.readPoints("(6, 7)");
    collection.readPoints("(1, 1)");
    cout << collection.averageCoordinates();
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>                                                              
using namespace std;

class MarksCollectionTooBig : exception{};
class MarksCollectionOutOfRange : exception{};
class MarksCollectionFull : exception{};
class StudentNameTooSmall : exception{};
class SizeTooBig : exception{};

class StudentInfo{
    string name;
    vector<double> marks;
    public:
        StudentInfo(){
            name = "";    
        }

        StudentInfo(string name, vector<double> marks){
            if(marks.size() > 10){
                throw MarksCollectionTooBig();
            }
            if(name.length() < 5){
                throw StudentNameTooSmall();
            }
            vector<double>::iterator it;
            for(it = marks.begin(); it != marks.end(); it++){
                if(*it > 6 || *it < 2){
                    throw MarksCollectionOutOfRange();
                }
            }
            this->name = name;
            this->marks = marks;   
        }

        string getName(){
            return name;
        }

        vector<double> getMarks(){
            return marks;
        }

        void addMark(double new_mark){
            if(marks.size() == 10){
                throw MarksCollectionFull();
            }
            if(new_mark > 6 || new_mark < 2){
                throw MarksCollectionOutOfRange();
            }
            marks.push_back(new_mark);
        }

        double getAverage(){
            return accumulate(marks.begin(), marks.end(), 0.0) / marks.size();
        }

        string toString(){
            ostringstream out;
            out << "<" << name << ">:";
            vector<double>::iterator it;
            for(it = marks.begin(); it != marks.end(); it++){
                out << " <" << *it << ">";
            }
            out << " [<" << getAverage() << ">]";
            return out.str();
        }

        void removeMarkAt(int index){
            if(marks.size() < index){
                throw SizeTooBig();
            }
            marks.erase(marks.begin() + index);
        }

        void replaceMarkAt(int index, double new_mark){
            if(marks.size() < index){
                throw SizeTooBig();
            }
            if(new_mark > 6 || new_mark < 2){
                throw MarksCollectionOutOfRange();
            }
            marks[index] = new_mark;
        }
};

int main(){
    string name = "Ivan Dimitrov";
    vector<double> marks;
    marks.push_back(2.444444);
    marks.push_back(5.444444);
    marks.push_back(4.444444);
    marks.push_back(5.444444);
    StudentInfo info = StudentInfo(name, marks);
    cout << "Student name: " << info.getName() << endl;
    info.removeMarkAt(3);
    info.replaceMarkAt(2, 6);
    cout << "Average grade: " << info.getAverage() << endl;
    cout << info.toString() << endl;
    return 0;
}
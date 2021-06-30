#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    // string data = "3.14 2ke";
    // istringstream in(data);
    // double pi;
    // in >> pi;
    // if(in.good()){
    //     cout << "Everything's OK" << endl;
    //     cout << "pi: " << pi << endl;
    // } else {
    //     cout << "Something went wrong" << endl;
    // }

    // int number;
    // in >> number;

    // if(in.good()){
    //     cout << "Everything's OK" << endl;
    //     cout << "number: " << number << endl;
    // } else {
    //     cout << "Something went wrong" << endl;
    // }

    // in.clear();

    // string end = "not set";
    // in >> end;

    // if(in){
    //     cout << "Everything's OK" << endl;
    //     cout << "End: " << end << endl;
    // } else{
    //     cout << "Stream is not OK" << endl;
    // }

    // if(in.eof()){
    //     cout << "Reached the end" << endl;
    // }

    // ostringstream out;

    // out << "test" << " " << "123" << "\n";

    // string data = out.str();
    // cout << "data: " << data << endl;

    ofstream out;
    out.open("./text.txt");

    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    out << name;
    out << "\n";

    int age;
    cout << "Enter your age: ";
    cin >> age;

    out << age;
    out.close();

    ifstream in;
    in.open("./text.txt");
    
    string iName;
    getline(in, iName);
    cout << iName << endl;

    int iAge;
    in >> iAge;
    cout << iAge << endl;
    return 0;
}
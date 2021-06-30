#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Contestant{
    string name;
    double speed;
    double distance;
    public:

        Contestant(){}

        Contestant(string name, double speed){
            this->name = name;
            this->speed = speed;
            this->distance = 0;
        }

        string getName(){
            return name;
        }

        double getSpeed(){
            return speed;
        }

        double getDistance(){
            return distance;
        }

        double calcDistance(int iterations_count){
            distance = speed * iterations_count;
            return distance;
        }
};

bool compareContestants(Contestant contestant1, Contestant contestant2){
    return contestant1.getDistance() > contestant2.getDistance();
}

class Race{
    vector<Contestant> contestants;
    public:
        Race(){}

        Race(vector<Contestant> contestants){
            this->contestants = contestants;
        }

        vector<Contestant> getContestants(){
            return contestants;
        }

        void addContestant(Contestant new_contestant){
            contestants.push_back(new_contestant);
        }

        void resetContestants(){
            for(int i=0;i<contestants.size();i++){
                contestants[i].calcDistance(0);
            }
        }

        void simulateRace(int iterations_count){
            resetContestants();
            for(int i=0; i<contestants.size();i++){
                contestants[i].calcDistance(iterations_count);
            }

            sort(contestants.begin(), contestants.end(), compareContestants);

        }

        string toString(){
            ostringstream out;
            for(int i=0;i<contestants.size();i++){
                out << contestants[i].getName() << ": ";
                out << contestants[i].getDistance() << "(";
                out << contestants[i].getSpeed() << ")\n";
            }
            
            return out.str();
        }
};

int main(){

    return 0;
}
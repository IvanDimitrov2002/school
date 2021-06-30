#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Contestant{
    string name;
    double speed;
    double distance = 0;
    public:
        Contestant(){
            name = "";
            speed = 0;
        }

        Contestant(string name, double speed){
            this->name = name;
            this->speed = speed;
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
            return distance = speed * iterations_count;
        }

};

bool compareContestants(Contestant contestant1, Contestant contestant2){
    return contestant1.getDistance() > contestant2.getDistance();
}

class Race{
    vector<Contestant> contestants;
    public:
        Race(){
            contestants.clear();
        }

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

        void simulateRace(int iteration_count){
            resetContestants();
            cout << getContestantsStanding();
            for(int i=0;i<contestants.size();i++){
                contestants[i].calcDistance(iteration_count);
                cout << getContestantsStanding();
            }

            sort(contestants.begin(), contestants.end(), compareContestants);
            cout << getContestantsStanding();
        }

        string getContestantsStanding(){
            ostringstream out;
            for(int i=0;i<contestants.size();i++){
                out << "<" << contestants[i].getName() << ">:" << " <" << contestants[i].getDistance() << "(<" << contestants[i].getSpeed() << ">)" << endl;     
            }
            return out.str();
        }

};

int main(){
    vector<Contestant> contestants;
    Contestant c1 = Contestant("Ivan", 3);
    Contestant c2 = Contestant("Kaloyan", 4);
    contestants.push_back(c1);
    contestants.push_back(c2);
    Race race = Race(contestants);
    race.simulateRace(4);
    return 0;
}
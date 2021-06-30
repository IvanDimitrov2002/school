#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal{
    public:
        const string name;
        short age;   
        Animal(short age, const string name) : age(age), name(name){};
};

class Cat : public Animal{
   public:   
        Cat(short age, const string name) : Animal(age, name){}

};

class Dog : public Animal{
    public:
        Dog(short age, const string name) : Animal(age, name){}

};

class Shelter{
    Shelter(){}
    public:
        static vector<Dog> dogs;
        static vector<Cat> cats;

        static void addAnimal(string kind, string name, short age){
            if(kind == "cat"){
                cats.push_back(Cat(age, name));
            } else {
                dogs.push_back(Dog(age, name));
            }
        }

        static Animal findAnimal(string kind, string name, short age){
            if(kind == "cat"){
                for(int i=0;i<cats.size();i++){
                    if(name == cats[i].name && age == cats[i].age){
                        Cat& cat = cats[i];
                        return cat;
                    }
                }
            }
            for(int i=0;i<dogs.size();i++){
                if(name == dogs[i].name && age == dogs[i].age){
                    Dog& dog = dogs[i];
                    return dog;
                }
            }
        }
};

vector<Dog> Shelter::dogs;
vector<Cat> Shelter::cats;

int main(){
    Shelter::addAnimal("cat", "Zlati", 13);
    cout << Shelter::cats[0].age << endl;
    cout << Shelter::findAnimal("cat", "Zlati", 13).age << endl;
    return 0;
}
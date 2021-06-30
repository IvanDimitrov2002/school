#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class ModelsCollectionTooSmall : exception{};
class ModelsCollectionEmptyName : exception{};
class ModelsCollectionDuplicate : exception{};
class ManufacturerNameTooSmall : exception{};
class SizeTooBig : exception{};

class CarCatalogue{
    string manufacturer;
    vector<string> models;
    public:
        CarCatalogue(){
            this->manufacturer = "";
        }

        CarCatalogue(string manufacturer, vector<string> models){
            if(models.size() < 5){
                throw ModelsCollectionTooSmall();
            }
            if(manufacturer.length() < 5){
                throw ManufacturerNameTooSmall();
            }
            vector<string> duplicates;
            vector<string>::iterator it;
            for(it = models.begin(); it != models.end(); it++){
                if(*it == "" || *it == " "){
                    throw ModelsCollectionEmptyName();
                }
                if(find(duplicates.begin(), duplicates.end(), *it) != duplicates.end()) {
                    throw ModelsCollectionDuplicate();
                }
                duplicates.push_back(*it);
            }
            this->manufacturer = manufacturer;
            this->models = models;
        }

        string getBrand(){
            return manufacturer;
        }

        vector<string> getModels(){
            return models;
        }

        void addModel(string model_name){
            if(model_name == "" || model_name == " "){
                throw ModelsCollectionEmptyName();
            }
            if(find(models.begin(), models.end(), model_name) != models.end()) {
                throw ModelsCollectionDuplicate();
            }
            models.push_back(model_name);
        }

        int hasModel(string model_name){
            if(count(models.begin(), models.end(), model_name)) {
                return 1;
            }
            return 0; 
        }
        
        string toString(){
            ostringstream out;
            out << "<" << manufacturer << ">:\n";
            vector<string>::iterator it;
            for(it = models.begin(); it != models.end(); it++){
                out << "  <" << *it << ">\n";
            }
            return out.str();
        }

        void removeModelAt(int index){
            if(models.size() < index){
                throw SizeTooBig();
            }
            models.erase(models.begin() + index);
        }

        void replaceModelAt(int index, string model_name){
            if(models.size() < index){
                throw SizeTooBig();
            }
            if(model_name == "" || model_name == " "){
                throw ModelsCollectionEmptyName();
            }
            if(find(models.begin(), models.end(), model_name) != models.end()) {
                throw ModelsCollectionDuplicate();
            }
            models[index] = model_name;
        }
};

int main(){
    vector<string> models;
    models.push_back("A");
    models.push_back("B");
    models.push_back("C");
    models.push_back("D");
    models.push_back("E");
    models.push_back("G");
    CarCatalogue catalogue = CarCatalogue("CarMaker", models);
    cout << catalogue.hasModel("F") << endl;
    catalogue.addModel("F");
    cout << catalogue.hasModel("F") << endl;
    cout << catalogue.toString();
    catalogue.removeModelAt(1);
    cout << catalogue.toString();
    catalogue.replaceModelAt(1, "T");
    cout << catalogue.toString();
    return 0;
}
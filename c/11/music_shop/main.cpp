#include "shop.h"

int main(){
    std::vector<AcousticGuitar> acousticGuitars;
    std::vector<ElectricGuitar> electricGuitars;
    AcousticGuitar ag1 = AcousticGuitar(1234, 2.5, "Koceto", 12, 5, 10, 14.6);
    AcousticGuitar ag2 = AcousticGuitar(1555, 55.5, "Koceto", 23, 77, 12, 450.6);
    acousticGuitars.push_back(ag1);
    acousticGuitars.push_back(ag2);
    ElectricGuitar eg1 = ElectricGuitar(4321, 69, "rado", 12, 4, 350, 50, 30);
    ElectricGuitar eg2 = ElectricGuitar(43, 690, "rado", 144, 45, 150, 25, 26);
    electricGuitars.push_back(eg1);
    electricGuitars.push_back(eg2);
    Shop shop = Shop(acousticGuitars, electricGuitars);
    std::vector<Guitar> twelveStrings = shop.get_all_twelve_strings();
    for(int i = 0; i < twelveStrings.size(); i++){
        std::cout << "Id: " << twelveStrings[i].id << std::endl;
    }
    return 0;
}
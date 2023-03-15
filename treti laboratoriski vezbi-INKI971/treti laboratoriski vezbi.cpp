#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    enum BrojDen {ponedelnik, vtornik, sreda, cetvtrok, petok, celosen};
    BrojDen brden;
    
    cout << "Vnesete den od nedelata (0-ponedelnik, 1-vtornik, 2-sreda, 3-cetvrtok, 4-petok, 5-celosen): ";
    int izbor;
    cin >> izbor;
    
    if (izbor < ponedelnik || izbor > celosen) {
        cout << "Izbraniot den ne e validen.\n";
        return 0;
    }
    
    brden = static_cast<BrojDen>(izbor);
    
    switch (brden) {
        case ponedelnik:
            cout << "Raspored za ponedelnik.\n";
            break;
        case vtornik:
            cout << "Raspored za vtornik.\n";
            break;
        case sreda:
            cout << "Raspored za sreda.\n";
            break;
        case cetvtrok:
            cout << "Raspored za cetvrtok.\n";
            break;
        case petok:
            cout << "Raspored za petok.\n";
            break;
        case celosen:
            cout << "Raspored za celosen period.\n";
            break;
    }
    
    return 0;
}

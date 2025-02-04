#include <iostream>

#include "CoordinateSystem.h"
#include "Vec3.h"

using namespace std;

int main() {
    CoordinateSystem cs = CoordinateSystem(Vec3(-3, 5, -1), 0, 72, 0);

    double x, y, z;
    while (true) {
        cout << "Entrez les coordonnees du vecteur dans le repere objet (x y z) : ";
        cin >> x >> y >> z;

        bool validInput = !cin.fail();

        if (!validInput) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Coordonnees invalide, veuillez reessayer" << endl;
        } else { break; }
    }

    cs.getUniversalPosition(Vec3(x, y, z)).print();

    return 0;
}
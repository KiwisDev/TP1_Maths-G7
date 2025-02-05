#include <iostream>

#include "CoordinateSystem.h"
#include "Vec3.h"

using namespace std;

int main() {
    double ogX, ogY, ogZ;
    while (true) {
        cout << "Entrez les coordonnees d origine du repere objet (x y z) : ";
        cin >> ogX >> ogY >> ogZ;

        bool validInput = !cin.fail();

        if (!validInput) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Coordonnees invalide, veuillez reessayer" << endl;
        } else { cout << endl; break; }
    }

    double rotX, rotY, rotZ;
    while (true) {
        cout << "Entrez les rotations en degre du repere objet (x y z) : ";
        cin >> rotX >> rotY >> rotZ;

        bool validInput = !cin.fail();

        if (!validInput) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Coordonnees invalide, veuillez reessayer" << endl;
        } else { cout << endl; break; }
    }

    CoordinateSystem cs = CoordinateSystem(Vec3(ogX, ogY, ogZ), rotX, rotY, rotZ);
    if (!cs.isLinearlyIndependent()) {
        cout << "Le system de coordonnee est invalide";
        return -1;
    }

    double vecX, vecY, vecZ;
    while (true) {
        cout << "Entrez les coordonnees du point dans le repere objet (x y z) : ";
        cin >> vecX >> vecY >> vecZ;

        bool validInput = !cin.fail();

        if (!validInput) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Coordonnees invalide, veuillez reessayer" << endl;
        } else { cout << endl; break; }
    }

    cout << "Position du point dans le repere universel : ";
    cs.getUniversalPosition(Vec3(vecX, vecY, vecZ)).print();

    return 0;
}
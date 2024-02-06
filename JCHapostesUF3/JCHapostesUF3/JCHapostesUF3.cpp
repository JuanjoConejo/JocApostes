#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funció per generar el llançament de dos daus i retornar la suma.
int rollDice() {
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

// Funció per gestionar el resultat de la jugada basat en l'aposta i la suma dels daus.
void gestionarResultat(int& diners, int aposta, int sumaDaus) {
    if (sumaDaus == aposta) {
        diners += 10 * aposta;
        cout << "Has guanyat " << 10 * aposta << " Euros!" << endl;
    }
    else if (abs(sumaDaus - aposta) <= 2) {
        diners += 2 * aposta;
        cout << "Has guanyat " << 2 * aposta << " Euros!" << endl;
    }
    else {
        diners -= aposta;
        cout << "Has perdut " << aposta << " Euros." << endl;
    }
}

// Funció per jugar una ronda del joc.
void jugarRonda(int& diners) {
    cout << "Diners disponibles: " << diners << " Euros" << endl;
    cout << "Escull una opcio" << endl;
    cout << "1. Fer una aposta" << endl;
    cout << "2. Sortir" << endl;

    int opcio;
    cin >> opcio;

    int sumaDaus = 0;

    switch (opcio) {
    case 1: {
        cout << "Introdueix la quantitat de diners a apostar: ";
        int aposta;
        cin >> aposta;

        if (aposta > diners) {
            cout << "No tens prou diners disponibles." << endl;
            break;
        }

        sumaDaus = rollDice();
        cout << "Has tret un " << sumaDaus << " en els daus." << endl;
        gestionarResultat(diners, aposta, sumaDaus);
        break;
    }
    case 2:
        cout << "Gracies per jugar!" << endl;
        exit(0);
    default:
        cout << "Opcio invalida. Torna-ho a provar." << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Convertir time_t a unsigned int

    int diners = 100;

    while (diners > 0) {
        jugarRonda(diners);
        cout << endl;
    }

    cout << "T'has quedat sense diners! Fi del joc." << endl;

    return 0;
}
#include <iostream>
#include <iomanip>  // define diferentes manipuladores
using namespace std;

int main(void) {
    cout << setfill('.') << endl;  // manipulador de relleno.
                                  // el carácter de relleno será el punto.
    cout << "Listado de calificaciones:" << endl;

    cout << "Pepe Garcia" << setw(24) << "5.5" << endl;
    cout << "Andrea Torres" << setw(19) << "6" << endl;
    cout << "Jose Perez" << setw(20) << "7" << endl;
    cout << "Landa Efren" << setw(19) << "7.5" << endl;
    cout << "Jose Ore" << setw(22) << "6" << endl;
    cout << "Yasin Añamuro" << setw(21) << "2.5" << endl;

    cout << setfill(' ') << endl;  // se restablece el carácter de relleno
    system("pause");
    return 0;
}
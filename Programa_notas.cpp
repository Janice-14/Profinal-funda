


#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
using namespace std;


// Estructura para guardar datos del alumno, almacena tipos de datos similares, diferentes o una combinación de ambos
struct Alumno {
    string nombre;
    string apellido1;
    string apellido2;
    int cedula;
    int ciclo;
    float notas[5];
    float promedio;
};

// Funcion para calcular el promedio de 5 notas
float calcularPromedio(const float notas[], int cantidad) {
    float suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma += notas[i];
    }
    return suma / cantidad;
}

int main() {
    int cantidad;
    cout << "¿Cuantos alumnos desea evaluar?: ";
    cin >> cantidad;
    cin.ignore(); // Para usar getline sin errores

    vector<Alumno> alumnos;

    for (int i = 0; i < cantidad; i++) {
        Alumno a;
        cout << "\n--- Alumno #" << (i + 1) << " ---" << endl;

        cout << "Nombre: ";
        getline(cin, a.nombre);

        cout << "Primer apellido: ";
        getline(cin, a.apellido1);

        cout << "Segundo apellido: ";
        getline(cin, a.apellido2);

        cout << "Cedula: ";
        cin >> a.cedula;

        cout << "Ciclo que cursa: ";
        cin >> a.ciclo;

        for (int j = 0; j < 5; j++) {
            cout << "Ingrese nota #" << (j + 1) << ": ";
            cin >> a.notas[j];
        }

        a.promedio = calcularPromedio(a.notas, 5);
        cin.ignore(); // Limpiar buffer para el siguiente getline
        alumnos.push_back(a);
    }

    // Mostrar los resultados
    cout << "\n======= LISTA DE ALUMNOS CON PROMEDIO =======\n";
    cout << left << setw(30) << "Nombre completo"
         << setw(12) << "Cedula"
         << setw(8)  << "Ciclo"
         << "Promedio" << endl;

    cout << "-------------------------------------------------------------\n";

    for (const Alumno& a : alumnos) {
        string nombreCompleto = a.nombre + " " + a.apellido1 + " " + a.apellido2;
        cout << left << setw(30) << nombreCompleto
             << setw(12) << a.cedula
             << setw(8)  << a.ciclo
             << fixed << setprecision(2) << a.promedio << endl;
    }

    return 0;
}

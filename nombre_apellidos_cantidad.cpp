#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// Estructura para guardar datos del alumno
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

// Función para validar texto (nombre/apellidos)
bool validarTexto(const string& texto) {
    if (texto.empty()) return false;
    for (char c : texto) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

//  Función para leer enteros positivos (como cantidad, cédula, ciclo)
bool leerEnteroPositivo(int &valor) {
    cin >> valor;
    if (cin.fail() || valor <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int main() {
    int cantidad;

    cout << "¿Cuántos alumnos desea evaluar?: ";
    while (!leerEnteroPositivo(cantidad)) {
        cout << "⚠️  Error: Ingrese un número entero positivo: ";
    }

    // Limpiar el salto de línea pendiente
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<Alumno> alumnos;

    for (int i = 0; i < cantidad; i++) {
        Alumno a;
        cout << "\n--- Alumno #" << (i + 1) << " ---" << endl;

        // Nombre
        do {
            cout << "Nombre: ";
            getline(cin, a.nombre);
            if (!validarTexto(a.nombre)) {
                cout << "Error: El nombre solo debe contener letras. Intente de nuevo.\n";
            }
        } while (!validarTexto(a.nombre));

        // Primer apellido
        do {
            cout << "Primer apellido: ";
            getline(cin, a.apellido1);
            if (!validarTexto(a.apellido1)) {
                cout << "Error: El apellido solo debe contener letras. Intente de nuevo.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (!validarTexto(a.apellido1));

        // Segundo apellido
        do {
            cout << "Segundo apellido: ";
            getline(cin, a.apellido2);
            if (!validarTexto(a.apellido2)) {
                cout << "Error: El apellido solo debe contener letras. Intente de nuevo.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (!validarTexto(a.apellido2));

        // Cedula
        cout << "Cédula: ";
        while (!leerEnteroPositivo(a.cedula)) {
            cout << "Error: Ingrese una cédula válida (> 0): ";
        }

        // Ciclo
        cout << "Ciclo que cursa: ";
        while (!leerEnteroPositivo(a.ciclo)) {
            cout << "Error: Ingrese un ciclo válido (> 0): ";
        }

        // Notas
        for (int j = 0; j < 5; j++) {
            cout << "Ingrese nota #" << (j + 1) << ": ";
            while (!(cin >> a.notas[j]) || a.notas[j] < 0 || a.notas[j] > 100) {
                cout << "Error: La nota debe estar entre 0 y 100. Intente de nuevo: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        a.promedio = calcularPromedio(a.notas, 5);
        cin.ignore(); // limpiar el buffer antes de siguiente getline
        alumnos.push_back(a);
    }

    // Mostrar resultados
    cout << "\n======= LISTA DE ALUMNOS CON PROMEDIO =======\n";
    cout << left << setw(30) << "Nombre completo"
         << setw(12) << "Cédula"
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
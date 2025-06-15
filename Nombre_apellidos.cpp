#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
using namespace std;1


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
//Función para validar texto, esto permite que los nombres y apellidos no estén vacíos y no tengan números ni caracteres especiales
bool validarTexto(const string& texto) {
    if (texto.empty()) return false;
    for (char c : texto) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;


    bool leerEnteroPositivo(int &valor) {
    cin >> valor;
    if (cin.fail() || valor <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}
    
}
int main() {
    int cantidad;

cout << "¿Cuántos alumnos desea evaluar?: ";
while (!leerEnteroPositivo(cantidad)) {
    cout << "Error: Ingrese un número entero positivo: ";
}

// Se limpia el salto de línea sobrante SOLO UNA VEZ,← importante para getline más adelante
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
        cout << "⚠️  Error: El nombre solo debe contener letras. Intente de nuevo.\n";
    }

} while (!validarTexto(a.nombre));


/string entrada;

// Nombre
do {
    cout << "Nombre: ";
    getline(cin, entrada);

    if (!validarTexto(entrada)) {
        cout << "⚠️  Error: El nombre solo debe contener letras. Intente de nuevo.\n";
    }

} while (!validarTexto(entrada));
a.nombre = entrada;

// Primer apellido
do {
    cout << "Primer apellido: ";
    getline(cin, entrada);

    if (!validarTexto(entrada)) {
        cout << "⚠️  Error: El apellido solo debe contener letras. Intente de nuevo.\n";
    }

} while (!validarTexto(entrada));
a.apellido1 = entrada;

// Segundo apellido
do {
    cout << "Segundo apellido: ";
    getline(cin, entrada);

    if (!validarTexto(entrada)) {
        cout << "⚠️  Error: El apellido solo debe contener letras. Intente de nuevo.\n";
    }

} while (!validarTexto(entrada));
a.apellido2 = entrada;
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
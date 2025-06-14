#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
// Finalizamos libreriassss

#ifdef _WIN32
#include <windows.h>  // Para colores en Windows
#endif

using namespace std;

struct Alumno {
    string nombre;
    string apellido1;
    string apellido2;
    int cedula;
    int ciclo;
    float notas[5];
    float promedio;
};

float calcularPromedio(const float notas[], int cantidadNotas) {
    float sumaNotas = 0;
    for (int indiceNota = 0; indiceNota < cantidadNotas; indiceNota++) {
        sumaNotas += notas[indiceNota];
    }
    return sumaNotas / cantidadNotas;
}

// Funciones para establecer colores en consola
void establecerColorVerde() {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
#else
    cout << "\033[32m";
#endif
}

void establecerColorRojo() {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
#else
    cout << "\033[31m";
#endif
}

void resetearColor() {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
#else
    cout << "\033[0m";
#endif
}

int main() {
#ifdef _WIN32
    // Configurar consola para colores ANSI (Windows 10+)
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD modoConsola = 0;
        GetConsoleMode(hOut, &modoConsola);
        modoConsola |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, modoConsola);
    }
#endif

    char respuestaUsuario = 'S';
    while (respuestaUsuario == 'S' || respuestaUsuario == 's') {
        int cantidadAlumnos;
        cout << "¿Cuántos alumnos desea evaluar?: ";
        while (!(cin >> cantidadAlumnos) || cantidadAlumnos <= 0) {
            cout << "Por favor ingrese un número entero positivo válido: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(); // Limpiar buffer

        vector<Alumno> listaAlumnos;

        for (int indiceAlumno = 0; indiceAlumno < cantidadAlumnos; indiceAlumno++) {
            Alumno alumnoActual;
            cout << "\n--- Alumno #" << (indiceAlumno + 1) << " ---" << endl;

            cout << "Nombre: ";
            getline(cin, alumnoActual.nombre);

            cout << "Primer apellido: ";
            getline(cin, alumnoActual.apellido1);

            cout << "Segundo apellido: ";
            getline(cin, alumnoActual.apellido2);

            cout << "Cédula: ";
            while (!(cin >> alumnoActual.cedula) || alumnoActual.cedula <= 0) {
                cout << "Ingrese una cédula válida (número entero positivo): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Ciclo que cursa: ";
            while (!(cin >> alumnoActual.ciclo) || alumnoActual.ciclo <= 0) {
                cout << "Ingrese un ciclo válido (número entero positivo): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            for (int indiceNota = 0; indiceNota < 5; indiceNota++) {
                cout << "Ingrese nota #" << (indiceNota + 1) << " (0-100): ";
                while (!(cin >> alumnoActual.notas[indiceNota]) || alumnoActual.notas[indiceNota] < 0 || alumnoActual.notas[indiceNota] > 100) {
                    cout << "Nota inválida. Ingrese nota #" << (indiceNota + 1) << " entre 0 y 100: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            alumnoActual.promedio = calcularPromedio(alumnoActual.notas, 5);
            cin.ignore(); // Limpiar buffer
            listaAlumnos.push_back(alumnoActual);
        }

        // Imprimir encabezados alineados
        cout << "\n======= LISTA DE ALUMNOS CON PROMEDIO Y NOTAS =======\n";
        cout << left
             << setw(30) << "Nombre completo"
             << setw(12) << "Cédula"
             << setw(8)  << "Ciclo"
             << setw(10) << "Promedio"
             << "Notas (5)\n";

        cout << "---------------------------------------------------------------------------------\n";

        // Imprimir cada alumno con colores según aprobado o no
        for (const Alumno& alumnoActual : listaAlumnos) {
            string nombreCompleto = alumnoActual.nombre + " " + alumnoActual.apellido1 + " " + alumnoActual.apellido2;
            cout << left
                 << setw(30) << nombreCompleto
                 << setw(12) << alumnoActual.cedula
                 << setw(8)  << alumnoActual.ciclo;

            // Color según aprobado o reprobado
            if (alumnoActual.promedio >= 70) {
                establecerColorVerde();
            } else {
                establecerColorRojo();
            }

            cout << fixed << setprecision(2) << setw(10) << alumnoActual.promedio;

            // Mostrar notas en mismo color
            for (int indiceNota = 0; indiceNota < 5; indiceNota++) {
                cout << fixed << setprecision(2) << alumnoActual.notas[indiceNota] << " ";
            }
            cout << endl;

            resetearColor();
        }

        cout << "\n¿Desea evaluar otra lista de alumnos? (S/N): ";
        cin >> respuestaUsuario;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer para siguiente ciclo
        cout << "\n";
    }

    cout << "Programa finalizado. ¡Gracias!\n";
    return 0;
}
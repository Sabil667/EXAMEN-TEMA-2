#include <iostream>

struct Estudiante {
    std::string nombre;
    int edad;
    double promedio;
};

// Función para mostrar todos los campos del estudiante
void mostrarEstudiante(const Estudiante& estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << std::endl;
    std::cout << "Edad: " << estudiante.edad << std::endl;
    std::cout << "Promedio: " << estudiante.promedio << std::endl;
}

int main() {
    Estudiante estudiante;

    // Solicitar al usuario que ingrese los detalles del estudiante
    std::cout << "Ingrese el nombre del estudiante: ";
    std::getline(std::cin, estudiante.nombre);

    std::cout << "Ingrese la edad del estudiante: ";
    std::cin >> estudiante.edad;

    std::cout << "Ingrese el promedio del estudiante: ";
    std::cin >> estudiante.promedio;


    // Mostrar los detalles del estudiante
    mostrarEstudiante(estudiante);

    return 0;
}

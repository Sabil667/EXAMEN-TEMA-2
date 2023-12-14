#include <cstdio>
// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[100];
    int edad;
    float promedio;
};

// Función para mostrar todos los campos del estudiante
void mostrarEstudiante(const struct Estudiante* estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d \n", estudiante->edad);
    printf("Promedio: %.2f\n", estudiante->promedio);
}

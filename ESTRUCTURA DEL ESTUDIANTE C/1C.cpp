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

int main() {
    // Crear un estudiante de ejemplo
    struct Estudiante estudiante;

    // Solicitar al usuario que ingrese los detalles del estudiante
    printf("Ingrese el nombre del estudiante: ");
    fgets(estudiante.nombre, sizeof(estudiante.nombre), stdin);

        printf("Ingrese la edad del estudiante: ");
        scanf("%d", &estudiante.edad);

        printf("Ingrese el promedio del estudiante: ");
        scanf("%f", &estudiante.promedio);

        // Mostrar los detalles del estudiante
        mostrarEstudiante(&estudiante);

        return 0;
    }

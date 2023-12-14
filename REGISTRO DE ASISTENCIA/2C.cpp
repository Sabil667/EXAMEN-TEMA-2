#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[100];
    int edad;
    float promedio;
    char materias[10][50];  // Lista de materias, con un límite de 10 materias y 50 caracteres cada una
    int numMaterias;
};

// Función para mostrar los detalles de un estudiante
void mostrarEstudiante(const struct Estudiante* estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d\n", estudiante->edad);
    printf("Promedio: %.2f\n", estudiante->promedio);

    // Mostrar materias
    printf("Materias:");
    for (int i = 0; i < estudiante->numMaterias; ++i) {
        printf(" %s", estudiante->materias[i]);
    }
    printf("\n");
}

// Función para agregar una materia al estudiante
void agregarMateria(struct Estudiante* estudiante, const char* materia) {
    if (estudiante->numMaterias < 10) {
        strcpy(estudiante->materias[estudiante->numMaterias], materia);
        estudiante->numMaterias++;
    } else {
        printf("No se pueden agregar más materias.\n");
    }
}

// Función para eliminar una materia del estudiante
void eliminarMateria(struct Estudiante* estudiante, const char* materia) {
    for (int i = 0; i < estudiante->numMaterias; ++i) {
        if (strcmp(estudiante->materias[i], materia) == 0) {
            // Mover las materias restantes hacia adelante para llenar el espacio eliminado
            for (int j = i; j < estudiante->numMaterias - 1; ++j) {
                strcpy(estudiante->materias[j], estudiante->materias[j + 1]);
            }
            estudiante->numMaterias--;
            printf("Materia eliminada con exito.\n");
            return;
        }
    }
    printf("La materia no existe.\n");
}

int main() {
    struct Estudiante estudiante1;

    // Solicitar al usuario que ingrese los detalles del estudiante
    printf("Ingrese el nombre del estudiante: ");
    fgets(estudiante1.nombre, sizeof(estudiante1.nombre), stdin);
    estudiante1.nombre[strcspn(estudiante1.nombre, "\n")] = '\0'; // Eliminar el salto de línea

    printf("Ingrese la edad del estudiante: ");
    scanf("%d", &estudiante1.edad);

    printf("Ingrese el promedio del estudiante: ");
    scanf("%f", &estudiante1.promedio);

    estudiante1.numMaterias = 0;  // Inicializar el número de materias

    int opcion;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Mostrar detalles del estudiante\n");
        printf("2. Agregar materia\n");
        printf("3. Eliminar materia\n");
        printf("0. Salir\n");

        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarEstudiante(&estudiante1);
                break;
            case 2:
            {
                char nuevaMateria[50];
                printf("Ingrese el nombre de la nueva materia: ");
                scanf("%s", nuevaMateria);
                agregarMateria(&estudiante1, nuevaMateria);
                printf("Materia agregada con exito.\n");
            }
                break;
            case 3:
            {
                char materiaAEliminar[50];
                printf("Ingrese el nombre de la materia a eliminar: ");
                scanf("%s", materiaAEliminar);
                eliminarMateria(&estudiante1, materiaAEliminar);
            }
                break;
            case 0:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no valida. Intentalo de nuevo.\n");
        }

    } while (opcion != 0);

    return 0;
}

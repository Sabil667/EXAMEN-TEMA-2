#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Asistencia
struct Asistencia {
    char fecha[20];
    char materia[50];
    char estado[20];
};

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[50];
    struct Asistencia *asistencias;
    int numAsistencias;
};

// Función para registrar la asistencia
void registrarAsistencia(struct Estudiante *estudiante, const char *fecha, const char *materia, const char *estado) {
    estudiante->asistencias = realloc(estudiante->asistencias, (estudiante->numAsistencias + 1)  sizeof(struct Asistencia));
    if (estudiante->asistencias == NULL) {
        fprintf(stderr, "Error de asignación de memoria\n");
        exit(EXIT_FAILURE);
    }

    struct Asistencia *nuevaAsistencia = &(estudiante->asistencias[estudiante->numAsistencias]);
    snprintf(nuevaAsistencia->fecha, sizeof(nuevaAsistencia->fecha), "%s", fecha);
    snprintf(nuevaAsistencia->materia, sizeof(nuevaAsistencia->materia), "%s", materia);
    snprintf(nuevaAsistencia->estado, sizeof(nuevaAsistencia->estado), "%s", estado);

    estudiante->numAsistencias++;
}

// Función para mostrar la asistencia
void mostrarAsistencia(const struct Estudiante *estudiante) {
    printf("Asistencia de %s:\n", estudiante->nombre);
    printf("%-15s%-15s%-15s\n", "Fecha", "Materia", "Estado");
    printf("------------------------------------------\n");

    for (int i = 0; i < estudiante->numAsistencias; i++) {
        printf("%-15s%-15s%-15s\n",
               estudiante->asistencias[i].fecha,
               estudiante->asistencias[i].materia,
               estudiante->asistencias[i].estado);
    }
}

int main() {
    // Ejemplo de uso
    struct Estudiante estudiante1;
    snprintf(estudiante1.nombre, sizeof(estudiante1.nombre), "Juan Perez");
    estudiante1.asistencias = NULL;
    estudiante1.numAsistencias = 0;

    registrarAsistencia(&estudiante1, "2023-01-01", "Matemáticas", "Asistió");
    registrarAsistencia(&estudiante1, "2023-01-02", "Física", "Falta");
    registrarAsistencia(&estudiante1, "2023-01-03", "Química", "Tardanza");

    mostrarAsistencia(&estudiante1);

    // Liberar memoria
    free(estudiante1.asistencias);

    return 0;
}

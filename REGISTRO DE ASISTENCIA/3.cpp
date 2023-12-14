#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Definición de la estructura Asistencia
struct Asistencia {
    std::string fecha;
    std::string materia;
    std::string estado;
};

// Definición de la clase Estudiante
class Estudiante {
private:
    std::string nombre;
    std::vector<Asistencia> asistencias;

public:
    // Constructor
    Estudiante(const std::string& nombre) : nombre(nombre) {}

    // Función para registrar la asistencia
    void registrarAsistencia(const std::string& fecha, const std::string& materia, const std::string& estado) {
        Asistencia nuevaAsistencia = {fecha, materia, estado};
        asistencias.push_back(nuevaAsistencia);
    }

    // Función para mostrar la asistencia
    void mostrarAsistencia() const {
        std::cout << "Asistencia de " << nombre << ":\n";
        std::cout << std::setw(15) << "Fecha" << std::setw(15) << "Materia" << std::setw(15) << "Estado" << "\n";
        std::cout << "------------------------------------------\n";

        for (const Asistencia& asistencia : asistencias) {
            std::cout << std::setw(15) << asistencia.fecha
                      << std::setw(15) << asistencia.materia
                      << std::setw(15) << asistencia.estado << "\n";
        }
    }
};

int main() {
    // Ejemplo de uso
    Estudiante estudiante1("Juan Perez");

    estudiante1.registrarAsistencia("2023-01-01", "Matemáticas", "Asistió");
    estudiante1.registrarAsistencia("2023-01-02", "Física", "Falta");
    estudiante1.registrarAsistencia("2023-01-03", "Química", "Tardanza");

    estudiante1.mostrarAsistencia();

    return 0;
}

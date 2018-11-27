#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {
    int personas, preguntas, limiteInferior, limiteSuperior, genero, edad, joven, viejo;
    ofstream txt("Resultados.txt");
    ofstream csv("Resultados.csv");

    std::cout << "Programa para la realización de encuestas automáticamente. Solo hace falta introducir el número de personas, preguntas, y los límites (inferior y superior) de las posibles respuestas a las preguntas.\n<----------------------------------------------------------------->" << std::endl;
    std::cout << "Introduce el número de personas: ";
    std::cin >> personas;
    std::cout << "Introduce el número de preguntas: ";
    std::cin >> preguntas;
    std::cout << "\nIntroduce el rango de edades:\nIntroduce la edad de la persona más joven: ";
    std::cin >> joven;
    std::cout << "Introduce la edad de la persona más longeva: ";
    std::cin >> viejo;
    std::cout << "\nIntroduce el rango de la encuesta:\nLímite inferior: ";
    std::cin >> limiteInferior;
    std::cout << "Límtie superior: ";
    std::cin >> limiteSuperior;

    csv << "\"Personas\",\"Edad\",\"Género\",";

    for (size_t i = 0; i < preguntas; ++i) {
        csv << "\"Pregunta " << i+1;
        if (i != preguntas-1) {
            csv << "\",";
        }else{
            csv << "\"";
        }
    }
    csv << "\n";

    int respuesta;

    //std::cout << "Estos son los resultados:" << std::endl;

    srand(time(NULL));
    for (size_t i = 0; i < personas; ++i) {
        //std::cout << "Persona " << i+1 << ":" << std::endl;
        edad = joven + (rand() % ((viejo+1)-joven));
        genero = 1 + (rand() % 2);
        txt << "Persona " << i+1 << ":\tEdad: " << edad << "\tGénero: " << genero << "\n";
        csv << "\"Persona " << i+1 <<"\",\"" << edad << "\",\"" << genero << "\",";
        for (size_t j = 0; j < preguntas; ++j) {
            respuesta = limiteInferior + (rand() % limiteSuperior);
            //std::cout << "\tPregunta " << j+1 << ":" << respuesta << std::endl;
            txt << "\tPregunta " << j+1 << ":" << respuesta << "\n";
            csv << "\"" << respuesta;
            if (j != preguntas-1) {
                csv << "\",";
            }else{
                csv << "\"";
            }
        }
        csv << "\n";
    }
    std::cout << "Archivos rellenados correctamente" << std::endl;
    txt.close();
    csv.close();

    return 0;
}

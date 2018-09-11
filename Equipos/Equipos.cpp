#include <iostream>
#include <string.h>
#include <vector>
#include <random>

using namespace std;

int main()
{
    //Declaracion de variables necesarias...
    int numerojugadores, numeroaleatorio;
    vector<string> equipoblanco, equiponegro, nombresjugadores;
    string nombre;

    //Declaracion de semilla para generar numero aleatorio para rellenar los equipos
    random_device semilla;
    mt19937 rng(semilla());
    uniform_int_distribution<int> gen(1, 2);

    do {
        cout << "Ingrese el número de jugadores: ";
        cin >> numerojugadores;
        if(numerojugadores < 0){
            cout << "No se puede jugar con un número negativo de jugadores."<<endl;
        }else {
            if (numerojugadores == 0) {
                cout <<"No se puede jugar sin jugadores."<<endl;
            }else {
                if (numerojugadores == 1) {
                    cout <<"Con un solo jugador no se pueden hacer dos equipos."<<endl;
                }
            }
        }
    } while(numerojugadores < 2);


    for(int i=0; i < numerojugadores; i++){
        cout << i+1 << ". ";
        cin >> nombre;
        nombresjugadores.push_back(nombre);
        numeroaleatorio = gen(rng);
        //Si el numero generado es 1...
        if(numeroaleatorio == 1){
            //Se comprueba que no se ha alcanzado el tamaño maximo del equipo
            //Si lo ha hecho se rellena el otro equipo...
            if(equipoblanco.size() < numerojugadores/2){
                equipoblanco.push_back(nombresjugadores[i]);
            }
            else{
                equiponegro.push_back(nombresjugadores[i]);
            }

        }
        else{
            //Se comprueba que no se ha alcanzado el tamaño maximo del equipo
            //Si lo ha hecho se rellena el otro equipo...
            if(equiponegro.size() < numerojugadores/2){
                equiponegro.push_back(nombresjugadores[i]);
            }
            else{
                equipoblanco.push_back(nombresjugadores[i]);
            }
        }
    }

    cout << "Equipo blanco: ";
    for(auto it = equipoblanco.begin(); it != equipoblanco.end(); it++){
        cout << *it << " ";
    }
    cout << endl <<"Equipo negro: ";
    for(auto it = equiponegro.begin(); it != equiponegro.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

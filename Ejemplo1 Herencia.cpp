// Ejemplo1 Herencia.cpp : Juego de Piedra, Papel o Tijera
#include <iostream>
#include "PlayerPc.h"
#include <ctime>     // para time()
#include <string>
using namespace std;

int main()
{
    // Inicializa para los números aleatorios
    srand(static_cast<unsigned int>(time(0)));

    cout << "==== JUEGO DE PIEDRA, PAPEL O TIJERA ====" << endl;
    cout << "1: Piedra, 2: Papel, 3: Tijera" << endl << endl;

    // Crear jugadores
    Player jugadorHumano;   // Jugador humano (usa la clase base)
    PlayerPc jugadorPC;     // PC (usa la clase derivada)

    int puntajeHumano = 0;
    int puntajePC = 0;
    int rondas = 0;

    cout << "Ingrese el numero de rondas a jugar: ";
    cin >> rondas;

    for (int i = 0; i < rondas; i++) {
        cout << "\n----- Ronda " << (i + 1) << " -----" << endl;

        // Turno del jugador humano
        cout << "\nTu turno!" << endl;
        jugadorHumano.seleccionar();

        // Turno de la computadora
        cout << "\nTurno de la computadora..." << endl;
        jugadorPC.seleccionar();

        // Mostrar jugadas
        cout << "\nTu jugada: ";
        jugadorHumano.imprimir();
        cout << "Computadora: ";
        jugadorPC.imprimir();

        // Determinar ganador
        int resultado = Player::determinarGanador(jugadorHumano, jugadorPC);

        // Mostrar resultado
        switch (resultado) {
        case 0:
            cout << "Resultado: Empate!" << endl;
            break;
        case 1:
            cout << "Resultado: Ganaste esta ronda!" << endl;
            puntajeHumano++;
            break;
        case 2:
            cout << "Resultado: La computadora gana esta ronda." << endl;
            puntajePC++;
            break;
        }

        cout << "Puntuacion actual - Tu: " << puntajeHumano << " | PC: " << puntajePC << endl;
    }

    // Mostrar resultado final
    cout << "\n==== RESULTADO FINAL ====" << endl;
    cout << "Tu puntuacion: " << puntajeHumano << endl;
    cout << "Puntuacion PC: " << puntajePC << endl;

    if (puntajeHumano > puntajePC) {
        cout << "Felicidades! Has ganado el juego!" << endl;
    }
    else if (puntajePC > puntajeHumano) {
        cout << "La computadora ha ganado el juego." << endl;
    }
    else {
        cout << "El juego ha terminado en empate!" << endl;
    }

    return 0;
}
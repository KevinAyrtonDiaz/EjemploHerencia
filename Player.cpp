#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
	jugada = -1;
}

Player::Player(int opcion)
{
	jugada = opcion;
}

void Player::seleccionar() // Corregido a seleccionar
{
	int opcion;
	cout << "Introduzca opcion (1: Piedra, 2: Papel, 3: Tijera): " << endl;
	cin >> opcion;
	setJugada(opcion); // Corregido el nombre
}

short Player::getJugada()
{
	return jugada;
}

void Player::setJugada(short x) // Corregido el nombre
{
	if (x >= 1 && x <= 3) // Corregido a <= 3 en lugar de < 4
	{
		jugada = x;
	}
	else
	{
		cout << "Opcion no valida" << endl;
	}
}

void Player::imprimir()
{
	string opcion;
	switch (jugada)
	{
	case 1:
		opcion = "Piedra";
		break;
	case 2:
		opcion = "Papel";
		break;
	case 3:
		opcion = "Tijera";
		break;
	default:
		opcion = "No seleccionada";
		break;
	}

	cout << "Jugada: " << opcion << endl;
}

// Método para determinar el ganador
int Player::determinarGanador(Player& p1, Player& p2)
{
	// Retorna 0 para empate, 1 si gana p1, 2 si gana p2
	if (p1.jugada == p2.jugada)
		return 0; // Empate

	if ((p1.jugada == 1 && p2.jugada == 3) || // Piedra vence a Tijera
		(p1.jugada == 2 && p2.jugada == 1) || // Papel vence a Piedra
		(p1.jugada == 3 && p2.jugada == 2))   // Tijera vence a Papel
		return 1; // Gana p1

	return 2; // Gana p2
}
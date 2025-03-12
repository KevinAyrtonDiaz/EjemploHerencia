#pragma once
class Player
{
protected: // Cambiado a protected para que las clases derivadas puedan acceder
	short jugada;
public:
	// Constructores
	Player();
	Player(int opcion);
	// Métodos
	virtual void seleccionar(); // Método virtual para permitir sobreescritura
	short getJugada();
	void setJugada(short x); // Corregido el nombre
	void imprimir();
	// Método para determinar el ganador
	static int determinarGanador(Player& p1, Player& p2);
};
#pragma once
#include "Player.h"

class PlayerPc : public Player
{
public:
    void seleccionar() override; // Sobreescribe el método de la clase base
};
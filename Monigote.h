#pragma once
#include "Base.h"
#include <iostream>
using namespace std;
class Monigote :
    public Base
{
private:
	
	bool ganador;
public:
	Monigote();
	Monigote(int px, int py);
	~Monigote();
	void Mover(Graphics^ g);
	bool retornar_ganador();
	void cambiar_vidas(int nuevo);
	int retornar_vidas();
};


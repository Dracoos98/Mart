#pragma once
#include "Base.h"
#include "Monigote.h"
#include "Meteoritos.h"
#include <vector>
#include <time.h>
using namespace std;
class Controladora :
    public Base
{
private:
    Monigote* objM;
    time_t Inicio;
    time_t Juego;
    vector<Base*>meteoros;
    int  meteoritos_s;
    int S;
    int T;
public:
    Controladora();
    ~Controladora();
    void Dibujar_Monigote(Graphics^ g, Bitmap^ bmp);
    void Desplazar_Monigote(direccion nuevo);
    void Insertar_Meteoritos();
    void Dibujar_Meteoritos(Graphics^ g, Bitmap^ bmp);
    bool Colision();
    bool Gano();
    bool Perdio();
    int retornar_meteoritos_s();
    int retornar_vidas();
    
    int retornar_tiempo();
    
};


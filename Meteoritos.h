#pragma once
#include "Base.h"
class Meteoritos :
    public Base
{
public:
    Meteoritos();
    ~Meteoritos();
    Meteoritos(int px, int py, int pw, int ph);
    void Mover(Graphics^ g);
    void Dibujar_desImagen(Graphics^ g, Bitmap^ bmp);
};


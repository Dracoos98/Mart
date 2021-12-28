#include "Meteoritos.h"

Meteoritos::Meteoritos()
{
}

Meteoritos::~Meteoritos()
{
}

Meteoritos::Meteoritos(int px, int py, int pw, int ph) :Base(px, py, pw, ph, 8, 8, 0, 0)
{
	
	System::Random^ r = gcnew System::Random();
	dy = (r->Next(4, 10));
	col = r->Next(0, 8);
	delete r;
}

void Meteoritos::Mover(Graphics^ g)
{
	if (dy + h + y > g->VisibleClipBounds.Height)
	{
		dy = 0;
		
	}
	y += dy;
}
void Meteoritos::Dibujar_desImagen(Graphics^ g, Bitmap^ bmp)
{
	w = bmp->Width / max_col;
	h = bmp->Height / max_fil;
	Rectangle porcion = Rectangle(col * w, fil * h, w, h);
	g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);
	if (col == max_col)

		col = 0;
	fil++;
	if (fil = max_fil)
		fil = 0;
}
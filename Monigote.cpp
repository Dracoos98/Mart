#include "Monigote.h"
Monigote::Monigote() {

}
Monigote::Monigote(int px, int py)  {
	vector<string>parametros = LeerArchivo();
	System::String^ auxlifes1 = gcnew System::String(parametros.at(0).c_str());
	System::String^ auxlifes2 = gcnew System::String(parametros.at(1).c_str());
	vidas = System::Convert::ToInt32(auxlifes1)+rand()%(System::Convert::ToInt32(auxlifes2)+1- System::Convert::ToInt32(auxlifes1));
	dx = 4;
	dy = 4;
	Desplazamiento(direccion::derecha);
	max_col = 4;
	max_fil = 4;
	col = 0;
	fil = 0;
	x = px;
	y = py;
	ganador = false;
	
}
Monigote::~Monigote() {
	
}
void Monigote::Mover(Graphics^ g) {
	if (x + dx < 1 || x + dx + w>g->VisibleClipBounds.Width) dx = 0;
	if (y + dy < 1 || y + dy + h>g->VisibleClipBounds.Height) dy = 0;
	if (y + dy < 30) ganador = true;
	x += dx;
	y += dy;
}


bool Monigote::retornar_ganador()
{
	return ganador;
}

void Monigote::cambiar_vidas(int nuevo)
{
	vidas = nuevo;
}

int Monigote::retornar_vidas()
{
	return vidas;
}


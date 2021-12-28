#include "Controladora.h"

Controladora::Controladora()
{
	objM = new Monigote(200, 500);
	Inicio = time(0);
	Juego = time(0);
	meteoritos_s = meteoros.size();
	
	vector<string>parametros = LeerArchivo();
	System::String^ tiempo = gcnew System::String(parametros.at(3).c_str());
	T = System::Convert::ToInt32(tiempo);
}

Controladora::~Controladora()
{
	delete objM;
	for (int i = 0; i < meteoros.size(); i++)
	{
		delete meteoros.at(i);
	}
}

void Controladora::Dibujar_Monigote(Graphics^ g, Bitmap^ bmp)
{
	objM->Dibujar_desImagen(g, bmp);
	objM->Mover(g);
}

void Controladora::Desplazar_Monigote(direccion nuevo)
{
	objM->Desplazamiento(nuevo);
}

void Controladora::Insertar_Meteoritos()
{
	System::Random^ r = gcnew System::Random();
	vector<string>parametros = LeerArchivo();
	System::String^ auxS = gcnew System::String(parametros.at(2).c_str());
	S = System::Convert::ToInt32(auxS);
	int b, c, e, f;
	int a = 1 + rand() % (3 + 1 - 1);
	e = 50 + rand() % (600 + 1 - 50);
	f = 50 + rand() % (600 + 1 - 50);
	if (a == 1)
	{
		if (difftime(time(0), Inicio) > S)
		{
			meteoros.push_back(new Meteoritos(e, 0, 1, 1));
			Inicio = time(0);
		}
	}
	if (a == 2)
	{
		if (difftime(time(0), Inicio) > S)
		{
			meteoros.push_back(new Meteoritos(f, 0, 1, 1));
			Inicio = time(0);
		}
	}
	

}

void Controladora::Dibujar_Meteoritos(Graphics^ g, Bitmap^ bmp)
{
	for (int i = 0; i < meteoros.size(); i++)
	{
		meteoros.at(i)->Dibujar_desImagen(g, bmp);
		meteoros.at(i)->Mover(g);
	}
	for (int i = 0; i < meteoros.size(); i++)
	{
		if (meteoros.at(i)->retornar_dy() == 0)
		{
			meteoros.erase(meteoros.begin() + i);
			
			meteoritos_s++;
		}
	}
}

bool Controladora::Colision()
{
	bool resultado_colision = false;
	Rectangle rmonigote = objM->retonar_rectangle();
	for (int j = 0; !resultado_colision && j < meteoros.size(); j++)
	{
		Rectangle rmeteoros = meteoros.at(j)->retonar_rectangle();
		if (rmonigote.IntersectsWith(rmeteoros))
		{
			
			meteoros.erase(meteoros.begin() + j);
			objM->cambiar_vidas(objM->retornar_vidas()-1);
			
			
		}
	}
	return resultado_colision;
}

bool Controladora::Gano()
{
	bool ganojuego = false;
	if (difftime(time(0), Juego) >= T)
	{
		ganojuego = true;
	}
	return ganojuego;
}

bool Controladora::Perdio()
{
	return objM->retornar_vidas()<=0;
}

int Controladora::retornar_meteoritos_s()
{
	return meteoritos_s;
}

int Controladora::retornar_vidas()
{
	return objM->retornar_vidas();
}



int Controladora::retornar_tiempo()
{
	return T - difftime(time(0), Juego);
}

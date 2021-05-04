#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


using namespace std;
const int maxcola = 5;
class Pacman
{
private:
	int primero, ultimo;
	string info[maxcola];
public:
	//void iniciar();
	int getprimero() { return primero; };
	int getultimo() { return ultimo; };
	void setprimero(int _primero) { primero = _primero; };
	void setultimo(int _ultimo) { ultimo = _ultimo; };
	int vacia();
	int llena();
	void insertar(string x);
	void eliminar();

		void mostrar();
};
/*void TQueue::iniciar()
{
ultimo=-1;
primero=1;
}*/
int Pacman::vacia()
{
	if (ultimo < primero)
		return 1;
	else
		return 0;
}
int Pacman::llena()
{
	if (ultimo == maxcola)
		return 1;
	else
		return 0;
}
void Pacman::insertar(string x)
{
	if (llena() == 1)
		cout << "La cola esta llena";

	else
	{
		ultimo++;
		info[ultimo] = x;
	}
}
void Pacman::eliminar()
{
	int i;
	if (vacia() == 1)
		cout << "La cola esta vacia";
	else
	{
		for (i = 0; i < ultimo + 1; i++)
			info[i] = info[i + 1];
		ultimo--;
	}
}
void Pacman::mostrar()
{
	cout << "\n";
	for (int i = 0; i < ultimo + 1; i++)
		cout << (info[i] + "\n");
	getchar();
}

int main()
{
	Pacman Pacman;
	int opc; string dato;
	char out;
	int top;
	Pacman.setprimero(0);
	Pacman.setultimo(-1);
	//queue.iniciar();

	
	return 0;
}

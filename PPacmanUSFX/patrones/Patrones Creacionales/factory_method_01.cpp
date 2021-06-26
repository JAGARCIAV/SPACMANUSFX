/**
 * Examlple of `factory method' design pattern
 * Copyright (C) 2011 Radek Pazdera
 * This program is free software: you can rojoistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <string>

using namespace std;

class Copa{
public:
	//Copa() : color("") {}

	Copa() {
		color = "";
	}

	string color;
	virtual void Mostrar() {};
	//virtual void Colorear() {};

	/* This is the factory method. */
	static Copa* getCopa(string color);
};

Copa* Copa::getCopa(std::string color)
{
	if (color == "rojo")
		return new CopaRoja();
	else if (color == "azul")
		return new CopaAzul();
	else
		return nullptr;
}




class CopaRoja : public Copa
{
public:
	CopaRoja()
	{
		color = "rojo";
	}
	void Mostrar() { std::cout << "MOSTRAR COPA ROJA" << std::endl; }
};

class CopaAzul : public Copa
{
public:
	CopaAzul()
	{
		color = "azul";
	}
	void Mostrar() { std::cout << "MOSTRAR COPA AZUL" << std::endl; }
	void Colorear() { std::cout << "COLOREANDO AZUL " << std::endl; }
};


/* A little testing */
int main()
{
	/* Now we decide the type of the Copa at
	 * runtime by the factory method argument */
	Copa* cR = Copa::getCopa("rojo");
	Copa* cA = Copa::getCopa("azul");

	std::cout << cR->color << std::endl;
	
	cR->Mostrar();

	std::cout << cA->color << std::endl;
	((CopaAzul*)cA)->Colorear();
	cA->Mostrar();
	
	system("pause");

}



//
//
//// A design without factory pattern
//#include <iostream> 
//using namespace std;
//
//// Library classes 
//class Vehicle {
//public:
//	virtual void printVehicle() = 0;
//};
//class TwoWheeler : public Vehicle {
//public:
//	void printVehicle() {
//		cout << "I am two wheeler" << endl;
//	}
//};
//class FourWheeler : public Vehicle {
//public:
//	void printVehicle() {
//		cout << "I am four wheeler" << endl;
//	}
//};
//
//// Client (or user) class 
//class Client {
//public:
//	Client(int type) {
//
//		// Client explicitly creates classes according to type 
//		if (type == 1)
//			pVehicle = new TwoWheeler();
//		else if (type == 2)
//			pVehicle = new FourWheeler();
//		else
//			pVehicle = nullptr;
//	}
//
//	~Client() {
//		if (pVehicle)
//		{
//			delete[] pVehicle;
//			pVehicle = nullptr;
//		}
//	}
//
//	Vehicle* getVehicle() {
//		return pVehicle;
//	}
//private:
//	Vehicle *pVehicle;
//};
//
////// Driver program 
////int main() {
////	Client *pClient = new Client(1);
////	Vehicle * pVehicle = pClient->getVehicle();
////	pVehicle->printVehicle();
////	return 0;
////}
//
//
//// C++ program to demonstrate factory method design pattern 
//#include <iostream> 
//using namespace std;
//
//enum VehicleType {
//	VT_TwoWheeler, VT_ThreeWheeler, VT_FourWheeler
//};
//
//// Library classes 
//class Vehicle {
//public:
//	virtual void printVehicle() = 0;
//	static Vehicle* Create(VehicleType type);
//};
//class TwoWheeler : public Vehicle {
//public:
//	void printVehicle() {
//		cout << "I am two wheeler" << endl;
//	}
//};
//class ThreeWheeler : public Vehicle {
//public:
//	void printVehicle() {
//		cout << "I am three wheeler" << endl;
//	}
//};
//class FourWheeler : public Vehicle {
//public:
//	void printVehicle() {
//		cout << "I am four wheeler" << endl;
//	}
//};
//
//// Factory method to create objects of different types. 
//// Change is requirojo only in this function to create a new object type 
//Vehicle* Vehicle::Create(VehicleType type) {
//	if (type == VT_TwoWheeler)
//		return new TwoWheeler();
//	else if (type == VT_ThreeWheeler)
//		return new ThreeWheeler();
//	else if (type == VT_FourWheeler)
//		return new FourWheeler();
//	else return nullptr;
//}
//
//// Client class 
//class Client {
//public:
//
//	// Client doesn't explicitly create objects 
//	// but passes type to factory method "Create()" 
//	Client()
//	{
//		VehicleType type = VT_ThreeWheeler;
//		pVehicle = Vehicle::Create(type);
//	}
//	~Client() {
//		if (pVehicle) {
//			delete[] pVehicle;
//			pVehicle = nullptr;
//		}
//	}
//	Vehicle* getVehicle() {
//		return pVehicle;
//	}
//
//private:
//	Vehicle *pVehicle;
//};
//
////// Driver program 
////int main() {
////	Client *pClient = new Client();
////	Vehicle * pVehicle = pClient->getVehicle();
////	pVehicle->printVehicle();
////	return 0;
//}
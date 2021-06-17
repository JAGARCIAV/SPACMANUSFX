/*
 * Example of `prototype' design pattern.
 * Copyright (C) 2011 Radek Pazdera
 * This program is free software: you can redistribute it and/or modify
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

 /* Prototype base class. */
class GamePanelPT
{
protected:
	string type;
	string value;

public:
	virtual GamePanelPT* clone() = 0;

 	string getType(){ return type; }
	string getValue(){	return value;}
};

class ConcretePrototype1 : public GamePanelPT
{
public:
	ConcretePrototype1(string number)
	{
		type = "Type1";
		value = number;
	}

	GamePanelPT* clone()
	{
		return new ConcretePrototype1(*this);
	}
};







/* Factory that manages prorotype instances and produces their clones. */
class ObjectFactory
{
	static GamePanelPT* type1value1;
	static GamePanelPT* type1value2;


public:
	static void  initialize()
	{
		type1value1 = new ConcretePrototype1("SCORE ROJO");
		type1value2 = new ConcretePrototype1("SCORE VERDE");

	}


	
	static GamePanelPT* getType1Value1(){return type1value1->clone();}
	static GamePanelPT* getType1Value2(){return type1value2->clone();}


};

GamePanelPT* ObjectFactory::type1value1 = 0;
GamePanelPT* ObjectFactory::type1value2 = 0;


int main()
{
	ObjectFactory::initialize();
	GamePanelPT* object;

	/* All the object were created by cloning the prototypes. */
	object = ObjectFactory::getType1Value1();
	std::cout << object->getType() << ": " << object->getValue() << std::endl;

	object = ObjectFactory::getType1Value2();
	std::cout << object->getType() << ": " << object->getValue() << std::endl;



	return 0;
}

#include "Animal.h"

Animal::Animal(string name, AnimalType type)
{
	_name = name;
	_type = type;
}

Animal::~Animal()
{
}

void Animal::SetOrder(int order)
{
	_order = order;
}

int Animal::GetOrder()
{
	return _order;
}

string Animal::GetName()
{
	return _name;
}

AnimalType Animal::GetType()
{
	return _type;
}

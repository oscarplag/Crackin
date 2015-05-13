#pragma once
#include "Animal.h"
#include<list>
#include<typeinfo>

class AnimalQueue
{
	private:
		list<Animal> catList;
		list<Animal> dogList;
		int order;
	public:
		AnimalQueue();
		~AnimalQueue();
		void EnQueue(Animal an);
		Animal DeQueue();
		Animal DeQueueDog();
		Animal DeQueueCat();

};

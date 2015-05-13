#include "AnimalQueue.h"

AnimalQueue::AnimalQueue()
{
	order = 0;
	catList = list<Animal>();
	dogList = list<Animal>();
}

AnimalQueue::~AnimalQueue()
{
}

void AnimalQueue::EnQueue(Animal an)
{
	order++;
	an.SetOrder(order);
	if(an.GetType() == CAT)
	{
		catList.push_back(an);
	}
	else if(an.GetType() == DOG)
	{
		dogList.push_back(an);
	}
}

Animal AnimalQueue::DeQueue()
{
	if(catList.empty() && dogList.empty())
	{
		throw -1;
	}
	else if(catList.empty())
	{
		Animal a = dogList.front();
		dogList.pop_front();
		return a;
	}
	else if(dogList.empty())
	{
		Animal a = catList.front();
		catList.pop_front();
		return a;
	}
	else
	{
		Animal cat = catList.front();
		Animal dog = dogList.front();
		if(cat.GetOrder()<dog.GetOrder())
		{
			catList.pop_front();
			return cat;
		}
		else
		{
			dogList.pop_front();
			return dog;
		}
	}
}

Animal AnimalQueue::DeQueueCat()
{
	if(catList.empty())
		throw -1;
	Animal cat = catList.front();
	catList.pop_front();
	return cat;
}
Animal AnimalQueue::DeQueueDog()
{
	if(dogList.empty())
		throw -1;
	Animal dog = dogList.front();
	dogList.pop_front();
	return dog;
}

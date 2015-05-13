#pragma once
#include<string>


using namespace std;

enum AnimalType
{
	CAT,
	DOG
};

class Animal
{
	private: 
		int _order;
		string _name;
		AnimalType _type;	
	public:
		Animal(string name, AnimalType type);
		void SetOrder(int order);
		int GetOrder();
		~Animal();
		AnimalType GetType();
		string GetName();
};


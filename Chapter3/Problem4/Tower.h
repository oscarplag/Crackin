#include<stack>

using namespace std;

class Tower
{
	private:
		stack<int> mystack;
		void moveTop(Tower* destination);
		void moveDisks(int numDisks, Tower* destination, Tower* buffer);
		int _index;

	public:
		Tower(int index);
		~Tower();
		void add(int d);
		void moveDisks(int numDisks, Tower& destination, Tower& buffer);
};

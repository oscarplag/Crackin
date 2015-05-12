#include<stack>

using namespace std;

class MyQueue 
{
	private:
		stack<int> stackOldest;
		stack<int> stackNewest;
		void shiftStacks();
	public:
		MyQueue();
		~MyQueue();
		void EnQueue(int val);
		int DeQueue();
		int Peek();
		int size();
		bool empty();
};

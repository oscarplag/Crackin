#include<stack>
#include<vector>

using namespace std;

class MyStack
{
	private:
		int _stackSize;
		int _stackIndex;
		vector<stack<int>* > _stack;

	public:
		MyStack(int stackSize);
		~MyStack();

		int Pop(int stackNum);
		int Peek(int stackNum);
		int Pop();
		int Peek();
		void Push(int val);
		bool IsEmpty(int stackNum);
};

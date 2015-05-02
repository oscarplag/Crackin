
class MyStack
{
	private:
		int* _indecies;
		int _stackSize;
		int _totalSize;
		int _numStacks;
		int GetTopIndex(int stack);
		int* _stack;

	public:
		MyStack(int numStacks, int totalSize);
		~MyStack();

		int Pop(int stackNum);
		int Peek(int stackNum);
		void Push(int val, int stackNum);
		bool IsEmpty(int stackNum);
};

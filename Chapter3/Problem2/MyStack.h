struct stackVal
{
	public:
		int val;
		int min;
};


class MyStack
{
	private:
		int _index;
		int _stackSize;
		stackVal* _stack;
		int _curMin;

	public:
		MyStack(int totalSize);
		~MyStack();

		int Pop();
		int Peek();
		void Push(int val);
		bool IsEmpty();
		int GetMin();
};

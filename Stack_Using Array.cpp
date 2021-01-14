#include<iostream>
using namespace std;

template<class ItemType>
class Stack{
	private:
		int top;
		int maxStack;
		ItemType* items;
	public:
		Stack();
		Stack(int max);
		~Stack();
		int IsEmpty() const;
		int IsFull() const;
		void Push(ItemType newItem);
		void Pop(ItemType& item);
		void Top(ItemType &TopItem);
};

template<class ItemType>
Stack<ItemType>::Stack(){
	maxStack = 500;
	top = -1;
	items = new ItemType[500];
}

template<class ItemType>
Stack<ItemType>::Stack(int max){
	maxStack = max;
	top = -1;
	items = new ItemType[max];
}

template<class ItemType>
Stack<ItemType>::~Stack(){
	delete[] items;
}

template<class ItemType>
int Stack<ItemType>::IsEmpty() const{
	return (top==-1);
}

template<class ItemType>
int Stack<ItemType>::IsFull() const{
	return (top==maxStack-1);
}

template<class ItemType>
void Stack<ItemType>::Push(ItemType newItem){
	if(IsFull())
	{   cout<<"Stack Overflow\n";
		exit(1); }
	top++;
	items[top] = newItem;
}

template<class ItemType>
void Stack<ItemType>::Pop(ItemType &item){
	if(IsEmpty()){
		cout<<"Stack Underflow\n";
		exit(1);
	} 
	item = items[top];
	top--;
}

template<class ItemType>
void Stack<ItemType>::Top(ItemType &TopItem){
	TopItem = items[top];
}


int main(){
	//=========== Create a stack of size 10 ===========
	Stack<int> Stack(10);
	int data;
	//=========== (a) Push the elements 6, 9, 12, 7, 10, 25 to the stack ===========
	Stack.Push(6); Stack.Push(9); Stack.Push(12); 
	Stack.Push(7); Stack.Push(10); Stack.Push(25);
	
	//=========== (b) Display the top element ===========
	Stack.Top(data); cout<<"Top Item: "<<data<<endl;
	
	//=========== (c) Call Pop and display the popped item ===========
	Stack.Pop(data); cout<<"Pop Item: "<<data<<endl;
	
	//=========== (d) Push 2 ===========
	Stack.Push(2); 
	
	//=========== (e) While the stack has elements, Call Pop and display the popped item ===========
	cout<<"\n====================================================================\n";
	cout<<"While stack has elements, calling pop and displaying the popped item\n\n";
	while(!Stack.IsEmpty()){ Stack.Pop(data);
							 cout<<"Pop Item: "<<data<<endl;  } 
	
							 cout<<"\nStack Empty";
	
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

const int sz=100000;

template<class T>
class Stack
{	
	private :
		T *stk;
		int top;
	public :
		Stack(){
			stk=new T[sz+1];
			top=-1;
		}
		void push(T val);
		void pop();
		bool isEmpty();
		T peak();
		~Stack(){
			delete [] stk;
		}
};

template<class T>
bool Stack<T>::isEmpty(){
	if(top==-1){
		return true;
	}
	else{
		return false;
	}
}

template<class T>
void Stack<T>::push(T val){
	try{
		if(top==sz){
			throw "Stack overflow";
		}
		else{
			top++;
			stk[top]=val;
		}
	}
	catch(const char *msg){
		cout<<msg<<"\n";
	}
		
}

template<class T>
void Stack<T>::pop(){
	try{
		if(isEmpty()){
			throw "Stack underflow";
		}
		else{
			top--;
		}	
	}
	catch(const char* msg){
		cout<<msg<<"\n";
	}
}


template<class T>
T Stack<T>::peak(){
	try{
		if(!isEmpty()){
			return stk[top];
		}
		else{
			throw "Stack is empty";
		}
	}
	catch(const char* msg){
		cout<<msg<<"\n";
	}
}
int main(){
	Stack <int>s ;
	// int as data type
	cout<<s.peak()<<"\n";
	s.pop();
	cout<<s.isEmpty()<<"\n";
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout<<s.peak()<<"\n";
	s.pop();
	cout<<s.peak()<<"\n";
	cout<<s.isEmpty()<<"\n";
	// char as data type;
	Stack <char> s1;
	s1.peak();
	s1.pop();
	s1.push('m');
	s1.push('a');
	s1.push('h');
	s1.push('i');
	cout<<s1.peak()<<"\n";
	s1.pop();
	cout<<s1.peak()<<"\n";
	s1.pop();
	cout<<s1.peak()<<"\n";
	s1.pop();
	cout<<s1.peak()<<"\n";
	s1.pop();
	return 0;
}
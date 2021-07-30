#include<bits/stdc++.h>

using namespace std;

template<class T>
class StackNode
{
	public:
		T val;
		StackNode<T> *next;
		StackNode<T> *prev;
};

template<class T>
class Stack{
	private : 
		StackNode<T> *root,*curr;
	public:
		Stack(){
			root=new StackNode<T>();
			root->next=NULL;
			root->prev=NULL;
			curr=root;
		}
		void push(int val);
		void pop();
		T peak();
		bool isEmpty();
		~Stack(){
			delete root;
		}
};

template<class T>
bool Stack<T>::isEmpty(){
	if(root==curr){
		return true;
	}
	else{
		return false;
	}
}

template<class T>
void Stack<T>::push(int val){
	StackNode<T> *temp=new StackNode<T>();
	temp->val=val;
	temp->prev=curr;
	curr->next=temp;
	curr=curr->next;
}

template<class T>
void Stack<T>::pop(){
	try{
		if(curr==root){
			throw "Stack underflow";
		}
		else{
			StackNode<T> *temp=curr;
			curr=curr->prev;
			curr->next=NULL;
			temp->prev=NULL;
			delete temp;
		}
	}
	catch(const char *msg){
		cout<<msg<<"\n";
	}
		
}

template<class T>
T Stack<T>::peak(){
	try{
		if(curr!=root){
			return curr->val;
		}
		else{
			throw "stack is empty";
		}
	}
	catch(const char* msg){
		cout<<msg<<"\n";
	}
}

int main(){
	Stack<int> s;
	s.peak();
	s.pop();
	cout<<s.isEmpty()<<"\n";
	s.push(1);
	s.push(2);
	s.push(3);
	cout<<s.peak()<<"\n";
	s.pop();
	cout<<s.peak()<<"\n";
	cout<<s.isEmpty()<<"\n";
//---------------------------------------------------------------//
	Stack<char> s1;
	s1.peak();
	s1.pop();
	cout<<s1.isEmpty()<<"\n";
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
	s1.peak();
	s1.pop();
	cout<<s1.isEmpty()<<"\n";
}
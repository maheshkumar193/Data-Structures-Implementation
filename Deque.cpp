#include<bits/stdc++.h>

using namespace std;

template<class T>
class DequeNode{
	public:
		T data;
		DequeNode<T>* prev;
		DequeNode<T>* next;
		DequeNode(){
			prev=NULL;
			next=NULL;
		}
		~DequeNode(){
			
		}
};

template<class T>
class Deque{
	private:
		DequeNode<T> *front,*back;
	public:
		Deque(){
			front=new DequeNode<T>();
			back=new DequeNode<T>();
			front->next=back;
			back->prev=front;
		}
		
		bool isEmpty();
		
		void push_back(T); 
		
		void push_front(T);
		
		void pop_back();
		
		void pop_front();
		
		T Front();
		
		T Back();
		
		~Deque(){
			delete front;
			delete back;
		}
		
};

template<class T>
bool Deque<T>::isEmpty(){
	return front->next==back;
}


template<class T>
void Deque<T>::push_front(T val){
	
	DequeNode<T>* temp=new DequeNode<T>();
	DequeNode<T>* first=front->next;
	temp->data=val;
	front->next=temp;
	temp->next=first;
	temp->prev=front;
	first->prev=temp;

}

template<class T>
void Deque<T>::push_back(T val){
	
	DequeNode<T>* temp=new DequeNode<T>();
	DequeNode<T>* last=back->prev;
	temp->data=val;
	last->next=temp;
	temp->next=back;
	temp->prev=last;
	back->prev=temp;
	
}

template<class T>
void Deque<T>::pop_front(){
	if(isEmpty()){
		cout<<"Deque is empty\n";
	}
	else{
		DequeNode<T>* first,*second;
		first=front->next;
		second=first->next;
		front->next=second;
		second->prev=front;
		first->next=NULL;
		first->prev=NULL;
		delete first;
	}
}

template<class T>
void Deque<T>::pop_back(){
	if(isEmpty()){
		cout<<"Deque is empty\n";
	}
	else{
		DequeNode<T>* last ,*lastButOne;
		last=back->prev;
		lastButOne=last->prev;
		lastButOne->next=back;
		back->prev=lastButOne;
		last->next=NULL;
		last->prev=NULL;
		delete last;
	}
}

template<class T>
T Deque<T>::Front(){
	try{
		if(!isEmpty()){
			return front->next->data;
		}
		else{
			throw "Deque is empty\n";
		}
	}
	catch(const char* msg){
		cout<<msg<<"\n";
	}
}

template<class T>
T Deque<T>:: Back(){
	try{
		if(!isEmpty()){
			return back->prev->data;
		}
		else{
			throw "Deque is empty\n";
		}
	}
	catch(const char* msg){
		cout<<msg<<"\n";
	}
}

int main(){
	Deque<int> dq;
	dq.pop_back();
	dq.pop_front();
	dq.push_back(19);
	dq.push_front(14);
	cout<<dq.Front()<<"\n";
	cout<<dq.Back()<<"\n";
	dq.pop_back();
	dq.pop_front();
	dq.push_back(17);
	cout<<dq.Front()<<"\n";
}


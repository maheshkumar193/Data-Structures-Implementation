#include<bits/stdc++.h>

using namespace std;

const int sz=5;

template<class T>
class Queue{
	private:
		T* q;
		int front,rear;
	public:
		Queue(){
			q=new T[sz];
			front=-1;
			rear=-1;
		}
		
		bool isEmpty();
		
		bool isFull();
		
		void enqueue(const T &val);
		
		void dequeue();
		
		T Front();
		
		~Queue(){
			delete [] q;
		}
};

template<class T>
bool Queue<T>:: isEmpty(){
	if(front==rear && rear==-1){
		return true;
	}
	else{
		return false;
	}
}

template<class T>
bool Queue<T>:: isFull(){
	if(front==(rear+1)%sz){
		return true;
	}
	return false;
}

template<class T>
void Queue<T> :: enqueue(const T &val){
	try{
		if(!isFull()){
			if(isEmpty()){
				rear=0;
				front=0;
			}
			else{
				rear=(rear+1)%sz;
			}
			q[rear]=val;
		}
		else{
			throw "Queue is full";
		}
	}
	catch(const char* msg){
		cout<<msg<<"\n";
	}
}

template<class T>
void Queue<T> :: dequeue(){
	try{
		if(!isEmpty()){
			if(front==rear){
				front=-1;
				rear=-1;
			}
			else{
				front=(front+1)%sz;
			}
		}
		else{
			throw "Queue is empty";
		}
	}
	catch(const char* msg){
		cout<<msg<<"\n";
	}
}

template<class T>
T Queue<T>:: Front(){
	try{
		if(!isEmpty()){
			return q[front];
		}
		else{
			throw "Queue is empty";
		}
	}	
	catch(const char* msg){
		cout<<msg<<"\n";
	}
}

int main(){
	Queue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.dequeue();
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	while(!q.isEmpty()){
		cout<<q.Front()<<"\n";
		q.dequeue();
	}
}
#include<bits/stdc++.h>

using namespace std;

template<class T>
class QueueNode{
	public:
		T val;
		QueueNode<T> *next;
};

template<class T>
class Queue{
	private:
		QueueNode<T> *front,*rear;
	public:
		Queue(){
			front=NULL;
			rear=NULL;
		}
		bool isEmpty();
		void enqueue(const T &val);
		void dequeue();
		T Front();
		~Queue(){
			
		}
};

template<class T>
bool Queue<T>::isEmpty(){
	if(rear==NULL){
		return true;
	}
	return false;
}

template<class T>
void Queue<T>::enqueue(const T &val){
	QueueNode<T> *temp=new QueueNode<T>();
	temp->val=val;
	if(isEmpty()){
		rear=temp;
		front=temp;
	}
	else{
		rear->next=temp;
		rear=rear->next;
	}
}

template<class T>
void Queue<T>::dequeue(){
	try{
		if(!isEmpty()){
			QueueNode<T>* temp=front;
			if(front==rear){
				rear=NULL;
				front=NULL;
			}
			else{
				front=front->next;	
			}
			delete temp;
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
T Queue<T> :: Front(){
	try{
		if(!isEmpty()){
			return front->val;
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
	q.Front();
	q.dequeue();
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	cout<<q.Front()<<"\n";
	q.dequeue();
	cout<<q.Front()<<"\n";
	q.dequeue();
	cout<<q.Front()<<"\n";
	q.dequeue();
	cout<<q.Front()<<"\n";
	q.dequeue();
	q.Front();
	q.dequeue();
//-------------------------------------------//
	Queue<char> q1;
	q1.Front();
	q1.dequeue();
	q1.enqueue('m');
	q1.enqueue('a');
	q1.enqueue('h');
	q1.enqueue('i');
	cout<<q1.Front()<<"\n";
	q1.dequeue();
	cout<<q1.Front()<<"\n";
	q1.dequeue();
	cout<<q1.Front()<<"\n";
	q1.dequeue();
	cout<<q1.Front()<<"\n";
	q1.dequeue();
	q1.Front();
	q1.dequeue();
}
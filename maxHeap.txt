#include <bits/stdc++.h>

using namespace std;

template<class T>
class maxHeap{
	
	private:
		T *data;
		int maxSize;
		int Size;
	public:
		maxHeap(){
			data=NULL;
			Size=0;
			maxSize=0;
		}
		
		bool isEmpty();
		
		void push(const T &val);
		
		void pop();
		
		T top();
		~maxHeap(){
			if(data!=NULL)
				delete [] data;
		}
};

template<class T>
bool maxHeap<T> :: isEmpty(){
	return Size==0?true:false;
}

template<class T>
void maxHeap<T> :: push(const T &val){
	if(Size==maxSize){
		maxSize+=maxSize;
		T* data1=new T[maxSize];
		for(int i=0;i<Size;i++){
			data1[i]=data[i];
		}
		if(data!=NULL){
			delete [] data;
		}
		data=data1;
	}
	data[Size]=val;
	int ind=Size;
	Size++;
	while(ind!=0){
		int ind1=(ind-1)/2;
		if(data[ind1]<data[ind]){
			swap(data[ind],data[ind1]);
			ind=ind1;
		}
		else{
			return;
		}
	}
}
 
template<class T>
T maxHeap<T> :: top(){
	try{
		if(!isEmpty()){
			return data[0];
		}
		else{
			throw "Heap is empty";
		}
	}
	catch(const char *msg){
		cout<<msg<<"\n";
	}
}


template<class T>
void maxHeap<T> :: pop(){
	try{
		if(!isEmpty()){
			data[0]=data[Size-1];
			Size--;
			int ind=0;
			while(ind<Size){
				int maxi=INT_MIN;
				if(2*ind+1<Size){
					maxi=max(maxi,data[2*ind+1]);	
				}
				if(2*ind+2<Size){
					maxi=max(maxi,data[2*ind+2]);
				}
				if(maxi<data[ind]){
					return;
				}
				else if(maxi==data[2*ind+1]){
					swap(data[ind],data[2*ind+1]);
					ind=2*ind+1;
				}
				else{
					swap(data[ind],data[2*ind+2]);
					ind=2*ind+2;
				}
			}
		}
		else{
			throw "Heap is empty";
		}
	}
	catch(const char* msg){
		cout<<msg<<"\n";
	}
}

int main(){ 
	maxHeap<int> mH;
	mH.push(100);
	mH.push(1);
	mH.push(2);
	mH.push(-2);
	mH.push(3);
	mH.push(-3);
	cout<<mH.top()<<"\n";
	mH.pop();
	mH.push(-7);
	mH.push(-10);
	while(!mH.isEmpty()){
		cout<<mH.top()<<" ";
		mH.pop();
	}
	cout<<"\n";
	return 0;
}
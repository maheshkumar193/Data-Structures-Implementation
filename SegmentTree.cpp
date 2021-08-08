#include<bits/stdc++.h>

using namespace std;

template<class T>
class segmentTree{
	
	private:
	
		T *seg_tree;
		
		T defaultValue;
		
		int sz;
		
		T (* combine)(T a,T b);
		
		void buildtree(int ,int ,int ,vector<T>&);
		
		void buildtree(int ,int ,int ,T arr[]);
		
		T queryHepler(int ind,int l,int r,int ql,int qr);
		
		void updateHepler(int ind,int l,int r,int idx,T val);
		
	public:
		segmentTree(vector<T>&data,T val,T(* combine)(T a,T b)){
			
			defaultValue=val;
			
			sz=data.size();
			
			seg_tree = new T[4*sz+5];
			
			this->combine=combine;
			
			buildtree(1,0,sz-1,data);
		}
		
		segmentTree(T arr[],int n,T val,T(* combine)(T a,T b)){
			
			defaultValue=val;
			
			sz=n;
			
			seg_tree = new T[4*sz+5];
			
			this->combine=combine;
			
			buildtree(1,0,sz-1,arr);
			
		}
		
		void update(int idx,T val);
		
		T query(int l,int r);
		
		~segmentTree(){
			delete [] seg_tree;
		}
};

template<class T>
void segmentTree<T>::buildtree(int ind,int l,int r,vector<T>&data){
	
	if(l==r){
		seg_tree[ind]=data[l];
		return;
	}
	int mid=l+(r-l)/2;
	buildtree(2*ind,l,mid,data);
	buildtree(2*ind+1,mid+1,r,data);
	seg_tree[ind]=combine(seg_tree[2*ind],seg_tree[2*ind+1]);

}

template<class T>
void segmentTree<T>::buildtree(int ind,int l,int r,T data[]){
	
	if(l==r){
		seg_tree[ind]=data[l];
		return;
	}
	int mid=l+(r-l)/2;
	buildtree(2*ind,l,mid,data);
	buildtree(2*ind+1,mid+1,r,data);
	seg_tree[ind]=combine(seg_tree[2*ind],seg_tree[2*ind+1]);
	
}

template<class T>
T segmentTree<T>::queryHepler(int ind,int l,int r,int ql,int qr){
	
	if(ql>r || qr<l){
		return defaultValue;
	}
	if(l>=ql && r<=qr){
		return seg_tree[ind];
	}
	int mid=l+(r-l)/2;
	return combine(queryHepler(2*ind,l,mid,ql,qr),queryHepler(2*ind+1,mid+1,r,ql,qr));
}

template<class T>
T segmentTree<T>::query(int l,int r){
	return queryHepler(1,0,sz-1,l,r);
}

template<class T>
void segmentTree<T>::updateHepler(int ind,int l,int r,int idx,T val){
	
	if(l>idx || r<idx){
		return;
	}
	
	if(l==r && l==idx){
		seg_tree[ind]=val;
		return;
	}
	
	int mid = l+(r-l)/2;
	
	updateHepler(2*ind,l,mid,idx,val);
	
	updateHepler(2*ind+1,mid+1,r,idx,val);
	
	seg_tree[ind]=combine(seg_tree[2*ind],seg_tree[2*ind+1]);

}

template<class T>
void segmentTree<T>::update(int idx,T val){
	updateHepler(1,0,sz-1,idx,val);
}

int combine(int a,int b) {   // define your combine method here 
	return a+b;
}

int main(){
	
	int arr[]={3,2,4,5,1,1,5,3};
	
	segmentTree<int> seg(arr,8,0,&combine);
	
	cout<<seg.query(0,3)<<"\n";
	
	cout<<seg.query(4,5)<<"\n";
	
	seg.update(2,1);
	
	cout<<seg.query(0,3)<<"\n";
	
}

#include <bits/stdc++.h>
using namespace std;

template<class T>
class AVLNode{
	public:
		T val;
		AVLNode *left;
		AVLNode *right;
		int h; //height
		AVLNode(){
			left=NULL;
			right=NULL;
			val=0;
			h=0;
		}
		~AVLNode(){
			
		}
};


template<class T>
class AVLTree{
	
	private:
		AVLNode<T>* root;
		
		int height(AVLNode<T>*);
		
		int balanceFactor(AVLNode<T>*);
		
		AVLNode<T>* insertion(AVLNode<T>* , T);
		
		AVLNode<T>* rotateLeftLeft(AVLNode<T>*);
		
		AVLNode<T>* rotateLeftRight(AVLNode<T>*);
		
		AVLNode<T>* rotateRightRight(AVLNode<T>*);
		
		AVLNode<T>* rotateRightLeft(AVLNode<T>*);
		
		AVLNode<T>* deletion(AVLNode<T>* temp , T val);
		
		void traversePreOrder(AVLNode<T>*);
		
		void traverseInOrder(AVLNode<T>*);
		
		void traversePostOrder(AVLNode<T>*);
		
		bool search(AVLNode<T>* root,T val);
		
		T minVal(AVLNode<T>*);
	public:
		
		AVLTree(){
			root=NULL;
		}
		
		void push(T val);
		
		void pop(T val);
		
		bool find(T val);
		
		void preOrder();
		
		void inOrder();
		
		void postOrder();
		
		~AVLTree(){
			
		}
};

template<class T>
T AVLTree<T>::minVal(AVLNode<T>* temp){
	if(temp->left!=NULL){
		return minVal(temp->left);
	}
	return temp->val;
}

template<class T>
bool AVLTree<T>:: search(AVLNode<T>* temp,T val){
	if(temp==NULL){
		return false;
	}
	if(temp->val==val){
		return true;
	}
	else if(temp->val>val){
		return search(temp->left,val);
	}
	else{
		return search(temp->right,val);
	}
}

template<class T>
int AVLTree<T>::height(AVLNode<T>* temp){
	if(temp!=NULL){
		return temp->h;
	}
	return 0;
}
template<class T>
int AVLTree<T>::balanceFactor(AVLNode<T>* temp){
	int left = height(temp->left);
	if(temp->left!=NULL){
		left++;
	}
	int right=height(temp->right);
	if(temp->right!=NULL){
		right++;
	}
	return left - right;
}

template<class T>
void AVLTree<T> :: push(T val){
	root=insertion(root,val);
}

template<class T>
AVLNode<T>* AVLTree<T>::rotateLeftLeft(AVLNode<T>*x){
	AVLNode<T>* y=x->left;
	AVLNode<T>* z=y->left;
	AVLNode<T>* t1=x->right;
	AVLNode<T>* t2=y->right;
	AVLNode<T>* t3=z->left;
	AVLNode<T>* t4=z->right;
	
	y->right=x;
	
	x->left=t2;
	
	x->h = max(height(x->left),height(x->right));
	
	if(x->left!=NULL || x->right!=NULL){
		x->h=x->h + 1;
	}
	
	y->h=max(height(x->left),height(z->right))+1;
	
	return y;
}

template<class T>
AVLNode<T>* AVLTree<T>::rotateLeftRight(AVLNode<T>* x){
	AVLNode<T>* y=x->left;
	AVLNode<T>* z=y->right;
	AVLNode<T>* t1=x->right;
	AVLNode<T>* t2=y->left;
	AVLNode<T>* t3=z->left;
	AVLNode<T>* t4=z->right;
	
	z->right=x;
	
	z->left=y;
	
	y->right=t3;
	
	x->left=t4;
	
	if(x->left!=NULL || x->right!=NULL){
		x->h=x->h + 1;
	}
	
	y->h = max(height(y->left),height(y->right));
	
	if(y->left!=NULL || y->right!=NULL){
		y->h=y->h + 1;
	}
	
	z->h = max(height(z->left),height(z->right));
	
	if(z->h!=0){
		z->h=z->h+1;
	}
	return z;
}

template<class T>
AVLNode<T>* AVLTree<T>::rotateRightLeft(AVLNode<T>* x){
	AVLNode<T>* y=x->right;
	AVLNode<T>* z=y->left;
	AVLNode<T>* t1=x->left;
	AVLNode<T>* t2=y->right;
	AVLNode<T>* t3=z->left;
	AVLNode<T>* t4=z->right;
	
	z->right=y;
	
	z->left=x;
	
	x->right=t3;
	
	y->left=t4;
	
	x->h = max(height(x->left),height(x->right));
	
	if(x->left!=NULL || x->right!=NULL){
		x->h=x->h + 1;
	}
	
	y->h = max(height(y->left),height(y->right));
	
	if(y->left!=NULL || y->right!=NULL){
		y->h=y->h + 1;
	}
	
	z->h = max(height(z->left),height(z->right));
	
	if(z->h!=0){
		z->h=z->h+1;
	}
	return z;
}

template<class T>
AVLNode<T>* AVLTree<T>::rotateRightRight(AVLNode<T>* x){
	AVLNode<T>* y=x->right;
	AVLNode<T>* z=y->right;
	AVLNode<T>* t1=x->left;
	AVLNode<T>* t2=y->left;
	AVLNode<T>* t3=z->left;
	AVLNode<T>* t4=z->right;
	
	y->right=z;
	
	y->left=x;
	
	x->right=t2;
	
	x->h = max(height(x->left),height(x->right));
	
	if(x->left!=NULL || x->right!=NULL){
		x->h=x->h + 1;
	}
	
	y->h=max(height(x->left),height(z->right))+1;
	return y;
}

template<class T>
AVLNode<T>* AVLTree<T>::insertion(AVLNode<T>* temp,T val){
	if(temp==NULL){
		AVLNode<T>* t = new AVLNode<T>();
		t->val=val;
		t->h=0;
		return t;
	}
	else if(temp->val>val){
		temp->left=insertion(temp->left,val);
	}
	else if(temp->val<val){
		temp->right=insertion(temp->right,val);
	}
	else{
		return temp;
	}
	
	temp->h = max(height(temp->left),height(temp->right));
	if(temp->left!=NULL || temp->right!=NULL){
		temp->h=temp->h + 1;
	}
	
	int bF=balanceFactor(temp);
	
	
	if(bF>1 && temp->left->val>val){
		temp=rotateLeftLeft(temp);
	}
	else if(bF>1 && temp->left->val<val){
		temp=rotateLeftRight(temp);
	}
	else if(bF<-1 && temp->right->val<val){
		temp=rotateRightRight(temp);
	}
	else if(bF<-1 && temp->right->val>val){
		temp=rotateRightLeft(temp);
	}
	
	return temp;
}

template<class T>
bool AVLTree<T>::find(T val){
	return search(root,val);
}

template<class T>
void AVLTree<T> :: pop(T val){
	try{
		if(find(val))
			root=deletion(root,val);	
		else
			throw "element not found";
	}
	catch(const char* msg){
		cout<<msg<<"\n";
	}
}

template<class T>
AVLNode<T>* AVLTree<T> :: deletion(AVLNode<T>*temp , T val){
	if(temp==NULL){
		return NULL;
	}
	else if(val>temp->val){
		temp->right=deletion(temp->right,val);
	}
	else if(val<temp->val){
		temp->left=deletion(temp->left,val);
	}
	else{
		if(temp->left==NULL || temp->right==NULL){
			AVLNode<T>* t=temp;
			if(temp->right==NULL){
				temp=temp->left;
			}
			else{
				temp=temp->right;
			}
			delete t;
		}
		else{
			int key=minVal(temp->right);
			temp->val=key;
			temp->right=deletion(temp->right,key);
		}
	}
	
	if(temp==NULL){
		return temp;
	}
	
	temp->h = max(height(temp->left),height(temp->right));
	if(temp->left!=NULL || temp->right!=NULL){
		temp->h=temp->h + 1;
	}
	
	int bF=balanceFactor(temp);
	
	
	if(bF>1 && temp->left->val>val){
		temp=rotateLeftLeft(temp);
	}
	else if(bF>1 && temp->left->val<val){
		temp=rotateLeftRight(temp);
	}
	else if(bF<-1 && temp->right->val<val){
		temp=rotateRightRight(temp);
	}
	else if(bF<-1 && temp->right->val>val){
		temp=rotateRightLeft(temp);
	}
	
	return temp;
}

template<class T>
void AVLTree<T> :: preOrder(){
	traversePreOrder(root);
	cout<<"\n";
}

template<class T>
void AVLTree<T> :: inOrder(){
	traverseInOrder(root);
	cout<<"\n";
}

template<class T>
void AVLTree<T> :: postOrder(){
	traversePostOrder(root);
	cout<<"\n";
}

template<class T>
void AVLTree<T> :: traversePreOrder(AVLNode<T>* temp){
	if(temp==NULL){
		return;
	}	
	cout<<temp->val<<" ";
	traversePreOrder(temp->left);
	traversePreOrder(temp->right);
}

template<class T>
void AVLTree<T> :: traverseInOrder(AVLNode<T>* temp){
	if(temp==NULL){
		return;
	}	
	traverseInOrder(temp->left);
	cout<<temp->val<<" ";
	traverseInOrder(temp->right);
}

template<class T>
void AVLTree<T> :: traversePostOrder(AVLNode<T>* temp){
	if(temp==NULL){
		return;
	}	
	traversePostOrder(temp->left);
	traversePostOrder(temp->right);
	cout<<temp->val<<" ";
}

int main(){
	AVLTree<int> t;
	t.push(1);
	t.push(2);
	t.push(3);
	
	t.preOrder();
	t.inOrder();
	t.postOrder();
	cout<<"-----------\n";
	t.push(4);
	t.push(5);
	
	t.preOrder();
	t.inOrder();
	t.postOrder();
	cout<<"-----------\n";
	cout<<t.find(6)<<"\n";
	cout<<t.find(4)<<"\n";
	
	t.push(6);
	t.push(7);
	cout<<"-----------\n";
	t.preOrder();
	t.inOrder();
	t.postOrder();
	
	t.push(8);
	t.pop(7);
	cout<<"-----------\n";
	t.preOrder();
	t.inOrder();
	t.postOrder();
	
	t.pop(10);
}
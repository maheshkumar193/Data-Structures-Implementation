// Red Black Tree Properties :

//0.every node is either red / black

//1.root is black 

//2.no adjacent nodes are Red

//3.count of black nodes from a node to all leaves which are desecendents to it , must be same .  

#include<bits/stdc++.h>

using namespace std;

template<class T>
class RBNode{
	public:
		
		int color;	
		
		RBNode<T>* left;
		
		RBNode<T>* right;
		
		RBNode<T>* parent;
		
		T data;
		
		RBNode(){
			left = NULL;
			color = 1; //red;
			right = NULL;
			parent = NULL;
		}
		
		~RBNode(){
			
		}
};

template<class T>
class RBTree{
	private:
		RBNode<T>* root;
		
		void insertion(RBNode<T>* ,RBNode<T>* , T);
		
		void deletion(T);
		
		bool search(RBNode<T>* , T);
		
		void balance(RBNode<T>*);
		
		RBNode<T>* getUncle(RBNode<T>*);
		
		RBNode<T>* getGrandPar(RBNode<T>*);
		
		void LeftLeftRotation(RBNode<T>*);
		
		void LeftRightRotation(RBNode<T>*);
		
		void RightLeftRotation(RBNode<T>*);
		
		void RightRightRotation(RBNode<T>*);
		
		RBNode<T>* getNode(RBNode<T>* temp, T key);
		
		void transPlant(RBNode<T>* a,RBNode<T>* b);
		
		RBNode<T>* inorderSuccesor(RBNode<T>* temp);
		
		void doubleBlack(RBNode<T>*,RBNode<T>*);
		
		void deleteBlackNode(RBNode<T>* temp);
		
		void deletionCase1(RBNode<T>*,RBNode<T>*);
		
		void deletionCase2(RBNode<T>*,RBNode<T>*);
		
		void deletionCase3(RBNode<T>*,RBNode<T>*);
		
		void deletionCase4(RBNode<T>*,RBNode<T>*);
		
		void traversePreOrder(RBNode<T>*);
		
		void traverseInOrder(RBNode<T>*);
		
		void traversePostOrder(RBNode<T>*);
	public:
		RBTree(){
			root=NULL;
		}
		
		void push(T val);
		
		void pop(T val);
		
		bool find(T val);
		
		void preOrder();
		
		void inOrder();
		
		void postOrder();
		
		~RBTree(){
			
		}
};

template<class T>
RBNode<T>* RBTree<T>::getGrandPar(RBNode<T>* temp){
	return temp->parent->parent;
}

template<class T>
RBNode<T>* RBTree<T>::getUncle(RBNode<T>* temp){
	RBNode<T>* grandpar=getGrandPar(temp);
	if(grandpar->right!=temp->parent){
		return grandpar->right;
	}
	return grandpar->left;
}

template<class T>
void RBTree<T>:: LeftLeftRotation(RBNode<T>* x){
	bool changeRoot=(x==root);
	RBNode<T>* y=x->left;
	RBNode<T>* z=y->left;
	RBNode<T>* T2=y->right;
	if(T2!=NULL) T2->parent=x;
	x->left=T2;
	y->right=x;
	y->parent=x->parent;
	x->parent=y;
	x->color=1;
	y->color=0;
	if(changeRoot){
		y=root;
	}
	else{
		y->parent->right=y;
	}
}

template<class T>
void RBTree<T>:: LeftRightRotation(RBNode<T>* x){
	bool changeRoot=(x==root);
	RBNode<T>* y=x->left;
	RBNode<T>* z=y->right;
	RBNode<T>* T1=x->right;
	RBNode<T>* T2=y->left;
	RBNode<T>* T3=z->left;
	RBNode<T>* T4=z->right;
	y->parent=z;
	z->left=y;
	z->parent=x->parent;
	x->parent=z;
	z->right=x;
	y->right=T3;
	if(T3!=NULL) T3->parent=y;
	x->left=T4;
	if(T4!=NULL) T4->parent=x;
	x->color=1;
	z->color=0;
	if(changeRoot){
		z=root;
	}
	else{
		z->parent->right=z;
	}
}

template<class T>
void RBTree<T>:: RightLeftRotation(RBNode<T>* x){
	bool changeRoot=(x==root);
	RBNode<T>* y=x->right;
	RBNode<T>* z=y->left;
	RBNode<T>* T1=x->left;
	RBNode<T>* T2=y->right;
	RBNode<T>* T3=z->right;
	RBNode<T>* T4=z->left;
	y->parent=z;
	z->right=y;
	z->parent=x->parent;
	x->parent=z;
	z->left=x;
	y->left=T3;
	if(T3!=NULL) T3->parent=y;
	x->right=T4;
	if(T4!=NULL) T4->parent=x;
	x->color=1;
	z->color=0;
	if(changeRoot){
		z=root;
	}
	else{
		z->parent->right=z;
	}
}

template<class T>
void RBTree<T>:: RightRightRotation(RBNode<T>* x){
	bool changeRoot=(x==root);
	RBNode<T>* y=x->right;
	RBNode<T>* z=y->right;
	RBNode<T>* T2=y->left;
	if(T2!=NULL) T2->parent=x;
	x->right=T2;
	y->left=x;
	y->parent=x->parent;
	x->parent=y;
	x->color=1;
	y->color=0;
	if(changeRoot){
		root=y;
	}
	else{
		y->parent->right=y;
	}
}

template<class T>
bool RBTree<T>::find(T val){
	return search(root,val);
}
		
template<class T>
bool RBTree<T>::search(RBNode<T>* temp,T val){
	if(temp==NULL){
		return false;
	}
	if(temp->data==val){
		return true;
	}
	else if(temp->data>val){
		return search(temp->left,val);
	}
	else{
		return search(temp->right,val);
	}
}
//insertion rules 

//1.If we have empty tree , insert  a black node

//2.If not empty , create a red node. If parent is black no problem .

//3.Else if parent of new node is red , then check parent siblings color (lets say this as x)

//4.if x is black or NULL , do suitable  rotation

//5.if color is red , recolor both parent and parent's sibling of new node to black & check if grand parent of new node is not root node.
//If root node do nothing , else recolor it & recheck from grand parent.

template<class T>
void RBTree<T>::push(T val){
	insertion(root,NULL,val); 
}

template<class T>
void RBTree<T>::balance(RBNode<T>* temp){
	if(temp==root){
		return;
	}
	RBNode<T>* par=temp->parent;
	if(par->color==0){
		return;
	}
	RBNode<T>* uncle=getUncle(temp);
	RBNode<T>* grandpar=getGrandPar(temp);
	if(uncle==NULL || uncle->color==0){
		if(grandpar->data>par->data && par->data>temp->data){       //left left rotation
 			LeftLeftRotation(grandpar);
		}
		else if(grandpar->data>par->data && par->data<temp->data){  // left right rotation
			LeftRightRotation(grandpar);
		}
		else if(grandpar->data<par->data && par->data>temp->data){ // right left rotation
			RightLeftRotation(grandpar);
		}
		else if(grandpar->data<par->data && par->data<temp->data){ // right right rotation
			RightRightRotation(grandpar);
		}
	}
	else{
		uncle->color=0;
		par->color=0;
		if(grandpar!=root){
			grandpar->color=1;
			balance(grandpar);
		}
	}
}
template<class T>
void RBTree<T>::insertion(RBNode<T>* temp,RBNode<T>* par, T val){
	if(temp==NULL && par==NULL){
		temp=new RBNode<T>();
		temp->data=val;
		temp->parent=par;
		temp->color=0; //black;
		root=temp;
	}
	if(temp==NULL){
		temp=new RBNode<T>();
		temp->data=val;
		temp->parent=par;
		if(par->data>val){
			par->left=temp;
		}
		else{
			par->right=temp;
		}
		balance(temp);
	}
	else if(temp->data>val){
		insertion(temp->left,temp,val);
	}
	else if(temp->data<val){
		insertion(temp->right,temp,val);
	}
}

// Deletion rules

// Note : deletion only takes place at leaf or at node which has  single child 

// Let  v be parent node , u be child node

// 1. either v or u is red , delete v and place u 

// 2.if both are black delete v and double black u

// 2.0 if u is root do nothing 

// 2.1 if sibling of v (say s) is black and s has atleast one red node child , perform 1 of 4 operations 

// 2.2 if s is black and has no red child , then make s as red & double black the parent v and recur

// 2.3 if s is red , perform a rotation to move old sibling up, recolor the old sibling and parent.

// 2.3 now fall under 2.1 or 2.2 which can be solved.

template<class T>
void RBTree<T>::pop(T val){
	try{
		if(find(val)){
			deletion(val);		
		}
		else{
			throw "node not found";
		}
	}
	catch(const char* msg){
		cout<<msg<<"\n";
	}
}

template<class T>
RBNode<T>* RBTree<T>::getNode(RBNode<T>* temp, T key){
	if(temp->data==key){
		return temp;
	}
	if(temp->data>key){
		return getNode(temp->left,key);
	}
	else{
		return getNode(temp->right,key);
	}
}

template<class T>
void RBTree<T>::transPlant(RBNode<T>* a,RBNode<T>* b){   // transPlanting only when 'a' has atleast one null child

	if(b!=NULL){
		if(a!=root){
			RBNode<T>* par=a->parent;
			if(par->right==a){
				par->right=b;
				b->parent=par;
			}
			else{
				par->left=b;
				b->parent=par;
			}
		}
		else{
			b->parent=NULL;
			root=b;
		}
	}
	else{
		if(a==root){
			root=NULL;
		}
		else{
			RBNode<T>* par=a->parent;
			if(par->right==a){
				par->right=b;
			}
			else{
				par->left=b;
			}
		}
	}
	a->right=NULL;
	a->left=NULL;
	a->parent=NULL;
	delete a;
}

template<class T>
RBNode<T>* RBTree<T>::inorderSuccesor(RBNode<T>* temp){
	while(temp->left!=NULL){
		temp=temp->left;
	}
	return temp;
}

template<class T>
void RBTree<T>::deleteBlackNode(RBNode<T>* temp){ // delete the black node
	RBNode<T>* child=NULL;
	if(temp->right!=NULL){
		child=temp->right;
	}
	else{
		child=temp->left;
	}
	transPlant(temp,child);
}

template<class T>
void RBTree<T>::deletionCase1(RBNode<T>* par,RBNode<T>* sibling){   // sibling sibling has atleast one red child

	if(par->right==sibling && sibling->left!=NULL && sibling->left->color==1){  //right left rotation
		sibling->left->color=par->color;
		par->color=0;
		RightLeftRotation(par);
	}

	else if(par->right==sibling && sibling->right!=NULL && sibling->right->color==1){ // right right rotation
		sibling->color=par->color;
		sibling->right->color=0;
		par->color=0;
		RightRightRotation(par);
	}

	else if(par->left==sibling && sibling->left!=NULL && sibling->left->color==1){ /// left left rotation
		sibling->color=par->color;
		sibling->left->color=0;
		par->color=0;
		LeftLeftRotation(par);
	}

	if(par->left==sibling && sibling->right!=NULL && sibling->right->color==1){ // left right rotation
		sibling->right->color=par->color;
		par->color=0;
		LeftRightRotation(par);
	}

}

template<class T>
void RBTree<T>::deletionCase2(RBNode<T>* par,RBNode<T>* sibling){   // sibling is black and parent in red
	sibling->color=1;
	par->color=0;
}

template<class T>
void RBTree<T>::deletionCase3(RBNode<T>* par,RBNode<T>* sibling){   // sibling is red
	sibling->color=0;
	par->color=1;
	RBNode<T>* temp=sibling->left;
	RightRightRotation(par);
	deletionCase1(par,temp);
}

template<class T>
void RBTree<T>::deletionCase4(RBNode<T>* par,RBNode<T>* sibling){   // propagating black node to parent
	sibling->color=1;
	par->color=0;
	RBNode<T>* temp=par; 
	par=par->parent;
	if(par==NULL){
		return;
	}
	if(par->right!=temp){
		sibling=par->right;
	}
	else{
		sibling=par->left;
	}
	doubleBlack(par,sibling);
}

template<class T>
void RBTree<T>::doubleBlack(RBNode<T>* par,RBNode<T>* sibling){

	if(par==NULL){ //black node is root 
		return; 
	}
	if(sibling->color==0 && ((sibling->left!=NULL && sibling->left->color==1) || (sibling->right!=NULL && sibling->right->color==1))){
		deletionCase1(par,sibling);
	}
	if(sibling->color==0 && par->color==1){
		deletionCase2(par,sibling);
	}
	else if(sibling->color==1){
		deletionCase3(par,sibling);
	}
	else if(sibling->color==0 && par->color==0){
		deletionCase4(par,sibling);
	}
}

template<class T>
void RBTree<T>::deletion(T val){
	RBNode<T>* temp=getNode(root,val);

	if(temp==root && temp->left==NULL && temp->right==NULL){
		root=NULL;
		delete temp;
		return;
	}
	RBNode<T>* par=temp->parent;
	RBNode<T>* sibling=NULL;
	if(par!=NULL){
		if(par->right!=temp){
			sibling=par->right;
		}
		else{
			sibling=par->left;
		}
	}
	if(temp->left==NULL){
		if(temp->color==1){
	
			transPlant(temp,temp->right);
		}
		else if(temp->right!=NULL && temp->right->color==1){

			temp->right->color=0;
			transPlant(temp,temp->right);
		}
		else{
			deleteBlackNode(temp);
			doubleBlack(par,sibling);
		}
	}
	
	else if(temp->right==NULL){
		if(temp->color==1){
			transPlant(temp,temp->left);
		}
		else if(temp->left!=NULL && temp->left->color==1){
			temp->left->color=0;
			transPlant(temp,temp->left);
		}
		else{
			deleteBlackNode(temp);
			doubleBlack(par,sibling);
		}
	}
	
	else{
		RBNode<T>* Next = inorderSuccesor(temp->right);
		temp->data=Next->data;
		if(Next->color == 1){
			transPlant(Next,Next->right);
		}
		else if(Next->right!=NULL && Next->right->color==1){
			Next->right->color=0;
			transPlant(Next,Next->right);
		}
		else{
			par=Next->parent;
			sibling=NULL;
			if(par!=NULL){
				if(par->right!=Next){
					sibling=par->right;
				}
				else{
					sibling=par->left;
				}
			}
			deleteBlackNode(Next);
			doubleBlack(par,sibling);
		}
	}
	
}

template<class T>
void RBTree<T> :: preOrder(){
	traversePreOrder(root);
	cout<<"\n";
}

template<class T>
void RBTree<T> :: inOrder(){
	traverseInOrder(root);
	cout<<"\n";
}

template<class T>
void RBTree<T> :: postOrder(){
	traversePostOrder(root);
	cout<<"\n";
}

template<class T>
void RBTree<T> :: traversePreOrder(RBNode<T>* temp){
	if(temp==NULL){
		return;
	}	
	cout<<temp->data<<" ";
	traversePreOrder(temp->left);
	traversePreOrder(temp->right);
}

template<class T>
void RBTree<T> :: traverseInOrder(RBNode<T>* temp){
	if(temp==NULL){
		return;
	}	
	traverseInOrder(temp->left);
	cout<<temp->data<<" ";
	traverseInOrder(temp->right);
}

template<class T>
void RBTree<T> :: traversePostOrder(RBNode<T>* temp){
	if(temp==NULL){
		return;
	}	
	traversePostOrder(temp->left);
	traversePostOrder(temp->right);
	cout<<temp->data<<" ";
}
int main(){
	RBTree<int> t;
	t.push(1);
	t.pop(1);
	t.push(2);
	// t.pop(2);
	t.push(3);
	
	// t.preOrder();
	// t.inOrder();
	// t.postOrder();
	// cout<<"-----------\n";
	t.push(4);
	t.push(5);
	
	// t.pop(2);
	t.preOrder();
	t.inOrder();
	t.postOrder();
	cout<<"-----------\n";
	cout<<t.find(6)<<"\n";
	cout<<t.find(4)<<"\n";
	
	t.push(6);
	t.push(7);
	// cout<<"-----------\n";
	t.preOrder();
	t.inOrder();
	t.postOrder();
	
	t.push(8);
	// t.pop(7);
	t.push(9);
	cout<<"-----------\n";
	t.preOrder();
	t.inOrder();
	t.postOrder();
	cout<<"-----------\n";
	t.pop(5);
	t.preOrder();
	t.inOrder();
	t.postOrder();
	cout<<"-----------\n";
	t.pop(3);
	t.preOrder();
	t.inOrder();
	t.postOrder();
	t.pop(10);
}
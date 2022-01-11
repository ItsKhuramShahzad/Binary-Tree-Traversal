#include<iostream>
using namespace std;
class node{
	public:
	node *left;
	node *right;
	int data;
};
node *root= NULL;
node * insert (node *r, int x){
	if(r==NULL){
		node *n= new node();
		n->data= x;
		n->left= n->right= NULL;
		return n;
	}
	else if (r->data==x){
		cout<<"Duplicate Found:"<< x <<endl;
	}
	else if (x<r->data){
     r->left=	insert (r->left, x);
	}
	else if (x>r->data){
     r->right= insert (r->right, x);
	}
}
node * Search (node *r, int x){
		if(r==NULL){
	
		return r;
	}
	else if (r->data==x){
		cout<<"Data Found:"<< x <<endl;
	}
	else if (x<r->data){
     return		Search (r->left, x);
	}
	else if (x>r->data){
     return		Search (r->right, x);
	}
}

 // In Order (left--Root--Right)
 void InOrderPrint(node *r){
 if (r == NULL)
        return;
    /* first recur on left child */
    InOrderPrint(r->left);
    /* then print the data of node */
    cout << " "<< r->data << " -> ";
    /* now recur on right child */
    InOrderPrint(r->right);
 }
 
 void PreOrderPrint(node *r){
 // Pre Order (Root--left--Right)	
 	if (r == NULL)
        return;
 
  /* First print the data of node */
    cout << " "<< r->data << " -> ";
 
    /* then recur on left subtree */
    PreOrderPrint(r->left);
    
     /* now recur on right subtree */
    PreOrderPrint(r->right);
 }
 
// Post Order (left--Right--Root)	
 void PostOrderPrint(node *r){
	 	if (r == NULL)
        return; 
  // first recur on left subtree
    PostOrderPrint(r->left);
    // then recur on right subtree
    PostOrderPrint(r->right);
    // now deal with the node
    cout << " "<< r->data << " -> ";
 }
 
// in Order (left--Root--Right)
// Pre Order (Root--left--Right)
// Post Order (left--Right--Root)
int main (){
	root=insert(root, 5);
	insert(root, 7);
	insert(root, 3);
	insert(root, 9);
	insert(root, 1);
		Search(root, 9);
	cout<<"In Order Print (left--Root--Right)"<<endl;
	InOrderPrint(root);
	
	cout<<"\n-----------------------"<<endl;
	cout<<"Pre Order Print (Root--left--Right)"<<endl;
	PreOrderPrint(root);
	
	cout<<"\n-----------------------"<<endl;
	cout<<"Post Order Print (left--Right--Root)"<<endl;
	PostOrderPrint(root);
	
	cout<<"\n-----------------------"<<endl;

	return 0;
}

#include<iostream>
using namespace std;
class node {
	public:
		node *left;
		node *right;
		int data;
		node(int data) {
			this->data=  data;
			left= right= NULL;
		}
};
bool flg=false;
node *root= NULL;
node * insert (node *r, int x) {
	if (r==NULL) {
		node* t= new node(x);

		if (!flg) {
			root= r=t;
			flg=true;
		} else
			r=t;

		return r;
	}
//    else if (r->data== val){
//        //cout<<"Duplicate Record  "<<val;
//            return r;
//    }
	else if (x < r->data) {
		r->left = insert(r->left , x );
		return r;
	} else if (x > r->data) {
		r->right= insert( r->right,x);
		return r;
	}
}
node * Search (node *r, int x) {
	if(r==NULL) {

		return r;
	} else if (r->data==x) {
		cout<<"Data Found:"<< x <<endl;
	} else if (x<r->data) {
		return		Search (r->left, x);
	} else if (x>r->data) {
		return		Search (r->right, x);
	}
}

// In Order (left--Root--Right)
void InOrderPrint(node *r) {
	if (r == NULL)
		return;
	/* first recur on left child */
	InOrderPrint(r->left);
	/* then print the data of node */
	cout << " "<< r->data << " -> ";
	/* now recur on right child */
	InOrderPrint(r->right);
}

void PreOrderPrint(node *r) {
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
void PostOrderPrint(node *r) {
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
int main () {
	insert(root, 5);
	insert(root, 7);
	insert(root, 3);
	insert(root, 9);
	insert(root, 11);
	insert(root, 13);
	insert(root, 19);
	insert(root, 6);
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

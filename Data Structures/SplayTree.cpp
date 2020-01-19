//Implementation of Splay Tree

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	Node *left, *right, *par;
	Node(int x){
		val = x;
		left = right = par = NULL;
	}
};

Node *root;

void rightRotate(Node *p){
	Node *l = p->left;
	Node *r = l->right;
	Node *pp = p->par;
	if(pp){
		if(pp->left==p)
			pp->left = l;
		else
			pp->right = l;
	}
	if(r)
		r->par = p;

	l->right = p;
	l->par = pp;

	p->left = r;
	p->par = l;
}

void leftRotate(Node *p){
	Node *r = p->right;
	Node *l = r->left;
	Node *pp = p->par;
	if(pp){
		if(pp->left==p)
			pp->left = r;
		else
			pp->right = r;
	}
	if(l)
		l->par = p;

	r->par = pp;
	r->left = p;

	p->par = r;
	p->right = l;
}

void splay(Node *T){
	while(true){
		Node *p = T->par;
		if(!p)
			break;
		Node *pp = p->par;
		if(!pp){
			if(p->left==T)
				rightRotate(p);
			else
				leftRotate(p);
			break;
		}
		if(pp->left==p){
			if(p->left==T){
				rightRotate(pp);
				rightRotate(p);
			}
			else{
				leftRotate(p);
				rightRotate(pp);
			}
		}
		else{
			if(p->right==T){
				leftRotate(pp);
				leftRotate(p);
			}
			else{
				rightRotate(p);
				leftRotate(pp);
			}
		}
	}
	root = T;
}

void insert(int v){
	if(!root){
		root = new Node(v);
		return;
	}
	Node *itr = root;
	while(true){
		if(itr->val==v){ //not multiset
			cout<<"Already present"<<endl;
			break;
		}
		if(itr->val > v){
			if(itr->left)
				itr = itr->left;
			else{
				Node *new_node = new Node(v);
				itr->left = new_node;
				new_node->par = itr;
				itr = new_node;
				break;
			}
		}
		else{
			if(itr->right)
				itr = itr->right;
			else{
				Node *new_node = new Node(v);
				itr->right = new_node;
				new_node->par = itr;
				itr = new_node;
				break;
			}
		}
	}
	splay(itr);
}

void inorder(Node *itr){
	if(!itr)
		return;
	inorder(itr->left);
	cout<<itr->val<<" ";
	inorder(itr->right);
}

Node *find(int v){
	if(!root)
		return NULL;
	Node *p = root;
	while(true){
		if(p->val==v)
			break;
		if(p->val>v){
			if(p->left)
				p = p->left;
			else
				break;
		}
		else{
			if(p->right)
				p = p->right;
			else
				break;
		}
	}
	splay(p);
	if(p->val==v)
		return p;
	return NULL;
}

bool erase(int v){
	Node *N = find(v);
	if(!N)
		return false;
	splay(N); 
	Node *p = N->left;
	if(!p){
		root = N->right;
		if(root)
			root->par = NULL;
		delete N;
		return true;
	}
	while(p->right)
		p = p->right;
	if(N->right){
		p->right = N->right;
		N->right->par = p;
	}
	root = N->left;
	root->par = NULL;
	delete N;
	return true;
}


/* Advantage - Simple implementation, Comparable performance, 
              frequently accessed nodes will move nearer to the root where they can be accessed more quickly...   */
              
              
/* Disadvantage - Perhaps the most significant disadvantage of splay trees is that the height of a splay tree can be linear.
                  For example, this will be the case after accessing all n elements in non-decreasing order.
                  
                  Splay trees can change even when they are accessed in a 'read-only' manner. 
                  This complicates the use of such splay trees in a multi-threaded environment. 
                  Specifically, extra management is needed if multiple threads are allowed to perform find operations concurrently...    */

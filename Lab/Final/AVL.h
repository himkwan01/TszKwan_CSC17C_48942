/* 
 * File:   AVL.h
 * Author: Himkw_000
 *
 * Created on December 9, 2015, 8:22 PM
 */

#ifndef AVL_H
#define	AVL_H


//AVL Tree

#include <bits/stdc++.h>
using namespace std;

struct Node{
	string data;
  int count;
	Node *left;
	Node *right;
	int depth;
	Node(string temp):data(temp), count(1), left(NULL), right(NULL), depth(0){}
};

class AVLTree{
private:
	//private variables
	int size;
	Node *root;
	//private functions
	int height(Node *tree);
	Node *insert(Node *tree, string data);
	Node *remove(Node *tree, Node *del);
	Node *LLRotation(Node *tree);
	Node *RRRotation(Node *tree);
	Node *LRRotation(Node *tree);
	Node *RLRotation(Node *tree);
	void preOrder(Node *tree);
	void inOrder(Node *tree);
	void postOrder(Node *tree);
	Node *minimum(Node *tree);
	Node *maximum(Node *tree);
	Node *remove(Node *tree);
	void destroy(Node *tree);
	Node *search(string data);
public:
	AVLTree(){root = NULL;size=0;}
	int max(int a, int b){return (a>b ? a : b);}
	void insert(string data);
	void remove(string data);
	int height(){return root->depth;}
	void preOrder(){preOrder(root);cout<<endl;}		//root - left - right
	void inOrder(){inOrder(root);cout<<endl;}		//left - root - right
	void postOrder(){postOrder(root);cout<<endl;}	//left - right - root
	string minimum();
	string maximum();
	void destroy();			//free memory
	Node *search(Node* tree, string data);
  int getSize(){return size;}
  ~AVLTree(){destroy();}
	
};

//private height
int AVLTree::height(Node *tree){
	if(tree != NULL)return tree->depth;
	return 0;
}

//public destroy
void AVLTree::destroy(){
	destroy(root);
}

//private destroy
void AVLTree::destroy(Node *tree){
	if(tree == NULL)return;
	if(tree->left != NULL)destroy(tree->left);
	if(tree->right!=NULL)destroy(tree->right);
	delete tree;
}

//private minimum
string AVLTree::minimum(){
	Node *temp = minimum(root);
	if(temp != NULL)
		return temp->data;
	return NULL;
}

//private maximum
string AVLTree::maximum(){
	Node *temp = maximum(root);
	if(temp != NULL)
		return temp->data;
	return NULL;
}

//public insert
void AVLTree::insert(string data){
	root = insert(root, data);
}

//private insert
Node *AVLTree::insert(Node *tree, string data){
	if(tree == NULL){
		tree = new Node(data);
		if(tree == NULL){
			cout<<"ERROR: insert fail\n";
			return NULL;
		}
    size++;
	}//insert ends
	
	//tree not null, call insert with left or right child
	else if(data < tree->data){
		tree->left = insert(tree->left, data);
		//check child height
		if(height(tree->left) - height(tree->right)==2){
			//not balnace
			if(data < tree->left->data){
				//LL -> right shift
				tree = LLRotation(tree);
			}
			else{
				//LR -> left shift -> right shift
				tree =LRRotation(tree);
			}
		}//balance end
	}//insert left end
	
	else if(data > tree->data){
		tree->right = insert(tree->right, data);
		//check child height
		if(height(tree->right) - height(tree->left) == 2){
			//unbalance
			if(data>tree->right->data){
				//RR -> left shift
				tree = RRRotation(tree);
			}
			else{
				//RL -> right shift -> left shift
				tree = RLRotation(tree);
			}
		}//balance end
	}//insert right end
	
	//same element
	else{
    tree->count++;
//		cout<<"Insert failed: not allow same elements\n";
	}
	//update height
	tree->depth = max(height(tree->left), height(tree->right))+1;
	return tree;
}

//public remove
void AVLTree::remove(string data){
	Node *temp = search(root, data);
	//if search != NULL, then temp = search
	if(temp!=NULL){
		root = remove(root, temp);
	}
	cout<<data<<" doesn't exist\n";
}

//private remove
Node *AVLTree::remove(Node *tree, Node *del){
	//if any pointer is null, then neither tree or data exists
	//only double check
	if(tree == NULL || del == NULL)
		return NULL;
	//del data at left tree
	if(del->data < tree->data){
		//call recursively
		tree->left = remove(tree->left, del);
		//already delete the node
		if(height(tree->right) - height(tree->left)==2){
			Node *r = tree->right;
			if(height(r->left) > height(r->right))
				tree = RLRotation(tree);
			else
				tree = RRRotation(tree);
		}
	}//if del data < tree data
	//del data > tree data
	else if(del->data > tree->data){
		tree->right = remove(tree->right, del);
		//unbalance
		if(height(tree->left) - height(tree->right) ==2){
			Node *l = tree->left;
			if(height(l->right) > height(l->left))
				tree = LRRotation(tree);
			else
				tree = LLRotation(tree);
		}
	}//else if del data > tree data
	
	else{	//tree = del
		if((tree->left!=NULL) && (tree->right!=NULL)){
			if(height(tree->left) > height(tree->right)){
				Node *max = maximum(tree->left);
				tree->data = max->data;
				tree->left = remove(tree->left, max);
			}
			else{
				Node *min = minimum(tree->right);
				tree->data = min->data;
				tree->right = remove(tree->right, min);
			}
		}//if left and right not null
		else{
			Node *tmp = tree;
			tree = (tree->left!=NULL) ? tree->left : tree->right;
			delete tmp;
		}
	}//else 
	
	return tree;
}
//right shift
Node *AVLTree::LLRotation(Node *tree){
	Node *temp = tree->left;
	tree->left = temp->right;
	temp->right = tree;
	//update height
	temp->depth = max(height(temp->left), height(temp->right)) + 1;
	tree->depth = max(height(tree->left), height(tree->right)) + 1;
	return temp;
}
//left shift
Node *AVLTree::RRRotation(Node *tree){
	Node *temp = tree->right;
	tree->right = temp->left;
	temp->left = tree;
	//update height
	temp->depth = max(height(temp->left), height(temp->right)) + 1;
	tree->depth = max(height(tree->left), height(tree->right)) + 1;
	return temp;
}

Node *AVLTree::LRRotation(Node *tree){
	tree->left = RRRotation(tree->left);
	return LLRotation(tree);
}

Node *AVLTree::RLRotation(Node *tree){
	tree->right = LLRotation(tree->right);
	return RRRotation(tree);
}
void AVLTree::preOrder(Node *tree){
	if(tree != NULL){
		cout<<tree->data<<" ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

void AVLTree::inOrder(Node *tree){
	if(tree != NULL){
		inOrder(tree->left);
		cout<<tree->data<<" ";
		inOrder(tree->right);
	}
}

void AVLTree::postOrder(Node *tree){
	if(tree != NULL){
		postOrder(tree->left);
		postOrder(tree->right);
		cout<<tree->data<<" ";
	}
}

Node *AVLTree::minimum(Node *tree){
	if(tree == NULL)return NULL;
	while(tree->left != NULL) tree = tree->left;
	return tree;
}

Node *AVLTree::maximum(Node *tree){
	if(tree == NULL)return NULL;
	while(tree->right != NULL) tree = tree->right;
	return tree;
}

Node* AVLTree::search(string data){
  return search(root, data);
}

Node *AVLTree::search(Node* tree, string data){
  if (tree==NULL || tree->data==data)
        return tree;
    if (data < tree->data)
        return search(tree->left, data);
    else
        return search(tree->right, data);
}

#endif	/* AVL_H */


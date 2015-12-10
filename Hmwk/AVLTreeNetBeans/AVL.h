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

template <class T>
struct Node{
	T data;
	Node<T> *left;
	Node<T> *right;
	int depth;
	Node<T>(T temp):data(temp), left(NULL), right(NULL), depth(0){}
};

template <class T>
class AVLTree{
private:
	//private variables
	
	Node<T> *root;
	
	//private functions
	int height(Node<T> *tree);
	Node<T> *insert(Node<T> *tree, T data);
	Node<T> *remove(Node<T> *tree, Node<T> *del);
	Node<T> *LLRotation(Node<T> *tree);
	Node<T> *RRRotation(Node<T> *tree);
	Node<T> *LRRotation(Node<T> *tree);
	Node<T> * RLRotation(Node<T> *tree);
	void preOrder(Node<T> *tree);
	void inOrder(Node<T> *tree);
	void postOrder(Node<T> *tree);
	Node<T> *minimum(Node<T> *tree);
	Node<T> *maximum(Node<T> *tree);
	Node<T> *remove(Node<T> *tree);
	void destroy(Node<T> *tree);
	Node<T>* search(T data);
public:
	AVLTree(){root = NULL;}
	int max(int a, int b){return (a>b ? a : b);}
	void insert(T data);
	void remove(T data);
	int height(){return root->depth;}
	void preOrder(){preOrder(root);cout<<endl;}		//root - left - right
	void inOrder(){inOrder(root);cout<<endl;}		//left - root - right
	void postOrder(){postOrder(root);cout<<endl;}	//left - right - root
	T minimum();
	T maximum();
	void destroy();			//free memory
	Node<T> *search(Node<T>* tree, T data);
  ~AVLTree(){destroy();}
	
};

//private height
template <class T>
int AVLTree<T>::height(Node<T> *tree){
	if(tree != NULL)return tree->depth;
	return 0;
}

//public destroy
template <class T>
void AVLTree<T>::destroy(){
	destroy(root);
}

//private destroy
template <class T>
void AVLTree<T>::destroy(Node<T> *tree){
	if(tree == NULL)return;
	if(tree->left != NULL)destroy(tree->left);
	if(tree->right!=NULL)destroy(tree->right);
	delete tree;
}

//private minimum
template <class T>
T AVLTree<T>::minimum(){
	Node<T> *temp = minimum(root);
	if(temp != NULL)
		return temp->data;
	return static_cast<T>(NULL);
}

//private maximum
template <class T>
T AVLTree<T>::maximum(){
	Node<T> *temp = maximum(root);
	if(temp != NULL)
		return temp->data;
	return static_cast<T>(NULL);
}

//public insert
template <class T>
void AVLTree<T>::insert(T data){
	root = insert(root, data);
}

//private insert
template <class T>
Node<T> *AVLTree<T>::insert(Node<T> *tree, T data){
	if(tree == NULL){
		tree = new Node<T>(data);
		if(tree == NULL){
			cout<<"ERROR: insert fail\n";
			return NULL;
		}
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
		cout<<"Insert failed: not allow same elements\n";
	}
	//update height
	tree->depth = max(height(tree->left), height(tree->right))+1;
	return tree;
}

//public remove
template <class T>
void AVLTree<T>::remove(T data){
	Node<T> *temp = search(root, data);
	//if search != NULL, then temp = search
	if(temp!=NULL){
		root = remove(root, temp);
	}
	cout<<data<<" doesn't exist\n";
}

//private remove
template <class T>
Node<T> *AVLTree<T>::remove(Node<T> *tree, Node<T> *del){
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
			Node<T> *r = tree->right;
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
			Node<T> *l = tree->left;
			if(height(l->right) > height(l->left))
				tree = LRRotation(tree);
			else
				tree = LLRotation(tree);
		}
	}//else if del data > tree data
	
	else{	//tree = del
		if((tree->left!=NULL) && (tree->right!=NULL)){
			if(height(tree->left) > height(tree->right)){
				Node<T> *max = maximum(tree->left);
				tree->data = max->data;
				tree->left = remove(tree->left, max);
			}
			else{
				Node<T> *min = minimum(tree->right);
				tree->data = min->data;
				tree->right = remove(tree->right, min);
			}
		}//if left and right not null
		else{
			Node<T> *tmp = tree;
			tree = (tree->left!=NULL) ? tree->left : tree->right;
			delete tmp;
		}
	}//else 
	
	return tree;
}
//right shift
template <class T>
Node<T> *AVLTree<T>::LLRotation(Node<T> *tree){
	Node<T> *temp = tree->left;
	tree->left = temp->right;
	temp->right = tree;
	//update height
	temp->depth = max(height(temp->left), height(temp->right)) + 1;
	tree->depth = max(height(tree->left), height(tree->right)) + 1;
	return temp;
}
//left shift
template <class T>
Node<T> *AVLTree<T>::RRRotation(Node<T> *tree){
	Node<T> *temp = tree->right;
	tree->right = temp->left;
	temp->left = tree;
	//update height
	temp->depth = max(height(temp->left), height(temp->right)) + 1;
	tree->depth = max(height(tree->left), height(tree->right)) + 1;
	return temp;
}

template <class T>
Node<T> *AVLTree<T>::LRRotation(Node<T> *tree){
	tree->left = RRRotation(tree->left);
	return LLRotation(tree);
}

template <class T>
Node<T> *AVLTree<T>::RLRotation(Node<T> *tree){
	tree->right = LLRotation(tree->right);
	return RRRotation(tree);
}
template <class T>
void AVLTree<T>::preOrder(Node<T> *tree){
	if(tree != NULL){
		cout<<tree->data<<" ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

template <class T>
void AVLTree<T>::inOrder(Node<T> *tree){
	if(tree != NULL){
		inOrder(tree->left);
		cout<<tree->data<<" ";
		inOrder(tree->right);
	}
}

template <class T>
void AVLTree<T>::postOrder(Node<T> *tree){
	if(tree != NULL){
		postOrder(tree->left);
		postOrder(tree->right);
		cout<<tree->data<<" ";
	}
}

template <class T>
Node<T> *AVLTree<T>::minimum(Node<T> *tree){
	if(tree == NULL)return NULL;
	while(tree->left != NULL) tree = tree->left;
	return tree;
}

template <class T>
Node<T> *AVLTree<T>::maximum(Node<T> *tree){
	if(tree == NULL)return NULL;
	while(tree->right != NULL) tree = tree->right;
	return tree;
}

template <class T>
Node<T>* AVLTree<T>::search(T data){
  return search(root, data);
}

template <class T>
Node<T> *AVLTree<T>::search(Node<T>* tree, T data){
  if (tree==NULL || tree->data==data)
        return tree;

    if (data < tree->data)
        return search(tree->left, data);
    else
        return search(tree->right, data);
}

#endif	/* AVL_H */


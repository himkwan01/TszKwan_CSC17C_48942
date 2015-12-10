#include <bits/stdc++.h>
using namespace std;


template <class T>
class AVLTreeNode{
    public:
        T data;				//data
        int height;			//tree height
        AVLTreeNode *left;	//left tree
        AVLTreeNode *right;	//right tree
		
        AVLTreeNode(T value, AVLTreeNode *l, AVLTreeNode *r):
            data(value), height(0),left(l),right(r) {}
};

template <class T>
class AVLTree {
    private:
        AVLTreeNode<T> *mRoot;	//根

    public:
        AVLTree();
        ~AVLTree();

        /*
		 * get tree height
		 * two functions (void, AVLTreeNode *)
		 */
        int height();
        // 获取树的高度
        int max(int a, int b);

        //root - left - right
        void preOrder();
        //left - root - right
        void inOrder();
        //left - right - root
        void postOrder();

        // (递归实现)查找"AVL树"中键值为data的节点
        AVLTreeNode<T>* search(T data);
        // (非递归实现)查找"AVL树"中键值为data的节点
        AVLTreeNode<T>* iterativeSearch(T data);

        // 查找最小结点：返回最小结点的键值。
        T minimum();
        // 查找最大结点：返回最大结点的键值。
        T maximum();

        // 将结点(data为节点键值)插入到AVL树中
        void insert(T data);

        // 删除结点(data为节点键值)
        void remove(T data);
		
        // 销毁AVL树
        void destroy();

        // 打印AVL树
        void print();
    private:
        // 获取树的高度
        int height(AVLTreeNode<T>* tree) ;

        //current tree root - left - right
        void preOrder(AVLTreeNode<T>* tree) const;
        //current tree left - root - right
        void inOrder(AVLTreeNode<T>* tree) const;
        //current tree left - right - root
        void postOrder(AVLTreeNode<T>* tree) const;

        // (递归实现)查找"AVL树x"中键值为data的节点
        AVLTreeNode<T>* search(AVLTreeNode<T>* x, T data) const;
        // (非递归实现)查找"AVL树x"中键值为data的节点
        AVLTreeNode<T>* iterativeSearch(AVLTreeNode<T>* x, T data) const;

        // 查找最小结点：返回tree为根结点的AVL树的最小结点。
        AVLTreeNode<T>* minimum(AVLTreeNode<T>* tree);
        // 查找最大结点：返回tree为根结点的AVL树的最大结点。
        AVLTreeNode<T>* maximum(AVLTreeNode<T>* tree);

        // LL：左左对应的情况(左单旋转)。
        AVLTreeNode<T>* leftLeftRotation(AVLTreeNode<T>* k2);

        // RR：右右对应的情况(右单旋转)。
        AVLTreeNode<T>* rightRightRotation(AVLTreeNode<T>* k1);

        // LR：左右对应的情况(左双旋转)。
        AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* k3);

        // RL：右左对应的情况(右双旋转)。
        AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* k1);

        // 将结点(z)插入到AVL树(tree)中
        AVLTreeNode<T>* insert(AVLTreeNode<T>* &tree, T data);

        // 删除AVL树(tree)中的结点(z)，并返回被删除的结点
        AVLTreeNode<T>* remove(AVLTreeNode<T>* &tree, AVLTreeNode<T>* z);

        // 销毁AVL树
        void destroy(AVLTreeNode<T>* &tree);

        // 打印AVL树
        void print(AVLTreeNode<T>* tree, T data, int direction);
};

//get specific tree height (not from root)
template <class T>
int AVLTree<T>::height(AVLTreeNode<T>* tree){
    //not empty return height
	if (tree != NULL)
        return tree->height;
    return 0;
}

//get whole tree height
template <class T>
int AVLTree<T>::height(){
    return height(mRoot);
}

//get the bigger one
template <class T>
int AVLTree<T>::max(int a, int b){
    return a>b ? a : b;
}

/*
 * 左左 -＞　右旋
 * 取舊根左子為新根，新根右子為舊根左子，舊根為新根右子
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::leftLeftRotation(AVLTreeNode<T>* k2){
    AVLTreeNode<T>* k1;

    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
	//update height
    k2->height = max( height(k2->left), height(k2->right)) + 1;
    k1->height = max( height(k1->left), k2->height) + 1;

    return k1;
}

/*
 * 右右 -> 左旋
 * 取根右子為新根，舊根為新根左子
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::rightRightRotation(AVLTreeNode<T>* k1){
    AVLTreeNode<T>* k2;

    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = max( height(k1->left), height(k1->right)) + 1;
    k2->height = max( height(k2->right), k1->height) + 1;

    return k2;
}

/*
 * LR：左右对应的情况(左双旋转)。
 *
 * 返回值：旋转后的根节点
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::leftRightRotation(AVLTreeNode<T>* k3){
    k3->left = rightRightRotation(k3->left);

    return leftLeftRotation(k3);
}

/*
 * RL：右左对应的情况(右双旋转)。
 *
 * 返回值：旋转后的根节点
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::rightLeftRotation(AVLTreeNode<T>* k1){
    k1->right = leftLeftRotation(k1->right);

    return rightRightRotation(k1);
}

/* 
 * 将结点插入到AVL树中，并返回根节点
 *
 * 参数说明：
 *     tree AVL树的根结点
 *     data 插入的结点的键值
 * 返回值：
 *     根节点
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::insert(AVLTreeNode<T>* &tree, T data){
	//empty node -> can insert
	if (tree == NULL){
		//create new node
        tree = new AVLTreeNode<T>(data, NULL, NULL);
		//sth like out of memory (error checking)
        if (tree==NULL){
            cout << "ERROR: create avltree node failed!" << endl;
            return NULL;
        }
    }
	//data < node->data
	//should insert data to node->left
    else if (data < tree->data){
        tree->left = insert(tree->left, data);
		//after insert check balance
		//coz insert at left. left>=right
		//if difference = 2, unbalance -> balance it
        if (height(tree->left) - height(tree->right) == 2){
			//data insert at the left -> left left -> right shift
            if (data < tree->left->data)
                tree = leftLeftRotation(tree);
			//data insert at the right -> left right -> 
            else
                tree = leftRightRotation(tree);
        }
    }
	//data > node->data
	//should insert data to node->right
    else if (data > tree->data){
        tree->right = insert(tree->right, data);
		//after insert check balance
		//coz insert at right, right>=left
		//if difference = 2, unbalance -> balance it
        if (height(tree->right) - height(tree->left) == 2){
			//data insert at the right -> right right -> left shift
            if (data > tree->right->data)
                tree = rightRightRotation(tree);
			//data insert at the left, right left
            else
                tree = rightLeftRotation(tree);
        }
    }
    else{ //data == tree->data)
        cout << "insert fail: not allowed to insert same data" << endl;
    }

    tree->height = max( height(tree->left), height(tree->right)) + 1;

    return tree;
}

template <class T>
void AVLTree<T>::insert(T data){
    insert(mRoot, data);
}

/* 
 * delete that node (z)
 *
 * 参数说明：
 *     tree AVL树的根结点
 *     z 待删除的结点
 * return： mroot
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::remove(AVLTreeNode<T>* &tree, AVLTreeNode<T>* z){
    // 根为空 或者 没有要删除的节点，直接返回NULL。
    if (tree==NULL || z==NULL)
        return NULL;

    if (z->data < tree->data){        // 待删除的节点在"tree的左子树"中
        tree->left = remove(tree->left, z);
        // 删除节点后，若AVL树失去平衡，则进行相应的调节。
        if (height(tree->right) - height(tree->left) == 2){
            AVLTreeNode<T> *r =  tree->right;
            if (height(r->left) > height(r->right))
                tree = rightLeftRotation(tree);
            else
                tree = rightRightRotation(tree);
        }
    }
    else if (z->data > tree->data){ // 待删除的节点在"tree的右子树"中
        tree->right = remove(tree->right, z);
        // 删除节点后，若AVL树失去平衡，则进行相应的调节。
        if (height(tree->left) - height(tree->right) == 2){
            AVLTreeNode<T> *l =  tree->left;
            if (height(l->right) > height(l->left))
                tree = leftRightRotation(tree);
            else
                tree = leftLeftRotation(tree);
        }
    }
    else{    // tree是对应要删除的节点。
        // tree的左右孩子都非空
        if ((tree->left!=NULL) && (tree->right!=NULL)){
            if (height(tree->left) > height(tree->right)){
                // 如果tree的左子树比右子树高；
                // 则(01)找出tree的左子树中的最大节点
                //   (02)将该最大节点的值赋值给tree。
                //   (03)删除该最大节点。
                // 这类似于用"tree的左子树中最大节点"做"tree"的替身；
                // 采用这种方式的好处是：删除"tree的左子树中最大节点"之后，AVL树仍然是平衡的。
                AVLTreeNode<T>* max = maximum(tree->left);
                tree->data = max->data;
                tree->left = remove(tree->left, max);
            }
            else{
                // 如果tree的左子树不比右子树高(即它们相等，或右子树比左子树高1)
                // 则(01)找出tree的右子树中的最小节点
                //   (02)将该最小节点的值赋值给tree。
                //   (03)删除该最小节点。
                // 这类似于用"tree的右子树中最小节点"做"tree"的替身；
                // 采用这种方式的好处是：删除"tree的右子树中最小节点"之后，AVL树仍然是平衡的。
                AVLTreeNode<T>* min = maximum(tree->right);
                tree->data = min->data;
                tree->right = remove(tree->right, min);
            }
        }
        else{
            AVLTreeNode<T>* tmp = tree;
            tree = (tree->left!=NULL) ? tree->left : tree->right;
            delete tmp;
        }
    }

    return tree;
}

template <class T>
void AVLTree<T>::remove(T data){
    AVLTreeNode<T>* z; 

    if ((z = search(mRoot, data)) != NULL)
        mRoot = remove(mRoot, z);
}

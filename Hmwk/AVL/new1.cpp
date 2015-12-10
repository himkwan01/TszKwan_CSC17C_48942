/**
 * C 语言: AVL树
 *
 * @author skywang
 * @date 2013/11/07
 */

#include <iostream>
#include "test.h"
using namespace std;

static int arr[]= {10,6,13,4,8,12,15,3,5,7,9,11,14,16,1};
//static int arr[]= {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main()
{
    int i,ilen;
    AVLTree<int>* tree=new AVLTree<int>();

    cout << "Insert: ";
    ilen = TBL_SIZE(arr);
    for(i=0; i<ilen; i++)
    {
        cout << arr[i] <<" ";
        tree->insert(arr[i]);
    }
	cout<<endl;
	cout<<"PreOrder\n";
	tree->preOrder();
	cout<<endl;
    cout<<"InOrder\n";
    tree->inOrder();
	cout<<endl;
	cout<<"PostOrder\n";
	tree->postOrder();
	cout<<endl;
    i = 6;
    cout << "remove: " << i <<endl;
    tree->remove(i);
    cout<<"PreOrder\n";
	tree->preOrder();
	cout<<endl;
    cout<<"InOrder\n";
    tree->inOrder();
	cout<<endl;
	cout<<"PostOrder\n";
	tree->postOrder();
	cout<<endl;
    // 销毁二叉树
    tree->destroy();

    return 0;
}
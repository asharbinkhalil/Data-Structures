#include<iostream>
#include"tree.cpp"
using namespace std;
int main()
{
    tree t;
    //t.root = t.createNode(1);
    //t.root->lchild = t.createNode(2);
    //t.root->rchild = t.createNode(9);
    //t.root->lchild->rchild = t.createNode(3);
    //t.root->lchild->lchild = t.createNode(4);
    //t.root->lchild->lchild->lchild = t.createNode(11);
    //t.root->lchild->lchild->rchild = t.createNode(12);
    //t.root->lchild->lchild->rchild->lchild = t.createNode(13);
    //t.root->lchild->lchild->rchild->rchild = t.createNode(14);
    t.insert(9);
    t.insert(7);
    t.insert(5);
    t.insert(3);
    t.insert(4);


    t.traverseInorder(t.root);
    cout<<"\nHEIGHT IS : " << t.height(t.root);

}
#include"node.cpp"
#include<iostream>
using namespace std;
class tree {
public:
    node* root;

    tree() {
        root == NULL;
    }
    bool isEmpty()
    {
        return (root == NULL);
    }
    int height(node* root)
    {
        static int c = -1;
        if (root == NULL)
            return c;
        height(root->lchild);
        c++;
    }
    void insert(char ch)
    {
        node* Node = new node;
        Node->value = ch;
        Node->lchild = NULL;
        Node->rchild = NULL;
        node* p = NULL;
        node* c = root;
        if (root == NULL)
            root = Node;
        else
        {
            while (c != NULL)
            {
                p = c;

                if (Node->value >= c->value)
                    c = c->rchild;
                else if (Node->value < c->value)
                    c = c->lchild;
            }
            if (Node->value > p->value)
                p->rchild = Node;
            else
                p->lchild = Node;

        }


    }
    node* createNode(int val)
    {
        node* Node = new node;
        Node->value = val;
        Node->lchild = NULL;
        Node->rchild = NULL;
        return (Node);
    }
    void traverseInorder(node* root)
    {
        if (root == NULL)
            return;
        traverseInorder(root->lchild);
        cout << " " << root->value << " ";
        traverseInorder(root->rchild);
    }
};
#include <iostream>
#include<stack>
#include<queue>
using namespace std;
class node
{
public:
    int value;
    node* lchild;
    node* rchild;
    node* parent;
    int height;
};
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
    node* createNode(int val)
    {
        node* Node = new node;
        Node->value = val;
        Node->lchild = NULL;
        Node->rchild = NULL;
        Node->height = 1;
        return (Node);
    }
    node* rRotate(node* y)
    {
        node* x = y->lchild;
        node* T2 = x->rchild;

        x->rchild = y;
        y->lchild = T2;

        y->height = max(height(y->lchild),  height(y->rchild)) + 1;

        x->height = max(height(x->lchild),  height(x->rchild)) + 1;

        return x;
    }

    // A utility function to lchild
    // rotate subtree rooted with x
    // See the diagram given above.
    node* lRotate(node* x)
    {
        node* y = x->rchild;
        node* T2 = y->lchild;

        // Perform rotation
        y->lchild = x;
        x->rchild= T2;

        // Update heights
        x->height = max(height(x->lchild), height(x->rchild)) + 1;
        y->height = max(height(y->lchild), height(y->rchild)) + 1;

        // Return new root
        return y;
    }
    void preOrder(node* root)
    {
        if (root != NULL)
        {
            cout << root->value << " ";
            preOrder(root->lchild);
            preOrder(root->rchild);
        }
    }
    node* insertAvl(node *root, int key)
    {
        if (root == NULL)
             return createNode(key);

        if (key < root->value)
            root->lchild = insertAvl(root->lchild, key);
        else if (key > root->value)
            root->rchild = insertAvl(root->rchild, key);
        else
            return root;
        root->height = 1 + max(height(root->lchild), height(root->rchild));

        int balance = getBalance(root);

        // Left Left Case
        if (balance > 1 && key < root->lchild->value)
            return rRotate(root);

        // Right Right Case
        if (balance < -1 && key > root->rchild->value)
            return lRotate(root);

        // Left Right Case
        if (balance > 1 && key > root->lchild->value)
        {
            root->lchild = lRotate(root->lchild);
            return rRotate(root);
        }
        // Right Left Case
        if (balance < -1 && key < root->rchild->value)
        {
            root->rchild = rRotate(root->rchild);
            return lRotate(root);
        }

        /* return the (unchanged) node pointer */
        return root;
    }
    int getBalance(node* N)
    {
        if (N == NULL)
            return 0;
        return height(N->lchild) - height(N->rchild);
    }
    int height(node* N)
    {
        if (N == NULL)
            return 0;
        return N->height;
    }
    int max(int l, int r)
    {
        if (l > r)
            return l;
        else
            return r;
    }

    
    void traverseinorder(node* root)
    {
        if (root == NULL)
            return;
        traverseinorder(root->lchild);
        cout << " " << root->value << " ";
        traverseinorder(root->rchild);
    }
    node* search(node* root, int src)
    {
        if (root == NULL)
            return root;
        if (src == root->value)
        {
            return root;
        }
        else if (root->value < src)
            return  search(root->rchild, src);
        else
            return search(root->lchild, src);
    }
    node* getInoder(node* nodee)
    {
        node* current = nodee;
        while (current && current->lchild != NULL)
            current = current->lchild;

        return current;
    }
    node* deleteNode(node* root, int value)
    {
        if (root == NULL)
            return root;

        if (value < root->value)
            root->lchild = deleteNode(root->lchild, value);       //move to lchild if waord is smaller

        else if (value > root->value)
            root->rchild = deleteNode(root->rchild, value);   //move to rchild if waord is smaller
        else
        {
            if (root->lchild == NULL and root->rchild == NULL)
                return NULL;

            //node with only one child or no child
            else if (root->lchild == NULL) {
                node* temp = root->rchild;
                free(root);
                return temp;
            }
            else if (root->rchild == NULL) {
                node* temp = root->lchild;
                free(root);
                return temp;
            }

            node* temp = getInoder(root->rchild);
            root->value = temp->value;


            root->rchild = deleteNode(root->rchild, temp->value);
        }
        return root;
    }
    int Height(node* root)
    {
        queue<node*> nl;
        int h = 0;
        int count = 0;
        node* curr;

        if (root == NULL) {
            return 0;
        }
        nl.push(root);
        while (!nl.empty()) {
            h++;

            count = nl.size();
            while (count--) {
                curr = nl.front();

                if (curr->lchild != NULL)
                    nl.push(curr->lchild);

                if (curr->rchild != NULL)
                    nl.push(curr->rchild);

                nl.pop();
            }
        }
        return h - 1;
    }
   
};
int main()
{
    // string s = "ABC*+D/";
     //t.root = t.createNode(1);
     //t.root->lchild = t.createNode(9);
     //t.root->rchild = t.createNode(4);
     //t.root->lchild->rchild = t.createNode(6);
     //t.root->lchild->lchild = t.createNode(0);
     //t.root->lchild->lchild->lchild = t.createNode(3);
     //t.root->lchild->lchild->rchild = t.createNode(2);
     //t.root->lchild->lchild->rchild->lchild = t.createNode(5);
     //t.root->lchild->lchild->rchild->rchild = t.createNode(8);
    tree  t;
    node* root = NULL;
   
    /* Constructing tree given in
    the above figure */
    root=t.insertAvl(root, 10);
  t.insertAvl(root, 20);
     t.insertAvl(root, 30);
    t.insertAvl(root, 40);
    t.insertAvl(root, 50);
     t.insertAvl(root, 25);
    t.traverseinorder(root);
}

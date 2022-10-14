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
};
class tree {
public:
    node* root;

    tree() {
        root = NULL;
    }
    void insert(int ch)
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
        height(root->rchild);
        c++;
    }
    void exptree(string postfix)
    {
        stack<node*> p;
        node* v = NULL;
        for (int i = 0; i < postfix.length(); i++)
        {
            if (postfix[i] == '-' || postfix[i] == '+' || postfix[i] == '/' || postfix[i] == '*')
            {
                node* temp = createNode(postfix[i]);
                p.push(temp);
            }

            if (postfix[i] >= '0' && postfix[i] <= '9')
            {
                node *x,*y=NULL;
                v = createNode(postfix[i]);
                x = p.top();
                p.pop();
                v->rchild = x;
                y = p.top();
                p.pop();
                v->lchild = y;
                p.push(v);

            }
        }
        traverseinorder(v);
    }
    node*  lca(int a, int b)
    {
            while (root)
            {
                if (a > root->value && b > root->value)
                    root = root->rchild;
                else if (a < root->value && b < root->value)
                    root = root->lchild;
                else
                    return root;
                    
            }
            return NULL;
        }
    node* createNode(int val)
    {
        node* Node = new node;
        Node->value = val;
        Node->lchild = NULL;
        Node->rchild = NULL;
        return (Node);
    }
    void traverseinorder(node* root)
    {
        if (root == NULL)
            return;
        traverseinorder(root->lchild);
        cout << " " << root->value << " ";
        traverseinorder(root->rchild);
   }
    bool checkbst(node* root)
    {
        static bool a = true;
        static int b = 0;
        if (root == NULL)
            return false;
        checkbst(root->lchild);
        
        if (root->value >= b)
        {
            b = root->value;
        }
        else
            a = false;
        checkbst(root->rchild);
        return a;
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
        node* current=nodee;
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
    int getDiameter(node* root)
    {
        int r = Height(root->rchild);
        int l = Height(root->lchild);
        return r + l + 1;
    }
    bool checkcousin(node* t1, node* t2)
    {
        node* temp1 = t1->parent;
        node* temp2 = t2->parent;
        t1 = t1->parent->parent;
        t2 = t2->parent->parent;

        /*if (t1->parent->parent!=NULL)
            if(t2->parent->parent!=NULL)
            if(t1->parent->parent->value == t2->parent->parent->value)
            return true;
        else
            return false;*/
        if (t1 != t2)
            return false;
        else if (temp1 != temp2)
            return true;
        else
            return false;
    }

    bool trseinorder(node* root, node* roota)
    {
        if (root == NULL)
            return false;
        trseinorder(root->lchild, roota);
        if (checkcousin(root, roota))
        {
            deleteNode(root, roota->value);
            return true;
        }
        trseinorder(root->rchild, roota);
    }
    bool Delete(node* t)
    {
        /*if (trseinorder(root, t))
            return true;
        else
            return false;*/
        if (t->parent->parent != NULL)
        {
            if (t->parent->parent->lchild)
            {
                if (t->parent->parent->lchild->lchild || t->parent->parent->lchild->rchild)
                {
                    deleteNode(root, t->value);
                    return true;
                }
            }
            else if (t->parent->parent->rchild)
            {
                if (t->parent->parent->rchild->lchild || t->parent->parent->rchild->rchild)
                {
                    deleteNode(root, t->value);
                    return true;
                }
            }
            else
                return false;

        }
    }
};
int main()
{
    tree t;
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
    
        t.insert(22);   
        t.insert(4);
        t.insert(8);
        t.insert(19);
        t.insert(9);
        t.insert(1);
        t.insert(3);
        t.insert(12);
  //  t.exptree(s);
    t.traverseinorder(t.root);
    //  s.root=t.lca(3,100);
   // cout<<"\nANCESTOR IS: " << s.root->value;
    //cout << t.checkbst(t.root);
  // cout << "height is" << t.height(t.root);
}


#include <iostream>
#include<stack>
using namespace std;
class node
{
public:
    int value;
    node* lchild;
    node* rchild;
};
class tree {
public:
    node* root;

    tree() {
        root == NULL;
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
    
        t.insert(18);   
        t.insert(4);
        t.insert(8);
        t.insert(19);
        t.insert(9);
        t.insert(1);
        t.insert(3);
        t.insert(6);
        t.root->lchild->lchild->value = 100;
  //  t.exptree(s);
    t.traverseinorder(t.root);
    tree s;
    s.root=t.lca(3,100);
   // cout<<"\nANCESTOR IS: " << s.root->value;
    cout << t.checkbst(t.root);
  // cout << "height is" << t.height(t.root);
}

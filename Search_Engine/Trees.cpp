#include <iostream>
#include<stack>
using namespace std;
class treenode
{
public:
    string word;
    linkedlist links;
    treenode* lchild;
    treenode* rchild;
};
class tree {
public:
    treenode* root;

    tree() {
        root = NULL;
    }
    void insert(string ch,string l)
    {
        treenode* a = new treenode;
        a->word = ch;
        a->links.add_to_start(l);
        a->lchild = NULL;
        a->rchild = NULL;
        treenode* p = NULL;
        treenode* c = root;
        if (root == NULL)
            root = a;
        else
        {
            while (c != NULL)
            {
                p = c;
                if (a->word > c->word)
                    c = c->rchild;
                else if (a->word < c->word)
                    c = c->lchild;
                else if (a->word == c->word)
                {
                    c->links.add_to_start(l);
                    return;
                }
            }
            if (a->word > p->word)
                p->rchild = a;
            else
                p->lchild = a;
        }


    }
    bool isEmpty() 
    {
        return (root == NULL);
    }
    void traverseinorder(treenode* root)
    {
        if (root == NULL)
            return;
        traverseinorder(root->lchild);
        cout << " " << root->word << "\n";
        traverseinorder(root->rchild);
   }
    treenode* search(treenode* root,string src)
    {
        if (root == NULL )
            return root;
        if (src == root->word)
        {
            root->links.display();
            return root;
        }
        else if(root->word<src)
          return  search(root->rchild,src);
        else 
           return search(root->lchild, src);
    }
     treenode* getInoder( treenode* node)
    {
        treenode* current = node;
        while (current && current->lchild != NULL)
            current = current->lchild;

        return current;
    }
    treenode* deleteNode(treenode* root, string word)
    {
        if (root == NULL)
            return root;

        if (word < root->word)
            root->lchild = deleteNode(root->lchild, word);       //move to left if waord is smaller

        else if (word > root->word)
            root->rchild = deleteNode(root->rchild, word);   //move to right if waord is smaller
        else 
        {
            if (root->lchild == NULL and root->rchild == NULL)
                return NULL;

            //treenode with only one child or no child
            else if (root->lchild == NULL) {
               treenode* temp = root->rchild;
                free(root);
                return temp;
            }
            else if (root->rchild == NULL) {
                treenode* temp = root->lchild;
                free(root);
                return temp;
            }

            treenode* temp = getInoder(root->rchild);
            root->word = temp->word;
            root->links = temp->links;

            root->rchild = deleteNode(root->rchild, temp->word);
        }
        return root;
    }
    bool removeduplinks(treenode* root)
    {
        if (root == NULL)
            return false;
        removeduplinks(root->lchild);
        root->links.removeDuplicates();
        removeduplinks(root->rchild);
    }
};



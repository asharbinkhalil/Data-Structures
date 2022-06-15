#include <iostream>
#include<stack>
#include<queue>
using namespace std;
class treenode
{
public:
	int word;
	treenode* parent;
	treenode* lchild;
	treenode* rchild;
};
class tree {
public:
	treenode* root;
	tree() {
		root = NULL;
	}
	void insert(int ch)
	{
		treenode* a = new treenode;
		a->word = ch;
	
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
			}
			a->parent = p;
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
	treenode* search(treenode* root, int src)
	{
		if (root == NULL)
			return root;
		if (src == root->word)
		{
			return root;
		}
		else if (root->word < src)
			return  search(root->rchild, src);
		else
			return search(root->lchild, src);
	}
	treenode* getInoder(treenode* node)
	{
		treenode* current = node;
		while (current && current->lchild != NULL)
			current = current->lchild;

		return current;
	}
	treenode* deleteNode(treenode* root, int word)
	{
		if (root == NULL)
			return root;

		if (word < root->word)
			root->lchild = deleteNode(root->lchild, word);       //move to lchild if waord is smaller

		else if (word > root->word)
			root->rchild = deleteNode(root->rchild, word);   //move to rchild if waord is smaller
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
		

			root->rchild = deleteNode(root->rchild, temp->word);
		}
		return root;
	}
	int Height(treenode* root)
	{
		queue<treenode*> nl;
		int h = 0;
		int count = 0; 
		treenode* curr; 
					
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
		return h-1;
	}
	int getDiameter(treenode* root)
	{
		int r=Height(root->rchild);
		int l = Height(root->lchild);
		return r + l + 1;
	}
	bool checkcousin(treenode* t1, treenode* t2)
	{
		treenode* temp1=t1->parent;
		treenode* temp2 = t2->parent;
		t1 = t1->parent->parent;
		t2 = t2->parent->parent;

		/*if (t1->parent->parent!=NULL)
			if(t2->parent->parent!=NULL)
			if(t1->parent->parent->word == t2->parent->parent->word)
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

	bool trseinorder(treenode* root, treenode* roota)
	{
		if (root == NULL)
			return false;
		trseinorder(root->lchild, roota);
		if (checkcousin(root, roota))
		{
			deleteNode(root, roota->word);
			return true;
		}
		trseinorder(root->rchild, roota);
	}
	bool Delete(treenode* t)
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
					deleteNode(root, t->word);
					return true;
				}
			}
			else if (t->parent->parent->rchild)
			{
				if (t->parent->parent->rchild->lchild || t->parent->parent->rchild->rchild)
				{
					deleteNode(root, t->word);
					return true;
				}
			}
			else
				return false;

		}
	}
};


void main()
{
	tree t;
	t.insert(5);
	t.insert(7);
	t.insert(6);

	t.insert(8);
	t.insert(2);
	t.insert(3);
	t.insert(1);
	t.insert(0);
	
  
	t.traverseinorder(t.root);
	treenode* t1=t.search(t.root,6);
	treenode* t2 = t.search(t.root, 1);
  cout<<"HAS COUSIN: "	<<t.checkcousin(t1, t2);
	cout << "DELETE : "<<t.Delete(t1);
  
	//cout << t.root->lchild->parent->word;
	cout << "\nDiameter is : "<<t.getDiameter(t.root);
}

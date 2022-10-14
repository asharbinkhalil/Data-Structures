#include <iostream>
#include<fstream>
#include <Windows.h>
#include<string>
#include<vector>
#include<sstream>
#include"linkedLIST.cpp"
#include"Trees.cpp"
using namespace std;
void design1();
void design2();
int main()
{
	design1();    //shashky
	cout << "\t\t\t\t\tEnter file name: ";
	string  filename;
	cin >> filename;
	fstream ifile(filename+".txt",ios::in);
	if (!ifile.is_open())
	{
		cout << "\t\t\t\t\tNo such file in the directory\n";
		exit(1);
	}
	vector<string> keywords;
	string link, searchit;
	string buff = "";
	design2();     //shashky
	cout << "\t\t\t\t\tEnter any word to search: ";
	cin >> searchit;
	linkedlist list,b;
	tree bst;
	
	while (getline(ifile, buff)) {
		if (buff[0] >= '0' && buff[0] <= '9')       //skipping link line but saving it in a string
		{
			buff[0] = ' ';
			buff[1] = ' ';
			link = buff;
			continue;
		}
		if (buff.length() == 0) continue;            //skipping the space line in file

		stringstream ss(buff);
		string buff2 = "";
		b.add_to_start(link);
		while (!ss.eof()) {          //word by word reaing in this loop
			ss >> buff2;             //space by space word reading
			keywords.push_back(buff2);


			if (searchit == buff2)      //task 1 lines
				list.add_to_start(link);


			bst.insert(buff2, link);      //task 2 line
		}
		while (!b.isEmpty())    //making list everytime empty for new word in the tree task 2
		{
			b.deletefromstart();
		}
	}
	cout <<   "\t\t\t\t\t/--------------------------------------/";
	cout << "\n\t\t\t\t\t\tLinks by Task 1 (LIST).\n";
	cout << "\t\t\t\t\t/--------------------------------------/\n\n\n\n";
	list.removeDuplicates();
	list.display();

	cout << "\n\n\n";
	cout << "\t\t\t\t\t/--------------------------------------/";
	cout << "\n\t\t\t\t\t\tLinks by Task 2. (BST)\n";
	cout << "\t\t\t\t\t/--------------------------------------/\n\n\n\n";
	bst.removeduplinks(bst.root);
	bst.search(bst.root, searchit);

	cout << "\t\t\t\t\tEnter a value to delete form BST: ";
	cin >> searchit;
	bst.deleteNode(bst.root, searchit);

	bst.search(bst.root, searchit);
	
}


void design1()
{
	cout << "\t\t\t\t------------------- ASHAR KHALIL----------------------\n";
	cout << "\t\t\t\t--------------------  20K - 1724 ---------------------\n";
	cout << "\t\t\t\t---------------- DATA STRUCTURES(A) ------------------\n";
	cout << "\t\t\t\t------------------ Assignment - 03 -------------------\n\n\n";
	cout << "\t\t\t\t\t/--------------------------------------/";
	cout << "\n\t\t\t\t\t|       Search Engine by ASHAR :)      | ";
	cout << "\n\t\t\t\t\t| -> Loads data from a file.           |";
	cout << "\n\t\t\t\t\t| -> Makes a binary tree.              |";
	cout << "\n\t\t\t\t\t| -> Search a keyword.                 |";
	cout << "\n\t\t\t\t\t| -> Get all links.                    |\n";
	cout << "\t\t\t\t\t/--------------------------------------/\n\n\n\n";
}
void design2()
{
	cout << "\t\t\t\t\t/--------------------------------------/";
	cout << "\n\t\t\t\t\t\tFILE LOADED SUCESSFULLY.\n";
	cout << "\t\t\t\t\t/--------------------------------------/\n\n\n\n";
	string design = "CREATING BINARY TREE";
	cout << "\t\t\t\t\t/--------------------------------------/";
	cout << "\n\t\t\t\t\t\t";
	for (int i = 0; i < design.length(); i++)
	{
		cout << design[i];
		Sleep(100);
	}
	cout << "\n\t\t\t\t\t/--------------------------------------/\n\n\n\n";
}
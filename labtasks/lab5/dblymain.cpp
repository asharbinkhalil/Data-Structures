#include"doubly linked list.cpp"


#include <iostream>
using namespace std;
int main()
{
    std::cout << "DOUBLY LINKED LIST!\n";
    doublylinkedlist obj;
    for (int i = 1; i <10; i++)
        obj.add_to_end(i);

    for (int i = 1; i < 10; i++)
        obj.add_to_end(i);


    obj.display();
    //   obj.deletebyval(7);
    cout << "duplicate removed :";
      obj.removedupplcate();

   // obj.func();
  //  obj.swapnodesbyindex(2, 3);
    obj.display();
}

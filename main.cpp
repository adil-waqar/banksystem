#include<iostream>
#include<iomanip>
using namespace std;
#include "_inc/datastructs.h"

int main(){
  bst avl1;
  bst* root = NULL;
  root = avl1.insert(2, root);
  root = avl1.insert(5, root);
  root = avl1.insert(7, root);
  root = avl1.remove(root, 5);
  avl1.display(root);

}

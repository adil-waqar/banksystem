#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
#include "E:\CS221\_inc\datastructs.h" // Add your own path here

class manager{
  private:
  int id;
  string password;
  float amount;
  user users;
  public:
  manager(int, string, float);
  user* openAccount(int, string, string, float, float, string, user* ); // id, password, name, amount, interest, type
  void depositAmount(int, float, user*);  // id, amount, root
  void setInterest(int, float, user*);
  void applyInterest(int, user*);
  void applyZakat(user*);
  void test(user*);

};

manager::manager(int id, string pass, float amount){
  this ->  id = id;
  this -> password = pass;
  this -> amount = amount;
}

user* manager::openAccount(int id, string pass, string name, float amount, float interest, string type, user* root){
  user* temp = users.insert(id, pass, name, amount, interest, type, root );
  return temp;
}

void manager::depositAmount(int id, float amount, user* root){
  user* user_find = users.search(id, root);
  if(user_find){
    user_find -> depositAmount(amount);
  } else cout << "User not found!" << endl;

}

void manager::setInterest(int id, float interest, user* root){
  user* user_find = users.search(id, root);
  user_find -> setInterest(interest);
}

void manager::applyInterest(int id, user* root){
  user* user_find = users.search(id, root);
  float newAmount = user_find -> getAmount() * ((user_find -> getInterest())/100) + user_find -> getAmount();
  //cout << newAmount;
   user_find -> setAmount(newAmount);
}

void manager::applyZakat(user* root){
  
}

void manager::test(user* root){
  users.display(root);
}

int main(){
  manager boy(1, "123", 500);
  user* root = NULL;
  root = boy.openAccount(1, "tom", "Adil", 100.0, 00.0, "Sav", root);
  root = boy.openAccount(2, "tom", "Adil", 129.0, 00.0, "Sav", root);
  root = boy.openAccount(3, "tom", "Adil", 566.6, 00.0, "Sav", root);
  boy.setInterest(1, 12.00, root);
  boy.applyInterest(1, root);
   boy.test(root);
}

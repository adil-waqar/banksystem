#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;
int transId = 500;
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
  void write(user*, ofstream&);
  user* read(user*, ifstream&);

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
    user_find -> transactions(transId, 0, 0, amount, "Deposit");
    transId++;
  } else cout << "User not found!" << endl;

}

void manager::setInterest(int id, float interest, user* root){
  user* user_find = users.search(id, root);
  user_find -> setInterest(interest);
}

void manager::applyInterest(int id, user* root){
  user* user_find = users.search(id, root);
  float newAmount = user_find -> getAmount() * ((user_find -> getInterest())/100) + user_find -> getAmount();
   user_find -> setAmount(newAmount);
}

void manager::applyZakat(user* root){
  users.zakat(root);
}

void manager::test(user* root){
  users.display(root);
}

// void manager::write(user* root, ofstream &outFile){
//   if (root == NULL) return;
//   // write(root -> left, outFile);
// }

void user::withdraw(int id, float amount, user* root){
  user* user_find = search(id, root);
  if (amount <= user_find -> getAmount() && user_find) {
    user_find -> setAmount(user_find -> getAmount() - amount);
    user_find -> transaction.insert(transId, 0,0,amount, "Withdrawl");
    transId++;
  } else cout << "Amount is greater than available balance or user id incorrect. " << endl;
}

void user::transfer(int from, int to, float amount, user* root){
  user* from_u = search(from, root);
  user* to_u = search(to, root);
  if (from_u && to_u) {
    if (from_u -> getAmount() >= amount) {
      from_u -> setAmount(from_u -> getAmount() - amount);
      to_u -> depositAmount(amount);
      from_u -> transaction.insert(transId, from, to, amount, "Transfer/Withdrawl");
      to_u -> transaction.insert(transId,from, to, amount, "Transfer/Deposit" );
      transId++;
    } else cout << "Amount is insufficient. " <<endl;

  } else cout <<"Either user id is incorrent or user doesn't exist. " <<endl;
}

user* manager::read(user* root, ifstream &inFile){
  int id;
  string password;
  string name;
  float amount;
  float interest;
  string type;
  while (inFile >> id >> password >> name >> amount >> interest >> type ) {
    root = openAccount(id, password, name, amount, interest, type, root);
  }
  return root;
}


int main(){
  // manager declarations
  manager boy(0, "123", 500);

  // Reading data from file

  ifstream inFile;
  inFile.open("data/users.txt");
  user* root = NULL; // User tree declarations
  root = boy.read(root, inFile);
  inFile.close();
  // End of reading
  // Manager changing stuff
  boy.setInterest(1, 11.00, root);
  boy.setInterest(2, 10.00, root);
  boy.applyInterest(2, root);
  boy.applyInterest(2, root);
  boy.applyInterest(1, root);
  boy.applyZakat(root);

  // Writing to file
  ofstream outFile("data/users.txt");
  user girl;
  girl.writeUsers(root, outFile);
  outFile.close();

  //  boy.test(root);
  // boy.depositAmount(3, 60, root);
  // girl.withdraw(3, 80, root);
  // girl.transfer(3, 2, 50, root);
  // cout << "User 3 transactions: " <<endl;
  //
  // girl.sortTransByAmount(3, root);
  // cout << "Sorted by Amount: " <<endl;
  // girl.printTrans(3, root);
  // cout << endl;
  // girl.sortTransById(3, root);
  // cout << "Sorted by ID: " <<endl;
  // girl.printTrans(3, root);
}

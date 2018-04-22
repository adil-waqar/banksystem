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
  void openAccount();
  void depositAmount();
  void setInterest();
  void applyInterest();
  void applyZakat();

};

manager::manager(int id, string pass, float amount){
  this ->  id = id;
  this -> password = pass;
  this -> amount = amount;
}

int main(){

}

#include<iostream>
#include<string>
using namespace std;

class user{
  private:
    user* left;
    user* right;
    int data; // This is the id
    string password;
    string name;
    float amount;
    float interest;
    string type;

  public:
    user* insert(int, string, string, float, float, string, user*);  // id, password, name, amount, interest, type
    user* search(int, user*);
    void display(user*);
    user* min(user*);
    void max(user*);
    int height(user*);
    user* remove(user*, int);
    user* right_rot(user*);
    user* left_rot(user*);
    user* lr_rot(user*);
    user* rl_rot(user*);
    float getAmount();
    void setAmount(int);
    void setInterest(float);
    float getInterest();
    void depositAmount(int);
    void zakat(user*);
    void showBal(int, user*);
    void withdraw(int, float, user*);

};

void user::withdraw(int id, float amount, user* root){
  user* user_find = search(id, root);
  if (amount <= user_find -> getAmount() && user_find) {
    user_find -> setAmount(user_find -> getAmount() - amount);
  } else cout << "Amount is greater than available balance or user id incorrect. " << endl;
}

void user::showBal(int id, user* root){
  user* user_find = search(id, root);
  if (user_find) cout << "Your current balance is: "<< user_find -> getAmount() << endl;
  else cout << "User not found! "<<endl;

}

void user::zakat(user* root){
  if (root == NULL) {
    return;
  }
  zakat(root -> left);
  if (root -> amount >= 40000) {
    root -> amount = root -> amount - 0.025 * root -> amount;
  }
  zakat(root -> right);
}

void user::depositAmount(int amounts){
  amount = amount + amounts;
}

float user::getInterest(){
  return interest;
}

float user::getAmount(){
  return amount;
}

void user::setAmount(int amounts){
  amount =  amounts;
}

void user::setInterest(float interests){
  interest = interests;
}

user* user::right_rot(user* t){
  user* u = t -> left;
  t -> left = u -> right;
  u ->right = t;
  return u;

}

user* user::left_rot(user* t){
  user* u = t -> right;
  t -> right = u -> left;
  u -> left = t;
  return u;
}

user* user::rl_rot(user* t){
  t -> right = right_rot(t -> right);
  return left_rot(t);
}

user* user::lr_rot(user* t){
  t -> left = left_rot( t-> left);
  return right_rot(t);
}

user* user::remove(user* root, int data){
        // base case
        if (root == NULL) {
                cout << "COURSE NOT FOUND." <<endl;
                return root;
        } else if (data > root->data) {
                root->right = remove(root->right, data);
        } else if(data < root->data) {
                root->left = remove(root->left, data);
        } else{
                // three cases
                // Case 1: No child
                if(root->left == NULL && root->right == NULL) {
                        delete root;
                        root = NULL;
                }

                // Case 2: One child
                else if(root->left == NULL) {
                        user* temp = root;
                        root = root->right;
                        delete temp;

                } else if(root->right == NULL) {
                        user* temp = root;
                        root = root->left;
                        delete temp;
                } else { // Case 3: Two children
                        user* temp = min(root->right);
                        root->data = temp->data;
                        root->right = remove(root->right, temp->data);
                }

        }

        if(root == NULL)
            return root;

        if(height(root->left) - height(root->right) == 2)
        {
                // right right case

                if(height(root->left->left) - height(root->left->right) == 1)
                        return left_rot(root);
                // right left case
                else
                        return rl_rot(root);
        }
        // If right node is deleted, left case
        else if(height(root->right) - height(root->left) == 2)
        {

                // left left case
                cout << "sfd";
                if(height(root->right->right) - height(root->right->left) == 1)
                        return right_rot(root);
                // left right case
                else
                        return lr_rot(root);
        }

        return root;


}

user* user::insert(int data, string pass, string name, float amount, float interest, string type, user* root){  // id, password, name, amount, interest, type
  if ( root == NULL) {
    user* temp = new user();
    temp -> data = data;
    temp -> password = pass;
    temp -> name = name;
    temp -> amount = amount;
    temp -> interest = interest;
    temp -> type = type;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
  } else if( data < root -> data){
    root -> left = insert(data, pass, name, amount, interest, type, root-> left);
    if (height(root -> left) - height(root -> right) == 2) {
      if ( data < root -> left -> data) {
        root = right_rot(root);
      } else root =  lr_rot(root);
    }
  } else{
    root -> right = insert(data, pass, name, amount, interest, type, root -> right);
    if (height(root -> right) - height(root -> left) == 2) {
      if (data > root -> right -> data ) {
        root = left_rot(root);
      } else root = rl_rot(root);
    }
  }
  return root;
}



user* user::search(int data, user* root){
  if (root  == NULL) {
    // cout<< "DATA NOT FOUND! "<<endl;
    return NULL;
  } else if( root -> data == data){
    // cout<<" DATA FOUND"<<endl;
    return root;
  }
   else if( data > root -> data){
    search(data,  root -> right);
  } else if (data < root -> data){
    search(data, root -> left);
  }

}

void user::display(user* root){
  if ( root == NULL) return;
  display( root -> left);
  cout << root -> amount << "\t"<<height(root) <<endl;
  display(root -> right);
}

user* user::min(user* root){
  while( root -> left != NULL){
    root = root -> left;
  }
  return root;
}

void user::max(user* root){
  while( root -> right != NULL){
    root = root -> right;
  }
  cout<< endl;
  cout<< "The max is: "<< root -> data;
}

int user::height(user* root ){
  // base case
  if (root == NULL) {
    return -1;
  }
  else{
  int ldepth = height(root -> left);
  int rdepth = height(root -> right);

  if (ldepth > rdepth) {
    return (ldepth + 1);
  } else return (rdepth + 1);
}
}

class transactions{
    private:
       struct node{
           int val;
           node *next;
       };
         node *Head;
    public:
        transactions();
        void insert(int);
        void display();
        void search(int);
        void deleteNode(int);
          ~transactions()
          {
              node *temp;
              while(temp)
              {
                  temp = this->Head;
                  this->Head = this->Head->next;
                  delete temp;
              }
          }
};


transactions::transactions()
{
    this->Head = NULL;
}

void transactions::insert(int val)
{
    node *newPtr = new node(), *temp = this->Head;
    newPtr->val = val;
    newPtr->next = NULL;
    if(!this->Head)
    {
        this->Head = newPtr;
        return;
    }
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = newPtr;
    return;

}

void transactions::display()
{
    node *temp = this->Head;
    while(temp)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
    return;
}

void transactions::deleteNode(int val)
{
    node *curr = this->Head, *prev = NULL;
    while(curr && curr->val != val)
    {
        prev = curr;
        curr = curr->next;
    }
    if(!curr)
    {
        cout << "Cannot Delete.\n";
        return;
    }
    if(curr == this->Head)
    {
        this->Head = this->Head->next;
    }
    else
        prev->next = curr->next;
    delete curr;

}

class bst{
  private:
    bst* left;
    bst* right;
    int data;

  public:
    bst* insert(int, bst*);
    void search(int, bst*);
    void display(bst*);
    bst* min(bst*);
    void max(bst*);
    int height(bst*);
    bst* remove(bst*, int);
};

bst* bst::remove(bst* root, int data){
  // base case
  if (root == NULL) {
    cout << "DATA NOT FOUND." <<endl;
    return root;
  } else if (data > root -> data) {
    root -> right = remove(root -> right, data);
  } else if(data < root -> data){
    root -> left = remove(root -> left, data);
  } else{
    // three cases
    // Case 1: No child
    if(root -> left == NULL && root -> right == NULL){
      delete root;
      root = NULL;
    }

    // Case 2: One child
    else if(root -> left == NULL){
      bst* temp = root;
      root = root -> right;
      delete temp;

    } else if(root -> right == NULL){
      bst* temp = root;
      root = root -> left;
      delete temp;
    } else { // Case 3: Two children
      bst* temp = min(root -> right);
      root -> data = temp -> data;
      root -> right = remove(root -> right, temp -> data);
    }

  }
  return root;
}

bst* bst::insert(int data, bst* root){
  if ( root == NULL) {
    bst* temp = new bst();
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
  } else if( data < root -> data){
    root -> left = insert(data, root-> left);
  } else{
    root -> right = insert(data, root -> right);
  }
}

void bst::search(int data, bst* root){
  if (root  == NULL) {
    cout<< "DATA NOT FOUND! "<<endl;
    return;
  } else if( root -> data == data){
    cout<<" DATA FOUND"<<endl;
    return;
  }
   else if( data > root -> data){
    search(data, root -> right);
  } else if (data < root -> data){
    search(data, root -> left);
  }

}

void bst::display(bst* root){
  if ( root == NULL) return;
  display( root -> left);
  cout << root -> data << "\t";
  display(root -> right);
}

bst* bst::min(bst* root){
  while( root -> left != NULL){
    root = root -> left;
  }
  return root;
}

void bst::max(bst* root){
  while( root -> right != NULL){
    root = root -> right;
  }
  cout<< endl;
  cout<< "The max is: "<< root -> data;
}

int bst::height(bst* root ){
  // base case
  if (root == NULL) {
    return -1;
  }
  else{
  int ldepth = height(root -> left);
  int rdepth = height(root -> right);

  if (ldepth > rdepth) {
    return (ldepth + 1);
  } else return (rdepth + 1);
}
}

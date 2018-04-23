#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct node{
    int id;
    int from;
    int to;
    float amount;
    string typeTrans;
    node *next;
};

class transactions{
    private:

         node *Head;
         node *Tail;
    public:
        transactions();
        void insert(int, int, int, float, string);
        void display();
        void search(int);
        void deleteNode(int);
        // sorting functions
        void mergeById(transactions,node*,node*,node*); //
    		void mergeSortById(transactions, node*,node*); //sort
    		void sortById(transactions n); //
        void mergeByAmount(transactions,node*,node*,node*); //
    		void mergeSortByAmount(transactions, node*,node*); //sort
    		void sortByAmount(transactions n); //
    		node* findMiddle(node *start, node *end); // copy
          // ~transactions()
          // {
          //     node *temp;
          //     while(temp)
          //     {
          //         temp = this -> Head;
          //         this -> Head = this -> Head ->next;
          //         delete temp;
          //     }
          // }
};


transactions::transactions()
{
    this -> Head = NULL;
    this -> Tail = NULL;
}

// Sorting
node* transactions::findMiddle(node *start, node *end)
{
	node *temp1 = start, *temp2 = start;
    while(temp1 != end && temp1->next != end && temp1->next != NULL)
    {
    	temp1 = temp1->next->next;
    	temp2 = temp2->next;
	}
	return temp2;
}
void transactions::mergeById(transactions n, node *left, node *mid, node *right)
{
     transactions temp1,temp2;
     temp1.Head = left;
     temp1.Tail = mid;
     temp2.Head = mid->next;
     temp2.Tail = right;

     node *i = left;
     node *j = mid->next;
     transactions temp;
     while(i != temp1.Tail->next && j != temp2.Tail->next)
     {
     	if(i->id < j->id)
     	{
     		temp.insert(i->id, i -> from, i -> to, i -> amount, i -> typeTrans);
     		i = i->next;
		 }
		 else
		 {
		 	temp.insert(j->id, j -> from, j -> to, j -> amount, j -> typeTrans);
		 	j = j->next;
		 }
	 }

	 while(i != temp1.Tail->next)
	 {
	 	temp.insert(i->id, i -> from, i -> to, i -> amount, i -> typeTrans);
	 	i = i->next;
	 }
	 while(j != temp2.Tail->next)
	 {
	 	temp.insert(j->id, j -> from, j -> to, j -> amount, j -> typeTrans);
	 	j = j->next;
	 }

	 node *y = temp.Head;
	 for(node *x = left; x != right->next; x = x->next)
	 {
	 	x->id = y->id; // Changes
    x -> from = y -> from;
    x -> to = y -> to;
    x -> amount = y -> amount;
    x -> typeTrans = y -> typeTrans;
	 	y = y->next;
	 }
}
void transactions::mergeSortById(transactions n, node *left, node *right)
{
	if(left != right)
	{
		node *mid = this->findMiddle(left, right);
		this->mergeSortById(n, left, mid);
		this->mergeSortById(n, mid->next, right);
		this->mergeById(n, left, mid,right);
	}
}
void transactions::sortById(transactions n)
{
	this->mergeSortById(n,this->Head, this->Tail);
}

void transactions::mergeByAmount(transactions n, node *left, node *mid, node *right)
{
     transactions temp1,temp2;
     temp1.Head = left;
     temp1.Tail = mid;
     temp2.Head = mid->next;
     temp2.Tail = right;

     node *i = left;
     node *j = mid->next;
     transactions temp;
     while(i != temp1.Tail->next && j != temp2.Tail->next)
     {
     	if(i->amount < j->amount)
     	{
     		temp.insert(i->id, i -> from, i -> to, i -> amount, i -> typeTrans);
     		i = i->next;
		 }
		 else
		 {
		 	temp.insert(j->id, j -> from, j -> to, j -> amount, j -> typeTrans);
		 	j = j->next;
		 }
	 }

	 while(i != temp1.Tail->next)
	 {
	 	temp.insert(i->id, i -> from, i -> to, i -> amount, i -> typeTrans);
	 	i = i->next;
	 }
	 while(j != temp2.Tail->next)
	 {
	 	temp.insert(j->id, j -> from, j -> to, j -> amount, j -> typeTrans);
	 	j = j->next;
	 }

	 node *y = temp.Head;
	 for(node *x = left; x != right->next; x = x->next)
	 {
	 	x->id = y->id; // Changes
    x -> from = y -> from;
    x -> to = y -> to;
    x -> amount = y -> amount;
    x -> typeTrans = y -> typeTrans;
	 	y = y->next;
	 }
}
void transactions::mergeSortByAmount(transactions n, node *left, node *right)
{
	if(left != right)
	{
		node *mid = this->findMiddle(left, right);
		this->mergeSortByAmount(n, left, mid);
		this->mergeSortByAmount(n, mid->next, right);
		this->mergeByAmount(n, left, mid,right);
	}
}
void transactions::sortByAmount(transactions n)
{
	this->mergeSortByAmount(n,this->Head, this->Tail);
}

void transactions::insert(int id, int from, int to, float amount, string typeTrans)
{
	node *newPtr= new node();
	newPtr->id = id;
  newPtr->from = from;
  newPtr->to = to;
  newPtr -> amount = amount;
  newPtr->typeTrans = typeTrans;

	newPtr->next = NULL;
	if(this->Head == NULL)
	{
		this->Head = this->Tail = newPtr;
		return;
	}
	this->Tail->next = newPtr;
	this->Tail = newPtr;
	return;

}

void transactions::display()
{
    node *temp = this -> Head;
    while(temp)
    {
        cout << temp -> id << '\t' << temp -> from << '\t'<< temp -> to << '\t'<< temp -> amount << '\t' << temp -> typeTrans <<endl;
        temp = temp -> next;
    }
    return;
}

void transactions::deleteNode(int id)
{
    node *curr = this -> Head, *prev = NULL;
    while(curr && curr -> id != id)
    {
        prev = curr;
        curr = curr -> next;
    }
    if(!curr)
    {
        cout << "Cannot Delete.\n";
        return;
    }
    if(curr == this -> Head)
    {
        this -> Head = this -> Head-> next;
    }
    else
        prev -> next = curr -> next;
    delete curr;

}


class user{
  private:
    user* left;
    user* right;
    transactions transaction;
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
    // Functions for user
    float getAmount();
    void setAmount(int);
    void setInterest(float);
    float getInterest();
    void depositAmount(int);
    void zakat(user*);
    void showBal(int, user*);
    void withdraw(int, float, user*);
    void transfer(int, int, float, user*);
    void transactions(int, int, int, float, string);
    void printTrans(int id, user*);
    void sortTransById(int id, user*);
    void sortTransByAmount(int id, user*);
    void writeUsers(user*, ofstream&);

};

void user::writeUsers(user* root, ofstream &outFile){
  if (root == NULL) return;
  writeUsers(root -> left, outFile);
  outFile << root -> data <<" " << root -> password << " " << root -> name << " " << root -> amount << " " << root -> interest << " " << root -> type << endl;
  writeUsers(root -> right, outFile);
}

void user::sortTransByAmount(int id, user* root){
  user* user_find = search(id, root);
  user_find -> transaction.sortByAmount(transaction);
}

void user::sortTransById(int id, user* root){
  user* user_find = search(id, root);
  user_find -> transaction.sortById(transaction);
}


void user::printTrans(int id, user* root){
  user* user_find = search(id, root);
  user_find -> transaction.display();
}

void user::transactions(int id, int from, int to, float amount, string typeTrans){
  transaction.insert(id, from, to, amount, typeTrans);
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
  cout << root -> data  <<'\t' <<root -> password<< '\t' << root -> name << '\t' <<root -> amount << '\t' <<root -> interest << '\t' <<root -> type << endl;
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

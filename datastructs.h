class tree{
  private:
    tree* left;
    tree* right;
    int data;

  public:
    tree* insertAvl(int, tree*);
    tree* insertBst(int, tree*);
    void search(int, tree*);
    void display(tree*);
    tree* min(tree*);
    void max(tree*);
    int height(tree*);
    tree* remove(tree*, int);
    tree* right_rot(tree*);
    tree* left_rot(tree*);
    tree* lr_rot(tree*);
    tree* rl_rot(tree*);

};


tree* tree::right_rot(tree* t){
  tree* u = t -> left;
  t -> left = u -> right;
  u ->right = t;
  return u;

}

tree* tree::left_rot(tree* t){
  tree* u = t -> right;
  t -> right = u -> left;
  u -> left = t;
  return u;
}

tree* tree::rl_rot(tree* t){
  t -> right = right_rot(t -> right);
  return left_rot(t);
}

tree* tree::lr_rot(tree* t){
  t -> left = left_rot( t-> left);
  return right_rot(t);
}

tree* tree::remove(tree* root, int data){
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
      tree* temp = root;
      root = root -> right;
      delete temp;

    } else if(root -> right == NULL){
      tree* temp = root;
      root = root -> left;
      delete temp;
    } else { // Case 3: Two children
      tree* temp = min(root -> right);
      root -> data = temp -> data;
      root -> right = remove(root -> right, temp -> data);
    }

  }
  return root;
}

tree* tree::insertAvl(int data, tree* root){
  if ( root == NULL) {
    tree* temp = new tree();
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
  } else if( data < root -> data){
    root -> left = insertAvl(data, root-> left);
    if (height(root -> left) - height(root -> right) == 2) {
      if ( data < root -> left -> data) {
        root = right_rot(root);
      } else root =  lr_rot(root);
    }
  } else{
    root -> right = insertAvl(data, root -> right);
    if (height(root -> right) - height(root -> left) == 2) {
      if (data > root -> right -> data ) {
        root = left_rot(root);
      } else root = rl_rot(root);
    }
  }
  return root;
}

tree* tree::insertBst(int data, tree* root){
  if ( root == NULL) {
    tree* temp = new tree();
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


void tree::search(int data, tree* root){
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

void tree::display(tree* root){
  if ( root == NULL) return;
  display( root -> left);
  cout << root -> data << "\t";
  display(root -> right);
}

tree* tree::min(tree* root){
  while( root -> left != NULL){
    root = root -> left;
  }
  return root;
}

void tree::max(tree* root){
  while( root -> right != NULL){
    root = root -> right;
  }
  cout<< endl;
  cout<< "The max is: "<< root -> data;
}

int tree::height(tree* root ){
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

class List{
    private:
       struct node{
           int val;
           node *next;
       };
         node *Head;
    public:
        List();
        void insert(int);
        void display();
        void search(int);
        void deleteNode(int);
          ~List()
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


List::List()
{
    this->Head = NULL;
}

void List::insert(int val)
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

void List::display()
{
    node *temp = this->Head;
    while(temp)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
    return;
}

void List::deleteNode(int val)
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

class avl{
  private:
    avl* left;
    avl* right;
    int data;

  public:
    avl* insert(int, avl*);
    void search(int, avl*);
    void display(avl*);
    avl* min(avl*);
    void max(avl*);
    int height(avl*);
    avl* remove(avl*, int);
    avl* right_rot(avl*);
    avl* left_rot(avl*);
    avl* lr_rot(avl*);
    avl* rl_rot(avl*);

};


avl* avl::right_rot(avl* t){
  avl* u = t -> left;
  t -> left = u -> right;
  u ->right = t;
  return u;

}

avl* avl::left_rot(avl* t){
  avl* u = t -> right;
  t -> right = u -> left;
  u -> left = t;
  return u;
}

avl* avl::rl_rot(avl* t){
  t -> right = right_rot(t -> right);
  return left_rot(t);
}

avl* avl::lr_rot(avl* t){
  t -> left = left_rot( t-> left);
  return right_rot(t);
}

avl* avl::remove(avl* root, int data){
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
      avl* temp = root;
      root = root -> right;
      delete temp;

    } else if(root -> right == NULL){
      avl* temp = root;
      root = root -> left;
      delete temp;
    } else { // Case 3: Two children
      avl* temp = min(root -> right);
      root -> data = temp -> data;
      root -> right = remove(root -> right, temp -> data);
    }

  }
  return root;
}

avl* avl::insert(int data, avl* root){
  if ( root == NULL) {
    avl* temp = new avl();
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
  } else if( data < root -> data){
    root -> left = insert(data, root-> left);
    if (height(root -> left) - height(root -> right) == 2) {
      if ( data < root -> left -> data) {
        root = right_rot(root);
      } else root =  lr_rot(root);
    }
  } else{
    root -> right = insert(data, root -> right);
    if (height(root -> right) - height(root -> left) == 2) {
      if (data > root -> right -> data ) {
        root = left_rot(root);
      } else root = rl_rot(root);
    }
  }
  return root;
}



void avl::search(int data, avl* root){
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

void avl::display(avl* root){
  if ( root == NULL) return;
  display( root -> left);
  cout << root -> data << "\t"<<height(root) <<endl;
  display(root -> right);
}

avl* avl::min(avl* root){
  while( root -> left != NULL){
    root = root -> left;
  }
  return root;
}

void avl::max(avl* root){
  while( root -> right != NULL){
    root = root -> right;
  }
  cout<< endl;
  cout<< "The max is: "<< root -> data;
}

int avl::height(avl* root ){
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

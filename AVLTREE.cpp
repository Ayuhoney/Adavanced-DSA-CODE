#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int key;
    Node* left;
    Node* right;
    int height;
};
int max(int a, int b){
    return (a > b) ? a : b;
}
int height(Node* node){
    if(!node)return 0;
    return node->height;
}
Node* newNode(int key){
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
Node *rightRotated(Node* y){
   Node* x = y->left;
   Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    x->height = 1 + max(height(x->left),height(x->right));
    y->height = 1 + max(height(y->left),height(y->right));

    return x;
}
Node* leftRotated(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + max(height(x->left),height(x->right));
    y->height = 1 + max(height(y->left),height(y->right));
    return y;
}
int getBalance(Node* node){

    if(!node) return 0;
    return height(node->left) - height(node->right);
}

Node* insert(Node* node , int key){
   
     if(node == NULL){
         return (newNode(key));
     }
     if(node->key > key){
         node->left = insert(node->left,key);
     }else if(node->key < key){
         node->right = insert(node->right ,key);
     }
     else return node;
    
    node->height = 1+max(height(node->left),height(node->right));
     int bf = getBalance(node);

     if(bf > 1){
         if(key < node->left->key){
             return rightRotated(node);
        }else if( key > node->left->key){
            node->left = leftRotated(node->left);
            return rightRotated(node);
        }
     }
     if(bf < -1){
         if(key > node->right->key){
             return leftRotated(node);
         }
         else if( key < node->right->key){
             node->right = rightRotated(node->right);
             return leftRotated(node);
         }
     }
     return node;
}
Node* NodeWitMaxValue(Node* node){
    Node* current = node;
    
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}
Node* deleted(Node* node ,int key){

    if(!node){
        return node;
    }
    if(node->key > key){
        node->left = deleted(node->left,key);
    }else if(node->key < key){
        node->right = deleted(node->right,key);
    }
    else{

        if((node->left == NULL) || (node->right == NULL)){

            Node* temp = node->left ? node->left : node->right;

            if(temp == NULL){
                temp = node;
                node = NULL;
            }else{
                *node = *temp;
                free(temp);
            }
        }else{
            Node* temp = NodeWitMaxValue(node->left);
            node->key = temp->key;
            node->left = deleted(node->left, temp->key);
        }
     }
     if(node == NULL) return node;

     node->height = 1+max(height(node->left),height(node->right));
     int bf = getBalance(node);

     if( bf > 1){
         if(getBalance(node->left) >= 0){
             return rightRotated(node);
         }else{
             node->left = leftRotated(node->left);
             return rightRotated(node);
         }
     }
     if( bf < -1){
         if(getBalance(node->right) <= 0){
             return leftRotated(node);
         }else{
             node->right = rightRotated(node->right);
             return leftRotated(node);
         }
     }
     return node;
  }
void printTree(Node *root, string indent, bool last) {
  if (root != nullptr) {
    cout << indent;
    if (last) {
      cout << "R----";
      indent += "   ";
    } else {
      cout << "L----";
      indent += "|  ";
    }
    cout << root->key << endl;
    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
  }
}

int main(){
  Node *root = NULL;
  root = insert(root, 33);
  root = insert(root, 13);
  root = insert(root, 53);
  root = insert(root, 9);
  root = insert(root, 21);
  root = insert(root, 61);
  root = insert(root, 8);
  root = insert(root, 11);
  printTree(root, "", true);
  root = deleted(root, 13);
  cout << "After deleting " << endl;
  printTree(root, "", true);

}


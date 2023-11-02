#include<bits/stdc++.h>
using namespace std;

template<typename T,int M>
class Btree{
    public:

    struct Node{

        vector<T>keys;
        vector<Node*>children;
        bool leaf;

        Node(bool isLeaf) : leaf(isLeaf){
            keys.reserve(M-1);
            children.reserve(M);
        }
    };
    
    Node* root;

    Btree() : root(nullptr){}

    void insert(const T& key){

        if(root == nullptr){
            root = new Node(true);
            root->keys.push_back(key);
            return;
        }
        Node* node = root;
        Node* parent  = nullptr;


        while(!node->leaf){

            parent = node;
            int i=0;

            while(i < node->keys.size() && key  > node->keys[i]){
                 ++i; 
           }
           node = node->children[i];
        }
         //if leaf node
         int i=0;
         while(i < node->keys.size() && key > node->keys[i]){
             ++i;
         }

         node->keys.insert(node->keys.begin()+i,key);
         if(node->keys.size() == M-1){
             split(node,parent);
         }
    }
 //--------------------------------------------------------------------------------------------   
    void split(Node* node , Node* parent){

        int mid = node->keys.size()/2;

        Node* left = new Node(node->leaf);
        Node* right = new Node(node->leaf);

        left->keys.assign(node->keys.begin(), node->keys.begin()+mid);
        right->keys.assign(node->keys.begin()+mid+1, node->keys.end());

        if(!node->leaf){

            left->children.assign(node->children.begin(),node->children.begin()+mid+1);
            right->children.assign(node->children.begin()+mid+1,node->children.end());
        }

        if(parent == nullptr){

            root = new Node(false);
            root->keys.push_back(node->keys[mid]);
            root->children.push_back(left);
            root->children.push_back(right);
        }else{
            int i=0;

            while(i < node->keys.size() && parent->keys[i]  < node->keys[mid]){
                ++i;
            }

            /*vector<int>vect{1,2,3,5};
              vect.insert(vect.begin() + 3, 4);*/
            /*OutPut: 1 2 3 {4} 5 
              index   0 1 2  3  4 */

            parent->keys.insert(parent->keys.begin()+i,node->keys[mid]);
            parent->children.erase(parent->children.begin()+i);
            
            //merging  children value
            parent->children.insert(parent->children.begin()+i,left);
            parent->children.insert(parent->children.begin()+i+1,right);
        }
        node->keys.erase(node->keys.begin()+mid);
        node->children.erase(node->children.begin()+mid+1);

        delete node;
    }
//---------------------------------------------------------------------------------------
    void deleteNode(const T& key) {
    if (root == nullptr) {
        return;
    }
    deleteNode(root, key, nullptr);
}

void deleteNode(Node* node, const T& key, Node* parent) {

    if (node == nullptr) return;
    int i = 0;

    while (i < node->keys.size() && key > node->keys[i]) {
        ++i;
    }

    if (i < node->keys.size() && key == node->keys[i]) {

        if (node->leaf) {
            node->keys.erase(node->keys.begin() + i);
        } else {
           
            // Replace the key with its predecessor or successor
            if (node->children[i]->keys.size() >= M / 2) {

                T predecessor = findPredecessor(node, i);
                node->keys[i] = predecessor;
                deleteNode(node->children[i], predecessor, node);

            } else if (node->children[i + 1]->keys.size() >= M / 2) {

                T successor = findSuccessor(node, i);
                node->keys[i] = successor;
                deleteNode(node->children[i + 1], successor, node);
                
            } else {
                // Merge the key and the right child into the left child
                mergeNodes(node, i);
                // Recursively delete the key from the merged child
                deleteNode(node->children[i], key, node);
            }
        }
    } else {
        deleteNode(node->children[i], key, node);
    }
}

T findPredecessor(Node* node, int index) {
    Node* current = node->children[index];
    while (!current->leaf) {
        current = current->children[current->keys.size()];
    }
    return current->keys.back();
}

T findSuccessor(Node* node, int index) {
    Node* current = node->children[index + 1];
    while (!current->leaf) {
        current = current->children[0];
    }
    return current->keys.front();
}

void mergeNodes(Node* node, int index) {

    Node* left = node->children[index];
    Node* right = node->children[index + 1];

    left->keys.push_back(node->keys[index]);
    left->keys.insert(left->keys.end(), right->keys.begin(), right->keys.end());

    left->children.insert(left->children.end(), right->children.begin(), right->children.end());
    node->keys.erase(node->keys.begin() + index);
    
    node->children.erase(node->children.begin() + index + 1);
    delete right;
}

     bool search(const T& key){

         Node* node  = root;
         while(node != nullptr){
             int i=0;
             while( i < node->keys.size() && key > node->keys[i]){
                 ++i;
             }
             if(i < node->keys.size() && key == node->keys[i] ){
                 return true;
             }
             node  = node->leaf ? nullptr : node->children[i];
         }
         return false;
     }
     void print(){
         if(root != nullptr){
             print(root);
         }
     }
    void print(const Node* node ,int depth =0){

        if(node != nullptr){
            for(auto key : node->keys){
                cout<<key<<' ';
            }
            cout<<'\n';
            if(!node->leaf){
                for(auto child : node->children){
                    print(child,depth+1);
                }
            }
        }
    }
};

signed main(){

     Btree<int, 2> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.print();

    std::cout << "Is 3 in the tree? " << std::boolalpha << tree.search(3) << '\n';
    std::cout << "Is 10 in the tree? " << std::boolalpha << tree.search(10) << '\n';

    cout<<"deleted key"<<endl;
    tree.deleteNode(2);
    tree.deleteNode(1);
    tree.print();


}

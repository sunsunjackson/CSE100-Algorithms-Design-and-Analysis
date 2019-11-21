//collaborator: Angel Snavely
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <sstream>


using namespace std;

class BST{
    
    struct Node{
        int val; //node value
        Node *left; //left pointer
        Node *right; //right pointer
        Node *parent; //parent pointer
    };
    
public:
    Node *root;
    enum TraversalOrder {InOrderTrav, PreOrderTrav, PostOrderTrav}; //enum's are so cool!
    
    BST() {
        root = NULL;
    }
    
    ~BST() {
        delete root;
        root = NULL;
    }
public:
    void Insert(int key){ // key is value to be inserted
        Node* y = NULL;
        Node* x = root;
        Node* z = new Node();
        z->val = key;
        z->left = NULL;
        z->right = NULL;
        z->parent = NULL;
        while(x != NULL) {
            y = x;
            if(key < (x->val))
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;
        if(y == NULL)
            root = z;
        else if(key < (y->val))
            y->left = z;
        else
            y->right = z;
    }
    
    void Delete(int toDelete){
        Node* z = Search(root, toDelete);
        Node* y;
        if(z != NULL){
            if((z->left) == NULL)
                Transplant(z, z->right);
            else if ((z->right) == NULL)
                Transplant(z, (z->left));
            else {
                y = Minimum(z->right);
                if((y->parent) != z) {
                    Transplant(y,y->right);
                    y->right = z->right;
                    y->right->parent = y;
                }
                Transplant(z,y);
                y->left = z->left;
                y->left->parent = y;
            }
        }
        return;
    }
    
    void Transplant(Node *u, Node *v){
        if((u->parent) == NULL)
            root = v;
        else if(u == (u->parent->left))
            u->parent->left = v;
        else
            u->parent->right = v;
        if(v != NULL)
            v->parent = u->parent;
    }
    
    Node *Successor(Node *x){
        Node* y = NULL;
        if((x->right) != NULL)
            return Minimum(x->right);
        y = x->parent;
        while(y != NULL && x == (y->right)){
            x = y;
            y = y->parent;
        }
        return y;
    }
    
    Node *Minimum(Node *x){
        while((x->left) != NULL)
            x = x->left;
        return x;
    }
    
    Node *Maximum(Node *x){
        while((x->right) != NULL)
            x = x->right;
        return x;
    }
    
    Node *Search(Node *x, int k){ // k == key
        while(x != NULL && k != (x->val)) {
            if(k < (x->val))
                x = x->left;
            else
                x = x->right;
        }
        return x;
    }
public:
    void Print(TraversalOrder Order){
        if(Order==InOrderTrav)
            InOrder(root);
        else if(Order==PreOrderTrav)
            PreOrder(root);
        else if(Order==PostOrderTrav)
            PostOrder(root);
    }
    
    void InOrder(Node *x){
        if(x != NULL) {
            InOrder(x->left);
            printf("%d\n",x->val);
            InOrder(x->right);
        }
    }
    
    void PreOrder(Node *x){
        if(x != NULL) {
            cout << x->val << endl;
            PreOrder(x->left);
            PreOrder(x->right);
        }
    }
    
    void PostOrder(Node *x){
        if(x != NULL) {
            PostOrder(x->left);
            PostOrder(x->right);
            cout << x->val << endl;
        }
    }
    
};
int main(int argc, const char * argv[]){
    BST bsTree;
    
    char line[99];
    while (cin.getline(line,99)){
        string str(line);
        if (str.size() == 0)
            continue;
        if (str[0] == 'e')
            return 0;
        
        if (str.substr(0,3) == "oin")
            bsTree.Print(BST::InOrderTrav);
        else {
            if ( str.substr(0,4)=="opre" )
                bsTree.Print(BST::PreOrderTrav);
            else {
                if (str.substr(0,5) == "opost")
                    bsTree.Print(BST::PostOrderTrav);
                else {
                    int key;
                    stringstream convert_stm(str.substr(1, str.size()-1));
                    if (!(convert_stm>>key))
                        key = -1;
                    if (str.substr(0,1) == "i")
                        bsTree.Insert(key);
                    else if (str.substr(0,1) == "d")
                        bsTree.Delete(key);
                }
            }
        }
    }
    return 0;
}

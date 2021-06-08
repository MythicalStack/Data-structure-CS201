#include<iostream>
#include<climits>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// check for BST
bool isBST(Node *root,Node* min=NULL,Node* max=NULL){
    if(root == NULL){
        return true;
    }
    if(min != NULL && root->data <= min->data){
        return false;
    }

    if(max != NULL && root->data >=max->data){
        return false;
    }

    bool leftvalid = isBST(root->left,min,root);
    bool rightvalid = isBST(root->right,root,max);
    return leftvalid and rightvalid;
}

int main()
{
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    /* 
            1
           / \
          2   3

    */

   if(isBST(root1,NULL,NULL)){
       cout << "valid BST" << endl;
   }else{
       cout << "Not valid BST" << endl;
   }

    Node* root2 = new Node(5);
    root2->left = new Node(2);
    root2->right = new Node(8);

    /*      
             5
            / \
           2   8
    
    */

    if(isBST(root2,NULL,NULL)){
       cout << "valid BST" << endl;
    }else{
       cout << "Not valid BST" << endl;
    }

    return 0;
}

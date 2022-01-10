#include <bits/stdc++.h>

using namespace std;

struct Node{
        int data;
        struct Node* left;
        struct Node* right;

        Node(int val){
            data=val;
            left=NULL;
            right=NULL;
        }
};

int height(Node *root){
    if(root == NULL)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh) +1;
}

bool isbalanced(Node *root , int *height){
    if(root == NULL)
        return true;
 
    int l=0 , r=0;
    if (isbalanced(root->left , &l) == false)    
        return false;
    if (isbalanced(root->right , &r) == false)
        return false;

    // int l=height(root->left);
    // int r=height(root->right);

    *height=max(l ,r)+1;

    if(abs(l-r)<=1)
        return true;
    else
        return false;

}


int main() {

    struct Node* root=new Node(1);

    root->left=new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    // root->left->left->right =new Node(6);
    // root->right->right = new Node(7);
     int height =0;
    cout<<isbalanced(root ,&height);
    return 0;
}
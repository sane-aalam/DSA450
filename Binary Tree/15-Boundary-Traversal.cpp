#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
 
// to create a new node
Node* CreateNode(int data)
{
    Node* newNode = new Node();
    if (!newNode)
        return nullptr;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

/*
Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3
*/

/* Method 1 :
case 1 : print the left side node if present otherwise right side + dont take leaf node
case 2 : print the leaf node node only
case 3 : print the right side node if present otherwise left side + dont take lead node
*/
void LeftView(Node*root, vector<int> &ans){
        if((root==NULL) || (root->left==NULL && root->right==NULL)){
            return;
        }
        
        ans.push_back(root->data);
        
        if(root->left){
            LeftView(root->left,ans);
        }
        else{
            LeftView(root->right,ans);
        }
    }
    
    void Leafnode(Node*root, vector<int> &ans){
        if(root==NULL)
            return;
            
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
        }
        
        Leafnode(root->left,ans);
        Leafnode(root->right,ans);
    }
    
    void RightView(Node*root, vector<int> &ans){
        if((root==NULL) || (root->left==NULL && root->right==NULL)){
            return;
        }
        
        if(root->right){
            RightView(root->right,ans);
        }
        else{
            RightView(root->left,ans);
        }
        
        ans.push_back(root->data);
    }


void boundary(Node * root, vector<int>& ans){

        // starting we are inserting root element in array
        // we will continue with root of left and right 
        ans.push_back(root->data);

        LeftView(root->left,ans);
        Leafnode(root->left,ans);
        Leafnode(root->right,ans);
        RightView(root->right,ans);
    
    cout << "this function is working!" << endl;
}


int main(){ 
    Node * root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->left = CreateNode(4);
    root->left->right = CreateNode(10);
    root->right->left = CreateNode(44);
    root->right->right = CreateNode(5);
    
    vector<int> ans;
    boundary(root,ans);

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

    cout << endl;
    return 0;
}
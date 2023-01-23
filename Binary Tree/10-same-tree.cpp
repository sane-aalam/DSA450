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


/* approach used :
- check the left part both tree are equal
- check the right part both tree are equal
- check the data of every node are eqaul */


bool sameTree(Node* root1, Node* root2){
    // if both are null then both are same tree
    if(root1 == nullptr and root2 == nullptr) 
        return true;
    // if root1 is null and root2 is not null return false;
    if(root1 == nullptr and root2 != nullptr) 
        return false;
    if(root1 != nullptr and root2 == nullptr){
        return false;
    }
 /*   
 return (root1->data == root2->data) && 
 sameTree(root1->left, root2->left) && 
    sameTree(root1->right, root2->right);  
        (one line + all calls)
*/

    // you can clearly understand
    bool left = sameTree(root1->left,root2->left);
    bool right = sameTree(root1->right, root2->right);

    bool value = (root1->data == root2->data);

    if(left and right and value){
        return true;
    }else{
        return false;
    }
}

int main(){ 
    Node *root1 = CreateNode(10);
    Node *root2 = CreateNode(10);
    root1->left = CreateNode(7);
    root1->right = CreateNode(15);
    root1->left->left = CreateNode(4);
    root1->left->right = CreateNode(9);
 
    root2->left = CreateNode(7);
    root2->right = CreateNode(15);
    root2->left->left = CreateNode(4);
    root2->left->right = CreateNode(29);
    
    if(sameTree(root1,root2) == true){
        cout << "Both are same!";
    }else{
        cout << "Both are not same!";
    }
    cout << endl;
    cout << "There is no problem " << endl;
    return 0;
}













   
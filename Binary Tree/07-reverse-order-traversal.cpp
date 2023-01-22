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


void Levelorder(Node* root, vector<int>&result){

        queue<Node*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            while(size--){
                Node * temp = q.front();
                q.pop();

                result.push_back(temp->data);

                // if temp of left is not null then push into the queue
                if(temp->left != nullptr) 
                    q.push(temp->left);
                // if temp of right is not present then push into the queue
                if(temp->right != nullptr) 
                  q.push(temp->right);
            }
        }
}

int main(){ 
    Node * root = CreateNode(11);
    root->left = CreateNode(12);
    root->right = CreateNode(13);
    root->left->left = CreateNode(14);
    root->right->right = CreateNode(15);
    
    // for storing the answer
    vector<int> result;
    cout << "Level order traversal using BFS" << endl;
    Levelorder(root, result);

    // reverse the result then you will get reverse solution
    reverse(result.begin(),result.end());

    // print the vector(result using for loop)
    for(int i = 0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
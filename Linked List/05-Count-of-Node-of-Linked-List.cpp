
// Algorithm :  size of the linked list is equal of the node of the linked list 

class Solution{
    public:
    //Function to count nodes of a linked list.
    int getCount(struct Node* head){
        
        int count = 0;
        Node * temp = head;
        while(temp != nullptr ){
            temp = temp->next;
            count ++ ;
        }
        return count;
    }
};
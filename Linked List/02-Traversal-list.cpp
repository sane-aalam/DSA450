
// Given a linked list. Print all the elements of the linked list.

class Solution
{
    public:
    void display(Node *head)
    {
      Node * temp = head;
      while(temp != nullptr){
          cout << temp->data << " ";
          temp = temp->next;
      }
    }
};
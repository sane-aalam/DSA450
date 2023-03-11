
   /* If there are two middle nodes, return the second middle node.
     Approach - 1 : 
    - finout the length of the linked list 
    - traversal the linked list using half of the legnth of list
   */

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // case 1 : find out the lengh of the list 
        int n = 0;
        ListNode * temp = head;
        while(temp != nullptr){
            n++;
            temp = temp->next;
        }
        // case 2 : half of length of list and traveral the node
        int half = n /2;
        temp = head;
        while(half--){
            temp = temp->next;
        }
        return temp;
    }
};

/*
Approach - 2 : Flod's cycle detection algoritm :
  - we will set two pointer slow and fast 
  - slow will increase by one step 
  - fast will increae by two step

  - end of the interation we will have middle of the node of ( slow pointer have )

*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        /*
Approach - 2 : Flod's cycle detection algoritm :
  - we will set two pointer slow and fast 
  - slow will increase by one step 
  - fast will increae by two step

  - end of the interation we will have middle of the node of ( slow pointer have )

*/
        ListNode * slow  = head;
        ListNode * fast = head;

        while(fast!= nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


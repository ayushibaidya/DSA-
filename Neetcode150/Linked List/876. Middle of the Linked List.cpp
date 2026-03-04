//slow fast pointers - TC: O(N) SC: O(1) 
//slow will point at middle - while()
class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head; 
        ListNode* fast = head; 

        while(fast != NULL && fast->next != NULL){
            slow = slow->next; 
            fast = fast->next->next; 
        }
        return slow; 
    }
};

//two pass find the middle: 
//1 - count the number of nodes 
//2 - go to mid = 0 + (n-0)/2; 

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0; 

        ListNode* curr = head; 

        while(curr != NULL){
            count++; 
            curr = curr->next; 
        }

        int mid = 0+(count-0)/2; 

        curr = head; 
        count = 0; 
        while(count != mid){
            count++; 
            curr = curr->next; 
        }

        return curr; 
    }
};
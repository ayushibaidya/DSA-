//iterative solution - TC: O(N) SC: O(1)

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        int carry = 0; 

        ListNode* dummy = new ListNode(0); 
        ListNode* curr = dummy; 

        while(list1 || list2 || carry){
            int num1 = (list1?list1->val:0); 
            int num2 = (list2?list2->val:0);

            int sum = num1+num2+carry; 

            carry = sum/10; 
            sum = sum%10; 

            curr->next = new ListNode(sum); 
            curr = curr->next; 
            if(list1) list1 = list1->next; 
            if(list2) list2 = list2->next; 
        }
        return dummy->next; 
    }
};
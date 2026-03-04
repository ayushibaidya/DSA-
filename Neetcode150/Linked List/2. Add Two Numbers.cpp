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

            int sum = num1+num2+carry; //carry gets added in the next loop 

            carry = sum/10; //gets if there is any carry = 1 -> gets added in the next loop 
            sum = sum%10; //gets the number in the ones place 

            curr->next = new ListNode(sum); 
            curr = curr->next; 
            if(list1) list1 = list1->next; 
            if(list2) list2 = list2->next; 
        }
        return dummy->next; 
    }
};
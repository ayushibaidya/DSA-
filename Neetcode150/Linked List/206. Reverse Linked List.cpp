// Clarifying Questions: (first two important)
// Is this a singly LL or doubly LL? 
// Can i modify the original list in-place or return a new reversed copy? 

// Do we reverse the whole LL or reverse k-group? 
// What are the constraints on n? (very large n can lead to stack overflow for recursion)
// Empty list we return NULL? 
// Single node we return head? 


//iterative solution - 3 pointers 4 steps 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL; 

        ListNode* curr = head; 
        ListNode* prev = NULL; 
        ListNode* next = NULL; 

        while(curr != NULL){
            next = curr->next; 
            curr->next = prev; 
            prev = curr; 
            curr = next; 
        }

        return prev; 
    }
};

//recursive solution - TC: O(N) SC:O(N) -> recursion call stack 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case
        if (head == nullptr || head->next == nullptr)
            return head;

        // Recursively reverse the rest
        ListNode* newHead = reverseList(head->next);

        // Reverse current connection
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};

//stack solution - TC: O(N) SC:O(N) - not ideal 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int> st; 

        
        ListNode* temp = head; 

        while(temp != NULL){
            st.push(temp->val); 
            temp = temp->next; 
        }

        temp = head; 

        while(temp != NULL){
            temp->val = st.top(); 
            st.pop(); 
            temp = temp->next; 
        }

        return head; 

    }
};
//hashset find a cycle 
//TC:O(N) SC:O(N)
class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> st; 

        ListNode* curr = head; 

        while(curr != NULL){
            if(st.find(curr) == st.end()){
                st.insert(curr); 
                curr = curr->next; 
            }else{
                return true; 
            }
        }
        return false;
    }
};


//slow fast pointers 
//TC:O(N) SC:O(1)
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head; 
        ListNode* fast = head; 

        while(fast != NULL && fast->next != NULL){
            slow = slow->next; 
            fast = fast->next->next;
            if(slow == fast){
                return true; 
            }
        }
        return false; 
    }
};


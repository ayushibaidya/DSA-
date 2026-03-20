//BRUTE FORCE USING TWO WHILE LOOPS AND TWO POINTERS
//TC: O(n^2) SC: O(1) 
bool hasCycle(ListNode* head) {
        if(head == NULL || head->next == NULL) return false; 

        ListNode* curr = head; 

        while(curr != NULL){
            ListNode* temp = head; 
            while(temp != curr){
                if(temp == curr->next){
                    return true; 
                }
                temp = temp->next; 
            }
            curr = curr->next; 
        }
        return false; 
    }

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


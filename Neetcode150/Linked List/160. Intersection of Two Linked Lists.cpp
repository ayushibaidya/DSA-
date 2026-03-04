//insert first list into hashset
//check if node from second list already exists in hashset
//TC: O(N) SC:O(N)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s; 

        ListNode* currA = headA;
        ListNode* currB = headB; 

        while(currA != NULL){
            s.insert(currA); 
            currA = currA->next; 
        }

        while(currB != NULL){
            if(s.find(currB) != s.end()){
                return currB; 
            }
            currB = currB->next; 
        }
        return NULL; 
    }
};

//extra long annoying version
//get length of both lists, increment longer list pointer by diff
//return if both pointers meet 
//TC: O(N) SC:O(N) - three pass
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currA = headA; 
        ListNode* currB = headB; 

        int len1 = 0; 
        int len2 = 0; 

        while(currA != NULL){
            len1++; 
            currA = currA->next; 
        }

        while(currB != NULL){
            len2++; 
            currB = currB->next; 
        }

        currA = headA;
        currB = headB; 

        int diff = abs(len1-len2); 

        if(len1 < len2){
            while(diff--){
                currB = currB->next; 
            }
        }else{
            while(diff--){
                currA = currA->next; 
            }
        }

        while(currA && currB){
            if(currA == currB){
                return currA; 
            }
            currA = currA->next; 
            currB = currB->next; 
        }
        return NULL; 
    }
};

//dancing pointers keep switching lists 
//TC: O(N) SC: O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //either list doesnt exist no intersection 
        if(!headA || !headB) return NULL; 

        ListNode* currA = headA; 
        ListNode* currB = headB; 

        while(currA != currB){
            if(currA == NULL){
                currA = headB; 
            }else{
                currA = currA->next; 
            }
            if(currB == NULL){
                currB = headA; 
            }
            else{
                currB = currB->next; 
            }
        }
        return currA; 
    }
};
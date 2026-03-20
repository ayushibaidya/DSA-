//BRUTE FORCE
//TC: O((n+m)(log(n+m))
//SC: O(n+m)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2; 
        if(list2 == NULL) return list1; 

        vector<int> temp; 
        
        ListNode* curr1 = list1; 
        ListNode* curr2 = list2; 

        //O(n)
        while(curr1 != NULL){
            temp.push_back(curr1->val); 
            curr1 = curr1->next; 
        }

        //O(m)
        while(curr2 != NULL){
            temp.push_back(curr2->val); 
            curr2 = curr2->next; 
        }

        //O((n+m)log(n+m))
        sort(temp.begin(), temp.end()); 

        ListNode* dummy = new ListNode(); 
        ListNode* tail = dummy; 

        //O(n)
        for(int i = 0; i < temp.size(); i++){
            tail->next = new ListNode(temp[i]); 
            tail = tail->next; 
        }
        return dummy->next; 
    }



//remember dummy node, curr points to dummy, move curr 
//TC: O(N+M) SC: O(1) 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2; 
        if(!list2) return list1; 

        ListNode* dummy = new ListNode(); 
        ListNode* curr = dummy; 

        while(list1 && list2){
            if(list1->val < list2->val){
                curr->next = list1; 
                list1 = list1->next; 
            }else{
                curr->next = list2; 
                list2 = list2->next; 
            }
            curr = curr->next; 
        }

        if(list1){
            curr->next = list1;  
        }

        if(list2){
            curr->next = list2; 
        }

        return dummy->next; 
    }
};

//recursive solution 
//TC: O(N+M) SC: O(N+M)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(!list1) return list2;
        if(!list2) return list1;
        
        if(list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

//create a new linked list and return that using dummyNode and tail pointer 
//TC: O(n+m) same as stitch the nodes in place but the stitch one has faster pointer updates
//SC: O(n+m)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2; 
        if(list2 == NULL) return list1; 

        ListNode* dummyNode = new ListNode(); 
        ListNode* tail = dummyNode; 

        ListNode* curr1 = list1; 
        ListNode* curr2 = list2; 

        while(curr1 != NULL && curr2 != NULL){
            if(curr1->val <= curr2->val){
                tail->next = new ListNode(curr1->val); 
                curr1 = curr1->next; 
            }else{
                tail->next = new ListNode(curr2->val); 
                curr2 = curr2->next;  
            }
            tail = tail->next; 
        }

        while(curr1 != NULL){
            tail->next = new ListNode(curr1->val); 
            curr1 = curr1->next; 
            tail = tail->next; 
        }while(curr2 != NULL){
            tail->next = new ListNode(curr2->val); 
            curr2 = curr2->next; 
            tail = tail->next; 
        }
        return dummyNode->next;
    }

    “Both approaches have O(n + m) time complexity, but I would prefer the in-place approach where we stitch the lists together.

In embedded systems, memory is often constrained and dynamic allocation (new) can be expensive and sometimes discouraged due to fragmentation and unpredictability. The in-place approach uses O(1) extra space and avoids heap allocations, making it more efficient and deterministic.

The only tradeoff is that it modifies the original lists, but unless immutability is required, this is usually acceptable and even preferred in low-level systems.”


“If the original lists must remain unchanged, or if safety and immutability are important, I would use the new list approach despite the extra space cost.”


“Same time complexity, but I’d choose the in-place approach because it avoids dynamic memory allocation and uses constant space, which is more efficient and predictable.”
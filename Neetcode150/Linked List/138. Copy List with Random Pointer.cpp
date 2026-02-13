class Solution{
    public:

    //TC: O(2n) + SC: O(n)+O(n)
    //SC - hashmap + creating copy nodes 
    Node* copyRandomList(Node* head){
        if(head == NULL){
            return NULL; 
        }

        Node* curr = head; 

        unordered_map<Node*, Node*> map; 

        //make copies of the nodes in given linked list 
        //TC: O(n)
        while(curr != NULL){
            Node* newNode = new Node(curr->val); 
            map[curr] = newNode; 
            curr = curr->next; 
        }

        //using the map make deep copies of all dummy nodes
        //deep copy all node pointers - TC:O(n)
        curr = head; 

        while(curr != NULL){
            Node* copyNode = map[curr]; 
            copyNode->next = map[curr->next]; 
            copyNode->random = map[curr->random]; 
            curr = curr->next; 
        }
        return map[head]; 
    }
}
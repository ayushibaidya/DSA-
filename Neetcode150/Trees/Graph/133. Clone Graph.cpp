class Solution {
public:

    Node* dfsClone(Node* node, map<Node*, Node*> &oldToNew){
        if(node == NULL) return NULL; 

        if(oldToNew.count(node)){
            return oldToNew[node];
        }

        //create new node and copy val from original
        Node* newNode = new Node(node->val); 

        //map the old to new node in map 
        oldToNew[node] = newNode; 

        for(Node* n:node->neighbors){
            newNode->neighbors.push_back(dfsClone(n, oldToNew)); 
        }
        return newNode; 
    }

    Node* cloneGraph(Node* node) {
        map<Node*, Node*> oldToNew; 
        return dfsClone(node, oldToNew); 
    }
};
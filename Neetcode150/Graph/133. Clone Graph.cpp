//dfs
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

//bfs
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL; 
        unordered_map<Node*, Node*>oldToNew; 

        queue<Node*> q; 
        oldToNew[node] = new Node(node->val); 

        q.push(node); 

        while(!q.empty()){
            Node* curr = q.front(); 
            q.pop(); 

            for(Node* no:curr->neighbors){
                if(oldToNew.find(no) == oldToNew.end()){
                    oldToNew[no] = new Node(no->val); 
                    q.push(no); 
                }
                oldToNew[curr]->neighbors.push_back(oldToNew[no]); 
            }
        }
        return oldToNew[node]; 
    }
};
//return 0 is pq emtpy ot the last remaining stone 
//a-b because a will always be greater than b 
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; 
        int n = stones.size(); 

        for(int i = 0; i < n; i++){
            pq.push(stones[i]); 
        }

        while(pq.size() > 1){
            int a = pq.top(); pq.pop(); 
            int b = pq.top(); pq.pop(); 

            if(a != b){
                pq.push(a-b); 
            }
        }
        if(pq.empty()){
            return 0; 
        }else{
            return pq.top(); 
        }
    }
};

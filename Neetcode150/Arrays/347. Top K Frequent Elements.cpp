class Solution {
public:

    //using a map store the frequency of the elements 
    //using a priority queue store only the top k elements 
    //while pq is not empty store the top k elements into vector 
    //return vector
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size(); 
        unordered_map<int, int> count; 
        vector<int>ans; 

        //count the elements in nums 
        for(int it:nums){
            count[it]++;   
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq; 

        for(auto [it, freq]:count){
            pq.push({freq, it}); 

            //only store the top k elements 
            if(pq.size() > k){
                pq.pop(); 
            }
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second); 
            pq.pop(); 
        }
        return ans; 
    }
};

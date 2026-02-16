class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(); 
        vector<int> ans; 

        unordered_map<int, int> m; 

        for(int i = 0; i < n; i++){
            int diff = target-nums[i];  
            if(m.find(diff) != m.end()){
                ans.push_back(m[diff]); 
                ans.push_back(i); 
                return ans; 
            }
            m[nums[i]] = i; 
        }
        return ans; 
    }
};

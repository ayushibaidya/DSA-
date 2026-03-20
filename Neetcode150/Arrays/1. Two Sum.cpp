//brute force - two nested loops 
//TC: O(n) SC: O(1)
vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size(); 

        vector<int>ans; 

        for(int i = 0; i < size; i++){
            for(int j = i+1; j < size; j++){
                if(nums[i] + nums[j] == target){
                    ans.push_back(i); 
                    ans.push_back(j); 
                    return ans; 
                }
            }
        }
        return ans; 
    }

//unordered_map 
//TC: O(n) SC: O(n)
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

//if we have to optimize space we can sort the array and use two pointers but that will make it 
//TC: O(nlogn) and SC: O(1)
vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> ans; 
        for(int i = 0; i < nums.size(); i++){
            ans.push_back({nums[i], i}); 
        }

        sort(ans.begin(), ans.end()); 

        int low = 0; int high = nums.size()-1; 

        while(low < high){
            int sum = ans[low].first + ans[high].first; 
            if(sum == target){
                return {ans[low].second, ans[high].second}; 
            }else if(sum < target){
                low++; 
            }else{
                high--; 
            }
        }
        return {};
    }
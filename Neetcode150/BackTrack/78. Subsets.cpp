//TC: O(2^n)
//SC: O(n)
class Solution {
public:

    void backTrack(vector<int> &nums, int index, vector<int> &temp, vector<vector<int>> &res){
        if(index == nums.size()){
            res.push_back(temp); 
            return;
        }

        temp.push_back(nums[index]); 
        backTrack(nums, index+1, temp, res); 
        temp.pop_back(); 
        backTrack(nums, index+1, temp, res); 
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp; 
        vector<vector<int>> res; 
        backTrack(nums, 0, temp, res); 
        return res; 
    }
};
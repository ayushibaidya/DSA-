//TC: O(n!)
//SC: O(n)
class Solution {
public:

    void backTrack(vector<int> &nums, int index, vector<int> &temp, vector<vector<int>> &res, vector<bool> &vis){
        if(index == nums.size()){
            res.push_back(temp); 
            return; 
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(vis[i] == 0){
                temp.push_back(nums[i]); 
                vis[i] = 1; 
                backTrack(nums, index+1, temp, res, vis); 
                temp.pop_back(); 
                vis[i] = 0; 
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp; 
        vector<vector<int>> res; 
        vector<bool> vis(nums.size(), 0); 

        backTrack(nums, 0, temp, res, vis); 
        return res; 
    }
};
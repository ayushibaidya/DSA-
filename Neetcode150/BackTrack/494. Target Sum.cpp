class Solution {
public:



    void backTrack(vector<int> &nums, int index, vector<int>&temp, int &count, int target){
        if(index == nums.size()){
            if(target == 0){
                count++;  
            }
            return;
        }

        backTrack(nums, index+1, temp, count, target-nums[index]);
        backTrack(nums, index+1, temp, count, target+nums[index]); 
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int>temp; 
        int count = 0; 
        backTrack(nums, 0, temp, count, target); 
        return count; 
        
    }
};
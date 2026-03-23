//TC: O(log n) + O(log n) = O(log n)
//SC: O(1)

class Solution {
public:

    int findLowerIndex(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0; 
        int high = nums.size()-1; 

        int ans = -1; 

        while(low <= high){
            //prevent integer overflow
            int mid = low + (high-low)/2; 
            if(nums[mid] >= target){
                if(nums[mid] == target){
                    ans = mid;
                } 
                high = mid-1; 
            }else{
                low = mid+1; 
            }
        }
        return ans; 
    }

    int findHigherIndex(vector<int> &nums, int target){
        int n = nums.size(); 
        int low = 0; 
        int high = nums.size()-1; 

        int ans = -1; 

        while(low <= high){
            int mid = low + (high-low)/2; 
            if(nums[mid] <= target){
                if(nums[mid] == target){
                    ans = mid; 
                }
                low = mid+1; 
            }else{
                high = mid-1; 
            }
        }
        return ans; 
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res; 
        res.push_back(findLowerIndex(nums, target)); 
        res.push_back(findHigherIndex(nums, target)); 
        return res; 
    }
};
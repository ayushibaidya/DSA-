//brute force 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(); 

        vector<int> temp; 
        //0 0 0 0 0 
        for(int i = 0; i < n; i++){
            if(nums[i]!=0){
                temp.push_back(nums[i]); 
            }
        }
        //temp -> 1 3 12 
        for(int i = 0; i < temp.size(); i++){
            nums[i] = temp[i]; 
        }

        for(int i = temp.size(); i < n; i++){
            nums[i] = 0; 
        }
        return; 
    }
};

//linear 
//T: O(n) SC: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; 

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]); 
                j++; 
            }
        }
    }
};

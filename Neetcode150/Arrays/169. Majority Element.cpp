//TC: O(n)
//SC: O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(); 

        unordered_map<int, int> freq; 

        for(int c:nums){
            freq[c]++; 
            if(freq[c] > (n/2)){
                return c; 
            }
        }
        return -1; 
    }
};
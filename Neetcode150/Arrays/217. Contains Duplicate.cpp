class Solution{
    public: 
    
    //use a set, if seen value before return true, else insert in set 
    //set only contains unique values 
    bool containsDuplicate(vector<int> &nums){
        int n = nums.size(); 

        unordered_set<int> s; 

        for(int i = 0; i < n; i++){
            if(s.find(nums[i]) != s.end()){
                return true; 
            }
            s.insert(nums[i]); 
        }
        return false; 
    }
}
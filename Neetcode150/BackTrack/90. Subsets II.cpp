class Solution{
    public: 

    void backTrack(vector<int> &nums, vector<int> &subset, vector<vector<int>> &results, int index){
        results.push_back(subset); 

        for(int i = index; i < nums.size(); i++){
            if(i > index && nums[i] == nums[i-1]){
                continue; 
            }
            subset.push_back(nums[i]); 
            backTrack(nums, subset, results, i+1); 
            subset.pop_back(); 
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums){
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> results; 
        vector<int> subset; 
        backTrack(nums, subset, results, 0); 
        return results; 
    }
}
class Solution {
public:

    void backTrack(vector<int> &candidates, int index, vector<int>&temp, vector<vector<int>> &res, int target){
        if(target == 0){
            res.push_back(temp); 
            return; 
        }

        for(int i = index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]){
                continue; 
            }
            if(candidates[i] <= target){
                temp.push_back(candidates[i]); 
                backTrack(candidates, i+1, temp, res, target-candidates[i]); 
                temp.pop_back(); 
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp; 
        vector<vector<int>> res; 

        sort(candidates.begin(), candidates.end()); 
        backTrack(candidates, 0, temp, res, target); 

        return res; 
    }
};
class Solution {
public:

    void backTrack(string &digits, unordered_map<char, string> &digitMap, string &currString, vector<string> &results, int index){
        if(index == digits.size()){
            results.push_back(currString);
            return;  
        }

        string options = digitMap[digits[index]]; 
        for(auto &c:options){
            currString.push_back(tolower(c)); 
            backTrack(digits, digitMap, currString, results, index+1); 
            currString.pop_back(); 
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> digitMap = {{'2', "ABC"}, {'3', "DEF"}, 
        {'4', "GHI"}, {'5', "JKL"}, {'6', "MNO"}, {'7', "PQRS"}, 
        {'8', "TUV"}, {'9', "WXYZ"}}; 

        vector<string> results; 
        string currString = ""; 

        backTrack(digits, digitMap, currString, results, 0);
        return results; 
    }
};
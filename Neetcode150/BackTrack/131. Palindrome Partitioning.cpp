class Solution {
public:

    bool isPalindrome(string &s, int low, int high){
        while(low <= high){
            if(s[low] != s[high]){
                return false; 
            }
            low++; high--; 
        }
        return true; 
    }

    void backTrack(string &s, vector<string> &palindrome, vector<vector<string>> &results, int index){
        if(index == s.size()){
            results.push_back(palindrome); 
            return; 
        }

        for(int i = index; i < s.size(); i++){
            if(isPalindrome(s, index, i)){
                //this 
                palindrome.push_back(s.substr(index, i-index+1)); 
                backTrack(s, palindrome, results, i+1); 
                palindrome.pop_back(); 
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> results; 
        if(s.size() == 0) return results; 

        vector<string> palindrome; 

        backTrack(s, palindrome, results, 0); 
        return results; 
    }
};

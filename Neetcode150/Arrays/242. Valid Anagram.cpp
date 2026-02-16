class Solution{
    public: 

    bool isAnagram(string s, string t){
        //check if they are the same size, if not return false 
        if(s.size() != t.size()) return false; 

        //now that we know they are the same size 
        int n = s.size(); 

        vector<int> count(26, 0); 

        //total count of s++ and t-- should be 0 
        //use 'a' for lower case letters 
        for(int i = 0; i < n; i++){
            count[s[i]-'a']++; 
            count[t[i]-'a']--; 
        }

        //all values in count should be 0 
        for(int i = 0; i < n; i++){
            if(count[i] != 0){
                return false; 
            }
        }
        return true; 
    }
}
//keywords - longest substring {contiguous block of data}

class Solution{ 
    public: 

    //brute force - O(n^2)
    int lengthOfLongestSubstring(string s){
        int n = s.size(); 

        int length = 0; 

        for(int i = 0; i < n; i++){
            unordered_set<char>set; 
            for(int j = i; j < n; j++){
                if(set.find(s[j] != set.end())){
                    break; 
                }
                set.insert(s[j]); 
                length = max(length, j-i+1); 
            }
        }
        return length; 
    }

    //sliding window - O(n)
    int lengthOfLongestSubstring(string s){
        int n = s.size(); 
        unordered_set<char> set; 
        int length = 0; 

        int i = 0; int j = 0; 

        while(j < n){
            if(set.find(s[j] == s.end())){
                set.insert(s[j]); 
                length = max(length, j-i+1); 
                j++; 
            }else{
                set.erase[s[i]]; 
                i++; 
            }
        }
        return length; 
    }
}
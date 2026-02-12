/*
j-i+1 is the distance between the two pointers which also represents the result len 
we have to get the max value of j-i+1

keep a count vector of the 26 letters, and keep track of maxFreq of the letters in a variable 

as long as the distance between i and j is less than k, we can move j forward and count letters 

if the distance becomes greater than k, we decrement the count of letters at i 
*/

class Solution {
    public: 
        int characterReplacement(string s, int k){
            vector<int> count(26, 0); 

            int i = 0; 
            int maxFreq = 0; 
            int longest = 0; 

            for(int j = 0; j < s.size(); j++){
                count[s[j]-'A']++; 

                maxFreq = (maxFreq, count[s[j]-'A']);  
                while((j-i+1)-maxFreq > k){
                    count[s[i]-'A']--; 
                    i++; 
                }
                longest = max(longest, j-i+1); 
            }
            return longest; 
        }
}
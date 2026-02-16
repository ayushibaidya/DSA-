class Solution{ 
    public: 

    bool isPlaindrom(string s){
        int n = s.size(); 

        int low = 0; int high = n-1; 

        while(low <= high){
            //check if low pointer is alphanumeric char, if not we move pointer 
            if((s[low] < '0' || s[low] > '9') && 
                (s[low] < 'a' || s[low] > 'z') &&
                (s[low] < 'A' || s[low] > 'Z')){
                    low++; continue; 
                }
            //check if high pointer is alpha numeric 
            else if((s[high] < '0' || s[high] > '9') && 
                (s[high] < 'a' || s[high] > 'z') &&
                (s[high] < 'A' || s[high] > 'Z')){
                    high--; continue; 
            }

            //check if they are the same letter, if not return false
            char c1 = tolower(s[low]); 
            char c2 = tolower(s[high]); 

            if(c1 != c2) return false; 
            low++; high--; 
        }
        return true;
    }
}; 
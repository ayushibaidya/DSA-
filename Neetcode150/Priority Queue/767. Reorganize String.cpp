//TC: O(logk) - where k is the number of unique characters
//SC: O(n)
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp; 

        for(auto& c:s){
            mp[c]++; 
        }

        priority_queue<pair<int, char>> pq; 

        for(auto it:mp){
            pq.push({it.second, it.first}); 
        }
        string ans = "";
        
        while(pq.size() > 1){
            auto letter1 = pq.top(); pq.pop(); 
            auto letter2 = pq.top(); pq.pop(); 

            ans += letter1.second; 
            ans += letter2.second; 

            if(--letter1.first > 0){
                pq.push(letter1); 
            }
            if(--letter2.first > 0){
                pq.push(letter2); 
            }
        }

        if(!pq.empty()){
            if(pq.top().first > 1){
                return ""; 
            }
            ans += pq.top().second; 
        }
        return ans; 
    }
};
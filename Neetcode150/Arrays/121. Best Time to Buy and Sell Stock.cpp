//clarifying questions 
//can the input array be empty or have one element? 
//are we allowed multiple transactions or only one? 
//is it given that one transction exists that is profitable? what should we return if no profit is possible? 

//brute force - TC: O(n^2) SC:O(1)
//remember prices[j] > prices[i]
int maxProfit(vector<int>& prices) {
        int size = prices.size(); 

        int maxProfit = 0;

        for(int i = 0; i < size; i++){
            for(int j = i+1; j < size; j++){
                if(prices[j] > prices[i]){
                    maxProfit = max(maxProfit, prices[j]-prices[i]); 
                }
            }
        }

        return maxProfit; 
    }

//maintain a minPrice in the array 
//if the diff between the minPrice and current price is greater that maxProfit, update it 
//TC: O(n) SC: O(1)
int maxProfit(vector<int>& prices) {
        int size = prices.size(); 

        int minPrice = INT_MAX;
        int maxProfit = 0; 

        for(int i = 0; i < size; i++){
            minPrice = min(minPrice, prices[i]); 
            int diff = prices[i]-minPrice; 
            maxProfit = max(diff, maxProfit); 
        }
        return maxProfit; 
    }
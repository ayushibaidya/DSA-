class solution{
    public: 

    //brute force solution - O(n^2) 
    int maxProfit(vector<int> &prices){
        int n = prices.size(); 
        int profit = 0; 

        for(int i = 0; i < n-1; i++){
            int currP = 0; 
            for(int j = i+1; j < n; j++){
                if(prices[j] > prices[i]){
                    currP = max(currP, prices[j]-prices[i]); 
                }
            }
            profit = max(profit, currP); 
        }
        return profit; 
    }

    //sliding window - while loop - O(n)
    int maxProfit(vector<int> &prices){
        int n = prices.size(); 

        int profit = 0; 

        int i = 0; int j = i+1; 

        while(j < n){
            if(prices[j] > prices[i]){
                profit = max(profit, prices[j]-prices[i]); 
                j++;
            }else{
                i = j; 
                j = j+1; 
            }
        }
        return profit; 
    }

    //sliding window - for loop - O(n)
    int maxProfit(vector<int> &prices){
        int minPrice = INT_MAX; 
        int profit = 0; 

        int n = prices.size(); 
        for(int i = 0; i < n; i++){
            minPrice = min(minPrice, prices[i]); 
            int diff = prices[i]-minPrice;
            if(diff > minPrice){
                profit = max(profit, diff); 
            }
        }
        return profit; 
    }
}
class Solution {
public:

//3 pass solution - compute pse, nse, and then the maxArea 
//there is better one pass solution 
//SC - one stack used for pse, emptied, then used for nse 
//one pass solution does not use extra arrays
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(); 
        int maxArea = 0; 

        vector<int>pse(n); 
        vector<int> nse(n); 

        stack<int>st; 

        //pse
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop(); 
            }
            if(st.empty()){
                pse[i] = -1; 
            }else{
                pse[i] = st.top(); 
            }
            st.push(i); 
        }

        while(!st.empty()){
            st.pop(); 
        }

        //nse
        for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        if (st.empty())
            nse[i] = n;  
        else
            nse[i] = st.top();

        st.push(i);
    }   

        for(int i = 0; i < n; i++){
            int width = nse[i]-pse[i]-1; 
            int area = heights[i]*width; 
            maxArea = max(maxArea, area); 
        }
        return maxArea; 
    }
};

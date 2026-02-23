class Solution {
public:

    //just calculating the time and returning the size of set wont work as that will give 
    //unique solutions 
    //TC: O(n) SC: O(n)
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size(); 

        vector<pair<int, double>> cars;
        for(int i = 0; i < n; i++){
            double time = (double)(target-position[i])/speed[i]; 
            cars.push_back({position[i], time}); 
        }
        //sort by closest to target
        sort(cars.rbegin(), cars.rend());

        stack<double> st; 

        for(auto& c:cars){
            double time = c.second; 

            if(st.empty() || st.top() < time){
                st.push(time); 
            }
        }
        return st.size(); 
    }
};

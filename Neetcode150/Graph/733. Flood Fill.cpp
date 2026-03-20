//dfs - grid+recursion stack 
//TC: O(n*m) SC: O(n*m)
class Solution {
public:

    void dfsFlood(vector<vector<int>> &image, int sr, int sc, int originalColor, int color){
        int n = image.size(); 
        int m = image[0].size(); 

        image[sr][sc] = color; 

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 

        for(auto [r,c]:dir){
            int nr = r+sr; 
            int nc = c+sc; 
            if(nr >= 0 && nc >= 0 && nr < n && nc < m && image[nr][nc] == originalColor){
                image[nr][nc] = color;
                dfsFlood(image, nr, nc, originalColor, color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc]; 

        if(originalColor != color){
            dfsFlood(image, sr, sc, originalColor, color);
        }
        return image; 
    }
};

//bfs - grid+recursion stack
//TC: O(n*m) SC: O(n*m)
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(); 
        int m = image[0].size(); 

        int originalColor = image[sr][sc]; 

        if(originalColor == color) return image; 

        queue<pair<int, int>> q; 
        q.push({sr,sc}); 

        image[sr][sc] = color; 

        vector<pair<int, int>> dir = {{-1,0}, {0,1}, {0,-1}, {1,0}}; 

        while(!q.empty()){
            auto [r,c] = q.front(); 
            q.pop(); 

            for(auto [dr,dc]:dir){
                int nr = r+dr; 
                int nc = c+dc; 
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && image[nr][nc] == originalColor){
                    image[nr][nc] = color; 
                    q.push({nr, nc}); 
                }
            }
        }
        return image;
    }
};
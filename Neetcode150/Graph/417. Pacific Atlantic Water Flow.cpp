class Solution {
public:
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(vector<vector<int>>& heights,
             vector<vector<bool>>& visited,
             int i, int j) {

        int n = heights.size();
        int m = heights[0].size();

        visited[i][j] = true;

        for(auto& d : directions) {
            int ni = i + d[0];
            int nj = j + d[1];

            if(ni >= 0 && nj >= 0 && ni < n && nj < m &&
               !visited[ni][nj] &&
               heights[ni][nj] >= heights[i][j]) {

                dfs(heights, visited, ni, nj);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        // Pacific: top row + left column
        for(int i = 0; i < n; i++)
            dfs(heights, pacific, i, 0);

        for(int j = 0; j < m; j++)
            dfs(heights, pacific, 0, j);

        // Atlantic: bottom row + right column
        for(int i = 0; i < n; i++)
            dfs(heights, atlantic, i, m-1);

        for(int j = 0; j < m; j++)
            dfs(heights, atlantic, n-1, j);

        vector<vector<int>> result;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
            }
        }

        return result;
    }
};
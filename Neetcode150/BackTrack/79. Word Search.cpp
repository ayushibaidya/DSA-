//TC: O(n*m*4^L) where L is the length of the word 
//SC: O(n*m)
class Solution {
public:
    bool checkWord(vector<vector<char>> &board, string word, int index, int i, int j, vector<vector<int>> &vis){
        vis[i][j] = 1; 

        int n = board.size(); 
        int m = board[0].size(); 

        if(index == word.size()-1) return true; 

        vector<pair<int, int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}}; 
        for(auto& [r,c]:dir){
            int nr = i+r; 
            int nc = j+c; 
            if(nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && board[nr][nc] == word[index+1]){
                if(checkWord(board, word, index+1, nr, nc, vis)){
                    return true; 
                }
            }
        }
        vis[i][j] = 0; 
        return false; 
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(); 
        int m = board[0].size(); 

        vector<vector<int>> vis(n, vector<int>(m, 0)); 

        int index = 0; 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[index]){
                    if(checkWord(board, word, index, i, j, vis)){
                    return true; 
                    }
                }
            }
        }
        return false; 
    }
};
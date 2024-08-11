class Solution {
public:
    int ctq=0;
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, int& ct){
        visited[r][c]=true;
        ct++;
        if(r+1>=0 && r+1<grid.size() && c>=0 && c<grid[0].size() && !visited[r+1][c] && grid[r+1][c]){
            dfs(grid, visited, r+1, c, ct);
        }
        if(r>=0 && r<grid.size() && c+1>=0 && c+1<grid[0].size() && !visited[r][c+1] && grid[r][c+1]){
            dfs(grid, visited, r, c+1, ct);
        }
        if(r-1>=0 && r-1<grid.size() && c>=0 && c<grid[0].size() && !visited[r-1][c] && grid[r-1][c]){
            dfs(grid, visited, r-1, c, ct);
        }
        if(r>=0 && r<grid.size() && c-1>=0 && c-1<grid[0].size() && !visited[r][c-1] && grid[r][c-1]){
            dfs(grid, visited, r, c-1, ct);
        }
    }
    int minDays(vector<vector<int>>& grid) {
        vector<vector<int>> islands;
        int count=0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i =0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
                if(!visited[i][j] && grid[i][j]==1){
                    dfs(grid, visited, i, j, ctq);
                    count++;
                }
                if(count>1){
                    return 0;
                }
            }
        }
        if(ctq==1){
            return 1;
        }
        if(count==0){
            return 0;
        }
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        for(int r =0;r<grid.size();r++){
            for(int c =0;c<grid[0].size();c++){
                if(grid[r][c]==1){
                    grid[r][c]=0;
                    int t=0;
                    if(r+1>=0 && r+1<grid.size() && c>=0 && c<grid[0].size() && !visited[r+1][c] && grid[r+1][c]){
                        dfs(grid, visited, r+1, c, t);
                        if(ctq-t>1){
                        return 1;
                        }
                    }
                    else if(r>=0 && r<grid.size() && c+1>=0 && c+1<grid[0].size() && !visited[r][c+1] && grid[r][c+1]){
                        dfs(grid, visited, r, c+1, t);
                        if(ctq-t>1){
                        return 1;
                        }
                    }
                    else if(r-1>=0 && r-1<grid.size() && c>=0 && c<grid[0].size() && !visited[r-1][c] && grid[r-1][c]){
                        dfs(grid, visited, r-1, c, t);
                        if(ctq-t>1){
                        return 1;
                        }
                    }
                    else if(r>=0 && r<grid.size() && c-1>=0 && c-1<grid[0].size() && !visited[r][c-1] && grid[r][c-1]){
                        dfs(grid, visited, r, c-1, t);
                        if(ctq-t>1){
                        return 1;
                        }
                    }

                    visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
                    grid[r][c]=1;
                }
                
            }
        }



        return 2;
        
    }
};

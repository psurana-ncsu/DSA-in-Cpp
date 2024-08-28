class Solution {
public:
    int m=0, n=0;
    
    bool traverse(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c){
        bool ans=true;
        if(grid1[r][c]==0){
            ans= false;
        }
        grid2[r][c]=0;
        //cout<<r<<" "<<c<<endl;
        if(r-1>=0 && r-1<m && c>=0 && c<n && grid2[r-1][c]==1){
            ans = ans & traverse(grid1, grid2, r-1, c);
        }
        if(r+1>=0 && r+1<m && c>=0 && c<n && grid2[r+1][c]==1){
            ans = ans & traverse(grid1, grid2, r+1, c);
        }
        if(r>=0 && r<m && c-1>=0 && c-1<n && grid2[r][c-1]==1){
            ans = ans & traverse(grid1, grid2, r, c-1);
        }
        if(r>=0 && r<m && c+1>=0 && c+1<n && grid2[r][c+1]==1){
            ans = ans & traverse(grid1, grid2, r, c+1);
        }
        return ans;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int subisland=0;
        m=grid2.size();
        n=grid2[0].size();
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid2[i][j]==1){
                    cout<<i<<j<<endl;
                    if(traverse(grid1, grid2, i, j)){
                    cout<<i<<" "<<j<<endl;
                    subisland++;
                    }
                }
            }
        }
        return subisland;
    }
};

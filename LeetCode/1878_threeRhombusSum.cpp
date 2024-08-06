class Solution {
public:
    vector<int> sums;
    int m=0, n=0, half=0;
    void cal(vector<vector<int>>& grid, int r, int c){
        for(int i=1;i<=half;i++){
            if((r+i*2)<m && (c-i)>=0 && (c+i)<n){
                int s=0;
                for(int j=0;j<i;j++){
                    s+=grid[r+j][c+j];
                    s+=grid[r+i+j][c+i-j];
                    s+=grid[r+2*i-j][c-j];
                    s+=grid[r+i-j][c-i+j];
                }
                sums.push_back(s);
            }
            else{
                break;
            }
        }
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        half=(min(m,n)-1)/2;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sums.push_back(grid[i][j]);
                cal(grid, i, j);
            }
        }
        sort(sums.begin(), sums.end(), greater<int>());
        vector<int> ans;
        int curr=0;
        for(int a:sums){
            if(curr!=a){
                ans.push_back(a);
                curr=a;
                if(ans.size()==3){
                    return ans;
                }

            }

        }
        int t= sums.size();
        // ans.push_back(sums[t-3]);
        // ans.push_back(sums[t-2]);
        // ans.push_back(sums[t-1]);
        return ans;

    }
};

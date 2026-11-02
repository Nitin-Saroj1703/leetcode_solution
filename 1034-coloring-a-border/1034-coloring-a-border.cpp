class Solution {
public:
    vector<pair<int,int>> internal;
    void dfs(vector<vector<int>>& grid,int r,int c,int newcolor,int original){
        if(r<0 || c < 0 || r >=grid.size() || c >=grid[0].size() || grid[r][c]!=original) return;
        grid[r][c]=-newcolor;
        dfs(grid,r+1,c,newcolor,original);
        dfs(grid,r-1,c,newcolor,original);
        dfs(grid,r,c+1,newcolor,original);
        dfs(grid,r,c-1,newcolor,original);
        if(not (r==0 || c==0 || r==grid.size()-1 || c==grid[0].size() || grid[r+1][c]!=-newcolor || grid[r-1][c]!=-newcolor|| grid[r][c+1]!=-newcolor|| grid[r][c-1]!=-newcolor)){
            internal.push_back({r,c});
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        if(grid[row][col]==color) return grid;
        int original=grid[row][col];
        dfs(grid,row,col,color,original);
        for(auto x:internal){
            int a=x.first;
            int b=x.second;
            grid[a][b]=original;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]<0) grid[i][j]*=-1;
            }
        }
        return grid;
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int cc=0; // connected components
        //bfs
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]=='1'){
                    cc++;
                    grid[r][c]='0';
                    queue<pair<int,int>> qu;
                    qu.push({r,c});
                    while(! qu.empty()){
                        auto temp=qu.front();
                        qu.pop();
                        int currRow=temp.first;
                        int currCol=temp.second;
                        // right
                        if(currRow+1 <row && grid[currRow+1][currCol]=='1' ){
                            grid[currRow+1][currCol]='0';
                            qu.push({currRow+1,currCol});
                        }
                        //left
                        if(currRow-1 >=0 && grid[currRow-1][currCol]=='1' ){
                            grid[currRow-1][currCol]='0';
                            qu.push({currRow-1,currCol});
                        }
                        //down
                        if(currCol+1 < col && grid[currRow][currCol+1]=='1' ){
                            grid[currRow][currCol+1]='0';
                            qu.push({currRow,currCol+1});
                        }
                        if(currCol-1>=0 && grid[currRow][currCol-1]=='1' ){
                            grid[currRow][currCol-1]='0';
                            qu.push({currRow,currCol-1 });
                        }
                    }
                }
            }
        }
        return cc;
    }
};
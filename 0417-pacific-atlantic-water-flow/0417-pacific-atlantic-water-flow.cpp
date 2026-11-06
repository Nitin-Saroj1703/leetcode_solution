class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int row;
    int col;
    vector<vector<int>> h;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        row = heights.size();
        col = heights[0].size();
        h = heights;
        queue<pair<int, int>> pacificbfs;
        queue<pair<int, int>> Atlanticbfs;
        for (int i = 0; i < row; i++) {
            pacificbfs.push({i, 0});
            Atlanticbfs.push({i, col - 1});
        }
        for (int j = 1; j < col; j++) {
            pacificbfs.push({0, j});
        }
        for (int j = 0; j < col - 1; j++) {
            Atlanticbfs.push({row - 1, j});
        }
        vector<vector<bool>> pac = bfs(pacificbfs);
        vector<vector<bool>> at = bfs(Atlanticbfs);
        vector<vector<int>> result;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (pac[i][j] && at[i][j])
                    result.push_back({i, j});
            }
        }
        return result;
    }
    vector<vector<bool>> bfs(queue<pair<int, int>>& qu) {
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        while (!qu.empty()) {
            auto cell = qu.front();
            qu.pop();
            int i = cell.first;
            int j = cell.second;
            visited[i][j] = true;
            for (int d = 0; d < 4; d++) {
                int newRow = i + dir[d][0];
                int newCol = j + dir[d][1];
                if (newRow >= 0 && newCol >= 0 && newRow < row && newCol < col) {
                    if (not visited[newRow][newCol] &&
                        h[newRow][newCol] >= h[i][j]) {
                        qu.push({newRow, newCol});
                    }
                }
            }
        }
        return visited;
    }
};
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        auto fill = [&](int r, int c) {
            stack<pair<int, int>> st;
            grid[r][c] = 1;
            st.push({r, c});
            while (!st.empty()) {
                auto [x, y] = st.top();
                st.pop();
                for (auto& d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;
                        st.push({nx, ny});
                    }
                }
            }
        };

        // 1. Eliminate islands touching the border
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && grid[i][j] == 0) {
                    fill(i, j);
                }
            }
        }

        // 2. Count remaining islands (all are closed)
        int count = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    fill(i, j);
                }
            }
        }

        return count;
    }
};
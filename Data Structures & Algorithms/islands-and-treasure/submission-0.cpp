class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }

        int rows[] = {-1, 1, 0, 0};
        int cols[] = {0, 0, -1, 1};

        while(!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nr = r + rows[i];
                int nc = c + cols[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 2147483647)
                {
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};

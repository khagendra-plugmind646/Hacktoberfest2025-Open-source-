class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    vector<vector<int>> v = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        priority_queue<pp, vector<pp>, greater<>> bc;

        for (int row = 0; row < n; row++) {
            for (int col : {0, m - 1}) {
                bc.push({heightMap[row][col], {row, col}});
                vis[row][col] = true;
            }
        }
        for (int col = 0; col < m; col++) {
            for (int row : {0, n - 1}) {
                bc.push({heightMap[row][col], {row, col}});
                vis[row][col] = true;
            }
        }

        int water = 0;
        while (!bc.empty()) {
            pp k = bc.top();
            bc.pop();
            int height = k.first;
            int i = k.second.first;
            int j = k.second.second;

            for (vector<int>& dir : v) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];
                if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && !vis[i_][j_]) {
                    water += max(height - heightMap[i_][j_], 0);
                    bc.push({max(height, heightMap[i_][j_]), {i_, j_}});
                    vis[i_][j_] = true;
                }
            }
        }
        return water;
    }
};

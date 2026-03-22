class Solution {
public:
    int orangesRot(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        int time = 0;
        
        while(!q.empty() && fresh > 0) {
            int size = q.size();
            time++;
            
            for(int i = 0; i < size; i++) {
                auto front = q.front();
                q.pop();
                
                int x = front.first;
                int y = front.second;
                
                for(int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m 
                       && grid[nx][ny] == 1) {
                        
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
        }
        
        return fresh == 0 ? time : -1;
    }
};

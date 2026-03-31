class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        // push all rotten & count fresh
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }

        int minutes = 0;
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty() && fresh>0){
            int size = q.size();
            minutes++;

            for(int i=0;i<size;i++){
                auto [r,c] = q.front();
                q.pop();

                for(auto d:dir){
                    int nr = r+d.first;
                    int nc = c+d.second;

                    if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        fresh--;
                        q.push({nr,nc});
                    }
                }
            }
        }

        return fresh==0 ? minutes : -1;
    }
};
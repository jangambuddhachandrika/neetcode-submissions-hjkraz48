class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<pair<int,int>>directions = {{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                {
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            auto [r,c] = q.front();
            q.pop();
            for(auto n : directions)
            {
                int nx = r+n.first;
                int ny = c+n.second;

                if(nx>=0 && ny>=0 &&nx<grid.size() && ny<grid[0].size() && grid[nx][ny]==INT_MAX)
                {
                    grid[nx][ny] = grid[r][c]+1;
                    q.push({nx,ny});
                }
            }
        }
        
    }
};

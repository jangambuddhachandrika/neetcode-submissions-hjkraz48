class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<pair<int,int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
        int count = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                
                if(grid[i][j]=='1')
                {
                    count++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j]=='0';
                    while(!q.empty())
                    {
                        auto [r,c] = q.front();
                        q.pop();
                        for(auto n: directions)
                        {
                            int nx = r+n.first;
                            int ny = c+n.second;
                            if(nx>=0 && ny>=0 && nx<grid.size()&& ny<grid[0].size()&& grid[nx][ny]=='1')
                            {
                                q.push({nx,ny});
                                grid[nx][ny]='0';
                            }
                        }
                    }
                }
            }
        }
        return count;
        
    }
};

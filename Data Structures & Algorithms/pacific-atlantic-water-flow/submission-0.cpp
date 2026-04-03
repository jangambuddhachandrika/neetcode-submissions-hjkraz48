class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n,false));
        vector<vector<bool>> atl(m, vector<bool>(n,false));

        // Pacific borders
        for(int i=0;i<m;i++) dfsIter(heights, pac, i, 0);
        for(int j=0;j<n;j++) dfsIter(heights, pac, 0, j);

        // Atlantic borders
        for(int i=0;i<m;i++) dfsIter(heights, atl, i, n-1);
        for(int j=0;j<n;j++) dfsIter(heights, atl, m-1, j);

        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }

    void dfsIter(vector<vector<int>>& heights,
                 vector<vector<bool>>& vis,
                 int sr, int sc) {

        int m = heights.size();
        int n = heights[0].size();

        stack<pair<int,int>> st;
        st.push({sr,sc});

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!st.empty()){
            auto [r,c] = st.top();
            st.pop();

            if(vis[r][c]) continue;
            vis[r][c] = true;

            for(auto [dr,dc] : dir){
                int nr = r + dr;
                int nc = c + dc;

                if(nr>=0 && nc>=0 && nr<m && nc<n &&
                   !vis[nr][nc] &&
                   heights[nr][nc] >= heights[r][c]){
                    st.push({nr,nc});
                }
            }
        }
    }
};

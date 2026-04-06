class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()){
            return;
        }

        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>> q;

        auto push = [&](int r, int c){
            if(r>=0 && r<m && c>=0 && c<n && board[r][c]=='O'){
                board[r][c] = '#';
                q.push({r,c});
            }
        };

        for(int i=0;i<m;i++){
            push(i,0);
            push(i,n-1);   // fixed
        }

        for(int j=0;j<n;j++){
            push(0,j);
            push(m-1,j);   // fixed
        }

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(auto [rd,cd]: dirs){
                push(r+rd,c+cd);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){   // fixed
                    board[i][j] = 'X';
                }
                else if(board[i][j]=='#'){  // fixed
                    board[i][j]='O';
                }
            }
        }
    }
};
class Solution {
public:
  
    typedef pair<int, int> p;
  
    bool checkValid(int i, int j, int r, int c) {
      if (i < 0 || j < 0)
        return false;
      
      if (i >= r || j >= c)
        return false;
      
      return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        int vis[301][301];
        memset(vis, 0, sizeof(vis));
        int dir[4][2] = {{0,1}, {0, -1},{1,0},{-1, 0}};
      
        int ans = 0;
        int r = grid.size();
        int c = grid[0].size();
      
        for(int i = 0 ; i < r ; i++) {
          for(int j = 0 ; j < c ; j++) {
            
            if (vis[i][j] == 1 || grid[i][j] == '0')
              continue;
            
          queue<p>q;
            q.push({i,j});
            ans++;
          
              while(!q.empty()) {
                p curr = q.front();
                q.pop();
                
                int row = curr.first, col = curr.second;
               // cout<<row<<" "<<col<<endl;

                
                if(!checkValid(row, col, r, c) || vis[row][col] == 1 || grid[row][col] == '0')
                  continue;
                
                //cout<<row<<" "<<col<<endl;
                vis[row][col] = 1;
                
                for(int e = 0 ; e < 4; e++) {
                    q.push({row + dir[e][0], col + dir[e][1]});
                  }
                }
            
              }
          }
      
      return ans;
        }     
};
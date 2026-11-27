class Solution {
public:
    int n,m;
    bool vis[300][300];
    vector<pair<int,int>>movement={{0,1},{0,-1},{1,0},{-1,0}};

    bool is_valid(int ci,int cj)
    {
        if(ci>=n || ci<0 || cj>=m ||cj<0)
        return false;
        return true;
    }

    void dfs(int si,int sj,vector<vector<char>>& grid)           //& soho pathate hbe 
    {
        vis[si][sj]=true;
        for(int i=0;i<4;i++)
        {
            int ci,cj;
            ci=si+movement[i].first;
            cj=sj+movement[i].second;
            if(is_valid(ci,cj) && !vis[ci][cj] && grid[ci][cj]=='1')
            {
                dfs(ci,cj,grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        memset(vis,false,sizeof(vis));
        int num_of_island=0;
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    dfs(i,j,grid);
                    num_of_island++;
                }
            }
        }

        return num_of_island;
    }
};
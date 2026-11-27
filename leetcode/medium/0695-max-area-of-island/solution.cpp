class Solution {
public:
    int max_area;
    int n,m;
    bool vis[50][50];
    int area;
    vector<pair<int,int>>movement={{0,1},{0,-1},{1,0},{-1,0}};

    bool is_valid(int ci,int cj)
    {
        if(ci>=n || ci<0 || cj>=m ||cj<0)
        return false;
        return true;
    }

    void dfs(int si,int sj,vector<vector<int>>& grid)           //& soho pathate hbe 
    {
        area++;
        max_area=max({max_area,area});
        vis[si][sj]=true;
        for(int i=0;i<4;i++)
        {
            int ci,cj;
            ci=si+movement[i].first;
            cj=sj+movement[i].second;
            if(is_valid(ci,cj) && !vis[ci][cj] && grid[ci][cj]==1)
            {
                dfs(ci,cj,grid);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        max_area=0;
        memset(vis,false,sizeof(vis));
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    area=0;
                    dfs(i,j,grid);
                }
            }
        }

        return max_area;
    }
};
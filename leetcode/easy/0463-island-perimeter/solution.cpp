class Solution {
public:
    int count;
    bool vis[100][100];
    vector<pair<int,int>>movement={{0,1},{0,-1},{1,0},{-1,0}};
    int n,m;
    bool is_valid(int ci,int cj)
    {
        if(ci>=n || ci<0 || cj>=m ||cj<0)
        return false;
        return true;
    }

    void dfs(int si,int sj,vector<vector<int>>& grid)           //& soho pathate hbe 
    {
        vis[si][sj]=true;
        for(int i=0;i<4;i++)
        {
            int ci,cj;
            ci=si+movement[i].first;
            cj=sj+movement[i].second;
            if(!is_valid(ci,cj))
                count++;
            else if(is_valid(ci,cj) && grid[ci][cj]==0)
                count++;
            else if(is_valid(ci,cj) && !vis[ci][cj] && grid[ci][cj]==1)
                dfs(ci,cj,grid);
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        count=0;
        n=grid.size();
        m=grid[0].size();
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                dfs(i,j,grid);
            }
        }
        return count;
    }
};
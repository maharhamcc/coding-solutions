class Solution {
public:
    int m,n;
    bool vis[500][500];
    int sub_islands;
    vector<pair<int,int>>movement={{0,1},{0,-1},{1,0},{-1,0}};
    bool flag;
    bool is_valid(int ci,int cj)
    {
        if(ci>=m || ci<0 || cj>=n || cj<0)
            return false;
        return true;
    }

    void dfs(int si,int sj,vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {

        vis[si][sj]=true;
        if(grid1[si][sj]==0)
            flag=false;
        for(int i=0;i<4;i++)
        {
            int ci,cj;
            ci=si+movement[i].first;
            cj=sj+movement[i].second;
            if(is_valid(ci,cj) && !vis[ci][cj] && grid2[ci][cj]==1)
            {
                dfs(ci,cj,grid1,grid2);
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m=grid1.size();
        n=grid1[0].size();
        sub_islands=0;
        memset(vis,false,sizeof(vis));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid2[i][j]==1)      //sudhu grid 2 ke pathabo , karon age grid2 er island gulo ber korte hbe 
                {
                    flag=true;
                    dfs(i,j,grid1,grid2);
                    if(flag==true)
                    sub_islands++;
                }
            }
        }
        return sub_islands;
    }
};
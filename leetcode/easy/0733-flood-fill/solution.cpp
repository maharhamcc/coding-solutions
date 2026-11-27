class Solution {
public:
    bool vis[50][50];
    vector<pair<int,int>>movement={{0,1},{0,-1},{1,0},{-1,0}};
    int n,m;
    int val;

    bool is_valid(int i,int j)                        
    {                                                  
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        return true;
    }
    void dfs(vector<vector<int>>& image, int si, int sj, int color)           
    {
        vis[si][sj]=true;
        image[si][sj]=color;
        for(int i=0;i<4;i++)
        {
            int ci,cj;
            ci=si+movement[i].first;
            cj=sj+movement[i].second;
            if(is_valid(ci,cj) && !vis[ci][cj] && image[ci][cj]==val)
                dfs(image,ci,cj,color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n=image.size();
        m=image[0].size();
        val=image[sr][sc];
        dfs(image,sr,sc,color);
        return image;
    }
};
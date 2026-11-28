# Count Sub Islands

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given two `m x n` binary matrices `grid1` and `grid2` containing only `0`'s (representing water) and `1`'s (representing land). An  **island**  is a group of `1`'s connected  **4-directionally**  (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in `grid2` is considered a  **sub-island** if there is an island in `grid1` that contains  **all**  the cells that make up  **this**  island in `grid2`.

Return the  ***number**  of islands in  *`grid2`* that are considered  **sub-islands** *.

 

Original
C++
 **Example 1:** 

```
Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.

```

 **Example 2:** 

```
Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2 
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.

```

 

 **Constraints:** 

- m == grid1.length == grid2.length
- n == grid1[i].length == grid2[i].length
- 1 <= m, n <= 500
- grid1[i][j] and grid2[i][j] are either 0 or 1.

## Solution

**Language:** C++  
**Runtime:** 33 ms (beats 72.49%)  
**Memory:** 93.4 MB (beats 91.97%)  
**Submitted:** 2026-11-28T12:54:41.403Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/count-sub-islands/)
# Number of Islands

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return  *the number of islands*.

An  **island**  is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Original
C++
 **Example 1:** 

```
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

```

 **Example 2:** 

```
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

```

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 300
- grid[i][j] is '0' or '1'.

## Solution

**Language:** C++  
**Runtime:** 28 ms (beats 47.75%)  
**Memory:** 16.3 MB (beats 67.19%)  
**Submitted:** 2026-11-27T05:39:34.611Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-islands/)
# Island Perimeter

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given `row x col` `grid` representing a map where `grid[i][j] = 1` represents land and `grid[i][j] = 0` represents water.

Grid cells are connected  **horizontally/vertically**  (not diagonally). The `grid` is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Original
C++
 **Example 1:** 

```
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

```

 **Example 2:** 

```
Input: grid = [[1]]
Output: 4

```

 **Example 3:** 

```
Input: grid = [[1,0]]
Output: 4

```

 

 **Constraints:** 

- row == grid.length
- col == grid[i].length
- 1 <= row, col <= 100
- grid[i][j] is 0 or 1.
- There is exactly one island in grid.

## Solution

**Language:** C++  
**Runtime:** 15 ms (beats 19.58%)  
**Memory:** 104.1 MB (beats 19.00%)  
**Submitted:** 2026-11-26T14:12:03.194Z  

```cpp
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
                { 
                    dfs(i,j,grid);
                    break;
                }
            }
        }
        return count;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/island-perimeter/)
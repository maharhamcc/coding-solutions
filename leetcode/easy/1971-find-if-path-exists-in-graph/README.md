# Find if Path Exists in Graph

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

There is a  **bi-directional**  graph with `n` vertices, where each vertex is labeled from `0` to `n - 1` (**inclusive**). The edges in the graph are represented as a 2D integer array `edges`, where each `edges[i] = [ui, vi]` denotes a bi-directional edge between vertex `ui` and vertex `vi`. Every vertex pair is connected by  **at most one**  edge, and no vertex has an edge to itself.

You want to determine if there is a  **valid path**  that exists from vertex `source` to vertex `destination`.

Given `edges` and the integers `n`, `source`, and `destination`, return `true` *if there is a  **valid path**  from* `source` *to* `destination` *, or* `false` *otherwise**.* 

 

Original
C++
 **Example 1:** 

```
Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2

```

 **Example 2:** 

```
Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.

```

 

 **Constraints:** 

- 1 <= n <= 2 * 105
- 0 <= edges.length <= 2 * 105
- edges[i].length == 2
- 0 <= ui, vi <= n - 1
- ui != vi
- 0 <= source, destination <= n - 1
- There are no duplicate edges.
- There are no self edges.

## Solution

**Language:** C++  
**Runtime:** 399 ms (beats 37.62%)  
**Memory:** 277.1 MB (beats 91.49%)  
**Submitted:** 2026-11-27T04:48:45.104Z  

```cpp
class Solution {
public:
    vector<int> adj_list[200000];
    bool vis[200000];

    void dfs(int source)
    {
        vis[source]=true;
        for(int child : adj_list[source])
        {
            if(!vis[child])
                dfs(child);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        memset(vis,false,sizeof(vis));
        for(int i=0;i<edges.size();i++)
        {
           int a=edges[i][0];                    //proti index a duita kore element thakbe bola ache 
           int b=edges[i][1];
           adj_list[a].push_back(b);
           adj_list[b].push_back(a);
        }
        dfs(source);
        return vis[destination];
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-if-path-exists-in-graph/)
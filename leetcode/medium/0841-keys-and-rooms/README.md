# Keys and Rooms

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

There are `n` rooms labeled from `0` to `n - 1` and all the rooms are locked except for room `0`. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of  **distinct keys**  in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array `rooms` where `rooms[i]` is the set of keys that you can obtain if you visited room `i`, return `true`  *if you can visit  **all**  the rooms, or*  `false`  *otherwise*.

 

 **Example 1:** 

```
Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.

```

 **Example 2:** 

```
Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.

```

 

 **Constraints:** 

- n == rooms.length
- 2 <= n <= 1000
- 0 <= rooms[i].length <= 1000
- 1 <= sum(rooms[i].length) <= 3000
- 0 <= rooms[i][j] < n
- All the values of rooms[i] are unique.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 14.5 MB (beats 67.18%)  
**Submitted:** 2026-11-01T17:56:28.163Z  

```cpp
class Solution {
public:
    bool vis[1001];

    void bfs(int src,vector<vector<int>>& rooms)
    {
        queue<int>q;
        q.push(src);
        vis[src]=true;
        while(!q.empty())
        {
            int par=q.front();
            q.pop();

            for(int child : rooms[par])
            {
                if(!vis[child])
                {
                    q.push(child);
                    vis[child]=true;
                }
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        memset(vis,false,sizeof(vis));
        int n=rooms.size();
        bfs(0,rooms);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                return false;
            }
        }
        return true;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/keys-and-rooms/)
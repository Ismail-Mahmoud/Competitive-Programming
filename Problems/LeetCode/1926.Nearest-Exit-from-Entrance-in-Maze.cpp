// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

class Solution {
public:
    int di[4] = {0, 0, -1, 1};
    int dj[4] = {-1, 1, 0, 0};
    bool vis[101][101];
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<tuple<int, int, int>> q({{entrance[0], entrance[1], 0}});
        vis[entrance[0]][entrance[1]] = true;
        while(!q.empty()) {
            tuple<int, int, int> p = q.front();
            q.pop();
            int i = get<0>(p), j = get<1>(p), steps = get<2>(p);
            for(int k = 0; k < 4; ++k) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if(!valid(ni, nj, maze)) {
                    continue;
                }
                if(exit(ni, nj, maze)) {
                    return steps + 1;
                }
                vis[ni][nj] = true;
                q.push({ni, nj, steps + 1});
            }
        }
        return -1;
    }
    bool empty(int i, int j, vector<vector<char>>& maze) {
        return maze[i][j] == '.';
    }
    bool inside(int i, int j, vector<vector<char>>& maze) {
        return i >= 0 && i < maze.size() && j >= 0 && j < maze[0].size();
    }
    bool valid(int i, int j, vector<vector<char>>& maze) {
        return inside(i, j, maze) && empty(i, j, maze) && !vis[i][j];
    }
    bool border(int i, int j, vector<vector<char>>& maze) {
        return i == 0 || i == maze.size() - 1 || j == 0 || j == maze[0].size() - 1;
    }
    bool exit(int i, int j, vector<vector<char>>& maze) {
        return border(i, j, maze) && empty(i, j, maze);
    }
};
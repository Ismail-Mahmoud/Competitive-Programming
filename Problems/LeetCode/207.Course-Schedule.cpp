// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool vis[2000], finished[2000];
    vector<int> pre[2000];
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto& v : prerequisites) {
            pre[v[0]].push_back(v[1]);
        }
        for(int c = 0; c < numCourses; ++c) {
            if(!canFinish(c)) {
                return false;
            }
        }
        return true;
    }
    bool canFinish(int c) {
        if(finished[c]) return true;
        if(vis[c]) return false;
        vis[c] = true;
        for(int p : pre[c]) {
            if(!canFinish(p)) {
                return false;
            }
        }
        return finished[c] = true;
    }
};
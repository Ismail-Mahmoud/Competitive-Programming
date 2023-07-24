// https://leetcode.com/problems/asteroid-collision/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> v;
        for(int x : asteroids) {
            while(!v.empty() && colliding(v.back(), x) && abs(x) > abs(v.back())) {
                v.pop_back();
            }
            if(v.empty() || !colliding(v.back(), x)) {
                v.push_back(x);
            }
            else if(abs(x) == abs(v.back())) {
                v.pop_back();
            }
        }
        return v;
    }

    bool colliding(const int& a, const int& b) {
        return a > 0 && b < 0;
    }
};
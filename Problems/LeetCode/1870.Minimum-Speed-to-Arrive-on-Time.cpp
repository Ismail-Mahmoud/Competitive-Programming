// https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, r = 1e7, m;
        while(l < r) {
            m = (l + r) >> 1;
            if(check(m, dist, hour)) r = m;
            else l = m + 1;
        }
        return check(l, dist, hour)? l : -1;
    }

    bool check(int speed, const vector<int>& dist, double max_hours) {
        double hours = 0;
        for(int i = 0; i < dist.size() - 1; ++i) {
            hours += ceil(dist[i], speed);
        }
        hours += 1.0 * dist.back() / speed;
        return hours <= max_hours;
    }

    int ceil(int a, int b) {
        return (a + b - 1) / b;
    }
};
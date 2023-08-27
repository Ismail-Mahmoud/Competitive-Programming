// https://leetcode.com/problems/frog-jump/

class Solution {
    int mem[2000][2000];
public:
    bool canCross(vector<int>& stones) {
        memset(mem, -1, sizeof(mem));
        return dp(0, 0, stones);
    }

    bool dp(int cur, int pre, const vector<int>& stones) {
        if(cur == stones.size() - 1) return true;

        int& ret = mem[cur][pre];
        if(~ret) return ret;

        const vector<int> nxt = getNext(cur, pre, stones);
        for(int i : nxt) {
            if(dp(i, cur, stones)) {
                return ret = true;
            }
        }

        return ret = false;
    }

    vector<int> getNext(int cur, int pre, const vector<int>& stones) {
        int d = stones[cur] - stones[pre];
        int nxt = lower_bound(stones.begin() + cur + 1, stones.end(), stones[cur] + d - 1) - stones.begin();
        vector<int> ret;
        while(nxt < stones.size() && valid(cur, pre, nxt, stones)) {
            ret.push_back(nxt++);
        }
        return ret;
    }

    bool valid(int cur, int pre, int nxt, const vector<int>& stones) {
        int d1 = stones[cur] - stones[pre];
        int d2 = stones[nxt] - stones[cur];
        for(int k = -1; k <= 1; ++k) {
            if(d2 == d1 + k) {
                return true;
            }
        }
        return false;
    }
};

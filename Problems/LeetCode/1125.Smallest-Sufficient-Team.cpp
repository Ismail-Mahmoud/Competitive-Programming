// https://leetcode.com/problems/smallest-sufficient-team/

class Solution {
public:
    static const int S = 16, P = 60, OO = 0x3f3f3f3f;
    int mem[1 << S][P];
    int num_skills, num_people;
    unordered_map<string, int> skill_id;
    int people_skills_mask[P];
    vector<int> ans;
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        num_skills = req_skills.size();
        num_people = people.size();
        for(int i = 0; i < num_skills; ++i) {
            skill_id[req_skills[i]] = i;
        }
        for(int p = 0; p < num_people; ++p) {
            int mask = 0;
            for(const string& skill : people[p]) {
                int sk = skill_id[skill];
                mask |= 1 << sk;
            }
            people_skills_mask[p] = mask;
        }
        memset(mem, -1, sizeof(mem));
        dp(0, 0);
        build(0, 0);
        return ans;
    }

    int dp(int mask, int p) {
        if(__builtin_popcount(mask) == num_skills) return 0;
        if(p == num_people) return OO;

        int& ret = mem[mask][p];
        if(~ret) return ret;

        return ret = min(dp(mask, p + 1), 1 + dp(mask | people_skills_mask[p], p + 1));
    }

    void build(int mask, int p) {
        if(__builtin_popcount(mask) == num_skills || p == num_people) return;

        if(mem[mask][p] == dp(mask, p + 1)) {
            build(mask, p + 1);
        }
        else {
            ans.push_back(p);
            build(mask | people_skills_mask[p], p + 1);
        }
    }
};
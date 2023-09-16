// https://leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size();
        vector<int> candies(ratings.size(), 1);
        for(int i = 1; i < N; ++i) {
            if(ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for(int i = N - 2; ~i; --i) {
            if(ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

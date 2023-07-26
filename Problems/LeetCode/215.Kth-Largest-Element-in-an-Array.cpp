// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
    static const int N = 1e4;
    int F[(N << 1) + 1];
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(int x : nums) {
            ++F[num_to_idx(x)];
        }
        for(int i = (N << 1); ~i; --i) {
            if(k <= F[i]) {
                return idx_to_num(i);
            }
            k -= F[i];
        }
        assert(false);
        return 0;
    }
    int num_to_idx(int num) {
        return num + N;
    }
    int idx_to_num(int idx) {
        return idx - N;
    }
};
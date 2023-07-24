// https://leetcode.com/problems/can-place-flowers/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0; i < flowerbed.size(); ++i) {
            if(!n) {
                break;
            }
            if(flowerbed[i]
            || (i && flowerbed[i - 1])
            || (i < flowerbed.size() - 1 && flowerbed[i + 1])) {
                continue;
            }
            flowerbed[i] = 1;
            --n;
        }
        return !n;
    }
};
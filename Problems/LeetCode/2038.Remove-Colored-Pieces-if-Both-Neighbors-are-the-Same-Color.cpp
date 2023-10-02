class Solution {
public:
    bool winnerOfGame(string colors) {
        int moves[2] = {0, 0};
        for(int i = 1; i < colors.size() - 1; ++i) {
            moves[colors[i] - 'A'] += colors[i] == colors[i - 1] && colors[i] == colors[i + 1];
        }
        return moves[0] > moves[1];
    }
};

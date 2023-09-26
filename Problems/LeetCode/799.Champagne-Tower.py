class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        def excess(glass: int) -> float:
            return 0 if glass < 0 or glass >= len(dp) \
                    else max(0, dp[glass] - 1)

        dp = [poured]
        for row in range(1, query_row + 1):
            dp = [
                0.5 * (excess(glass - 1) + excess(glass))
                for glass in range(query_glass + 1)
            ]
        return min(1, dp[query_glass])

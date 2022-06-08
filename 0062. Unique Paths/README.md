1. This is math problem. Be careful the integer overflow while calculating combination.
2. You can run DP with recursion. dp_map[i][j] = dp_map[i-1][j] + dp_map[i][j-1].
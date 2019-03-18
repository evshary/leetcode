from typing import List
import math

class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        adj_matrix = [[math.inf] * (N+1) for i in range(N+1)]
        distance_array = [math.inf]*(N+1)
        for start,stop,weight in times:
            adj_matrix[start][stop] = weight
        for i in range(1,N+1):
            adj_matrix[i][i] = 0
        for i in range(1,N+1):
            distance_array[i] = adj_matrix[K][i]
        # Set check array
        check = [0]*(N+1)
        check[K] = 1
        # Dijkstra Algorithm
        for i in range(1,N):
            min = math.inf
            min_idx = -1
            for j in range(1,N+1):
                if check[j] == 0 and distance_array[j] < min:
                    min = distance_array[j]
                    min_idx = j
            if min_idx == -1:
                break
            check[min_idx] = 1
            for j in range(1,N+1):
                if adj_matrix[min_idx][j] != math.inf and distance_array[j] > distance_array[min_idx] + adj_matrix[min_idx][j]:
                    distance_array[j] = distance_array[min_idx] + adj_matrix[min_idx][j]
        ret_val = max(distance_array[1:])
        if ret_val == math.inf:
            ret_val = -1
        return ret_val

solution = Solution()
# answer = 2
times = [[2,1,1],[2,3,1],[3,4,1]]
N = 4
K = 2
# answer
times = [[1,2,1]]
N = 2
K = 2
print("solution=", solution.networkDelayTime(times, N, K))
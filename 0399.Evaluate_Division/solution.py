from typing import List
import collections

class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        adj_matrix = collections.defaultdict(dict)
        for (num1,num2),value in zip(equations, values):
            adj_matrix[num1][num2] = value
            adj_matrix[num2][num1] = 1/value
            adj_matrix[num1][num1] = 1
            adj_matrix[num2][num2] = 1
        for i in adj_matrix:
            for j in adj_matrix[i]:
                for k in adj_matrix[i]:
                    adj_matrix[j][k] = adj_matrix[j][i] * adj_matrix[i][k]
        return [adj_matrix[num1].get(num2,-1.0) for num1,num2 in queries]

solution = Solution()
equations = [["a","b"],["b","c"],["c","d"],["x","y"]]
values = [2.0, 3.0, 4.0, 2.0]
queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"],["a","d"]]
print(solution.calcEquation(equations, values, queries))
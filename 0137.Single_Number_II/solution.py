from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        hash_table = {}
        for i in nums:
            try:
                hash_table[i] += 1
                if hash_table[i] == 3:
                    del hash_table[i]
            except:
                hash_table[i] = 1
        return list(hash_table)[0]

solution = Solution()
print("single number=", solution.singleNumber([2,2,3,2]))

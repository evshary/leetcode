class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        hash_table = {}
        for num in nums:
            if num in hash_table.keys():
                del hash_table[num]
            else:
                hash_table[num] = 1
        return list(hash_table.keys())[0]
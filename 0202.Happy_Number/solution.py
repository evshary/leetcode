class Solution:
    def isHappy(self, n: int) -> bool:
        hashs = {}
        while n not in hashs:
            hashs[n] = 1
            new_n = 0
            while n != 0:
                new_n += (n%10) ** 2
                n = n // 10
            if new_n == 1:
                return True
            n = new_n
        return False

solution = Solution()
print(solution.isHappy(19))
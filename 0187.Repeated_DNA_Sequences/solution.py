from typing import List

class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        dict_map = {}
        for i in range(len(s)):
            if i + 9 > len(s):
                break
            try:
                dict_map[s[i:i+10]] += 1
            except:
                dict_map[s[i:i+10]] = 1
        return [key for key,value in dict_map.items() if value > 1]

solution = Solution()
test_cases = [("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT", ["AAAAACCCCC", "CCCCCAAAAA"]),
             ]
for case in test_cases:
    answer = solution.findRepeatedDnaSequences(case[0])
    if (answer == case[1]):
        print("pass: %s" % case[0])
    else:
        print("fail:", case[0], "correct:", case[1], "answer:", answer)
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        hashs = {}
        max_len = left_window = window_len = 0
        for i in range(len(s)):
            if s[i] in hashs:
                max_len = max(max_len, window_len)
                left_window = max(left_window, hashs[s[i]])
                window_len = i - left_window
            else:
                window_len += 1
            hashs[s[i]] = i
        max_len = max(max_len, window_len)   
        return max_len

solution = Solution()
test_cases = [("abcabcbb", 3),
              ("bbbbb", 1),
              ("pwwkew", 3),
              (" ", 1),      # Be careful while len(s) == 1
              ("dvdf", 3),   # We can't recount from second 'd'. This should be "vdf"
              ("abba", 2),   # If we get index between two 'a', b repeats.
              ("tmmzuxt", 5)
             ]
for case in test_cases:
    answer = solution.lengthOfLongestSubstring(case[0])
    if (answer == case[1]):
        print("pass: %s" % case[0])
    else:
        print("fail: %s correct: %d, answer: %d" % (case[0], case[1], answer))
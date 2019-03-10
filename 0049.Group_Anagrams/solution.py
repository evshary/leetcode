class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashs = {}
        for str in strs:
            sort_tuple = tuple(sorted(list(str)))
            try:
                hashs[sort_tuple].append(str)
            except:
                hashs[sort_tuple] = [str]
        ret_list = []
        for key, value in hashs.items():
            ret_list.append(value)
        return ret_list
use std::cmp;

impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let s: &String = &strs[0];
        let mut slen = s.len();
        for i in 1..strs.len() {
        	slen = cmp::min(slen, strs[i].len());
        	let mut common_len = 0;
        	while common_len < slen {
                if strs[i].as_bytes()[common_len] != s.as_bytes()[common_len] {
                    break;
                }
        		common_len += 1;
        	}
        	if common_len < slen {
        		slen = common_len;
        	}
        }
        String::from(&s[..slen])
    }
}
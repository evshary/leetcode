use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut hash = HashMap::new();
        let mut ans = Vec::new();
        for i in 0..nums.len() {
        	if hash.contains_key(&(target - nums[i])) {
        		ans.push(hash[&(target-nums[i])]);
        		ans.push(i as i32);
        		break;
        	}
        	hash.insert(nums[i], i as i32);
        }
        ans
    }
}
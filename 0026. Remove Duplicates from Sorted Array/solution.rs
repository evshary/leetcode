impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut newsize = 0;
        let mut idx = 0;
        while idx < nums.len() {
        	nums[newsize] = nums[idx];
        	while idx + 1 < nums.len() && nums[idx+1] == nums[newsize] {
        		idx += 1;
        	}
            newsize += 1;
        	idx += 1;
        }
        newsize as i32
    }
}
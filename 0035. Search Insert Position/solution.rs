impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let mut left: i32 = 0;
        let mut right: i32 = nums.len() as i32 - 1;
        while left <= right {
        	let mid: usize = (left + (right - left) / 2) as usize;
        	if nums[mid] > target {
        		right = mid as i32 - 1;
        	} else if nums[mid] < target {
        		left = mid as i32 + 1;
        	} else {
        		return mid as i32;
        	}
        }
        (right + 1) as i32
    }
}
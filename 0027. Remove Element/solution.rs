impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        if nums.len() == 0 { return 0; }
        let mut newsize = nums.len() as i32;
        let mut left = 0;
        let mut right = nums.len() - 1;
        while left <= right {
        	if nums[right] == val {
        		newsize -= 1;
                if (right == 0) { break; }
        		right -= 1;
        	} else if nums[left] == val {
                nums.swap(left, right);
        		left += 1;
        	} else {
        		left += 1;
        	}
        }
        newsize
    }
}
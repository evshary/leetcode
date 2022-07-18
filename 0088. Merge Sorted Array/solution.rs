impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        for i in (0..m).rev() {
        	nums1[(i+n) as usize] = nums1[i as usize];
        }
        let mut idx = 0;
        let mut idx1 = 0;
        let mut idx2 = 0;
        while idx1 < m && idx2 < n {
        	if nums1[(n+idx1) as usize] < nums2[idx2 as usize] {
        		nums1[idx as usize] = nums1[(n+idx1) as usize];
        		idx1 += 1;
        	} else {
        		nums1[idx as usize] = nums2[idx2 as usize];
        		idx2 += 1;
        	}
        	idx += 1;
        }
        while idx1 < m {
        	nums1[idx as usize] = nums1[(n+idx1) as usize];
        	idx += 1;
        	idx1 += 1;
        }
        while idx2 < n {
        	nums1[idx as usize] = nums2[idx2 as usize];
        	idx += 1;
        	idx2 += 1;
        }
    }
}
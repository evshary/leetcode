1. We should simplify the problem:
   - When nums[mid] > target >= nums[left], we should find left to mid for target.
   - When nums[right] >= target > nums[mid], we should find mid to right for target.
2. Special case: When the nums[left] and nums[right] is the same as nums[mid], we should do left++ and right--.
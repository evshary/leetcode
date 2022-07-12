I wrote 
```
while (nums[numsSize-1] == val) numsSize--;
```
instead of 
```
if (nums[numsSize-1] == val) {
    numsSize--;
    continue;
}
```

This is because I don't consider the condition "i < numsSize" should always be true.
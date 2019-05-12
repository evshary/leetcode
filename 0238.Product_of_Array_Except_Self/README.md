1. I should read the problem carefully. I misunderstand the problems.
2. Since we can't use division, we can only use mulitplication. Therefore we can go throught the array like below.
```
If array is [a, b, c, d] and we want to get [b*c*d, a*c*d, a*b*d, a*b*c]
Our idea is to go from begin to end and then from end to begin and collect the multiplier for each element.
First we can iterate from begin to end
[1, a, a*b, a*b*c]
Then from end to begin
[b*c*d, a*c*d, a*b*d, a*b*c]
```
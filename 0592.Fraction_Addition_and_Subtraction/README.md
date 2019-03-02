1. This problem is difficult to solve in C. The main idea is to transform fraction in structure and transform back to string after calculation. I use gcd to optimize the answer after adding.
2. Be careful the input can be two digits(i.e, 10). I spend too much time to get the correct transformation.
3. Don't use itoa, use sprintf instead. It save your life!
4. Be careful signed issue. It'll affect gcd result.
5. My result:
   - Runtime: 4 ms, faster than 100.00% of C online submissions for Fraction Addition and Subtraction.
   - Memory Usage: 7.3 MB, less than 100.00% of C online submissions for Fraction Addition and Subtraction.
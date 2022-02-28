class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
/*
1,2,3, 4, 5, 6, 7
1 3 6 10 15 21 28   (odd: 4, even:3)
0 2 5  9 14 20 27 -1(odd: 3, even:3) odd-- & reverse
0 0 3  7 12 18 25 -2(odd: 3, even:2) even--
0 0 0  4  9 15 22 -3(odd: 2, even:2) odd-- & reverse
                  -4(odd: 2, even:1) even--
				  -5(odd: 1, even:1) odd-- & reverse
				  -6(odd: 1, even:0) even--
 */
        unsigned long result = 0;
        int odd_num = 0;
        int even_num = 0;
        int accumulated_num = 0;
        // calculate the number of odd and even for array accumlated from 1
        for (auto i : arr) {
            accumulated_num += i;
            if (accumulated_num % 2 == 0)
                even_num++;
            else
                odd_num++;
        }
        result = odd_num;
        // remove each element from acculated array
        for (int i = 0; i < arr.size()-1; i++) {
            if (arr[i] % 2 == 0) {
                even_num -= 1;
            } else {
                odd_num -= 1;
                swap(odd_num, even_num);
            }
            result = (result + odd_num) % 1000000007;
        }
        return result;
    }
};
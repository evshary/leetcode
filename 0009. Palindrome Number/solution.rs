impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if (x < 0) {
            return false;
        }
        let mut big = 1;
        let mut small = 1;
        while (x/10) / big != 0 {
        	big *= 10;
        }
        while small < big {
        	if ((x / small) % 10) != ((x / big) % 10) {
                return false;
            }
        	small *= 10;
        	big /= 10;
        }
        true
    }
}
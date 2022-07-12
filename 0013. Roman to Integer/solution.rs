use std::collections::HashMap;

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let mut ans: i32 = 0;
        let mapping = HashMap::from([
        	('I', 1),
        	('V', 5),
        	('X', 10),
        	('L', 50),
        	('C', 100),
        	('D', 500),
        	('M', 1000),
        ]);
        let mut lastc = ' ';
        for c in s.chars() {
        	match c {
        		'V' => {
        			if lastc == 'I' {
        				ans -= mapping[&lastc] * 2;
        			}
        		},
        		'X' => {
        			if lastc == 'I' {
        				ans -= mapping[&lastc] * 2;
        			}
        		},
        		'L' => {
        			if lastc == 'X' {
        				ans -= mapping[&lastc] * 2;
        			}
        		},
        		'C' => {
        			if lastc == 'X' {
        				ans -= mapping[&lastc] * 2;
        			}
        		},
        		'D' => {
        			if lastc == 'C' {
        				ans -= mapping[&lastc] * 2;
        			}
        		},
        		'M' => {
        			if lastc == 'C' {
        				ans -= mapping[&lastc] * 2;
        			}
        		},
        		_ => {},
        	}
       		ans += mapping[&c];
       		lastc = c;
        }
        ans
    }
}
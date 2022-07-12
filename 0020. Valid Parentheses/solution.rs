impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack = Vec::new();
        for c in s.chars() {
        	match c {
        		')' => {
        			if stack.is_empty() || *stack.last().unwrap() != '(' {
        				return false;
        			}
                    stack.pop();
        		},
        		']' => {
        			if stack.is_empty() || *stack.last().unwrap() != '[' {
        				return false;
        			}
                    stack.pop();
        		},
        		'}' => {
        			if stack.is_empty() || *stack.last().unwrap() != '{' {
        				return false;
        			}
                    stack.pop();
        		},
        		_ => {
        			stack.push(c);
        		}
        	}
        }
        if (stack.is_empty()) {
        	return true;
        }
        false
    }
}
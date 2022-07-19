// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn is_same_tree(p: Option<Rc<RefCell<TreeNode>>>, q: Option<Rc<RefCell<TreeNode>>>) -> bool {
    	if p == None && q == None {return true;}
    	if let Some(pnode) = p {
    		if let Some(qnode) = q {
    			let left_child = Self::is_same_tree(pnode.borrow().left.clone(), qnode.borrow().left.clone());
    			let right_child = Self::is_same_tree(pnode.borrow().right.clone(), qnode.borrow().right.clone());
    			if left_child && right_child && pnode.borrow().val == qnode.borrow().val {
		        	return true;
		        }
    		}
    	}
        false
    }
}
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
	fn traverse(root: Option<Rc<RefCell<TreeNode>>>, v: &mut Vec<i32>) {
		if let Some(node) = root {
			Self::traverse(node.borrow().left.clone(), v);
			Self::traverse(node.borrow().right.clone(), v);
			v.push(node.borrow().val);
		}
	}
    pub fn postorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut v = Vec::new();
        Self::traverse(root, &mut v);
        v
    }
}
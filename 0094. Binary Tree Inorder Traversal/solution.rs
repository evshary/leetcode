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
	    if root == None {
	        return
	    }
	    // as_ref() and unwrap() will strip Option with reference, borrow() is for RefCell, and clone() will is to match Rc()
	    Self::traverse(root.as_ref().unwrap().borrow().left.clone(), v);
	    v.push(root.as_ref().unwrap().borrow().val);
	    Self::traverse(root.unwrap().borrow().right.clone(), v);
	}
    pub fn inorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut v = Vec::new();
	    // To call traverse, need to add Self::
        Self::traverse(root, &mut v); // v need to define as mut ref
        v
    }
}
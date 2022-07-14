// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn delete_duplicates(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() {
            return None;
        }
        let mut h = head;
        let mut node = h.as_mut().unwrap();
        while let Some(next_node) = node.next.as_mut() {
            if next_node.val == node.val {
                node.next = next_node.next.take();
            } else {
            	node = node.next.as_mut().unwrap();
            }
        }
        h
    }
}
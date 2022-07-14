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
    pub fn remove_elements(head: Option<Box<ListNode>>, val: i32) -> Option<Box<ListNode>> {
        let mut h = Some(ListNode::new(0));
        h.as_mut().unwrap().next = head;
        let mut node = h.as_mut().unwrap();
        while let Some(next_node) = node.next.as_mut() {
        	if next_node.val == val {
        		node.next = next_node.next.take();
        	} else {
        		node = node.next.as_mut().unwrap();
        	}
        }
        h.unwrap().next
    }
}
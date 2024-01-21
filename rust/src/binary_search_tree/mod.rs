use std::cmp::Ordering;

pub struct Node {
    data: i32,
    left: Pointer,
    right: Pointer,
}

type Pointer = Option<Box<Node>>;

impl Node {
    #[allow(dead_code)]
    pub fn new(data: i32) -> Node {
        Node {
            data,
            left: None,
            right: None,
        }
    }

    #[allow(dead_code)]
    pub fn insert(&mut self, data: i32) {
        let new_node;

        match data.cmp(&self.data) {
            Ordering::Less => {
                if self.left.is_some() {
                    self.left.as_mut().unwrap().insert(data);
                } else {
                    new_node = Box::new(Node::new(data));
                    self.left = Some(new_node);
                }
            }
            Ordering::Greater => {
                if self.right.is_some() {
                    self.right.as_mut().unwrap().insert(data);
                } else {
                    new_node = Box::new(Node::new(data));
                    self.right = Some(new_node);
                }
            }
            Ordering::Equal => (),
        }
    }

    pub fn inorder(&self) {
        if self.left.is_some() && self.right.is_some() {
            self.left.as_ref().unwrap().inorder();
            println!("{}", self.data);
            self.right.as_ref().unwrap().inorder();
        } else if self.left.is_some() && self.right.is_none() {
            self.left.as_ref().unwrap().inorder();
            println!("{}", self.data);
        } else if self.left.is_none() && self.right.is_some() {
            println!("{}", self.data);
            self.right.as_ref().unwrap().inorder();
        } else {
            println!("{}", self.data);
        }
    }
}

/*
 * Name: Computer Algorithms
 * Author: Chen Liang
 * Description: Implementation of computer algorithms
 * Date: 11-Feb-2023
 */


mod insert_sort;
mod binary_search_tree;
// use computer_algorithms::binary_search_tree;

fn main() {
    // let mut array = [30, 10, 60, 70, 50, 30, 20, 80, 40, 90];

    // println!("{:?}", &array);
    // insert_sort::forward::mono_increasing(&mut array);
    // insert_sort::forward::mono_decreasing(&mut array);
    // insert_sort::backward::mono_increasing(&mut array);
    // insert_sort::backward::mono_decreasing(&mut array);

    // println!("{:?}", &array);
    //
    let mut tree_node = binary_search_tree::Node::new(8);
    tree_node.insert(3);
    tree_node.insert(1);
    tree_node.insert(6);
    tree_node.insert(10);
    tree_node.insert(14);
    tree_node.insert(13);
    tree_node.insert(4);
    tree_node.insert(7);
    tree_node.inorder();
}

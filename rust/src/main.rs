/*
 * Name: Computer Algorithms
 * Author: Chen Liang
 * Description: Implementation of computer algorithms
 * Date: 11-Feb-2023
 */

mod insert_sort;

fn main() {
    let mut array = [30, 10, 60, 70, 50, 30, 20, 80, 40, 90];

    println!("{:?}", &array);
    // insert_sort::forward::mono_increasing(&mut array);
    // insert_sort::forward::mono_decreasing(&mut array);
    // insert_sort::backward::mono_increasing(&mut array);
    insert_sort::backward::mono_decreasing(&mut array);

    println!("{:?}", &array);
}

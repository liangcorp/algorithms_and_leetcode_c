mod insert_sort;

fn main() {
    let mut array = [30, 10, 50, 30, 20, 80, 40, 90];

    println!("{:?}", array);
    // insert_sort::increasing(&mut array);
    insert_sort::decreasing(&mut array);
    println!("{:?}", array);
}

fn main() {
    let mut array = [30, 10, 50, 30, 20, 80, 40, 90];
    let mut key;
    let mut j: i32;

    println!("{:?}", array);

    // Array index goes from 0..n
    // Starting from the second position to the end (i.e. 1..n)
    for i in 1..array.len() {
        // key is the value at the current index
        // NOTE: first round is at index 1 (i.e. the second position)
        key = array[i];

        // Moving the index to the beginning 1 index at a time
        j = i as i32 - 1;

        // As long as the current index is not 0
        // AND as long as the key value is less than the
        //  value at the current index
        //
        // Assigned value at the current index to (current index + 1)
        // i.e. moving the value at current index towards the end by 1 index
        // Then moving the current index backwards towards the begining by 1 index
        while j > -1 && array[j as usize] > key {
            array[j as usize + 1] = array[j as usize];
            j -= 1;
        }

        // When we reach the begining
        // OR the value at current index is less than 'key'
        // Assign key value to (current index + 1)
        array[(j + 1) as usize] = key;
    }
    println!("{:?}", array);
}

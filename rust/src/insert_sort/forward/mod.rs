#[allow(dead_code)]
/// Sorting monotonically increasing
pub fn mono_increasing(array: &mut [i32]) {
    let mut key;
    let mut j: i32;
    // Index i goes from 0..n
    // Starting from the second position to the end (i.e. 1..n)
    for i in 1..array.len() {
        // key is the value at index i
        // NOTE: first round i is at index 1 (i.e. the second element)
        key = array[i];

        // Assign index j to (i - 1)
        // First round j is at index 0 (i.e. the first element)
        // i.e. i = 1 and j = 0 in the first round.
        j = i as i32 - 1;

        // As long as j is not 0
        // AND as long as the key value is less than the
        //  value at j
        //
        // Assigned value at j to (j + 1)
        // i.e. moving the value at j towards the end by 1 index
        // Then shifting j backwards towards the beginning by 1 index
        // Continue this until a value (less then key value) is found
        while j > -1 && array[j as usize] > key {
            array[(j + 1) as usize] = array[j as usize];
            j -= 1;
        }
        // When we reach the beginning
        // OR the value at j is less than 'key'
        // Assign key value to (j + 1)
        // i.e. insert key value at the position behind
        //    the value that is less then the key value
        array[(j + 1) as usize] = key;
    }
}

#[allow(dead_code)]
/// Sorting monotonically decreasing
pub fn mono_decreasing(array: &mut [i32]) {
    let mut key;
    let mut j: i32;

    for i in 1..array.len() {
        key = array[i];

        j = i as i32 - 1;

        // If the element at next position is more than
        // the element at current position
        // then swap elements
        while j > -1 && array[j as usize] < key {
            array[(j + 1) as usize] = array[j as usize];
            j -= 1;
        }
        array[(j + 1) as usize] = key;
    }
}

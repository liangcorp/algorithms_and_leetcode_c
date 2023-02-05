#[allow(dead_code)]
/// Sorting monotonically increasing
/// Looping from back to front
pub fn mono_increasing(array: &mut [i32]) {
    let mut key;
    let mut j: i32;

    for i in (0..(array.len() - 1)).rev() {
        key = array[i];

        j = i as i32 + 1;

        while j < (array.len() as i32 + 1) && array[j as usize] < key {
            array[j as usize - 1] = array[j as usize];
            j += 1;
        }
        array[j as usize - 1] = key;
    }
}

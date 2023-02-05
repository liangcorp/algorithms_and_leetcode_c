#[allow(dead_code)]
/// Sorting monotonically increasing
pub fn mono_increasing(array: &mut [i32]) {
    let mut key;
    let mut j;

    for i in (0..(array.len() - 1)).rev() {
        key = array[i];

        j = i + 1;

        while j < array.len() && array[j] < key {
            array[j - 1] = array[j];
            j += 1;
        }
        array[j - 1] = key;
    }
}

#[allow(dead_code)]
/// Sorting monotonically decreasing
pub fn mono_decreasing(array: &mut [i32]) {
    let mut key;
    let mut j;

    for i in (0..(array.len() - 1)).rev() {
        key = array[i];

        j = i + 1;

        while j < array.len() && array[j] > key {
            array[j - 1] = array[j];
            j += 1;
        }
        array[j - 1] = key;
    }
}

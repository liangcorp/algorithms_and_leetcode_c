#[test]
fn insert_sort_test() {
    let mut array = [30, 10, 60, 70, 50, 30, 20, 80, 40, 90];
    computer_algorithms::insert_sort::backward::mono_increasing(&mut array);
    let want = [10, 20, 30, 30, 40, 50, 60, 70, 80, 90];
    assert_eq!(array, want);
}

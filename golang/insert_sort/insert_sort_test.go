package main

import (
    "testing"
)

func InsertSortMonoIncrease(array []int) []int {
    key := 0
    j := 0

    for i := 1; i < len(array); i++ {
        key = array[i]
        j = i - 1

        for j > -1 && array[j] > key {
            array[j + 1] = array[j]
            j -= 1
        }
        array[j + 1] = key
    }
    return array
}

func CompareSlices(first []int, second []int) int {

    if len(first) != len(second) {
        return 1
    }

    for i, number := range first {
        if number != second[i] {
            return 1
        }
    }
    return 0
}

func TestInsertSort(t *testing.T) {
    t.Run("Sort 10 integers", func(t *testing.T) {
        array := []int{30, 10, 60, 70, 50, 30, 20, 80, 40, 90}

        got := InsertSortMonoIncrease(array)
        want := []int{10, 20, 30, 30, 40, 50, 60, 70, 80, 90}

        if CompareSlices(got, want) != 0 {
            t.Errorf("got %v want %v, given %v", got, want, array)
        }
    })
}

package algorithm

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func BinarySearch(numbers []int, begin, end, target int) int {
	if begin >= end {
		return -1
	}

	mid := (begin + end) / 2

	if numbers[mid] == target {
		return int(mid)
	}

	if numbers[mid] < target {
		return BinarySearch(numbers, mid+1, end, target)
	}

	// target < numbers[mid]
	return BinarySearch(numbers, begin, mid, target)
}

func TestBinarySearch(t *testing.T) {
	numbers := []int{-1, 0, 3, 5, 9, 12, 13, 15, 17, 19, 21}
	target := 5

	length := len(numbers)
	index := BinarySearch(numbers, 0, length, target)
	assert.Equal(t, index, 3)
}

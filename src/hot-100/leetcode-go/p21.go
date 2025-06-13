package leetcode_go

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	// Check if any of lists are null
	if list1 == nil {
		return list2
	}

	if list2 == nil {
		return list1
	}

	// Create result linked list, and a iterator for result
	// This is a dummy head
	res := &ListNode{}
	resIt := res
	// Assign two iterators to both list
	it1, it2 := list1, list2
	for it1 != nil && it2 != nil {
		// Compare values
		if it1.Val >= it2.Val {
			// Add smaller one to result
			resIt.Next = &ListNode{Val: it2.Val, Next: nil}
			resIt = resIt.Next
			// Smaller one move forward
			it2 = it2.Next

			continue
		}

		// Add smaller one to result
		resIt.Next = &ListNode{Val: it1.Val, Next: nil}
		resIt = resIt.Next
		// Smaller one move forward
		it1 = it1.Next
	}

	// Finally, check if any iterator (it1 it2) has elements left
	var leftIt *ListNode
	if it1 == nil {
		leftIt = it2
	} else {
		leftIt = it1
	}

	for leftIt != nil {
		resIt.Next = &ListNode{Val: leftIt.Val, Next: nil}
		resIt = resIt.Next
		leftIt = leftIt.Next
	}
	// Return the next of dummy head
	return res.Next
}

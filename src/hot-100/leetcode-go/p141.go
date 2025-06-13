package leetcode_go

func hasCycle(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return false
	}

	first, second := head.Next, head.Next.Next

	for second != nil && second.Next != nil && first != second {
		second = second.Next.Next
		first = first.Next
	}

	if first == second {
		return true
	}

	// Otherwise, second == nil || second Next == nil
	return false
}

package leetcode_go

func detectCycle(head *ListNode) *ListNode {
	// 1. Detect if there is a cycle

	// No cycle at all if 0 or 1 node
	if head == nil || head.Next == nil {
		return nil
	}

	// Slow and fast iterators
	slow, fast := head.Next, head.Next.Next

	for fast != nil && fast.Next != nil && slow != fast {
		slow = slow.Next
		fast = fast.Next.Next
	}

	// If fast == nil || fast Next == nil, no cycle
	if fast == nil || fast.Next == nil {
		return nil
	}

	// 2. Otherwise, there is a cycle, move slow to head, determine if where cycle begins

	slow = head
	// Move forward $(length from head to cycle begin) times
	// This can be proved using math
	for slow != fast {
		slow = slow.Next
		fast = fast.Next
	}

	// Finally reached cycle begin
	return fast
}

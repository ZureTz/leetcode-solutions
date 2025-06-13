package leetcode_go

// func getIntersectionNode(headA, headB *ListNode) *ListNode {
// 	// Check if any of them is null
// 	if headA == nil || headB == nil {
// 		return nil
// 	}

// 	// Iterate two list until one reached nil
// 	itA, itB := headA, headB
// 	// Length to indicate shorter linked list length
// 	for itA != nil && itB != nil {
// 		itA = itA.Next
// 		itB = itB.Next
// 	}

// 	// Also two flags to mark whether a or b reaches nil (end) first
// 	AFirstFlag := itA == nil
// 	BFirstFlag := itB == nil

// 	diffLength := 0
// 	// If both of them are nil, then diffLength = 0
// 	if AFirstFlag && BFirstFlag {
// 		diffLength = 0
// 	} else if AFirstFlag { // Otherwise, extend iteration on a or b to find diff
// 		// A is shorter
// 		for itB != nil {
// 			itB = itB.Next
// 			diffLength++
// 		}
// 	} else {
// 		// B is shorter
// 		for itA != nil {
// 			itA = itA.Next
// 			diffLength++
// 		}
// 	}

// 	// Reset itA and itB and step for diffLength based on flag
// 	itA = headA
// 	itB = headB

// 	if AFirstFlag {
// 		for range diffLength {
// 			itB = itB.Next
// 		}
// 	} else {
// 		for range diffLength {
// 			itA = itA.Next
// 		}
// 	}

// 	// Finally, step until find common address
// 	for itA != itB {
// 		itA = itA.Next
// 		itB = itB.Next
// 	}

// 	// If find nil, return
// 	if itA == nil || itB == nil {
// 		return nil
// 	}

// 	// Otherwise, found intersection
// 	return itA
// }

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	// Check if any of them is null
	if headA == nil || headB == nil {
		return nil
	}

	itA, itB := headA, headB
	for itA != itB {
		if itA == nil {
			itA = headB
		} else {
			itA = itA.Next
		}

		if itB == nil {
			itB = headA
		} else {
			itB = itB.Next
		}
	}

	return itA
}

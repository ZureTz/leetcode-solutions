package leetcode_go

func buildTreeImpl(preOrder []int, preBegin, preEnd int, inOrder []int, inBegin, inEnd int) *TreeNode {
	// If begin == end
	if preBegin == preEnd || inBegin == inEnd {
		return nil
	}
	// If len == 1:
	if preEnd-preBegin == 1 || inEnd-inBegin == 1 {
		return &TreeNode{
			Val: preOrder[preBegin],
		}
	}

	rootNum := preOrder[preBegin]
	// Search rootNum in inOrder to find where is the middle
	var middleIndex int
	for i := inBegin; i < inEnd; i++ {
		if rootNum == inOrder[i] {
			middleIndex = i
			break
		}
	}

	// Separate into two parts
	res := &TreeNode{
		Val: rootNum,
	}

	res.Left = buildTreeImpl(preOrder, preBegin+1, preBegin+1+middleIndex-inBegin, inOrder, inBegin, middleIndex)
	res.Right = buildTreeImpl(preOrder, preBegin+1+middleIndex-inBegin, preEnd, inOrder, middleIndex+1, inEnd)
	return res
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	preSize := len(preorder)
	inSize := len(inorder)
	return buildTreeImpl(preorder, 0, preSize, inorder, 0, inSize)
}

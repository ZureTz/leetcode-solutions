package leetcode_go

func isValidLand(grid [][]byte, i, j int) bool {
	if i < 0 || i >= len(grid) {
		return false
	}

	if j < 0 || j >= len(grid[i]) {
		return false
	}

	if grid[i][j] == '0' {
		return false
	}

	return true
}

func dfs(grid [][]byte, i, j int) {
	if !isValidLand(grid, i, j) || grid[i][j] == '2' {
		return
	}

	grid[i][j] = '2'
	dfs(grid, i-1, j)
	dfs(grid, i+1, j)
	dfs(grid, i, j-1)
	dfs(grid, i, j+1)
}

func numIslands(grid [][]byte) int {
	countIslands := 0

	for i := range grid {
		for j := range grid[i] {
			if !isValidLand(grid, i, j) || grid[i][j] == '2' {
				continue
			}
			// Otherwise, dfs, and increase count
			dfs(grid, i, j)
			countIslands++
		}
	}

	return countIslands
}

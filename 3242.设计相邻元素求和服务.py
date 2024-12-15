#
# @lc app=leetcode.cn id=3242 lang=python3
#
# [3242] 设计相邻元素求和服务
#

# @lc code=start
class NeighborSum:
    def __init__(self, grid: List[List[int]]):
        self.grid = grid
    
    def find_location(self, value: int):
        for i in range(len(self.grid[0])):
            for j in range(len(self.grid[0])):
                if value == self.grid[i][j]:
                    return (i, j)
        return (-1, -1)

    def adjacentSum(self, value: int) -> int:
        sum = 0
        x, y = self.find_location(value)
        if x != 0:
            sum += self.grid[x-1][y]
        if x != len(self.grid[0]) - 1:
            sum += self.grid[x + 1][y]
        if y != 0:
            sum += self.grid[x][y - 1]
        if y != len(self.grid[0]) - 1:
            sum += self.grid[x][y + 1]
        return sum

    def do_it(self, x: int, y: int, sum: int) -> int:
        if x < len(self.grid[0]) and x >= 0 and y < len(self.grid[0]) and y >= 0:
            sum += self.grid[x][y]
            return self.grid[x][y]
        return 0

    def diagonalSum(self, value: int) -> int:
        sum = 0
        x, y = self.find_location(value)
        i = x -1 
        j = y - 1 
        sum += self.do_it(i, j, sum)
        j = y + 1 
        sum += self.do_it(i, j, sum)
        i = x + 1
        sum += self.do_it(i, j, sum)
        j = y - 1 
        sum += self.do_it(i, j, sum)
        return sum


# Your NeighborSum object will be instantiated and called as such:
# obj = NeighborSum(grid)
# param_1 = obj.adjacentSum(value)
# param_2 = obj.diagonalSum(value)
# @lc code=end


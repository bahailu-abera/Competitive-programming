class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        for i in range(len(matrix)):
            for j in range(1, len(matrix[i])):
                matrix[i][j] += matrix[i][j - 1]

        for i in range(len(matrix[0])):
            for j in range(1, len(matrix)):
                matrix[j][i] += matrix[j - 1][i]
        self.matrix = matrix

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:

        right_bottom = self.matrix[row2][col2]

        if row1 == 0 and col1 == 0:
            return right_bottom
        if col1 == 0:
            return right_bottom - self.matrix[row1 - 1][col2]
        if row1 == 0:
            return right_bottom - self.matrix[row2][col1 - 1]
        left_bottom = self.matrix[row2][col1 - 1]
        left_bottom -= self.matrix[row1 - 1][col1 - 1]
        right_bottom -= self.matrix[row1 - 1][col2]

        return right_bottom - left_bottom



# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)

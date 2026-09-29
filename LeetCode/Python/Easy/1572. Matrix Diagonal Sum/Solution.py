class Solution:
    def diagonalSum(self, mat: list[list[int]]) -> int:
        n = len(mat)
        total_sum = 0
        
        for i in range(n):
            total_sum += mat[i][i]          # Primary diagonal
            total_sum += mat[i][n - 1 - i]  # Secondary diagonal
            
        if n % 2 == 1:
            total_sum -= mat[n // 2][n // 2]  # Remove overlapping center
            
        return total_sum

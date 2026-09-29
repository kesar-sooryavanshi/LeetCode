class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False
            
        m, n = len(matrix), len(matrix[0])
        low, high = 0, (m * n) - 1
        
        while low <= high:
            mid = (low + high) // 2
            # Map the 1D index back to 2D matrix coordinates
            mid_val = matrix[mid // n][mid % n]
            
            if mid_val == target:
                return bool(True)
            elif mid_val < target:
                low = mid + 1
            else:
                high = mid - 1
                
        return bool(False)

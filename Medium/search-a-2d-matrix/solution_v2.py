class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        i=0
        j=len(matrix)*len(matrix[0])-1
        while i<=j:
            mid=(i+j)//2
            r=mid//len(matrix[0])
            c=mid%len(matrix[0])
            if matrix[r][c]==target:
                return True
            elif matrix[r][c]<target:
                i=mid+1
            else:
                j=mid-1
        return False
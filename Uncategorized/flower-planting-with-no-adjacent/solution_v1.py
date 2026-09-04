class Solution:
    def gardenNoAdj(self, n: int, paths: List[List[int]]) -> List[int]:
        adj=[[] for _ in range(n+1)]
        for x,y in paths:
            adj[x].append(y)
            adj[y].append(x)
            
        answer=[0]*(n+1)
        
        for garden in range(1,n+1):
            used={answer[neighbor] for neighbor in adj[garden]}
            for color in range(1,5):
                if color not in used:
                    answer[garden]=color
                    break
                    
        return answer[1:]
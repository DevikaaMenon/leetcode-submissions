class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        counts=Counter(tiles)
        
        def backtrack(counts):
            total=0
            
            for letter in counts:
                if counts[letter]==0:
                    continue
                    
                total+=1
                counts[letter]-=1
                
                total+=backtrack(counts)
                counts[letter]+=1
            return total
        
        return backtrack(counts)
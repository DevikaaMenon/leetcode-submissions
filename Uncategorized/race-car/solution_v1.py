class Solution:
    def racecar(self, target: int) -> int:
        from collections import deque 

        visited={(0,1)}
        queue=deque([(0,1,0)])

        while queue:
            pos,speed,steps=queue.popleft()

            if pos==target:
                return steps

            new_pos,new_speed=pos+speed, speed*2
            if (new_pos,new_speed) not in visited and abs(new_pos)<=2*target:
                visited.add((new_pos,new_speed))
                queue.append((new_pos,new_speed,steps+1))

            new_speed=-1 if speed>0 else 1
            if (pos,new_speed) not in visited:
                visited.add((pos,new_speed))
                queue.append((pos,new_speed,steps+1))
        return -1
from collections import deque

class Solution:
    def minMoves(self, classroom, energy):
        m, n = len(classroom), len(classroom[0])
        
        start = None
        litter_pos = {}
        
        for i in range(m):
            for j in range(n):
                c = classroom[i][j]
                if c == 'S':
                    start = (i, j)
                elif c == 'L':
                    litter_pos[(i, j)] = len(litter_pos)
        
        num_litter = len(litter_pos)
        full_mask = (1 << num_litter) - 1
        
        if num_litter == 0:
            return 0
        
        sr, sc = start
        best_energy = {}
        queue = deque()
        queue.append((sr, sc, energy, 0, 0))
        best_energy[(sr, sc, 0)] = energy
        
        dirs = [(-1,0),(1,0),(0,-1),(0,1)]
        
        while queue:
            r, c, e, mask, moves = queue.popleft()
            
            if best_energy.get((r, c, mask), -1) > e:
                continue
            
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                
                if not (0 <= nr < m and 0 <= nc < n):
                    continue
                if classroom[nr][nc] == 'X':
                    continue
                if e == 0:
                    continue
                
                new_e = e - 1
                new_mask = mask
                cell = classroom[nr][nc]
                
                if cell == 'R':
                    new_e = energy
                elif cell == 'L':
                    idx = litter_pos[(nr, nc)]
                    new_mask = mask | (1 << idx)
                
                if new_mask == full_mask:
                    return moves + 1
                
                key = (nr, nc, new_mask)
                if new_e > best_energy.get(key, -1):
                    best_energy[key] = new_e
                    queue.append((nr, nc, new_e, new_mask, moves + 1))
        
        return -1
import sys

def solution(A):  
  max_count = 0
  
  if len(A) == 2:
    return 2
 
  for i in range(len(A)):
    curr_count = 1
    count = 0
    
    for j in range(i,len(A)):
      
      if A[j] == A[i]:
        curr_count += 1
        continue
        
      if A[j] != A[i] and count <3:
        count += 1
        curr_count += 1
      
      if count == 3:
        break
    
    max_count = max(max_count, curr_count)
     
  
  return max_count
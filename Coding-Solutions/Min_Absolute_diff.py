def solution(A):
  """Your solution goes here."""
  import math
  absolute_diff = 0
  
  for i in range(len(A)-1):
    if(A[i+1] - A[i] < absolute_diff):
      absolute_diff = math.fabs(A[i+1] - A[i])
        
  return absolute_diff
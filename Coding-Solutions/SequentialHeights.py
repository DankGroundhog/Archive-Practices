def solution(A):
  """Your solution goes here."""
  max = 0
  count = 0
  for i in range(len(A)):
    if(i+1 <= len(A)):
      if(A[i] >= max):
        max = A[i]
        count += 1
      elif(A[i] == A[i-1]):
        count += 1
      elif(A[i] >= A[i-1] and A[i] <= A[i+1]):
        count += 1
  
  return count
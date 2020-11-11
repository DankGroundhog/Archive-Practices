def Largest(A, low_index, high_index):

  if(len(A)==0):
    return 0

  max = 0

  if(low_index == high_index):
    return A[low_index]
  else:

    max = Largest(A, low_index +1, high_index)

    if A[low_index] >= max:
      return A[low_index]
    else:
      return max

lista = [1,6,7,2,8,10]
print(Largest(lista, 0, len(lista)-1))
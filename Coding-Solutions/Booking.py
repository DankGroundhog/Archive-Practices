def whateverFnct(A):
    rooms = set()

    #Using sets since sets can only have unique
    #elements. We are looking for booked rooms.
    for i in range(len(A)):
        if A[i][0] == '+':
            rooms.add(A[i][1:])

    #returns the amount of unique rooms books
    return len(rooms)
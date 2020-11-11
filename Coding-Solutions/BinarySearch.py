def binarySearch(list,item):
    first = 0
    last = len(list) - 1
    mid = 0
    found = False


    while(first <= last and not(found)):
        
        mid = (first + last) // 2
        if (list[mid] == item):
            found = True
        elif (list[mid] > item):
            last = mid - 1
        else:
            first = mid + 1    
    if(found):
        return mid
    else:
        return -1

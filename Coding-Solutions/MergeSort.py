def merge_sort_first(list):
    merge_sort_second(list, 0, len(list)-1)

def merge_sort_second(list, first, last):
    if first < last:
        middle = (first + last) // 2
        merge_sort_second(list, first, middle)
        merge_sort_second(list, middle+1, last)
        merge(list, first, middle, last)

def merge(list, first, middle, last):
    Left_half = list[first:middle]
    Right_half = list[middle:last+1]

    x = 0
    y = 0

    for z in range(first, last+1):
        if Left_half[x] <= Right_half[y]:
            list[z] = Left_half[x]
            x += 1
        else:
            list[z] = Right_half[y]
            y += 1
def quicksort(array):
    if len(array) < 2:
        return array

    pivot = array[0]
    minors = [item for item in array[1:] if item <= pivot]
    majors = [item for item in array[1:] if item > pivot]

    return quicksort(minors) + [pivot] + quicksort(majors)


print(quicksort([3, 5, 2, 1, 4]))

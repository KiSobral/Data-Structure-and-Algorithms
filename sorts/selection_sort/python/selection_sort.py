def find_smaller(array):
    smaller = array[0]
    smaller_index = 0

    for i in range(0, len(array)):
        if array[i] < smaller:
            smaller = array[i]
            smaller_index = i

    return smaller_index


def selection_sort(array):
    new_array = []

    for i in range(len(array)):
        smaller = find_smaller(array)
        new_array.append(array.pop(smaller))

    return new_array


print(selection_sort([9, 5, 7, 4, 11, 2]))

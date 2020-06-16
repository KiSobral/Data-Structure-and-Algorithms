def binary_search(list, item):
    '''
        This function searchs within a given list for a given item.

        --- Keyword arguments:
            - list: A List that contains an arbitrary number of int numbers
            - item: An Int object that corresponds to the number that must be looked for into the List

        --- Possible returns:
            - If the item is in list, the function will return the position of the item
            - If the item is not in list, the function will return None
    '''
    min = 0
    max = len(list) - 1

    while min <= max:
        middle = int((min + max) / 2)
        guess = list[middle]

        if guess == item:
            return middle
        elif guess > item:
            max = middle-1
        else:
            min = middle+1

    else:
        return None


my_list = [item for item in range(1, 10, 2)]
print(my_list)
print(binary_search(my_list, 5))
print(binary_search(my_list, 6))

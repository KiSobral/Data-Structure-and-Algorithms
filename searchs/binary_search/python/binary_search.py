def binary_search(list, item):
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

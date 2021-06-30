def group_by_f(f, lst):
    dict = {}
    for element in lst:
        dict.setdefault(f(element), []).append(element)
    return dict


print(group_by_f(lambda a: a % 2 == 0, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
print(group_by_f(len, [[1], [7, 8], [1, 2, 3, 4], [4], ["random", "words"]]))

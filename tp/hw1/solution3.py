def max_notes(P):
    return sum(max(P, key=lambda x: sum(x))) if len(P) > 0 else 0


def leading(P):
    return P.index(max(P, key=lambda x: x[-1]))


print(max_notes([[1, 2, 3], [2, 2, 2], [9, 7, 3]]))
print(leading([[1, 10, 2], [2, 2, 2], [9, 7, 3]]))

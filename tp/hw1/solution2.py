def is_stronger(drug1, drug2):
    if set(drug1[1]) != set(drug2[1]) and len(drug1[1]) >= len(drug2[1]):
        for ingredient2 in drug2[1]:
            contains = False
            for ingredient1 in drug1[1]:
                if ingredient2[0] == ingredient1[0]:
                    if ingredient2[1] > ingredient1[1]:
                        return False
                    contains = True
                    break
            if not contains:
                return False
        return True
    return False


def least_stronger(drug1, drugs):
    differences = []
    for i in range(len(drugs)):
        differences.append([i, []])
        for ingredient1 in drug1[1]:
            for ingredient2 in drugs[i][1]:
                if ingredient1[0] == ingredient2[0] and \
                        ingredient1[1] <= ingredient2[1]:
                    differences[i][1].append(ingredient2[1] - ingredient1[1])
    differences = [d for d in differences if len(d[1]) >= len(drug1[1])]
    if len(differences) == 0:
        return differences
    return drugs[min(differences, key=lambda x: sum(x[1]))[0]]


def strong_relation(drugs):
    drugs_relation = []
    for i in range(len(drugs)):
        drugs_relation.append((drugs[i], []))
        for drug2 in drugs:
            if(is_stronger(drug2, drugs[i])):
                drugs_relation[i][1].append(drug2[0])
    return drugs_relation


A = ("A", [("p", 5), ("q", 3)])
B = ("B", [("p", 4), ("q", 3)])
C = ("C", [("p", 3)])
D = ("D", [("p", 4.5), ("q", 3), ("r", 1)])
E = ("E", [("p", 4.1), ("q", 3), ("r", 1)])
print(is_stronger(A, B))
print(least_stronger(B, [A, C, D]))
print(strong_relation([A, B, C]))

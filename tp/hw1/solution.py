def group_by_f(f, lst):
    dict = {}

    for element in lst:
        dict.setdefault(f(element), []).append(element)
    return dict


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


def max_notes(P):
    return sum(max(P, key=lambda x: sum(x))) if len(P) > 0 else 0
def leading(P):
    return P.index(max(P, key=lambda x: x[-1]))


from time import sleep


class Iterable:
    def __init__(self, max):
        self.max = max
        self.numbers = []

    def __iter__(self):
        if(len(self.numbers) == self.max):
            return iter(self.numbers)
        self.number = 0
        return self

    def __next__(self):
        if(self.number < self.max):
            sleep(0.5)
            self.number += 1
            self.numbers.append(self.number)
            return self.number
        raise StopIteration

    def generator(self):
        D = {}
        q = 2
        while True:
            if q not in D:
                yield q
                D[q * q] = [q]
            else:
                for p in D[q]:
                    D.setdefault(p + q, []).append(p)
                del D[q]
            q += 1
        

if __name__ == "__main__":

    it = Iterable(5)

    # for i in it:
    #     print(i)
    # print("")
    # for i in it:
    #     print(i)

    for i in it.generator():
        sleep(0.05)
        print(i)

class Address:
    @property
    def address(self):
        return ", ".join([self.__city, self.__street, self.__number])

    @address.setter
    def address(self, value):
        self.__city, self.__street, self.__number = value.split(",")


class Person:
    def __init__(self, name):
        self.__name = name
        self.__address = Address()

    @property
    def name(self):
        return self.__name

    @name.setter
    def name(self, name):
        self.__name = name

    @property
    def address(self):
        return self.__address.address

    @address.setter
    def address(self, value):
        self.__address.address = value


class Computer:
    @property
    def specs(self):
        return ', '.join([self.__mark, self.__year_of_producing, self.__cpu, self.__os, self.__ram, self.__disk])

    @specs.setter
    def specs(self, value):
        self.__mark, self.__year_of_producing, self.__cpu, self.__os, self.__ram, self.__disk = value.split(",")


class MarkBook:
    __grades = {}

    def addMark(self, subject, mark):
        if subject not in self.__grades:
            self.__grades[subject] = list([])
        self.__grades[subject].append(mark)

    def getMarks(self, subject):
        self.__grades[subject]

    def getAverage(self, subject):
        return sum(self.__grades[subject]) / len(self.__grades[subject])


class Student(Person):
    def __init__(self, name, number):
        super().__init__(name)
        self.__number = number
        self.__markBook = MarkBook()
        self.__computer = Computer()

    def addMark(self, subject, mark):
        self.__markBook.addMark(subject, mark)

    def getAverage(self, subject):
        return self.__markBook.getAverage(subject)

    @property
    def number(self):
        return self.__number

    @property
    def specs(self):
        return self.__computer.specs

    @specs.setter
    def specs(self, value):
        self.__computer.specs = value


student = Student("Ivan Dimitrov", 14)
print(student.name)
student.addMark("TP", 2)
student.addMark("TP", 4)
print("Average mark:", student.getAverage("TP"))
print(student.number)
student.specs = "Dell, 2014, Ryzen 7 3700X, Linux Mint, 16GB, 1TB SSD"
print(student.specs)

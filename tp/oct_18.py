# class Heap:
#     def create(self):
#         print("Creating Heap")


# class Node(Heap):
#     def create(self):
#         print("Creating Node")


# node = Node()
# node.create()

# class TeamMember(object):
#     def __init__(self, name, uid):
#         self.name = name
#         self.uid = uid


# class Leader(object):
#     def __init__(self, skill, jobtitle):
#         self.skill = skill
#         self.jobtitle = jobtitle


# class TeamLeader(TeamMember, Leader):
#     def __init__(self, name, uid, skill, jobtitle, exp):
#         self.exp = exp
#         TeamMember.__init__(self, name, uid)
#         Leader.__init__(self, skill, jobtitle)
#         print("Name {}, Skill: {}, Exp: {}".format(self.name, self.skill, self.exp))

# class Heap:
#     def create(self, name=None):
#         if name is not None:
#             print("Hello " + name)
#         else:
#             print("Hello ")


# heap = Heap()
# heap.create()
# heap.create(" test parameter")

class base(object):
    def base_func(self):
        print("Method of base class")


class child(base):
    def base_func(self):
        print("Method of child class")
        super(child, self).base_func()


class next_child(child):
    def base_func(self):
        print("Method of next_child class")
        super(next_child, self).base_func()


obj = next_child()
obj.base_func()

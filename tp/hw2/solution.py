class NotYourTurn(Exception):
    pass

class InvalidKey(Exception):
    pass

class InvalidValue(Exception):
    pass

class InvalidMove(Exception):
    pass

class TicTacToeBoard():
    def __init__(self):
        self.board = dict.fromkeys(["A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3"], " ")
        self.latest = None

    def __setitem__(self, key, val):
        if self.latest == val:
            raise NotYourTurn
        if self.board[key] is not " ":
            raise InvalidMove
        if key not in self.board.keys():
            raise InvalidKey
        if val != "O" and val != "X":
            raise InvalidValue
        self.latest = val
        self.board[key] = val

    def __str__(self):
        return '\n  -------------\n' +\
            '3 | {} | {} | {} |\n'.format(self.board["A3"], self.board["B3"], self.board["C3"]) +\
            '  -------------\n' +\
            '2 | {} | {} | {} |\n'.format(self.board["A2"], self.board["B2"], self.board["C2"]) +\
            '  -------------\n' +\
            '1 | {} | {} | {} |\n'.format(self.board["A1"], self.board["B1"], self.board["C1"]) +\
            '  -------------\n' +\
            '    A   B   C  \n'

    def game_status(self):
        winner = None
        if self.board["A1"] == self.board["A2"] == self.board["A3"] != " ":
            winner = self.board["A1"]
        elif self.board["B1"] == self.board["B2"] == self.board["B3"] != " ":
            winner = self.board["B1"]
        elif self.board["C1"] == self.board["C2"] == self.board["C3"] != " ":
            winner = self.board["C1"]
        elif self.board["A1"] == self.board["B1"] == self.board["C1"] != " ":
            winner = self.board["A1"]
        elif self.board["A2"] == self.board["B2"] == self.board["C2"] != " ":
            winner = self.board["A2"]
        elif self.board["A3"] == self.board["B3"] == self.board["C3"] != " ":
            winner = self.board["A3"]
        elif self.board["A1"] == self.board["B2"] == self.board["C3"] != " ":
            winner = self.board["A1"]
        elif self.board["C1"] == self.board["B2"] == self.board["A3"] != " ":
            winner = self.board["C1"]
        if winner is not None:
            return winner + " wins!"
        if " " in self.board.values():
            return 'Game in progress.'
        return 'Draw!'
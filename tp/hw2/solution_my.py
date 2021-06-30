from collections import defaultdict


class InvalidMove(Exception):
    pass


class InvalidValue(Exception):
    pass


class InvalidKey(Exception):
    pass


class NotYourTurn(Exception):
    pass


class TicTacToeBoard():
    def __init__(self):
        self.board = defaultdict(lambda: " ")
        self.last_turn = ""

    def __getitem__(self, key):
        return self.board[key]

    def __setitem__(self, key, value):
        if self.game_status() == 'Game in progress.':
            if value == self.last_turn:
                raise NotYourTurn
            if self.board[key] != " ":
                raise InvalidMove
            if value != "X" and value != "O":
                raise InvalidValue
            keys = ["A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3"]
            if key not in keys:
                raise InvalidKey
            self.last_turn = value
            self.board[key] = value

    def __str__(self):
        return '''
  -------------
3 | {} | {} | {} |
  -------------
2 | {} | {} | {} |
  -------------
1 | {} | {} | {} |
  -------------
    A   B   C  \n'''.format(
                        self.board["A3"], self.board["B3"], self.board["C3"],
                        self.board["A2"], self.board["B2"], self.board["C2"],
                        self.board["A1"], self.board["B1"], self.board["C1"])

    def game_status(self):
        if self.board["A1"] == self.board["A2"] == self.board["A3"] != " ":
            return self.board["A1"] + ' wins!'
        if self.board["B1"] == self.board["B2"] == self.board["B3"] != " ":
            return self.board["B1"] + ' wins!'
        if self.board["C1"] == self.board["C2"] == self.board["C3"] != " ":
            return self.board["C1"] + ' wins!'
        if self.board["A1"] == self.board["B1"] == self.board["C1"] != " ":
            return self.board["A1"] + ' wins!'
        if self.board["A2"] == self.board["B2"] == self.board["C2"] != " ":
            return self.board["A2"] + ' wins!'
        if self.board["A3"] == self.board["B3"] == self.board["C3"] != " ":
            return self.board["A3"] + ' wins!'
        if self.board["A1"] == self.board["B2"] == self.board["C3"] != " ":
            return self.board["A1"] + ' wins!'
        if self.board["C1"] == self.board["B2"] == self.board["A3"] != " ":
            return self.board["C1"] + ' wins!'
        for value in self.board.values():
            if value == " ":
                return 'Game in progress.'
        return 'Draw!'

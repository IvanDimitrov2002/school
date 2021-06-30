DROP DATABASE PlayerStats;
CREATE DATABASE PlayerStats;
USE PlayerStats;

CREATE TABLE StatTypes(
	StatCode VARCHAR(5) NOT NULL PRIMARY KEY,
    Name VARCHAR(20) NOT NULL
);

CREATE TABLE Positions(
	PositionCode VARCHAR(2) NOT NULL PRIMARY KEY,
    Name VARCHAR(40) NOT NULL
);

CREATE TABLE Players(
	Id INTEGER NOT NULL AUTO_INCREMENT PRIMARY KEY,
    Name VARCHAR(80) NOT NULL,
    Num INTEGER NOT NULL,
    PositionCode VARCHAR(2) NOT NULL,
    
    FOREIGN KEY (PositionCode) REFERENCES Positions(PositionCode)
);

CREATE TABLE Tournaments(
	Id INTEGER NOT NULL AUTO_INCREMENT PRIMARY KEY,
    Name VARCHAR(80) NOT NULL
);

CREATE TABLE Matches(
	Id INTEGER NOT NULL AUTO_INCREMENT PRIMARY KEY,
    MatchDate DATE NOT NULL,
    TournamentId INTEGER NOT NULL,
    
    FOREIGN KEY (TournamentId) REFERENCES Tournaments(Id)
);

CREATE TABLE MatchStats(
	Id INTEGER NOT NULL AUTO_INCREMENT PRIMARY KEY,
    MatchId INTEGER NOT NULL,
    PlayerId INTEGER NOT NULL,
    EventMinute INTEGER NOT NULL,
    StatCode VARCHAR(5) NOT NULL,
    
    FOREIGN KEY (MatchId) REFERENCES Matches(Id),
    FOREIGN KEY (PlayerId) REFERENCES Players(Id),
    FOREIGN KEY (StatCode) REFERENCES StatTypes(StatCode)
);

INSERT INTO StatTypes VALUES('G', 'Гол');
INSERT INTO StatTypes VALUES('A', 'Асистенция');
INSERT INTO StatTypes VALUES('R', 'Червен картон');
INSERT INTO StatTypes VALUES('Y', 'Жълт картон');
INSERT INTO StatTypes VALUES('OG', 'Автогол');
INSERT INTO StatTypes VALUES('IN', 'Смяна влиза');
INSERT INTO StatTypes VALUES('OUT', 'Смяна излиза');

INSERT INTO Positions VALUES('GK', 'Вратар');
INSERT INTO Positions VALUES('RB', 'Десен защитник');
INSERT INTO Positions VALUES('LB', 'Ляв защитник');
INSERT INTO Positions VALUES('CB', 'Централен защитник');
INSERT INTO Positions VALUES('RM', 'Десен полузащитник');
INSERT INTO Positions VALUES('LM', 'Ляв полузащитник');
INSERT INTO Positions VALUES('CM', 'Полузащитник');
INSERT INTO Positions VALUES('CF', 'Централен нападател');

INSERT INTO Players VALUES(NULL, 'Ivaylo Trifonov', 1, 'GK');
INSERT INTO Players VALUES(NULL, 'Valko Trifonov', 2, 'RB');
INSERT INTO Players VALUES(NULL, 'Ognyan Yanev', 3, 'CB');
INSERT INTO Players VALUES(NULL, 'Zahari Dragomirov', 4, 'CB');
INSERT INTO Players VALUES(NULL, 'Bozhidar Chilikov', 5, 'LB');
INSERT INTO Players VALUES(NULL, 'Timotei Zahariev', 6, 'CM');
INSERT INTO Players VALUES(NULL, 'Marin Valentinov', 7, 'CM');
INSERT INTO Players VALUES(NULL, 'Mitre Cvetkov', 99, 'CF');
INSERT INTO Players VALUES(NULL, 'Zlatko Genov', 9, 'CF');
INSERT INTO Players VALUES(NULL, 'Matey Goranov', 10, 'RM');
INSERT INTO Players VALUES(NULL, 'Sergei Zhivkov', 11, 'LM');

INSERT INTO Tournaments VALUES(NULL, 'Шампионска лига');
INSERT INTO Tournaments VALUES(NULL, 'Първа лига');
INSERT INTO Tournaments VALUES(NULL, 'Купа на България');
INSERT INTO Tournaments VALUES(NULL, 'Суперкупа на България');

INSERT INTO Matches VALUES(NULL, '2018-04-08', 2);
INSERT INTO Matches VALUES(NULL, '2018-04-13', 2);
INSERT INTO Matches VALUES(NULL, '2018-04-21', 2);
INSERT INTO Matches VALUES(NULL, '2018-04-28', 2);
INSERT INTO Matches VALUES(NULL, '2018-05-06', 2);
INSERT INTO Matches VALUES(NULL, '2018-05-11', 2);
INSERT INTO Matches VALUES(NULL, '2017-09-21', 3);
INSERT INTO Matches VALUES(NULL, '2017-10-26', 3);

INSERT INTO MatchStats VALUES(NULL, 8, 9, 14, 'G');
INSERT INTO MatchStats VALUES(NULL, 8, 8, 14, 'A');
INSERT INTO MatchStats VALUES(NULL, 8, 3, 43, 'Y');
INSERT INTO MatchStats VALUES(NULL, 7, 2, 28, 'Y');
INSERT INTO MatchStats VALUES(NULL, 7, 10, 45, 'Y');
INSERT INTO MatchStats VALUES(NULL, 7, 10, 65, 'R');
INSERT INTO MatchStats VALUES(NULL, 1, 10, 23, 'G');
INSERT INTO MatchStats VALUES(NULL, 1, 9, 23, 'A');
INSERT INTO MatchStats VALUES(NULL, 1, 9, 43, 'G');
INSERT INTO MatchStats VALUES(NULL, 2, 4, 33, 'OG');
INSERT INTO MatchStats VALUES(NULL, 2, 9, 68, 'G');
INSERT INTO MatchStats VALUES(NULL, 2, 1, 68, 'A');
INSERT INTO MatchStats VALUES(NULL, 3, 3, 35, 'G');
INSERT INTO MatchStats VALUES(NULL, 3, 4, 35, 'A');
INSERT INTO MatchStats VALUES(NULL, 3, 8, 55, 'G');
INSERT INTO MatchStats VALUES(NULL, 3, 11, 55, 'A');
INSERT INTO MatchStats VALUES(NULL, 4, 3, 9, 'G');
INSERT INTO MatchStats VALUES(NULL, 4, 8, 9, 'G');
INSERT INTO MatchStats VALUES(NULL, 4, 8, 56, 'OG');
INSERT INTO MatchStats VALUES(NULL, 5, 8, 67, 'G');

SELECT p.Name, p.Num
FROM Players p
WHERE p.PositionCode = 'RB' OR p.PositionCode = 'LB' OR p.PositionCode = 'CB';

SELECT m.MatchDate, t.Name
FROM Matches m
INNER JOIN Tournaments t
ON m.TournamentId = t.Id
WHERE m.MatchDate LIKE '2018-04-%';

SELECT m.MatchDate, p.Name, p.Num, ms.EventMinute, st.Name
FROM MatchStats ms
INNER JOIN Matches m
ON m.Id = ms.MatchId
INNER JOIN Players p
ON p.Id = ms.PlayerId
INNER JOIN StatTypes st
ON ms.StatCode = st.StatCode
WHERE p.Num = 99;

SELECT ms.StatCode, COUNT(*) AS Count
FROM MatchStats ms
WHERE ms.StatCode = 'OG';

SELECT m.MatchDate, COUNT(*) as Goals
FROM Matches m
INNER JOIN MatchStats ms
ON m.Id = ms.MatchId
WHERE ms.StatCode = 'G' AND m.MatchDate < '2018-05-01'
GROUP BY m.MatchDate;

SELECT ps.Name, COUNT(ms.StatCode) as Goals
FROM Positions ps
INNER JOIN Players p
ON p.PositionCode = ps.PositionCode
LEFT JOIN MatchStats ms
ON p.Id = ms.PlayerId AND ms.StatCode = 'G'
GROUP BY ps.Name;

SELECT p.Name, p.Num, ps.Name as Position, COUNT(*) as Cards
FROM Players p
INNER JOIN Positions ps
ON ps.PositionCode = p.PositionCode
INNER JOIN MatchStats ms
ON ms.PlayerId = p.Id
WHERE ms.StatCode = 'Y' OR ms.StatCode = 'R'
GROUP BY p.Name
ORDER BY Cards DESC;
CREATE DATABASE 11b_13_work;
USE 11b_13_work;

CREATE TABLE Languages (
	LanguageId INTEGER AUTO_INCREMENT PRIMARY KEY,
    Name VARCHAR(20) NOT NULL
);

CREATE TABLE Developers (
	Id INTEGER AUTO_INCREMENT PRIMARY KEY,
	Name VARCHAR(150) NOT NULL,
    Experience INTEGER NOT NULL,
    LanguageId INT,
	EGN CHAR(10),
	Birthday DATE,
    FOREIGN KEY (LanguageId) REFERENCES Languages(LanguageId)
);

CREATE TABLE ProjectManagers (
	Id INTEGER AUTO_INCREMENT PRIMARY KEY,
	Name VARCHAR(150) NOT NULL,
	Experience INTEGER NOT NULL,
	EGN CHAR(10),
	Birthday DATE
);

CREATE TABLE QAs (
	Id INTEGER AUTO_INCREMENT PRIMARY KEY,
	Name VARCHAR(150) NOT NULL,
	Experience INTEGER NOT NULL,
	EGN CHAR(10),
	Birthday DATE
);

INSERT INTO Languages
VALUES 
	(NULL, 'Javascript'),
	(NULL, 'C++'),
	(NULL, 'SQL');

INSERT INTO Developers
VALUES 
	(NULL, 'Ivan Dimitrov', 70, 1, "1234567890", '2002-03-29'),
	(NULL, 'Peter Petrov', 20, 2, "0987654321", '2000-08-03'),
	(NULL, 'George Marinov', 78, 3, "1223334444", '1999-05-22');

INSERT INTO ProjectManagers
VALUES 
	(NULL, 'Ivan Dimitrov', 20, "2468097531", '2000-08-03'),
	(NULL, 'Peter Hristov', 70, "1357908642", '2002-03-29'),
	(NULL, 'Hristo Georgiev', 14, "4444333221", '1984-11-08');
    
INSERT INTO QAs
VALUES 
	(NULL, 'Gosho Goshevski', 70, "2222222222", '2000-08-03'),
	(NULL, 'Krisi Dimitrova', 78, "1111111111", '2002-03-29'),
	(NULL, 'Viktoria Atanasova', 14, "3333333333", '1984-11-08');

SELECT * FROM Developers d 
INNER JOIN ProjectManagers pm
ON d.Id = pm.Id;

SELECT * FROM Developers d 
INNER JOIN Languages l
ON d.LanguageId = l.LanguageId;

SELECT * FROM Developers d 
LEFT JOIN ProjectManagers pm
ON d.Experience = pm.Experience;

SELECT * FROM Developers d 
RIGHT JOIN ProjectManagers pm
ON d.Birthday = pm.Birthday;

SELECT * FROM Developers d 
LEFT JOIN ProjectManagers pm
ON d.Experience = pm.Experience
RIGHT JOIN QAs qa
ON qa.Experience = pm.Experience;
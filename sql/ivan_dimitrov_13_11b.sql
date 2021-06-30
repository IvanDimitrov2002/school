CREATE DATABASE 11b_13_school;
USE 11b_13_school;

CREATE TABLE Students (
	Id INTEGER AUTO_INCREMENT PRIMARY KEY,
    Name VARCHAR(150) NOT NULL,
    Num INT NOT NULL,
    Class VARCHAR(3) NOT NULL,
	EGN CHAR(10),
    EntranceExamResult NUMERIC(3, 2),
    Birthday DATE
);

INSERT INTO Students 
VALUES (NULL, 'Ivan Dimitrov', 13, '11b', "1234567890", 5.5, '2002-03-29');

SELECT * 
FROM Students;
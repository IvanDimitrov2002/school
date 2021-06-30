CREATE DATABASE school;
USE school;

CREATE TABLE Students (
	Id INTEGER AUTO_INCREMENT PRIMARY KEY,
    Name VARCHAR(150) NOT NULL,
    Class VARCHAR(3) NOT NULL,
    Status CHAR(1) DEFAULT 'A',
    EntranceExamResult NUMERIC(3, 2),
    Birthday DATE,
    EGN CHAR(10)
);

SELECT * 
FROM Students;

INSERT INTO Students 
VALUES (NULL, 'Ivan Petrov', '11b', NULL, 5.5, '2000-02-29', NULL);
INSERT INTO Students 
VALUES (NULL, 'Ivan Petrov', '12b', NULL, 5.4, '2000-02-29', NULL);
INSERT INTO Students 
VALUES (NULL, 'Ivan Angelov', '11b', NULL, 5.3, '2000-02-29', NULL);
INSERT INTO Students 
VALUES (NULL, 'Bogdan Petrov', '11b', NULL, 5.2, '2000-02-29', NULL);
UPDATE Students
SET EntranceExamResult = EntranceExamResult*1.1;

UPDATE Students
SET Status = 'A'
WHERE Status IS NULL;

SELECT * FROM Students
WHERE EntranceExamResult >= 6 AND (Name LIKE '% Petrov' OR Name LIKE '% Petrova');
UPDATE  Students
SET EntranceExamResult = 6
WHERE EntranceExamResult > 6;
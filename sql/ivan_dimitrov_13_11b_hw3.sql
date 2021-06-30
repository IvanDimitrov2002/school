CREATE DATABASE 11b_13_students;
USE 11b_13_students;

CREATE TABLE IF NOT EXISTS Students (
	Id INTEGER AUTO_INCREMENT PRIMARY KEY,
    Name VARCHAR(150) NOT NULL,
    Num INTEGER NOT NULL,
    Class VARCHAR(3) NOT NULL
);

CREATE TABLE IF NOT EXISTS Subjects (
	Id INTEGER AUTO_INCREMENT PRIMARY KEY,
    Name VARCHAR(150) UNIQUE NOT NULL
); 

CREATE TABLE IF NOT EXISTS MarkWords (
	Id INTEGER AUTO_INCREMENT PRIMARY KEY,
	RangeStart FLOAT NOT NULL,
    RangeEnd FLOAT NOT NULL,
    MarkAsWord VARCHAR(150) NOT NULL
);

CREATE TABLE IF NOT EXISTS StudentMarks (
	Id INTEGER AUTO_INCREMENT PRIMARY KEY,
	StudentId INTEGER NOT NULL UNIQUE,
    SubjectId INTEGER NOT NULL UNIQUE,
    FOREIGN KEY (StudentId) REFERENCES Students(Id),
    FOREIGN KEY (SubjectId) REFERENCES Subjects(Id),
    ExamDate DATE UNIQUE,
    StudentMark FLOAT
);

INSERT INTO Subjects VALUES 
	(NULL, 'TP'),
	(NULL, 'MAT'),
	(NULL, 'OOP'),
	(NULL, 'BEL');
    
INSERT INTO Students VALUES 
	(NULL, 'Ganio Ganev', 3, '11G'),
	(NULL, 'Ivan Dimitrov', 13, '11B'),
	(NULL, 'General Grievous', 20, '11V'),
	(NULL, 'Georg Gerginov', 21, '11A');
    
INSERT INTO MarkWords VALUES 
	(NULL, 2, 2.5, 'СЛАБ'),
    (NULL, 2.5, 3.49, 'СРЕДЕН'),
    (NULL, 3.5, 4.49, 'ДОБЪР'),
    (NULL, 4.5, 5.49, 'МНОГО ДОБЪР'),
    (NULL, 5.5, 6, 'ОТЛИЧЕН');
    
INSERT INTO StudentMarks VALUES 
	(NULL, (SELECT Id FROM Students WHERE Name='Ganio Ganev'),
    (SELECT Id FROM Subjects WHERE Name='OOP'), '2002-01-23', 5.50),

    (NULL, (SELECT Id FROM Students WHERE Name='Ivan Dimitrov'),
    (SELECT Id FROM Subjects WHERE Name='TP'), '2010-10-05', 3.70),

    (NULL, (SELECT Id FROM Students WHERE Name='General Grievous'),
    (SELECT Id FROM Subjects WHERE Name='MAT'), '2022-11-15', 6.00);
    
    
SELECT st.Name, sb.Name, sm.ExamDate, sm.StudentMark, mw.MarkAsWord 
FROM MarkWords AS mw,
	Students AS st
INNER JOIN StudentMarks AS sm
ON st.Id = sm.StudentId 
INNER JOIN Subjects AS sb
ON sm.SubjectId = sb.Id
WHERE sm.StudentMark >= mw.RangeStart AND sm.StudentMark <= mw.RangeEnd AND sm.StudentMark > 4;

SELECT st.Name, st.Num, st.Class
FROM Students AS st
LEFT JOIN StudentMarks AS sm
ON st.Id = sm.StudentId
WHERE sm.StudentMark IS NULL;

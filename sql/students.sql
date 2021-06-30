DROP DATABASE IF EXISTS school;
CREATE DATABASE school CHARSET 'utf8';
USE school;

CREATE TABLE Students(
	Id INTEGER NOT NULL AUTO_INCREMENT PRIMARY KEY,
	Name VARCHAR(150) NOT NULL,
	Num INTEGER NOT NULL,
	ClassNum INTEGER NOT NULL,
	ClassLetter CHAR(1) NOT NULL,
	Birthday DATE,
	EGN CHAR(10),
	EntranceExamResult NUMERIC(3,2)
);

CREATE TABLE H_Students(
	UId INTEGER NOT NULL AUTO_INCREMENT PRIMARY KEY,
	Id INTEGER,
	Name VARCHAR(150),
    BeginDate DATETIME NOT NULL,
    EndDate DATETIME,
	Num INTEGER,
	ClassNum INTEGER,
	ClassLetter CHAR(1),
	Birthday DATE,
	EGN CHAR(10),
	EntranceExamResult NUMERIC(3,2)
);

Delimiter $

Create TRIGGER Students_AI_Hist 
AFTER INSERT ON Students FOR EACH ROW
BEGIN 
    INSERT INTO H_Students VALUES(NULL, NEW.Id, NEW.Name,  NOW(), NULL, NEW.Num, NEW.ClassNum, NEW.ClassLetter, NEW.Birthday, NEW.EGN, NEW.EntranceExamResult);
END $

Create TRIGGER Students_AU_Hist 
AFTER UPDATE ON Students FOR EACH ROW
BEGIN 
    UPDATE H_Students
    SET EndDate = NOW()
    WHERE H_Students.Id = Id AND EndDate IS NULL;
    
    INSERT INTO H_Students VALUES(NULL, NEW.Id, NEW.Name,  NOW(), NULL, NEW.Num, NEW.ClassNum, NEW.ClassLetter, NEW.Birthday, NEW.EGN, NEW.EntranceExamResult);
END $

Create TRIGGER Students_AD_Hist 
AFTER DELETE ON Students FOR EACH ROW
BEGIN 
	UPDATE H_Students
    SET EndDate = NOW()
    WHERE H_Students.Id = Id AND EndDate IS NULL;
    
    INSERT INTO H_Students VALUES(NULL, OLD.Id, OLD.Name, NOW(), NULL, OLD.Num, OLD.ClassNum, OLD.ClassLetter, OLD.Birthday, OLD.EGN, OLD.EntranceExamResult);
END $

DELIMITER ;

CREATE TABLE Subjects(
	Id INTEGER NOT NULL AUTO_INCREMENT,
	Name VARCHAR(100),
	
	PRIMARY KEY(Id)
);

CREATE TABLE StudentMarks(
	StudentId INTEGER NOT NULL,
	SubjectId INTEGER NOT NULL,
	ExamDate DATETIME NOT NULL,
	Mark NUMERIC(3,2) NOT NULL,
	
	PRIMARY KEY( StudentId, SubjectId, ExamDate ),
	FOREIGN KEY (StudentId) REFERENCES Students(Id),
	FOREIGN KEY (SubjectId) REFERENCES Subjects(Id)
);

CREATE TABLE H_StudentMarks(
	UId INTEGER NOT NULL AUTO_INCREMENT PRIMARY KEY,
	StudentId INTEGER NOT NULL,
	SubjectId INTEGER NOT NULL,
	ExamDate DATETIME NOT NULL,
	Mark NUMERIC(3,2) NOT NULL,
    BeginDate DATETIME NOT NULL,
    EndDate DATETIME,
	
	FOREIGN KEY (StudentId) REFERENCES Students(Id),
	FOREIGN KEY (SubjectId) REFERENCES Subjects(Id)
);

Delimiter $

Create TRIGGER StudentMarks_AI_Hist 
AFTER INSERT ON StudentMarks FOR EACH ROW
BEGIN 
    INSERT INTO H_StudentMarks VALUES(NULL, NEW.StudentId, NEW.SubjectId,  NEW.ExamDate, NEW.Mark, NOW(), NULL);
END $

Create TRIGGER StudentMarks_AU_Hist 
AFTER UPDATE ON StudentMarks FOR EACH ROW
BEGIN 
    UPDATE H_StudentMarks
    SET EndDate = NOW()
    WHERE H_StudentMarks.StudentId = StudentId 
    AND H_StudentMarks.SubjectId = SubjectId 
    AND H_StudentMarks.ExamDate = ExamDate AND EndDate IS NULL;
    
    INSERT INTO H_StudentMarks VALUES(NULL, NEW.StudentId, NEW.SubjectId,  NEW.ExamDate, NEW.Mark, NOW(), NULL);
END $

Create TRIGGER StudentMarks_AD_Hist 
AFTER DELETE ON StudentMarks FOR EACH ROW
BEGIN 
	UPDATE H_StudentMarks
    SET EndDate = NOW()
    WHERE H_StudentMarks.StudentId = StudentId 
    AND H_StudentMarks.SubjectId = SubjectId 
    AND H_StudentMarks.ExamDate = ExamDate AND EndDate IS NULL;
    
    INSERT INTO H_StudentMarks VALUES(NULL, OLD.StudentId, OLD.SubjectId,  OLD.ExamDate, OLD.Mark, NOW(), NULL);
END $

DELIMITER ;

INSERT INTO Students(Id, Name, Num, ClassNum, ClassLetter, Birthday, EGN) VALUES( 101, 'Зюмбюл Петров', 10, 11, 'а', '1999-02-28', NULL );
INSERT INTO Students(Name, Num, ClassNum, ClassLetter, Birthday, EGN) VALUES( 'Исидор Иванов', 15, 10, 'б', '2000-02-29', '0042294120' );
INSERT INTO Students(Name, Num, ClassNum, ClassLetter, Birthday, EGN) VALUES( 'Панчо Лалов', 20, 10, 'б', '2000-05-01', NULL );
INSERT INTO Students(Name, Num, ClassNum, ClassLetter, Birthday, EGN) VALUES( 'Петраки Ганьов', 20, 10, 'а', '1999-12-25', '9912256301' );
INSERT INTO Students(Name, Num, ClassNum, ClassLetter, Birthday, EGN) VALUES( 'Александър Момчев', 1, 8, 'а', '2002-06-11', NULL );

INSERT INTO Subjects(Id, Name) VALUES( 11, 'Английски език' );
INSERT INTO Subjects(Name) VALUES( 'Литература' );
INSERT INTO Subjects(Name) VALUES( 'Математика' );
INSERT INTO Subjects(Name) VALUES( 'СУБД' );

INSERT INTO StudentMarks VALUES( 101, 11, '2017-03-03', 6 );
INSERT INTO StudentMarks VALUES( 101, 11, '2017-03-31', 5.50 );
INSERT INTO StudentMarks VALUES( 102, 11, '2017-04-28', 5 );
INSERT INTO StudentMarks VALUES( 103, 12, '2017-04-28', 4 );
INSERT INTO StudentMarks VALUES( 104, 13, '2017-03-03', 5 );
INSERT INTO StudentMarks VALUES( 104, 13, '2017-04-07', 6 );
INSERT INTO StudentMarks VALUES( 104, 11, '2017-04-07', 4.50 );
INSERT INTO StudentMarks VALUES( 104, 12, '2017-04-08', 2 );
INSERT INTO StudentMarks VALUES( 102, 12, '2017-04-08', 2 );
INSERT INTO StudentMarks VALUES( 102, 12, '2017-04-09', 2 );
INSERT INTO StudentMarks VALUES( 103, 12, '2017-04-09', 2 );

SELECT * FROM H_StudentMarks;
SELECT * FROM H_Students;

SELECT * FROM H_Students
WHERE '2020-12-18 11:44:00' >= BeginDate AND ("2020-12-18 11:44:00" < EndDate OR EndDate IS NULL);

SELECT st.Name, sb.Name as SubjectName, AVG(sm.Mark) as AverageMark
FROM H_Students st
LEFT JOIN H_StudentMarks sm ON
st.Id = sm.StudentId AND ("2020-12-18 11:44:00" >= sm.BeginDate AND ("2020-12-18 11:44:00" < sm.EndDate OR sm.EndDate IS NULL))
INNER JOIN Subjects sb ON
sm.SubjectId = sb.Id
WHERE "2020-12-18 11:44:00" >= st.BeginDate AND ("2020-12-18 11:44:00" < st.EndDate OR st.EndDate IS NULL)
GROUP BY st.Id, st.Name, sm.SubjectId;

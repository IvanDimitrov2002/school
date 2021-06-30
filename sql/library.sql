DROP DATABASE IF EXISTS Library;
CREATE DATABASE Library;
USE Library;

CREATE TABLE Books (
	Id INTEGER NOT NULL AUTO_INCREMENT PRIMARY KEY,
	Name VARCHAR(100)  NOT NULL,
    Year VARCHAR(4) NOT NULL,
    ISBN VARCHAR(40) NOT NULL
);

CREATE TABLE Authors (
	Id INTEGER NOT NULL AUTO_INCREMENT PRIMARY KEY,
	Name VARCHAR(255) NOT NULL
);

CREATE TABLE BooksAuthors (
	BookId INTEGER NOT NULL,
    AuthorId INTEGER NOT NULL,
    
    FOREIGN KEY (BookId) REFERENCES Books(Id),
	FOREIGN KEY (AuthorId) REFERENCES Authors(Id)
);

INSERT INTO Books VALUES(100, "Metro 2033", "2010", "978-619-1234-25-0");
INSERT INTO Books VALUES(NULL, "The Lord of the Rings", "1954", "978-629-4321-25-0");
INSERT INTO Books VALUES(NULL, "Under the Yoke", "1893", "978-639-1423-25-0");
INSERT INTO Books VALUES(NULL, "Divine Comedy", "1472", "978-649-4123-25-0");
INSERT INTO Books VALUES(NULL, "Bel Ami", "1885", "978-659-1432-25-0");
INSERT INTO Books VALUES(NULL, "Mockingjay", "2010", "978-659-4132-25-0");
INSERT INTO Books VALUES(NULL, "The Two Towers", "1954", "978-659-9876-25-0");
INSERT INTO Books VALUES(NULL, "Futu.re", "2010", "978-619-6789-25-0");

INSERT INTO Authors VALUES(100, "Dmitry Glukhovsky");
INSERT INTO Authors VALUES(NULL, "J. R. R. Tolkien");
INSERT INTO Authors VALUES(NULL, "Ivan Vazov");
INSERT INTO Authors VALUES(NULL, "Dante Alighieri");
INSERT INTO Authors VALUES(NULL, "Guy de Maupassant");
INSERT INTO Authors VALUES(NULL, "Suzanne Collins");
INSERT INTO Authors VALUES(NULL, "Imaginary Guy");
INSERT INTO Authors VALUES(NULL, "Imaginary Girl");
INSERT INTO Authors VALUES(NULL, "No Books Author");
INSERT INTO Authors VALUES(NULL, "No Books Author2");

INSERT INTO BooksAuthors VALUES(100,100);
INSERT INTO BooksAuthors VALUES(101,101);
INSERT INTO BooksAuthors VALUES(102,102);
INSERT INTO BooksAuthors VALUES(103,103);
INSERT INTO BooksAuthors VALUES(104,104);
INSERT INTO BooksAuthors VALUES(105,105);
INSERT INTO BooksAuthors VALUES(105,106);
INSERT INTO BooksAuthors VALUES(105,107);
INSERT INTO BooksAuthors VALUES(106,101);
INSERT INTO BooksAuthors VALUES(107,100);
INSERT INTO BooksAuthors VALUES(107,106);
INSERT INTO BooksAuthors VALUES(107,107);

SELECT Name 
FROM Books 
WHERE YEAR = "2010";

SELECT Name 
FROM Books 
WHERE YEAR = "1954";

SELECT b.Name, b.Year, b.ISBN 
FROM Books b
INNER JOIN BooksAuthors ba
ON b.Id = ba.BookId
INNER JOIN Authors a
ON a.Id = ba.AuthorId
WHERE a.Name = "J. R. R. Tolkien";

SELECT a.Name
FROM Authors a
INNER JOIN BooksAuthors ba
ON a.Id = ba.AuthorId
INNER JOIN Books b
ON b.Id = ba.BookId
WHERE b.ISBN = "978-659-4132-25-0";

SELECT a.Name, COUNT(ba.BookId) as BooksCount
FROM Authors a
LEFT JOIN BooksAuthors ba
ON a.Id = ba.AuthorId
GROUP BY a.Name
ORDER BY BooksCount DESC;

SELECT b.Name, COUNT(ba.AuthorId) as AuthorsCount
FROM Books b
INNER JOIN BooksAuthors ba
ON b.Id = ba.BookId
WHERE b.Year = "2010"
GROUP BY b.Name
HAVING AuthorsCount >= 2
ORDER BY b.Name ASC;
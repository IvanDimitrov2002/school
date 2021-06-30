Това е проект, от който трябва да започнете, за да изпълните задачата - https://docs.google.com/document/d/11doMHVgi1t03fls4PPa_OuOlNW1T26UNApoc04UmKn4/edit?usp=sharing

Всички необходими dependency-та вече са добавени в pom.xml. Не е необходимо да добавяте други.

Файлът **_src\main\resources\services.json_** съдържа данните за видовете услуги, които трябва да управлявате.

Клас файлът _**src\test\java\com\example\demo\RetryApplicationTests.java**_ съдържа интеграционни тестове, които ще проверяват валидността на вашата разработка. Не променяйте нищо по тестовете.

Файлът **_Postman.postman_collection.json_** е експорт на работещи заявки в Postman.

Пример на заявките с cURL:

`curl --location --request GET 'http://localhost:8080/services'`

`curl --location --request POST 'http://localhost:8080/enroll' --header 'Content-Type: text/plain' --data-raw 'b86933bf-d672-497e-9e5e-940246b1e647'`

`curl --location --request PUT 'http://localhost:8080/desk/5' --header 'Content-Type: application/json' --data-raw '["b86933bf-d672-497e-9e5e-940246b1e647","aa29efcc-327f-4560-bc3d-898bb0dc4f18"]'`

`curl --location --request GET 'http://localhost:8080/board?top=5'`

Успех!

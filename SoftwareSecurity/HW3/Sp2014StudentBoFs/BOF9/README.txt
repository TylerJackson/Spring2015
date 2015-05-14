Program Description:
This application is a grade book that shows the grades for the students in the class.  
In order to see the grades for a student, the user has to login.  If a teacher logs in
they will see all the grades for all the student's in the class.  If a student logs in, 
they will only see the grades for themselves.  

In order to execute this program, you will need to compile the program from source.  
To accomplish this, the user will need to execute the following command:

g++ GradeBook.cpp -o GradeBook

This will produce an executable file called GradeBook.  In order to execute the program,
the just enter ./GradeBook on the command line.


The goal of this exploit is have to be able to login as a teacher user when you don't know
the teacher users password.  

The list of valid user names/passwords and their roles are as follows:

Bob who is a teacher
Alice/Alice1 is a student
Trudy/Trudy2 is a student
Craig/Craig3 is a Student


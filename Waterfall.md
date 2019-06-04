The Waterfall Model:

With the waterfall method, software is developed from scratch and, therefore, the model needs to be concrete and provide a clear view of tasks from beginning to end. The waterfall method works by fully completing one software unit and then moving on the the next component. To avoid waisting time by designing a system that doesn't meet the software requirements, the requirements and software design have to be solid in order to solve the problem efficiently. 

Requirements and Definition: 
The requirements of the system are the overall function of the program. 
If the requirements are not clear or are incorrect, there is no purpose of the system.
The first step is the time to define functions, constraints and any system specifications that need to be met.
In terms of the Course User Registration Software Emulartor (CURSE), there has to be correct registration numbers, class times, assigned professors, and available seats. 
A user interface is needed for the user to be able to interact with the software.
There must be different users such as students, professors, and an admin who should be able to access the database.
The students should be able to register for classes if the correct constraints are met.
The student can register, look at the available courses, and view their own schedule.
The instructor will see courses and the roster for their courses.
The admin has permission to edit everything. The different users will be kept in a database of users.
Constraints can be more technical as a user should be given a user interface and the database should be readable 

System and Software Design: 
Once a solid list of requirements and constraints is established, the next step is to actually develop the architecture and components of the system.
When designing a system like CURSE, there needs to be solid architecture in order for the system to not fail.
With so much traffic at one time, the system must be able to handle or distribute the load so that the system will not crash. 
The software will run on a local PC. The local host will host the database for the application to use.
The local database can be hosted on a web server with the use of XAMPP.
XAMPP is a good choice to work with because it has cross-platform capabilities.
The UI of the program can be accomplished in Java in the console on an IDE with basic system input and output statements.
Java has object-oriented capabilities to use the data from the databases well. 
The code will be hosted on github so proper version control best practices can take place. 

Implementation and Unit Testing: 
Once the architecture and other components are established, the next step is to implement the functionality into the system.
This will implement the technical aspects of the requirements and definition portion of the model.
The database for users should be built first. This should be able to hold 100 students, 10 instructors, and 1 admin.
This will be done in subtasks by making three different types of user that contain different data.
A constraint is needed here to make sure that a student is taking the right number of courses, not too little or too many.
The database for users should be built first. This should be able to hold 100 students, 10 instructors, and 1 admin.
This will be done in subtasks by making three different types of user that contain different data.
A constraint is needed here to make sure that a student is taking the right number of courses, not too little or too many.
The software for a user interface and the software for the functionality of CURSE should be developed according to the constraints set.
Once the code is written, the programmer is expecting to be able to have a student register for a class. To follow the waterfall method, each individual software unit would have to be finished before moving on to the next unit but this system has connected parts, which requires some overlap of development. Testing must be done to see if the bare minimum is correct.
For example, a user should be able to login, a user should have proper credentials, and the database should be displaying correctly.

Integration and System Testing: 
While the functionality of the program might be working, there are most likely flaws in the system.
This is where the system as a whole should be tested. A student must be able to at least register for a class.
If these works, constraints and stipulations should be added.
If there are no seats available in the class, a student should not be able to register for that particular class.
If a student does not have the prerequisites required for the class, the student should not be able to register.
This should also include tests for the system architecture.
There will be a large number of users signing in at the same time and attempting to register at the same time.
A good test would be to simulate a registration with a large amount of users to see if the program will be able to handle the load.

On github, the master branch of the code can be branched off into a feature branch to be merged back in once the feature is completed.
Each independent software unit has been tested on its own to the extent of its constraints.
It is unknown if merging each unit together will cause conflicts. 
After the software units have been merged together a full regression effort will take place to ensure the absence of any merge conflicts. 
If any issues are found, they can be addressed and retested. 

Operation and maintenance: 
While the system may seem bulletproof, everything will eventually break and there must be maintenance performed by the admin.
Some common bugs could include failure at logging in, failure of registering for a class, failure of viewing the courses correctly, and failing because the website crashed. Over time the requirements of the system may evolve as well. The software may become popular and require a larger database, or different functionality may need to be added. If these events occur, they will be addressed with by restarting the waterfall development process. 

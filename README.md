Seat booking collective database management system

The Idea is implement a portable database for a Airline. This database is going to be a single file that has the record for all the planes
of airline company. The database is a simple ticket booking system Infact it is a customized table created after users how many seats they
have in their planes and creates a unique entry for that seat.

User: Are the people who will be managing this database.

Let's say Airline requires a database for 40 setas in their plane. Table will look like

1 A B C D 
2 A B C D
. A B C D
. A B C D
10A B C D

Now let's say passanger books seat 2B the db will record it with X

1 A B C D 
2 A X C D
. A B C D
. A B C D
10A B C D

1) Create Database

2) Open Databases

3) Delete Database

4) Create Archive


It first Opens the Archived file and then start stuff 

1)Create Database

Asks user if they want to create a new seat database for new plane.

Ask how many seats do they want to enter in it and unique name for the database.

Then exits form option 1 and database gets saved to db file.

2) Open Database 

After Creating database user opens this option

Opens already existed databases

User select his database of a particular plane

He opens it

It has following options

1) Book Seat
2) View Seats
3) Find Seat
4) Unbook Seat

3) Delete Database

It shows all databases and asks user if they want to delete one or not.

4) Create Archive

It Creates the archive of three files into single file
....................

it creates the table with using array 
and when user is done he can save it to file

all the databases (table) can be saved to a single file easily

seek will seperate each table while opening

use pthreads to find information. HOW

--- Allow user to split file if file size is too big for the portablity.




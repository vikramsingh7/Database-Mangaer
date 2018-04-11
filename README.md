Database Manager for an Airline Company.
This single program provides the functionality of booking seats and also allows airline comapny to manage their ticket booking database.

User: Are the people who will be managing this database.

The Idea is to implement a portable database for an Airline company. This database consists of two files that has the information
about the available seats in a plane of an airline company. These two files are managed by a database manager through various 
functionalities. It allows users to book and unbook seats for customers.

Let us how it works:
Let's say Airline requires a database for 40 setas in their plane. dbManager will ask users to enter number of seats
then it will create a table such as:

1 A B C D 
2 A B C D
. A B C D
. A B C D
40A B C D

Now let's say passanger books seat 2B the db will record it with X

1 A B C D 
2 A X C D
. A B C D
. A B C D
10A B C D

Interface is such as:
1) Create Database

2) Open Databases

3) Delete Database

4) Create Archive



1)Create Database

Asks user if they want to create a new seat database for new plane.
Ask how many seats do they want to enter in it and unique name for the database.
Then exits form option 1 and database gets saved to db file.

2) Open Database 
BUG: The database that you enter most recent won't be open due to programming faults.

Allows users to open and start booking activities.
Opens already existed databases

It has following options

1) Book Seat
2) View Seats
3) Find Seat
4) Unbook Seat

3) Delete Database

It shows all databases and asks user if they want to delete one or not.

4) Create Archive

It Creates the archive of three files into single file
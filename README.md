# Bed & Breakfast Room Reservation System
A user-friendly reservation system designed for bed and breakfast owners to manage their bookings. The system includes features such as room allocation, cancellation, and display of guest data. This program uses linked lists to store guest data, and file handling to store this data persistently in a text file. This program is suitable for small hotels or guesthouses with a limited number of rooms.

# Prerequisites
- C++ compiler
- Windows OS

# How to use
- Clone the repository to your local machine
- Navigate to the directory where the files are saved
- Compile and run the program using your C++ compiler
- Follow the instructions on the screen to allocate or cancel a room, check the room number of a guest or display all guests' information
- The details of each guest are saved in guests.txt

#Classes
- `guest`: 
This class stores the guest details such as name, CNIC, room number, email, and contact number.
- `Room`
This class has two functions:
-- `allocate():` This function takes input from the user, validates it, and stores the guest's details in a linked list.
-- `cancel()`: This function cancels the reservation by taking input from the user, searching for the corresponding guest, and removing them from the linked list.

# Functions
- `checknameinput()`: This function validates the guest's name by checking if it contains only alphabets.
- `checkroomNuminput()`: This function validates the room number by checking if it contains only digits and if the room number is already in use.
- `checkCNIC()`: This function validates the guest's CNIC by checking if it is 13 digits long.
- `checkcontactNo()`: This function validates the guest's contact number by checking if it is 11 digits long.
- `validateEmail()`: This function validates the guest's email address by checking if it contains '@' and '.' and has a valid domain.
- `checkguestEmail()`: This function validates the guest's email address by calling validateEmail() and repeatedly asking the user to enter a valid email address if it is not valid.

# File Handling
- The program uses file handling to store the guest details in a file named guests.txt.
- When a guest room is allocated, their details are appended to the end of the file.
- The file is opened in append mode to prevent overwriting the existing contents.

# Author
This program was written by Laiba Shakil as a personal project. Feel free to use, modify, or distribute the code.

# License
This project is licensed under the MIT License - see the LICENSE file for details.

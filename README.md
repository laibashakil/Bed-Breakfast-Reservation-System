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

# Classes
1.	`guest`: This is a class representing the guests who will be allocated rooms. It has properties such as name, CNIC, roomNum, guestEmail, and contactNo representing the guest's name, identification number, room number, email, and contact number, respectively. The guest class also has a pointer to the next guest in the linked list.
2.	`Room`: This class represents the hotel rooms and their allocation to guests. It has a private member head, which is a pointer to the first guest object in a linked list. The Room class has functions such as `checknameinput()`, `checkroomNuminput()`, `checkCNIC()`, `checkcontactNo()`, `validateEmail()`, `checkguestEmail()`, `allocate()`, and `cancel()`.

# Functions
1.	`checknameinput()`: This function is responsible for taking input of the guest's name, removing any spaces in the input, and validating that the input only contains alphabetic characters.
2.	`checkroomNuminput()`: This function is responsible for taking input of the guest's room number, validating that the input only contains digits, and checking if the entered room number is already in use by another guest.
3.	`checkCNIC()`: This function is responsible for taking input of the guest's 13-digit CNIC number and validating that the input is exactly 13 digits long.
4.	`checkcontactNo()`: This function is responsible for taking input of the guest's contact number, validating that the input is exactly 11 digits long, and ensuring that the input only contains digits.
5.	`validateEmail()`: This function takes an email address as input and returns a boolean value indicating whether the input is a valid email address or not.
6.	`checkguestEmail()`: This function is responsible for taking input of the guest's email address, validating that the input is a valid email address using the `validateEmail()` function, and prompting the user to enter a valid email address if the input is not valid.
7.	`allocate()`: This function is responsible for allocating a room to a guest. It takes input of the guest's name, room number, CNIC number, contact number, and email address using the above-mentioned functions. It then appends this information to a text file and creates a new guest object with the input information and adds it to the linked list of guests.
8.	`cancel()`: This function is responsible for canceling the allocation of a room to a guest. It takes input of the guest's name and room number using the `checknameinput()` and `checkroomNuminput()` functions, respectively. It then searches the linked list of guests for a matching guest object and deletes it.

# File Handling
- The program uses file handling to store the guest details in a file named guests.txt.
- When a guest room is allocated, their details are appended to the end of the file.
- The file is opened in append mode to prevent overwriting the existing contents.

# Contributing
If you would like to contribute to the program, please fork the repository and submit a pull request. Contributions are welcome and appreciated.

# License
This project is licensed under the MIT License - see the LICENSE file for details.

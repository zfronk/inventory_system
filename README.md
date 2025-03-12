# Warehouse Inventory Management System

## Overview
The Warehouse Inventory Management System is a C-based console application designed to help users manage warehouse inventory efficiently. It allows users to add, view, delete, and search for items, storing the data in a text file for persistence.

## Features
- **Add Items**: Users can input item names and prices, which are then stored in a file.
- **View Inventory**: Displays a list of all stored items.
- **Delete Items**: Users can remove specific items from the inventory.
- **Search Items**: Allows searching for items within the inventory.
- **User-friendly Interface**: Console-based interaction with error handling and input validation.

## Installation & Usage
### Prerequisites
- A C compiler (e.g., GCC)
- A terminal or command prompt

### Compilation
Use the following command to compile the program:
```sh
gcc -o run.exe inventory_system.c
```

### Running the Application
Execute the compiled program:
```sh
./run.exe
```

### Navigating the Application
1. Choose an option from the dashboard by entering the corresponding number.
2. Follow on-screen prompts to add, delete, view, or search items.
3. Enter '5' to exit the application.

## File Structure
- `inventory.c` - Main source code
- `items_added.txt` - Storage file for inventory items

## Future Enhancements
- Implement dynamic memory allocation for item storage.
- Add a graphical user interface (GUI) using Raylib or another toolkit.
- Improve search functionality with advanced filtering options.
- Implement data encryption for secure inventory management.

## License
This project is open-source and available for modification and distribution.

## Author
Steve


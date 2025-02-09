# C Programming Project: Wizard Management

This project is a **test to evaluate my skills in the C programming language**. It is a C application that allows the management of a list of wizards. It includes functionalities to register, modify, save, and load wizard data, as well as sort them by their magical level.

## Features

- **Register Wizards:** Allows the user to manually enter new wizards with a name, magical level, and favorite spell.
- **Modify Magical Levels:** Users can update the magical level of existing wizards.
- **Save to File:** Wizard data can be saved in a binary file.
- **Load from File:** Loads wizard data from a previously saved binary file.
- **Sort Wizards:** Displays the list of wizards sorted by their magical level from highest to lowest.
- **Interactive Menu:** Easy navigation through an interactive terminal menu.

## Requirements

- A C compiler (such as GCC).
- An operating system compatible with C (Linux, macOS, Windows).

## Compilation and Execution

To compile the program, run the following command in your terminal:

```bash
gcc -o wizard_management wizard_management.c
```

To run the program:

```bash
./wizard_management
```

## Code Structure

### Definition of the `Wizard` Structure

```c
struct Wizard {
    char name[50];
    int magicalLevel;
    char favoriteSpell[30];
};
```

### Key Functionalities

1. **Register Wizards:**
    - Allows entering new wizards and stores their data in a dynamic array.

2. **Modify Magical Levels:**
    - Validates that the new level is between 1 and 100.
    - Warns if the level decreases.

3. **Save and Load from File:**
    - Saves data in a binary file (`wizards.bin`).
    - Allows loading data from the file at program startup.

4. **Sort Wizards:**
    - Sorts wizards from highest to lowest by their magical level using the bubble sort algorithm.

### Interactive Menu

The program features an interactive menu with the following options:

1. Register wizards manually.
2. Modify wizards' magical levels.
3. Save the list of wizards to a magical file.
4. Load wizards from a magical file.
5. Display wizards sorted by magical level.
6. Exit the program.

## Example of Use

Upon starting the program, the default wizards are automatically loaded:

- **Gojo** - Magical Level: 95 - Favorite Spell: *Infinito*
- **Goku** - Magical Level: 85 - Favorite Spell: *Kamehamehame*
- **Gandalf** - Magical Level: 90 - Favorite Spell: *You shall not pass!*



May the magic of programming be with you! 🧙‍♂️🚀


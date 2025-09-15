# Knight Gambit - Chess Knight Pathfinding Project

**Authors:** Ori Braverman (ID: 318917010), Sagi Goldfarb (ID: 316496173)  
**Date:** June 9th, 2021  
**Course:** Data Structures Programming Project

## Project Overview

Knight Gambit is a comprehensive chess knight pathfinding application written in C. The project implements various algorithms and data structures to solve the classic "Knight's Tour" problem and related chess knight movement challenges on a 5x5 chessboard.

The project is structured as a modular solution with 7 main components (Q1-Q7), each building upon the previous to create a complete knight pathfinding system with file I/O capabilities and user interaction.

## Features

- **Knight Move Validation**: Calculate all valid knight moves from any position
- **Path Tree Generation**: Build a complete tree of all possible knight paths
- **Knight's Tour Solver**: Find paths that cover the entire chessboard
- **Binary File I/O**: Save and load chess paths in compressed binary format
- **Interactive Menu System**: User-friendly interface for all functionalities
- **Chess Position Management**: Efficient linked list and tree data structures

## Project Structure

```
Chess-Project/
├── main.c              # Entry point and debugging mains
├── utility.h/c         # Common data structures and utility functions
├── Q1.h/c             # Valid knight moves calculation
├── Q2.h/c             # Chess position list management and visualization
├── Q3.h/c             # Path tree generation for all possible moves
├── Q4.h/c             # Knight's tour solver (covering entire board)
├── Q5.h/c             # Binary file save functionality
├── Q6.h/c             # Binary file load and validation functionality  
├── Q7.h/c             # Interactive menu system
├── ChessProject.vcxproj # Visual Studio project file
└── README.txt          # Original basic readme
```

## Core Data Structures

### Chess Position (`chessPos`)
```c
typedef char chessPos[2]; // e.g., {'A', '1'} for position A1
```

### Position Array (`chessPosArray`)
```c
typedef struct _chessPosArray {
    unsigned int size;
    chessPos* positions;
} chessPosArray;
```

### Position List (`chessPosList`)
```c
typedef struct chessPosList {
    chessPosCell* head;
    chessPosCell* tail;
} chessPosList;
```

### Path Tree (`pathTree`)
```c
typedef struct _pathTree {
    treeNode* root;
} pathTree;
```

## Module Breakdown

### Q1 - Valid Knight Moves
- **Purpose**: Calculate all valid knight moves from any position on a 5x5 board
- **Key Function**: `validKnightMoves()` - Returns a 3D array of valid moves for each board position
- **Algorithm**: Uses knight move offsets: {(-2,-1), (-2,1), (-1,-2), (1,-2), (2,-1), (2,1), (1,2), (-1,2)}

### Q2 - Position List Management
- **Purpose**: Manage sequences of chess positions using linked lists
- **Key Functions**: 
  - `display()` - Visualize the chess path on a board
  - `printList()` - Print the sequence of moves
- **Features**: Board visualization with move order numbering

### Q3 - Path Tree Generation
- **Purpose**: Build a complete tree of all possible knight paths from a starting position
- **Key Function**: `findAllPossibleKnightPaths()` - Creates a tree with all reachable positions
- **Algorithm**: Recursive tree building with position tracking to avoid cycles

### Q4 - Knight's Tour Solver
- **Purpose**: Find a path that visits all 25 squares of the 5x5 board exactly once
- **Key Function**: `findKnightPathCoveringAllBoard()` - Searches the path tree for complete tours
- **Challenge**: Classic backtracking problem with exponential complexity

### Q5 - Binary File Export
- **Purpose**: Save chess position lists to compressed binary files
- **Key Function**: `saveListToBinFile()` - Encodes positions using custom bit packing
- **Compression**: Uses 5 bits per position (2.5 bits for column A-E, 2.5 bits for row 1-5)

### Q6 - Binary File Import & Validation
- **Purpose**: Load and validate chess paths from binary files
- **Key Functions**:
  - `checkAndDisplayPathFromFile()` - Load, validate, and display paths
  - `isValidKnightList()` - Verify that consecutive moves are valid knight moves
- **Validation**: Ensures loaded paths follow knight movement rules

### Q7 - Interactive Menu System
- **Purpose**: Provide user-friendly interface to all functionalities
- **Features**:
  1. Input chess position and calculate valid moves
  2. Generate path tree from position
  3. Find knight's tour (if possible)
  4. Save path to binary file
  5. Load and validate path from binary file
  6. Exit program

## Build Instructions

### Windows (Visual Studio)
1. Open `ChessProject.vcxproj` in Visual Studio
2. Build the solution (Ctrl+Shift+B)
3. Run the executable

### Windows (MinGW/GCC)
```bash
gcc -o chess_project main.c Q1.c Q2.c Q3.c Q4.c Q5.c Q6.c Q7.c utility.c
```

### Linux/Mac (Cross-platform adaptation needed)
The project currently uses Windows-specific headers (`conio.h`). To compile on Linux/Mac:
1. Remove or conditionally compile `#include <conio.h>` from `utility.h`
2. Replace `system("cls")` calls with `system("clear")` in Q7.c
3. Compile with:
```bash
gcc -o chess_project main.c Q1.c Q2.c Q3.c Q4.c Q5.c Q6.c Q7.c utility.c
```

## How to Run

1. **Compile the project** using the instructions above
2. **Run the executable**: `./chess_project` (Linux/Mac) or `chess_project.exe` (Windows)
3. **Follow the interactive menu**:
   - Choose option 1-6 from the main menu
   - Enter chess positions in format like "A1", "B3", "E5"
   - Use the generated files for testing save/load functionality

## Sample Usage

```
Welcome to Knight Gambit!

1. Show valid moves for a position
2. Generate all possible paths from position  
3. Find knight's tour (cover entire board)
4. Save current path to file
5. Load and validate path from file
6. Exit

Enter your choice: 1
Enter position (e.g., A1): B3

Valid moves from B3:
A1, A5, C1, C5, D2, D4
```

## File Formats

### Binary Path Files (.bin)
- Custom compressed format storing chess position sequences
- Each position encoded in 5 bits
- File starts with path length, followed by encoded positions

### Generated Files
- `FullList.bin` - Complete knight's tour (if found)
- `Q5binaryList.bin` - Sample path file for testing
- `check.bin` - Validation test file

## Algorithms & Complexity

- **Valid Moves Calculation**: O(1) per position, O(n²) for full board
- **Path Tree Generation**: O(k^d) where k is average branching factor, d is depth
- **Knight's Tour**: Exponential complexity O(8^25) worst case, uses backtracking
- **File I/O**: Linear in path length O(n)

## Educational Value

This project demonstrates:
- **Data Structures**: Linked lists, trees, arrays
- **Algorithms**: Backtracking, tree traversal, path finding
- **File I/O**: Binary file handling, custom encoding schemes
- **Memory Management**: Dynamic allocation, proper cleanup
- **Modular Programming**: Separation of concerns across multiple modules

## Limitations

- **Board Size**: Fixed 5x5 board (can be modified by changing SIZE constant)
- **Platform**: Currently Windows-specific due to `conio.h` dependency
- **Performance**: Brute force approach for knight's tour may be slow for certain positions
- **Memory**: Large path trees may consume significant memory

## Future Enhancements

- Cross-platform compatibility
- Configurable board sizes
- Heuristic-based knight's tour algorithms (Warnsdorff's rule)
- Graphical user interface
- Path optimization algorithms
- Multi-threading for faster pathfinding

## Contributing

This is an academic project. The code serves as a reference implementation for chess knight pathfinding algorithms and data structures education.

## License

Academic project - for educational purposes.
♟️ THE CHESS GAMBIT

A fully functional command-line Chess game developed in C Programming Language. This project implements core chess mechanics, including legal move validation, check and checkmate detection, board management, and game state saving/loading.

Designed as an educational and practical software engineering project, Chess With C demonstrates the use of modular programming, data structures, file handling, and game logic implementation in C.

📖 Project Overview

Chess With C is a terminal-based chess application that allows two players to play a complete game of chess directly from the command line.

The project focuses on implementing the fundamental rules of chess while maintaining clean and modular code architecture. Each major functionality is separated into dedicated source files, making the project easier to maintain, debug, and expand.

This project serves as an excellent example of:

- Structured Programming
- Modular Software Design
- Algorithm Development
- File Handling in C
- Game Logic Implementation
- Data Validation Techniques

✨ Features

♟ Complete Chess Gameplay
- Standard 8×8 chess board
- Two-player gameplay
- Turn-based move system
- Piece movement according to official chess rules

✅ Move Validation
- Legal move checking
- Prevention of invalid moves
- Friendly-piece collision detection
- Capture validation

👑 Check Detection
- Detects when a king is under attack
- Alerts players during gameplay

🏆 Checkmate Detection
- Identifies checkmate situations
- Determines game winner automatically

💾 Save & Load System
- Save current game progress
- Resume previously saved matches
- File-based game persistence

🖥 Terminal Interface
- Lightweight console-based design
- Fast execution
- Cross-platform compatibility with GCC

📂 Project Structure

CHESS_WITH_C/
│
├── main.c             # Program entry point
├── board.c            # Chess board creation and display
├── moves.c            # Move validation and execution
├── save_game.c        # Save and load game functionality
├── checkmate.c        # Check and checkmate detection
│
├── README.md
└── savegame.txt

🛠 Technologies Used

- C Programming Language
- GCC Compiler
- Standard C Libraries
- File Handling
- Modular Programming Techniques

🚀 Compilation & Execution

Windows PowerShell (UTF-8 Support)

$OutputEncoding = [Console]::OutputEncoding = [System.Text.Encoding]::UTF8
gcc main.c board.c moves.c save_game.c checkmate.c -o chess -lm
.\chess

Standard GCC Compilation

gcc main.c board.c moves.c save_game.c checkmate.c -o chess -lm
./chess

Visual Studio Code Terminal

cd "C:\Users\agomo\OneDrive\Desktop\New folder\project_chess"
$OutputEncoding = [Console]::OutputEncoding = [System.Text.Encoding]::UTF8
gcc main.c board.c moves.c save_game.c checkmate.c -o chess -lm
.\chess

🎯 Learning Outcomes

Through this project, the following concepts are demonstrated:
- Procedural Programming
- Function Decomposition
- Game State Management
- Chess Rule Implementation
- Input Validation
- File Operations
- Software Modularity
- Debugging and Testing

🔮 Future Improvements

Potential enhancements include:
- Single-player mode with AI opponent
- Minimax algorithm implementation
- Alpha-Beta Pruning optimization
- Graphical User Interface (GUI)
- Online multiplayer support
- Move history tracking
- PGN (Portable Game Notation) export
- Undo/Redo functionality
- Chess clock integration

👨‍💻 Author

Md. Atif Absar
Computer Science & Engineering (CSE)
Khulna University of Engineering & Technology (KUET)

📜 License

This project is developed for educational and academic purposes. Feel free to fork, modify, and learn from the code while providing appropriate attribution.

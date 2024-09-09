# Tic-Tac-Toe Game with Sockets

This C++ project is a networked Tic-Tac-Toe game that uses socket programming to allow client-server interaction. The server and client exchange game moves using TCP/IP sockets, and the game board is updated accordingly. The application demonstrates both socket communication and the implementation of the game logic using a functional approach, with an AI opponent powered by the Minimax algorithm.

## Features

- **Socket Communication**: The game uses Winsock2 for communication between client and server over TCP/IP.
- **Tic-Tac-Toe Game Logic**: Implements a simple Tic-Tac-Toe game where the client plays with 'X' and the server plays with 'O'.
- **Game Board Management**: The game board is represented as a 3x3 matrix and is updated in real-time based on the players' moves.
- **Minimax Algorithm**: The AI opponent uses the Minimax algorithm to decide its moves, ensuring optimal gameplay for the server.
- **Input Validation**: Ensures that inputs are valid and handles cases where a cell is already occupied.
- **Winner Detection**: The game checks for winning conditions after every move and announces the winner.

## Project Structure

- **Matrix**: The Tic-Tac-Toe board is represented as a 2D array (`matrix[3][3]`), where each cell is initially filled with numbers 1-9. As players make moves, the respective cells are updated with 'X' (client) or 'O' (server).
  
- **Winsock Integration**: The application uses Winsock2 to manage TCP/IP connections. The server listens for connections from a client, and the client sends/receives data (moves) to/from the server.

- **Game Logic**:
  - The client makes a move by sending a number (1-9) representing the cell they want to play in.
  - The server validates the move, updates the board, and sends the updated move back to the client.
  - The game checks for a winner after each move, verifying if there are any three matching marks in a row, column, or diagonal.

- **Minimax Algorithm**: The server AI uses the Minimax algorithm to calculate its moves. This ensures that the server always plays optimally, making the best possible move in each situation.

- **Error Handling**: The server and client handle errors like invalid inputs (out-of-bounds or non-numeric values) and already-occupied cells.

## How to Build

1. **Install Visual Studio** (or another C++ compiler supporting Winsock).
2. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/tic-tac-toe-sockets
   ```
3. Open the project in Visual Studio.
4. Ensure that Winsock libraries are linked properly:

  ```C++
  #pragma comment (lib, "ws2_32.lib")
  ```
5. Compile and run both the server and client applications on separate terminals or machines.

## How to Play
1. Start the server:
    - The server will wait for a connection from the client.

2. Start the client:
    - The client will connect to the server.

3. Players take turns entering numbers (1-9) representing the cells on the Tic-Tac-Toe board.
    - The server plays as 'O'.
    - The client plays as 'X'.

4. The game will continue until a player wins or all cells are filled.

## Example

```
1 2 3
4 5 6
7 8 9
```
The players input numbers from 1 to 9 to place their 'X' or 'O' on the board.

```
X O X
O X O
7 8 9
```

## Requirements
- Windows OS
- Visual Studio or any C++ compiler with Winsock support

License
This project is open source and available under the MIT License.

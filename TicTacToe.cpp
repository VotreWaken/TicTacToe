#define WIN32_LEAN_AND_MEAN

#include <iostream>

// Include Winsock and TCPIP libraries 
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32.lib")

#pragma warning(disable : 4996)

using namespace std;

// Exchange Buffer between Server and Client
char recvbuf[2];
char sendbuf[2];

// Matrix to fill
char matrix[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

// Player char 
char player = 'O';

// Update Matrix to default values Function 
void UpdateMatrix()
{
	// ASCII 49 = '1' in loop set matrix values to in order
	int counter = 49;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			matrix[i][j] = counter;
			++counter;
		}
	}
}

// Draw Matrix Function
void Draw()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

// The function takes 0 element of the buffer received from the Client,
// Which contains the value entered by the Client and applies this value to the matrix
void InputClient(char sendbuf[])
{
	// Variable takes 0 element of the buffer received from the Client
	int a = sendbuf[0];

	// Use the value of the variable and enter it into the matrix
	if (a == 1)
		matrix[0][0] = 'X';
	else if (a == 2)
		matrix[0][1] = 'X';
	else if (a == 3)
		matrix[0][2] = 'X';
	else if (a == 4)
		matrix[1][0] = 'X';
	else if (a == 5)
		matrix[1][1] = 'X';
	else if (a == 6)
		matrix[1][2] = 'X';
	else if (a == 7)
		matrix[2][0] = 'X';
	else if (a == 8)
		matrix[2][1] = 'X';
	else if (a == 9)
		matrix[2][2] = 'X';

	// Return a variable to a buffer
	sendbuf[0] = a;
}

// The Function asks the server for a value that will be writtenand
// displayed on the matrixand written to the buffer with index 1 which is sent to the client
void InputServer(char sendbuf[])
{
	int a;
	cout << "Enter number: ";
	cin >> a;

	if (a > 9)
	{
		cout << "Error Field" << endl;
		return InputServer(sendbuf);
	}

	// Catch Error if input is char 
	if (std::cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		std::cout << "Error number" << endl;
		return InputServer(sendbuf);
	}

	if (a == 1)
	{
		if (matrix[0][0] == '1')
			matrix[0][0] = 'O';
		else
		{
			cout << "Field is already in use try again!" << endl;
			return InputServer(sendbuf);
		}
	}

	else if (a == 2)
	{
		if (matrix[0][1] == '2')
			matrix[0][1] = 'O';
		else
		{
			cout << "Field is already in use try again!" << endl;
			return InputServer(sendbuf);
		}
	}

	else if (a == 3)
	{
		if (matrix[0][2] == '3')
			matrix[0][2] = 'O';
		else
		{
			cout << "Field is already in use try again!" << endl;
			return InputServer(sendbuf);
		}
	}
	else if (a == 4)
	{
		if (matrix[1][0] == '4')
			matrix[1][0] = 'O';
		else
		{
			cout << "Field is already in use try again!" << endl;
			return InputServer(sendbuf);
		}
	}
	else if (a == 5)
	{
		if (matrix[1][1] == '5')
			matrix[1][1] = 'O';
		else
		{
			cout << "Field is already in use try again!" << endl;
			return InputServer(sendbuf);
		}
	}
	else if (a == 6)
	{
		if (matrix[1][2] == '6')
			matrix[1][2] = 'O';
		else
		{
			cout << "Field is already in use try again!" << endl;
			return InputServer(sendbuf);
		}
	}
	else if (a == 7)
	{
		if (matrix[2][0] == '7')
			matrix[2][0] = 'O';
		else
		{
			cout << "Field is already in use try again!" << endl;
			return InputServer(sendbuf);
		}
	}
	else if (a == 8)
	{
		if (matrix[2][1] == '8')
			matrix[2][1] = 'O';
		else
		{
			cout << "Field is already in use try again!" << endl;
			return InputServer(sendbuf);
		}
	}
	else if (a == 9)
	{
		if (matrix[2][2] == '9')
			matrix[2][2] = 'O';
		else
		{
			cout << "Field is already in use try again!" << endl;
			return InputServer(sendbuf);
		}
	}
	sendbuf[1] = a;
}

// Function Checks Matrix elements for a winning move
char Win()
{

	if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
		return 'X';
	if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
		return 'X';
	if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
		return 'X';

	if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
		return 'X';
	if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
		return 'X';
	if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
		return 'X';

	if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
		return 'X';
	if (matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X')
		return 'X';

	if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
		return 'O';
	if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')
		return 'O';
	if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')
		return 'O';

	if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
		return 'O';
	if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')
		return 'O';
	if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')
		return 'O';

	if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
		return 'O';
	if (matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O')
		return 'O';

	return '/';
}

// Initialize Server Socket whos takes Client connection 
void ServerSocket()
{
	// Variable stores data from functions
	long res;

	// The WSADATA structure contains information about the implementation of Windows sockets
	WSADATA wsaData;

	// called to start using WS2_32.dll
	// Requests the version 2.2 of Winsock that the caller can use.
	res = WSAStartup(MAKEWORD(2, 1), &wsaData);

	// Output on display that the step completed successfully
	if (res == 0)
		cout << "WSASTARTUP sucsessful" << endl;

	// Create an unbound sockets to server 
	// To have the server listen for client connections
	// And Client Socket 
	SOCKET slisten, client;

	// Create a SOCKET for the server to listen for client connections
	slisten = socket(AF_INET, SOCK_STREAM, 0);

	// Output on display that the step completed successfully
	if (slisten != INVALID_SOCKET)
		cout << "Socket Sucsessful" << endl;

	// The sockaddr_in structure describes a socket for dealing with IP protocols.
	sockaddr_in info;

	char ip[16];
	cout << "Enter ip (127.0.0.1): " << endl;
	cin >> ip;

	// The sin_addr field contains the IP address to which the socket will be bound.
	info.sin_addr.s_addr = inet_addr(ip);

	// AF_INET is used to specify the IPv4 address family.
	info.sin_family = AF_INET;

	unsigned short port = 8080;
	cout << "Enter port (8080): " << endl;
	cin >> port;
	// sin_port contains the port number the process intends to occupy
	info.sin_port = htons(port);

	// The variable 'infolen' receives data about the size of the structure
	int infolen = sizeof(info);

	// the server puts the port numberand IP address into structure sockaddr_,
	// passing it, and the socket, to the bind() function
	res = bind(slisten, (struct sockaddr*)&info, infolen);

	// Output on display that the step completed successfully
	if (res != SOCKET_ERROR)
		cout << "Bind Sucsessful" << endl;

	// listen on this IP address and port for incoming connection requests.
	// created socket and backlog value as parameters
	// the backlog parameter is set to SOMAXCONN. 
	// This value is a special constant that tells the Winsock 
	// provider for this socket to allow the maximum number of pending
	// connections allowed in the queue.
	res = listen(slisten, SOMAXCONN);

	// Output on display that the step completed successfully
	if (res != SOCKET_ERROR)
		cout << "Listen Sucsessful" << endl;

	// The sockaddr_in structure describes a socket for dealing with IP protocols.
	sockaddr_in clientinfo;

	// The variable 'infolen' receives data about the size of the structure
	int clientinfolen = sizeof(clientinfo);

	// When a socket is listening for a connection, the program must process connection requests on that socket.
	client = accept(slisten, (struct sockaddr*)&clientinfo, &clientinfolen);

	// Output on display that the step completed successfully
	if (client != SOCKET_ERROR)
		cout << "Client accepted: " << inet_ntoa(clientinfo.sin_addr) << ":" << htons(clientinfo.sin_port) << endl;


	// Variable to calculate the tie
	int n = 0;

	// The loop runs before the socket became invalid
	do
	{
		// The function is used to read data from the socket and write it to the buffer
		res = recv(client, recvbuf, 2, 0);
		n++;

		// Function to applies value from buffer to the matrix
		InputClient(recvbuf);

		// Draw Matrix Function
		Draw();

		// Checks if the game ended in a draw or a win
		if (Win() == 'X')
		{
			cout << "X wins!" << endl;
			n = 0;
			UpdateMatrix();
		}
		if (Win() == 'O')
		{
			cout << "O wins!" << endl;
			n = 0;
			UpdateMatrix();
		}
		if (Win() == '/' && n == 9)
		{
			cout << "It's a draw!" << endl;
			n = 0;
			UpdateMatrix();
		}

		// Function to applies value from Server to the matrix
		InputServer(recvbuf);

		// The function is used to send data from the socket
		res = send(client, recvbuf, 2, 0);

		n++;
	} while (res != SOCKET_ERROR);


	// The closesocket function closes an existing socket.
	closesocket(client);
	closesocket(slisten);

	// The WSACleanup function terminates use of the Winsock 2 DLL (Ws2_32.dll).
	WSACleanup();
}

// The function takes element of the Minimax algorithm and applies this value to the matrix
void InputAi(int a, int b)
{
	if (a == -1 || b == -1)
	{
		return;
	}
	matrix[a][b] = 'O';
}

// This function returns true or false
//  if there are moves remaining on the board.
bool isMovesLeft(char matrix[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (matrix[i][j] >= 49 && matrix[i][j] <= 57)
				return true;
	return false;
}

// This is the evaluation function as discussed
int evaluate(char b[3][3])
{
	// Checking for Rows for X or O victory.
	for (int row = 0; row < 3; row++)
	{
		if (b[row][0] == b[row][1] &&
			b[row][1] == b[row][2])
		{
			if (b[row][0] == 'X')
				return +10;
			else if (b[row][0] == 'O')
				return -10;
		}
	}

	// Checking for Columns for X or O victory.
	for (int col = 0; col < 3; col++)
	{
		if (b[0][col] == b[1][col] &&
			b[1][col] == b[2][col])
		{
			if (b[0][col] == 'X')
				return +10;

			else if (b[0][col] == 'O')
				return -10;
		}
	}

	// Checking for Diagonals for X or O victory.
	if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
	{
		if (b[0][0] == 'X')
			return +10;
		else if (b[0][0] == 'O')
			return -10;
	}

	if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
	{
		if (b[0][2] == 'X')
			return +10;
		else if (b[0][2] == 'O')
			return -10;
	}
}

// This is the minimax function. It considers all
// the possible ways the game can go and returns
// the value of the board
int minimax(char matrix[3][3], int depth, bool isMax)
{
	int score = evaluate(matrix);

	// If Maximizer has won the game return his/her
	// evaluated score
	if (score == 10)
		return score;

	// If Minimizer has won the game return his/her
	// evaluated score
	if (score == -10)
		return score;

	// If there are no more moves and no winner then
	// it is a tie

	// If this maximizer's move
	if (isMax)
	{
		int best = -1000;

		// Traverse all cells
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				// Check if cell is empty (49 == '1' && 57 == '9')
				if (matrix[i][j] >= 49 && matrix[i][j] <= 57)
				{
					int temp = 0;
					temp = matrix[i][j];
					// Make the move
					matrix[i][j] = 'O';

					// Call minimax recursively and choose
					// the maximum value
					best = max(best,
						minimax(matrix, depth + 1, !isMax));

					// Undo the move
					matrix[i][j] = temp;
				}
			}
		}
		return best;
	}

	// If this minimizer's move
	else
	{
		int best = 1000;

		// Traverse all cells
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				// Check if cell is empty
				if (matrix[i][j] >= 49 && matrix[i][j] <= 57)
				{
					// Make the move
					int temp = 0;
					temp = matrix[i][j];
					matrix[i][j] = 'O';

					// Call minimax recursively and choose
					// the minimum value
					best = min(best,
						minimax(matrix, depth + 1, !isMax));

					// Undo the move
					matrix[i][j] = temp;
				}
			}
		}
		return best;
	}
}

// This will return the best possible move for the player
void findBestMove(char matrix[3][3])
{
	int bestVal = -1000;
	int bestMove;
	int bestRow = -1;
	int bestCol = -1;

	// Traverse all cells, evaluate minimax function for
	// all empty cells. And return the cell with optimal
	// value.
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// Check if cell is empty
			if (matrix[i][j] >= 49 && matrix[i][j] <= 57)
			{
				// Make the move
				int temp = 0;
				temp = matrix[i][j];
				matrix[i][j] = 'X';

				// compute evaluation function for this
				// move.
				int moveVal = minimax(matrix, 0, false);

				matrix[i][j] = temp;

				// If the value of the current move is
				// more than the best value, then update
				// best/
				if (moveVal > bestVal)
				{
					bestRow = i;
					bestCol = j;
					bestVal = moveVal;
				}
			}
		}
	}

	InputAi(bestRow, bestCol);
}

// The function takes element from Player and input to matrix
void InputSingle()
{
	int a;
	cout << "Enter number: ";
	cin >> a;

	if (a > 9)
	{
		cout << "Error Field" << endl;
		return InputSingle();
	}

	// Catch Error if input is char 
	if (std::cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		std::cout << "The input is not a number from 1 to 9" << endl;
		return InputSingle();
	}

	if (a == 1)
	{
		if (matrix[0][0] == '1')
			matrix[0][0] = 'X';
		else
		{
			cout << "Field is already in use try again!" << endl;
			InputSingle();
		}
	}
	else if (a == 2)
	{
		if (matrix[0][1] == '2')
			matrix[0][1] = 'X';
		else
		{
			cout << "Field is already in use try again!" << endl;
			InputSingle();
		}
	}
	else if (a == 3)
	{
		if (matrix[0][2] == '3')
			matrix[0][2] = 'X';
		else
		{
			cout << "Field is already in use try again!" << endl;
			InputSingle();
		}
	}
	else if (a == 4)
	{
		if (matrix[1][0] == '4')
			matrix[1][0] = 'X';
		else
		{
			cout << "Field is already in use try again!" << endl;
			InputSingle();
		}
	}
	else if (a == 5)
	{
		if (matrix[1][1] == '5')
			matrix[1][1] = 'X';
		else
		{
			cout << "Field is already in use try again!" << endl;
			InputSingle();
		}
	}
	else if (a == 6)
	{
		if (matrix[1][2] == '6')
			matrix[1][2] = 'X';
		else
		{
			cout << "Field is already in use try again!" << endl;
			InputSingle();
		}
	}
	else if (a == 7)
	{
		if (matrix[2][0] == '7')
			matrix[2][0] = 'X';
		else
		{
			cout << "Field is already in use try again!" << endl;
			InputSingle();
		}
	}
	else if (a == 8)
	{
		if (matrix[2][1] == '8')
			matrix[2][1] = 'X';
		else
		{
			cout << "Field is already in use try again!" << endl;
			InputSingle();
		}
	}
	else if (a == 9)
	{
		if (matrix[2][2] == '9')
			matrix[2][2] = 'X';
		else
		{
			cout << "Field is already in use try again!" << endl;
			InputSingle();
		}
	}

}

// Function to start Single Play 
void SinglePlayer()
{
	// Variable to calculate the tie
	int n = 0;

	while (1)
	{
		// Draw Matrix Function
		Draw();

		// Input user variable to matrix
		InputSingle();
		n++;

		// Checks if the game ended with draw
		if (Win() == '/' && n == 9)
		{
			cout << "It's a draw!" << endl;
			n = 0;
			UpdateMatrix();
		}

		// minmax algorith input 
		findBestMove(matrix);

		n++;

		// Checks if the game ended with win
		if (Win() == 'X')
		{
			cout << "X wins!" << endl;
			n = 0;
			UpdateMatrix();
		}
		else if (Win() == 'O')
		{
			cout << "O wins!" << endl;
			n = 0;
			UpdateMatrix();
		}
		else if (Win() == '/' && n == 9)
		{
			cout << "It's a draw!" << endl;
			n = 0;
			UpdateMatrix();
		}
	}
}


// The Function asks the Client for a value that will be writtenand
// displayed on the matrix and written to the buffer with index 0 which is sent to the Server
void InputConnectClient(char sendbuf[])
{
	int a;
	cout << "Enter number: ";
	cin >> a;

	if (a > 9)
	{
		cout << "Error Field" << endl;
		return InputConnectClient(sendbuf);
	}

	// Catch Error if input is char 
	else if (std::cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		std::cout << "Error number, Enter from 1 to 9" << endl;
		return InputConnectClient(sendbuf);
	}

	if (a == 1)
	{
		if (matrix[0][0] == '1')
			matrix[0][0] = 'X';
		else
		{
			cout << "Field is already in use try again!" << endl;
			return InputConnectClient(sendbuf);
		}
	}

	else if (a == 2)
	{
		if (matrix[0][1] == '2')
			matrix[0][1] = 'X';
		else
		{
			cout << "Field is already in use try again!" << endl;
			return InputConnectClient(sendbuf);
		}
	}

	else if (a == 3)
	{
		if (matrix[0][2] == '3')
			matrix[0][2] = 'X';
		else
		{
			cout << "Field is already in use try again!" << endl;
			return InputConnectClient(sendbuf);
		}
	}
	else if (a == 4)
	{
		if (matrix[1][0] == '4')
			matrix[1][0] = 'X';
		else
		{
			cout << "Field is already in use try again!" << endl;
			return InputConnectClient(sendbuf);
		}
	}
	else if (a == 5)
	{
		if (matrix[1][1] == '5')
			matrix[1][1] = 'X';
		else
		{
			cout << "Field is already in use try again!" << endl;
			return InputConnectClient(sendbuf);
		}
	}
	else if (a == 6)
	{
		if (matrix[1][2] == '6')
			matrix[1][2] = 'X';
		else
		{
			cout << "Field is already in use try again!" << endl;
			return InputConnectClient(sendbuf);
		}
	}
	else if (a == 7)
	{
		if (matrix[2][0] == '7')
			matrix[2][0] = 'X';
		else
		{
			cout << "Field is already in use try again!" << endl;
			return InputConnectClient(sendbuf);
		}
	}
	else if (a == 8)
	{
		if (matrix[2][1] == '8')
			matrix[2][1] = 'X';
		else
		{
			cout << "Field is already in use try again!" << endl;
			return InputConnectClient(sendbuf);
		}
	}
	else if (a == 9)
	{
		if (matrix[2][2] == '9')
			matrix[2][2] = 'X';
		else
		{
			cout << "Field is already in use try again!" << endl;
			return InputConnectClient(sendbuf);
		}
	}


	sendbuf[0] = a;

}

// The function takes 1 element of the buffer received from the Server,
// Which contains the value entered by the Server and applies this value to the matrix
void InputConnectServer(char sendbuf[])
{
	int a = sendbuf[1];
	if (a == 1)
		matrix[0][0] = 'O';
	else if (a == 2)
		matrix[0][1] = 'O';
	else if (a == 3)
		matrix[0][2] = 'O';
	else if (a == 4)
		matrix[1][0] = 'O';
	else if (a == 5)
		matrix[1][1] = 'O';
	else if (a == 6)
		matrix[1][2] = 'O';
	else if (a == 7)
		matrix[2][0] = 'O';
	else if (a == 8)
		matrix[2][1] = 'O';
	else if (a == 9)
		matrix[2][2] = 'O';
	sendbuf[1] = a;
}

// Initialize Cleint Socket whos connection to Server
void ConnectSocket()
{
	// Variable stores data from functions
	long rec;

	// The WSADATA structure contains information about the implementation of Windows sockets
	WSADATA wsaData;

	// Declare an unbound connect socket
	SOCKET sConnect;

	// The sockaddr_in structure describes a socket for dealing with IP protocols.
	sockaddr_in connectinfo;

	// called to start using WS2_32.dll
	// Requests the version 2.2 of Winsock that the caller can use.
	rec = WSAStartup(MAKEWORD(2, 0), &wsaData);

	// Output on display that the step completed successfully
	if (rec == 0)
		cout << "WSASTARTUP sucsessful" << endl;

	// Create a SOCKET for connecting to server
	sConnect = socket(AF_INET, SOCK_STREAM, 0);

	// Output on display that the step completed successfully
	if (sConnect != INVALID_SOCKET)
		cout << "Socket Sucsessful" << endl;

	char ip[16];
	cout << "Enter connect ip (127.0.0.1): " << endl;
	cin >> ip;

	// The sin_addr field contains the IP address to which the socket will be bound.
	connectinfo.sin_addr.s_addr = inet_addr(ip);

	// AF_INET is used to specify the IPv4 address family.
	connectinfo.sin_family = AF_INET;

	unsigned short port = 8080;
	cout << "Enter connect port (8080): " << endl;
	cin >> port;
	// sin_port contains the port number the process intends to occupy
	connectinfo.sin_port = htons(port);

	// The variable 'connectlen' receives data about the size of the structure
	int connectlen = sizeof(connectinfo);

	// Connect to server.
	rec = connect(sConnect, (struct sockaddr*)&connectinfo, connectlen);

	// Output on display that the step completed successfully
	if (rec != SOCKET_ERROR)
		cout << "Connect Sucsessful" << endl;


	//  fill the structure with value 0
	memset(&sendbuf, 0, sizeof(sendbuf));

	// Variable to calculate the tie
	int n = 0;

	// The loop runs before the socket became invalid
	do
	{
		n++;

		// Draw Matrix Function
		Draw();

		// Function to applies value from buffer to the matrix
		InputConnectClient(sendbuf);

		// The function is used to send data from the socket
		rec = send(sConnect, sendbuf, 2, 0);

		// Checks if the game ended in a draw or a win

		if (Win() == 'X')
		{
			cout << "X wins!" << endl;
			n = 0;
			UpdateMatrix();
		}
		if (Win() == 'O')
		{
			cout << "O wins!" << endl;
			n = 0;
			UpdateMatrix();
		}
		if (Win() == '/' && n == 9)
		{
			cout << "It's a draw!" << endl;
			n = 0;
			UpdateMatrix();
		}

		// The function is used to read data from the socket and write it to the buffer
		rec = recv(sConnect, sendbuf, 2, 0);

		// Function to applies value from buffer to the matrix
		InputConnectServer(sendbuf);

		n++;
	} while (rec != SOCKET_ERROR);

	// The closesocket function closes an existing socket.
	closesocket(sConnect);

	// The WSACleanup function terminates use of the Winsock 2 DLL (Ws2_32.dll).
	WSACleanup();
}

int main()
{
	// Declare a variable that user enter
	int UserChoice;
	while (1)
	{
		cout << "Enter GameMode" << endl;
		cout << "1. Singeplayer with AI" << endl;
		cout << "2. Multiplayer (Host)" << endl;
		cout << "3. Multiplayer (Connect)" << endl;
		cout << "4. Exit" << endl;
		cin >> UserChoice;

		// Catch Errors if input variable char 
		cin.clear();
		cin.ignore(100, '\n');

		switch (UserChoice)
		{
		case 1:
		{
			// SinglePlayer Function 
			SinglePlayer();
			break;
		}
		case 2:
		{
			// Create Server Socket Function 
			ServerSocket();
			break;
		}
		case 3:
		{
			// Connect to Server Function 
			ConnectSocket();
			break;
		}
		case 4:
			return 0;
		default: cout << "Error number " << endl;
			break;
		}
	}
}
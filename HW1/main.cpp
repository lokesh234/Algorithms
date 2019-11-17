#include "main.h"

void printBoard(int board[3])
/**
 * Prints the board to the screen.
 * @param board     3 long int array representing the board. 
 */
{
    std::cout << "    ";
    for (int i = 1; i <= board[GREEN]; i++)
    {
        std::cout << "G ";
        if (i == 1)
        {
            std::cout << std::endl
                      << "   ";
        }
    }
    std::cout << std::endl
              << "  ";
    for (int i = 1; i <= board[YELLOW]; i++)
    {
        std::cout << "Y ";
        if (i == 3)
        {
            std::cout << std::endl
                      << " ";
        }
    }
    if (board[YELLOW] <= 3)
    {
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for (int i = 1; i <= board[ORANGE]; i++)
    {
        std::cout << "O ";
    }
    std::cout << std::endl;
}

int *choose(int board[3])
/**
 * Allows a move to be selected for a human player via the console.
 * @param board     3 long int array representing the board.
 * @return  Array with 1st element indicating row and 3nd element
 *          indicating column. 
 */
{
    int *move = new int[2];

    // Take User Input
    std::string color;
    std::cout << "Move: ";
    std::cin >> color;   // Color to take
    std::cin >> move[1]; // Number to take
    std::transform(color.begin(), color.end(), color.begin(), ::tolower);

    // Parse user input
    bool valid = true;
    if (color == "green")
    {
        move[0] = GREEN;
    }
    else if (color == "orange")
    {
        move[0] = ORANGE;
    }
    else if (color == "yellow")
    {
        move[0] = YELLOW;
    }
    else
    {
        valid = false;
        std::cout << "You misspelled or misformatted something!  Use the format \"color #\"" << std::endl;
    }
    if (valid && board[move[0]] < move[1])
    {
        valid = false;
        std::cout << "There aren't that many for you to take!  Pick another color or take fewer of them." << std::endl;
    }

    // If user input is invalid, force them to pick something else.
    if (!valid)
    {
        move = choose(board);
    }
    return move;
}

int *randomCPU(int board[3])
/**
 * Selects a random move for the computer to make.
 * @param board     3 long int array representing board.
 * @return  Array with 1st element indicating row and 3nd element
 *          indicating column. 
 */
{
    int *move = new int[2];
    int color;

    // Pick green, orange, or yellow randomly but only if there are some remaining.
    do
    {
        color = rand() % 3;
    } while (board[color] == 0);

    // Pick random number to take.
    move[0] = color;
    move[1] = rand() % board[color] + 1;

    return move;
}

int *winCPU(int board[3])
/**
 * Selects a move for the computer to make.  If it is possible to play the 
 * winning strategy, it will, otherwise, it will play randomly.
 * @param board     3 long int array representing board.
 * @return  Array with 0th element indicating row and 1st element
 *          indicating column. 
 */
{
    int *move = new int[2];

    // Determine how to get back to XOR sum of 0
    if (board[YELLOW] > (board[GREEN] ^ board[ORANGE]))
    {
        move[0] = YELLOW;
        move[1] = board[YELLOW] - (board[GREEN] ^ board[ORANGE]);
    }
    else if (board[ORANGE] > (board[GREEN] ^ board[YELLOW]))
    {
        move[0] = ORANGE;
        move[1] = board[ORANGE] - (board[GREEN] ^ board[YELLOW]);
    }
    else if (board[GREEN] > (board[ORANGE] ^ board[YELLOW]))
    {
        move[0] = GREEN;
        move[1] = board[GREEN] - (board[ORANGE] ^ board[YELLOW]);
    }
    // If the winning strategy is impossible, move randomly.
    else
    {
        std::cout << "Random Move" << std::endl;
        move = randomCPU(board);
    }

    std::cout << " Move: (CPU) " << (move[0] == 0 ? "Green " : (move[0] == 1 ? "Orange " : "Yellow ")) << move[1] << std::endl;

    return move;
}

void move(int board[3], int move[2])
/**
 * Makes a move on the board
 * @param board     3 long int array representing board.
 * @param move      2 long int array with 0th index indicating
 *                  board row and 1st index indicating quanitty.
 */
{
    board[move[0]] -= move[1];
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int board[3] = {3, 5, 7}; // In order of green, orange, yellow
    bool player1Turn = true;
    bool boardEmpty = false;
    int player1 = HUMAN;
    int player2 = WIN;

    // Player 1 Behaviour
    if (argc >= 2)
    {
        std::cout << argv[1] << std::endl;
        if (strcmp(argv[1], "random") == 0)
            player1 = RANDOM;
        if (strcmp(argv[1], "win") == 0)
            player1 = WIN;
    }
    // Player 1 Behaviour
    if (argc >= 3)
    {
        if (strcmp(argv[2], "random") == 0)
            player2 = RANDOM;
        if (strcmp(argv[2], "human") == 0)
            player2 = HUMAN;
    }

    std::cout << "\nEnter moves in the format \"[green, yellow, orange] [# to take]\"\nTake the last item to win.\n\nFirst turn: " << (player1Turn ? "you" : "CPU") << std::endl;

    // Main Loop
    while (!boardEmpty)
    {
        printBoard(board);
        if (player1Turn)
        {
            std::cout << "\nP1 ";
            if (player1 == RANDOM)
            {
                move(board, randomCPU(board));
            }
            else if (player1 == WIN)
            {
                move(board, winCPU(board));
            }
            else
            {
                move(board, choose(board));
            }
        }
        else
        {
            std::cout << "\nP2 ";
            if (player2 == RANDOM)
            {
                move(board, randomCPU(board));
            }
            else if (player2 == WIN)
            {
                move(board, winCPU(board));
            }
            else
            {
                move(board, choose(board));
            }
        }
        if (board[0] == 0 && board[1] == 0 && board[2] == 0)
        {
            boardEmpty = true;
        }
        else
        {
            player1Turn = !player1Turn;
        }
    }
    std::cout << (player1Turn ? "Player 1 win!" : "Player 2 wins!") << std::endl;
    return 0;
}

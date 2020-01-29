#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
 *  CSC 112: Project 1: Battleship (Part 2)
 *  Name: William Turkett
 *  Date: January 23, 2020
 *  Author: Ethan Cooley
 */

int main() {

    // Initialize variables //

    srand(time(0));  // Seed
    int Guesses = 0; // Guesses counter starts at 0
    int N; // Initialize integer N for board size

    bool Board = false; // Board will be false until a positive NxN is established
    while (!Board) {    // Game will ask for board size again if input is negative

        cout << "Enter N for NxN Board Size: ";
        cin >> N;
        if (N < 1) {
            cout << "Please enter a positive number for board size." << endl;
            cout << endl;
        }
        else {
            Board = true; // Break the loop if board size is positive
        }
    }

    string MapArray[N][N]; // Initialize map array

    // Replace empty spaces in array with " "
    int i;
    int j;
    for (i = 0; i < N; i++) {   // Nested Loop Action
        for (j = 0; j < N; j++) {
            MapArray[i][j] = " ";
        }
    }

    // Randomly generate battleship location
    int ship_row = (rand() % N) + 1;
    int ship_col = (rand() % N) + 1;

    // Game will run as long as battleship is not hit
    bool Sink = false;

    // Main Loop
    while (!Sink) {
        // Display Location options
        cout << "Guess a location (row[1-" << N << "] column[1-" << N << "]): ";

        int row; // Initialize Variables
        int col;
        cin >> row; // User Input
        cin >> col;

        Guesses += 1; // Guess counter increases by 1 each time a user inputs
        // * Even if the input is invalid

        // If input is negative
        if ((row < 1) || (col < 1)) {
            cout << "Invalid Position!" << endl;   // Sanitize input
            cout << endl;
            continue;                                       // Ask again for input
        }

        // If position is invalid
        if ((row > N) || (col > N)) {
            cout << "Invalid Position!" << endl;
            cout << endl;
            continue;
        }

        if (row == ship_row && col == ship_col) {     // If the user hits the battleship
            MapArray[row - 1][col - 1] = "O";         // Location turns to O
        } else if ((row <= N) && (col <= N)) {        // If user does not hit battleship
            MapArray[row - 1][col - 1] = "X";         // And position is valid, location turns to X
        }

        // Display Map
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (j == N-1) {
                    cout << MapArray[i][j] << endl;
                }
                else {
                    cout << MapArray[i][j] << "!";
                }
            }
        }
        cout << " " << endl;

        // If the user hits the battleship
        if (MapArray[row - 1][col - 1] == "O") {
            cout << "You sunk my battleship! (" << Guesses << " guesses)" << endl;
            Sink = true;
        }
    }
    return 0;
}
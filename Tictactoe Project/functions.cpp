#include "functions.h"




std::array<std::array<char, 3>, 3> matrix() {
    std::array<std::array<char, 3>, 3> matrix = {{
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    }};
    return matrix;
}


void board(std::array<std::array<char, 3>, 3> data) {
	std::cout << " -------------\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << " | " << data[i][j];
		}
		std::cout << " |\n";
		if (i == 2)
			std::cout << " -------------\n";
		else
			std::cout << " |---|---|---|\n";
	}
}


std::array<int, 2> userInput(std::array<std::array<char, 3>, 3> data, char c) {
	int x, y;
	while (true) {
		std::cout << "Enter Row <space> Column: ";
        std::cin >> x >> y;
        if (x >= 0 && x < 3 && y >= 0 && y < 3) {
        	if (data[x][y] == ' ') {
	            return {x, y};
	        }
	        else 
	        	std::cout << "This Position is already Filled! Choose Another\n";
        }
        else 
            std::cout << "Invalid Input. Please Enter Values Between 0 and 2 for Both Row and Column\n";
    }
}


void updateBoard(std::array<std::array<char, 3>, 3>& data, char c, std::array<int, 2> input) {
	data[input[0]][input[1]] = c;
}


bool winner(std::array<std::array<char, 3>, 3> data, std::array<int, 2> input, char c) {
    if (data[input[0]][0] == c && data[input[0]][1] == c && data[input[0]][2] == c) {
        return true;
    }
    if (data[0][input[1]] == c && data[1][input[1]] == c && data[2][input[1]] == c) {
        return true;
    }
    if (input[0] == input[1] && data[0][0] == c && data[1][1] == c && data[2][2] == c) {
        return true;
    }
    if (input[0] + input[1] == 2 && data[0][2] == c && data[1][1] == c && data[2][0] == c) {
        return true;
    }

    return false;
}


void game(std::array<std::array<char, 3>, 3> data, char c, bool has_won) {
	for (int i = 0; i < 9; i++) {
		board(data);
		if (i % 2 == 0) {
			std::cout << "It's Player (X)'s Turn\n";
			c = 'X';
		}
		else {
			std::cout << "It's Player (O)'s Turn\n";
			c = 'O';
		}
		auto input = userInput(data, c);
		updateBoard(data, c, input);
		has_won = winner(data, input, c);
		if (has_won) {
			std::cout << "\n\t\tPlayer " << c << " Wins!\n\n";
			break;
		}
	}
	if (!has_won)
		std::cout << "\n\t\tIt's a Draw!\n\n";
	board(data);
}

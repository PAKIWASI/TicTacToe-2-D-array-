#include <iostream>
#include <array>



std::array<std::array<char, 3>, 3> matrix();

void board(std::array<std::array<char, 3>, 3> data);

std::array<int, 2> userInput(std::array<std::array<char, 3>, 3> data, char c);

void updateBoard(std::array<std::array<char, 3>, 3>& data, char c, std::array<int, 2> input);

bool winner(std::array<std::array<char, 3>, 3> data, std::array<int, 2> input, char c);

void game(std::array<std::array<char, 3>, 3> data, char c, bool has_won);
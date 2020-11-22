//cpp
#include "tic_tac_toe.h"
#include "tic_tac_toe_data.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

#include <vector>
#include <memory>
#include <fstream>

void TicTacToeData::save_games(const std::vector<std::unique_ptr<TicTacToe>>& games)
{
    // open file for writing
    std::ofstream game_data;
    game_data.open("game_data.txt");

    for(auto& game : games)
    {
        for (auto& slot : game->get_slots())
        {
            game_data << slot;
        }
        game_data << game->get_winner() << "\n";
    }
}

std::vector<std::unique_ptr<TicTacToe>> TicTacToeData::get_games()
{
	// Create a string line
    std::string line;
    // Open File
	std::ifstream game_data("game_data.txt");
    // Create vector<string> pegs
	std::vector<string> slots;

	// Create vector unique ptr of TicTacToe boards
    std::vector<std::unique_ptr<TicTacToe>> games;

	if (game_data.is_open())
	{
		while (getline(game_data, line))
		{
			slots.clear();
			for (std::size_t i = 0; i < line.length() - 1; i++)
			{
				slots.push_back(string(1, line.at(i)));
			}
			std::unique_ptr<TicTacToe> game;

			// if vector of string size 9 create board of TicTacToe3 using make_unique
            if (slots.size() == 9)
			{
				game = std::make_unique<TicTacToe3>(slots, string(1, line.at(line.length() - 1)));
			}
			// else if size 16 create board of TicTacToe4 using make_unique
            else if (slots.size() == 16)
			{
				game = std::make_unique<TicTacToe4>(slots, string(1, line.at(line.length() - 1)));
			}
			else
			{
				continue;
			}
            // add the board to the boards vector
			games.push_back(std::move(game));
		}
	}
    // close the file
	game_data.close();

	// return the boards vector
    return games;
}
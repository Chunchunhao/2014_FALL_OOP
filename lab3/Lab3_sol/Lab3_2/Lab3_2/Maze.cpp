#include "Maze.h"

#include <fstream>
#include <iostream>

using namespace std;

Maze::Maze(const std::string& file_name)
{
	std::ifstream inf(file_name.c_str());	

	inf >> n_y >> n_x;

	string tmp_row;

	// remove  dummy line
	getline(inf, tmp_row);

	while (getline(inf, tmp_row))
	{
		maze_data.push_back(tmp_row);
	}
}

const vector< vector< unsigned > >& Maze::find()
{ 
	char current_block = 'S';
	start(current_x, current_y);
	bool marched = false;
	Direction ahead = S;

	

	while (current_block != 'F')
	{
		marched = false;
		vector<Direction> use_sequence = get_sequence(ahead);	
	
		for (vector<Direction>::size_type index = 0; index != use_sequence.size() && marched != true; ++index)
		{
			Direction direction = use_sequence[index];
			if (is_a_way(static_cast<Direction>(direction)))
			{
				//update
				ahead = direction;
				move(static_cast<Direction>(direction));
				current_block = maze_data[current_y][current_x];
				maze_data[current_y][current_x] = 'O';
				path.push_back({ current_x, current_y });
				marched = true;
			}
		}

		//printLayout(cout, *this);
		//printPath(cout, path);
	}

	maze_data[current_y][current_x] = 'F';

	return path; 
}

vector<Direction> Maze::get_sequence(Direction ahead)
{
	vector<Direction> to_s = { W, S, E, N };
	vector<Direction> to_n = { E, N, W, S };
	vector<Direction> to_w = { N, W, S, E };
	vector<Direction> to_e = { S, E, N, W };
	switch (ahead)
	{
	case S:
		return to_s;
		break;
	case N:
		return to_n;
		break;
	case W:
		return to_w;
		break;
	case E:
		return to_e;
		break;
	}

	return to_s;

}

void Maze::start(unsigned& x, unsigned& y)
{
	bool found = false;
	for (vector< vector< int > >::size_type index = 0; index != maze_data.size() && found != true; ++index)
	{
		const auto found_pos = maze_data[index].find_first_of('S');
		if (found_pos != string::npos)
		{
			x = found_pos;
			y = index;
			found = true;
		}
	}
}

bool Maze::check_way(const char block)
{
	if (block == ' ' || block == 'O')
		return true;
	else
		return false;
}

bool Maze::is_a_way(Direction d)
{
	char pos;
	switch (d)
	{
	case E:
		if (current_x < n_x - 1)
		{
			pos = maze_data[current_y][current_x + 1];
			if (pos == ' ' || pos == 'O' || pos == 'F')
			{
				return true;
			}
			else 
				return false;
		}
		else
			return false;
		break;
	case S:
		if (current_y < n_y - 1)
		{
			pos = maze_data[current_y + 1][current_x];
			if (pos == ' ' || pos == 'O' || pos == 'F')
			{
				return true;
			}
			else
				return false;
		}
		else
			return false;
		break;
	case W:
		if (current_x > 0)
		{
			pos = maze_data[current_y][current_x - 1];
			if (pos == ' ' || pos == 'O' || pos == 'F')
			{
				return true;
			}
			else
				return false;
		}
		else
			return false;
		break;
	case N:
		if (current_y > 0)
		{
			pos = maze_data[current_y - 1][current_x];
			if (pos == ' ' || pos == 'O' || pos == 'F')
			{
				return true;
			}
			else
				return false;
		}
		else
			return false;
		break;
	case Stay:
		return false;
		break;
	}

	return false;
}

void Maze::move(Direction d)
{
	switch (d)
	{
	case E:
		++current_x;
		break;
	case S:
		++current_y;
		break;
	case W:
		--current_x;
		break;
	case N:
		--current_y;
		break;
	}
}

std::ostream& printLayout(std::ostream& ostr, const Maze& input_maze)
{
	for (unsigned y = 0; y != input_maze.ny(); ++y)
	{
		for (unsigned x = 0; x != input_maze.nx(); ++x)
		{
			ostr << input_maze.maze_data[y][x] ;
		}
		ostr << std::endl;
	}
	ostr << std::endl;

	return ostr;
}

std::ostream& printPath(std::ostream& ostr, const vector< vector< unsigned > >& input_maze)
{
	for (const auto& coord : input_maze)
	{
		ostr << "(" << coord[0] << ", " << coord[1] << ")" << endl;
	}

	return ostr;
}
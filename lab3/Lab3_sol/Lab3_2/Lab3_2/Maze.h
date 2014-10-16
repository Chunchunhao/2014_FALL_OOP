#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <vector>

typedef std::string MazeArray;
typedef std::vector< MazeArray > MazeData;

enum Direction{E = 0, S = 1, W = 2, N = 3, Stay = 4};

struct Maze
{
	Maze(const std::string& file_name);

	const unsigned& nx() const{ return n_x; }
	const unsigned& ny() const{ return n_y; }

	const std::vector< std::vector< unsigned > >& find();

	void start(unsigned& x, unsigned& y);

	bool is_a_way(Direction d);

	void move(Direction d);

	bool check_way(const char block);

	std::vector<Direction> get_sequence(Direction ahead);

	MazeData maze_data;

	std::vector< std::vector< unsigned > > path;

	std::size_t n_x;
	std::size_t n_y;

	unsigned current_x, current_y;
};

std::ostream& printLayout(std::ostream& ostr, const Maze& input_maze);
std::ostream& printPath(std::ostream& ostr, const std::vector< std::vector< unsigned > >& input_maze);

#endif // MAZE_H
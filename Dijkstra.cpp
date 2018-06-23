#include <iostream>
#include <string>
#include <vector>


int main()
{
	//initializes the matrix representation of the graph
	int array[20][20] = {
		{ 0, 1, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 0, 2, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 2, 0, 3, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 1, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 34 },
		{ 1, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0 },
		{ 3, 5, 0, 0, 0, 0, 4, 0, 18, 0, 0, 0, 30, 7, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 20, 0, 0, 0, 0, 18, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 10, 0, 0, 0, 2, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 1, 0, 7 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 12, 0, 8, 0, 0, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 8, 0, 0, 0, 0, 0, 5, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 11, 7, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 1, 0, 29, 0, 21, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 29, 0, 1, 3, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 5, 0, 21, 3, 1, 0, 4, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 5 },
		{ 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 5, 0 }
	};
	//The array keeps track of which nodes we visited (visited[n][0] is 1 when visited and 0 when not) 
	//their cost (visited[n][1] = cost) and the previous node (visited[n][2] = prev_node)
	int visited[20][3] = { 0 };
	bool finished = false;
	bool no_input = true;
	std::string start;
	std::string stop;
	int start_int = 0;
	int stop_int = 0;
	//Get the correct user input
	while (no_input) {
		std::cout << "Please specify a start point from A - T (enter in caps): ";
		std::cin >> start;
		std::cout << "Please specify a stop point from A - T (enter in caps): ";
		std::cin >> stop;
		start_int = (int)start.at(0) - 65;
		stop_int = (int)stop.at(0) - 65;
		if (start_int > 19 || start_int < 0 || stop_int > 19 || stop_int < 0) {
			std::cout << "Your input was not correct\n";
		}
		else {
			no_input = false;
		}
	}
	visited[start_int][0] = 1;
	visited[start_int][1] = 0;

	//while not all vertices are visited
	while (!finished) {
		int smallest_index = 0;
		int smallest_value = 0;
		int previous_node = 0;
		//for all visited vertices
		for (int i = 0; i < 20; ++i) {
			if (visited[i][0] == 1) {
				//all reachable vertices get minimal sum of values of edges to reach them
				for (int c = 0; c < 20; ++c) {
					//if the node is marked as unvisited
					if (visited[c][0] == 0) {
						if (array[i][c] != 0) {
							visited[c][1] = visited[i][1] + array[i][c];
							//Mark edge to vertex with smallest value
							if (smallest_value == 0 || array[i][c] + visited[i][1] < smallest_value) {
								smallest_index = c;
								smallest_value = array[i][c] + visited[i][1];
								previous_node = i;
							}
						}
					}
				}
			}
		}
		//Mark this vertex as visited
		visited[smallest_index][0] = 1;
		visited[smallest_index][1] = smallest_value;
		visited[smallest_index][2] = previous_node;
		finished = true;
		for (int i = 0; i < 20; ++i) {
			if (visited[i][0] != 1) {
				finished = false;
				break;
			}
		}
	}
	
	std::cout << "The cost to go from: " << start << " to " << stop << " is " << visited[stop_int][1] << "\n";
	//creates a vector and adds the steps of the shortest path from the start to the stop
	finished = false;
	int current_index = stop_int;
	std::vector<int> way;
	while (!finished) {
		if (visited[current_index][2] != 0) {
			way.push_back(visited[current_index][2]);
			current_index = visited[current_index][2];
		}
		else {
			way.push_back(start_int);
			finished = true;
		}
	}
	//prints the way from start to stop to the console
	while(way.size() > 0) {
		char start = way.back() + 65;
		way.pop_back();
		char step = 0;
		if (way.size() == 0) {
			step = stop_int + 65;
		} else {
			step = way.back() + 65;
		}
		std::cout << start << " - " << step << "\n";
	}
	//prevents the program from closing automatically when started with visual studio
	std::cin.get();
	std::cin.get();
	return 0;
}

#include <iostream>
#include <fstream>
#include <string>



int main()
{
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
	int visited[20][2] = { 0 };
	bool finished = false;
	visited[0][0] = 1;
	visited[0][1] = 0;

	//while not all vertices are visited
	while (!finished) {
		int smallest_index = 0;
		int smallest_value = 0;
		//for all visited vertices
		for (int i = 0; i < 20; ++i) {
	
			if (visited[i][0] == 1) {
				//all reachable vertices get minimal sum of values of edges to reach them
				for (int c = 0; c < 20; ++c) {
					if (visited[c][0] == 0 && visited[c][1] != 0 && (visited[c][1] < smallest_value || smallest_value == 0)) {
						smallest_value = visited[c][1];
						smallest_index = c;
					}
					if (array[i][c] != 0 && visited[c][0] == 0) {
						visited[c][1] = visited[i][1] + array[i][c];
						//Mark edge to vertex with smallest value
						if (smallest_value == 0 || array[i][c] < smallest_value) {
							smallest_index = c;
							smallest_value = array[i][c] + visited[i][1];
						}
					}
				}
			}
		}
		//Mark this vertex as visited
		visited[smallest_index][0] = 1;
		visited[smallest_index][1] = smallest_value;
		//TODO not completely working yet...
		finished = true;
		for (int i = 0; i < 20; ++i) {
			if (visited[i][0] != 1) {
				finished = false;
			}
		}
	}
	std::cout << "Hello CMake." << std::endl;
	return 0;
}

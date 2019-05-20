#include "header.h"

void nearestNeighbour(AdjMatrix matrix, CoordList list) {
	
	int start = rand() % matrix.size();
	int current = start;
	int next_town = 0;
	int town_check = 0;
	double min_path = INT8_MAX;
	double dist = 0;
	vector<int> path;
	for (int i = 0; i < matrix.size(); i++) {
		path.push_back(1);
	}
	path[start] = 0;
	cout << endl << "Path: (" << list[start].first << "|" << list[start].second <<") - ";


	for (int i = 0; i < matrix.size()-1; i++) {
		
		for (town_check = 0; town_check < path.size(); town_check++) {
			if (path[town_check] == 1 && min_path > matrix[current][town_check]) {
				min_path = matrix[current][town_check];
				next_town = town_check;
			}
		}
		cout << "(" << list[next_town].first << "|" << list[next_town].second << ") - ";
		dist += min_path;
		current = next_town;
		path[next_town] = 0;
		min_path = INT8_MAX;
	}
	dist += matrix[current][start];
	cout << "(" << list[start].first << "|" << list[start].second << ")" << endl;
	cout << "Total Distance: " << dist << endl;
}
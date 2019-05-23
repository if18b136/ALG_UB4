#include "header.h"


using namespace std;
int factorial(int n) {
	if (n > 1) {
		return n * factorial(n - 1);
	}
	else {
		return 1;
	}
}

void enumeration(AdjMatrix matrix, CoordList List) {

	vector<int> vertex;
	vector<int> best_path;
	double min_path = INT8_MAX;
	double dist = 0;
	int pathC = factorial(matrix.size() - 1);
	for (int i = 0; i < matrix.size(); i++) {
		vertex.push_back(i);
	}
	vertex.push_back(0);
	for (int k = 0; k < pathC; k++) {

		for (int i = 0; i < matrix.size(); i++) {

			dist += matrix[vertex[i]][vertex[i + 1]];
		}
		min_path = min(min_path, dist);

		if (min_path == dist) {
			
			best_path = vertex;
		}
		dist = 0;
		next_permutation(vertex.begin() + 1, vertex.end() - 1);
	}
	
	cout << endl << "Path: ";
	for (int j = 0; j < best_path.size() - 1; j++) {
		cout << "(" << List[best_path[j]].first << "|" << List[best_path[j]].second << ") - ";
	}
	cout << "(" << List[best_path[0]].first << "|" << List[best_path[0]].second << ")" << endl;
	cout << "Total Distance: " << min_path << endl;

	
}

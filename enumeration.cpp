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
	double min_path = INT_MAX;
	double dist = 0;
	int pathC = factorial(matrix.size() - 1) / 2;
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
			cout << "new min dist: " << dist << endl;
			cout << "new best path: ";
			for (int j = 0; j < vertex.size(); j++) {
				cout << " - " << vertex[j];
			}
			cout << endl << endl << endl;
			best_path = vertex;
		}
		dist = 0;
		next_permutation(vertex.begin() + 1, vertex.end() - 1);
	}


	
}
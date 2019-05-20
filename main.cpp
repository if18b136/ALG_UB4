#include "header.h"
//#include <unistd.h>


using namespace std;

int main(int argc, char* argv[]) {
	srand(time(0));
	char c = 0;
	int mode = 0, lineC = 0, lineI = 0;
	double aa = 0, bb = 0;
	char line[1024]; // 1024 ist statisch
	auto start = chrono::steady_clock::now();
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	string filename;
	CoordList jimmy;	// jimmy gotta dig big.

	while ((c = getopt(argc, argv, "en")) != -1) {

		filename = (string)argv[2];
		switch (c) {
		case 'e':
			mode = 1;

			break;
		case 'n':
			mode = 2;

			break;
		default:
			assert(0);
		}
	}
	cout << "test" << endl;
	ifstream file(filename);

	while (file) {
		file.getline(line, 255);
		istringstream lineS(line);
		if (lineC == 0) {
			lineS >> lineC;
		}
		else if (lineI < lineC) {
			lineS >> aa >> bb;
			pair<double, double> coord;
			coord = make_pair(aa, bb);
			jimmy.push_back(coord);
			//cout << jimmy[lineI].first << " / " << jimmy[lineI].second << endl;
			lineI++;
			if (lineI == lineC) {
				break;
			}
		}
	}

	AdjMatrix field(lineC, vector<double>(lineC, 0));

	for (int col = 0; col < lineC; col++) {
		for (int row = 0; row < lineC; row++) {
			double dist = sqrt(pow((jimmy[col].first - jimmy[row].first), 2) + pow((jimmy[col].second - jimmy[row].second), 2));

			field[col][row] = dist;	
		}
	}
	switch (mode) {
	case 1:
		start = chrono::steady_clock::now();
		enumeration(field, jimmy);
		end = chrono::steady_clock::now();
		diff = end - start;
		cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
		break;
	case 2:
		start = chrono::steady_clock::now();
		nearestNeighbour(field, jimmy);
		end = chrono::steady_clock::now();
		diff = end - start;
		cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
		break;
	}
	return 0;
}
#include "header.h"
//#include <unistd.h>


using namespace std;

int main(/*int argc, char* argv[]*/) {
	typedef vector<pair<double, double> > CoordList;
	typedef vector <vector<double> > AdjMatrix;

	char c = 0;
	int mode = 0, lineC = 0, lineI = 0;
	double aa = 0, bb = 0;
	char line[1024]; // 1024 ist statisch
	
	string filename;
	char* argv[3] = { nullptr, nullptr, nullptr }; // substitude
	CoordList jimmy;	// jimmy gotta dig big.

	while (/*(c = getopt(argc, argv, "e:n:")) != -1*/ argv[2] == nullptr) {
		cout << "modus: ";
		cin >> c;
		cout << ": ";
		cin >> filename;
		argv[2] = (char*)filename[0];
		switch (c) {
		case 'e':
			mode = 1;
			break;
		case 'n':
			mode = 2;
			break;
		}
	}
	ifstream file(filename);

	while (file) {
		file.getline(line, 255);
		//cout << line << endl;
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
			cout << dist << endl;
		}
		cout << endl;
	}
		//for i
			//for j
				//field[i][j].push_back(dist);

	/*
	int a = 1.0, b = 2.0;
	double e = 4.5, d = 1.7;
	
	pair<pair<double, double>, double> trupel;
	trupel = make_pair(coord, 3.5);

	
		//vector <vector <pair<pair<double,double>, double> > > franklin;
		AdjMatrix franklin(5, vector<pair<pair<double, double>, double>>(5, trupel));
		
		pair<pair<double, double>, double> trupel2 = make_pair(make_pair(b,e), d);
		franklin[a][b] = trupel2;
		*/
	return 0;
}

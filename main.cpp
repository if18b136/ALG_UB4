#include "header.h"
//#include <unistd.h>


using namespace std;

int main(/*int argc, char* argv[]*/) {
	char c = 0;
	int mode = 0;
	
	char filename[] = "";
	char* argv[3] = { nullptr, nullptr, nullptr };

	while (/*(c = getopt(argc, argv, "e:n:")) != -1*/ argv[2] == nullptr) {
		cout << "modus: ";
		cin >> c;
		cout << ": ";
		cin >> filename;
		argv[2] = filename;
		switch (c) {
		case 'e':
			mode = 1;
			break;
		case 'n':
			mode = 2;
			break;
		}
	}
	int a = 1.0, b = 2.0;
	double e = 4.5, d = 1.7;
	pair<double, double> coord;
	coord = make_pair(a, b);
	pair<pair<double, double>, double> trupel;
	trupel = make_pair(coord, 3.5);

	typedef vector < vector<pair<pair<double,double>, double>> > AdjMatrix;
		//vector <vector <pair<pair<double,double>, double> > > franklin;
		AdjMatrix franklin(5, vector<pair<pair<double, double>, double>>(5, trupel));
		
		pair<pair<double, double>, double> trupel2 = make_pair(make_pair(b,e), d);
		franklin[a][b] = trupel2;
	return 0;
}

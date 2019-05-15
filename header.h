#pragma once
#include <utility>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

typedef vector<pair<double, double> > CoordList;
typedef vector <vector<double> > AdjMatrix;


void enumeration(int size, AdjMatrix matrix, CoordList list);
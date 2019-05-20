#pragma once
#include <utility>
#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <cstdint>
#include <limits>
#include <unistd.h>
#include <assert.h>


using namespace std;

typedef vector<pair<double, double> > CoordList;
typedef vector <vector<double> > AdjMatrix;




void enumeration(AdjMatrix matrix, CoordList list);

void nearestNeighbour(AdjMatrix matrix, CoordList list);
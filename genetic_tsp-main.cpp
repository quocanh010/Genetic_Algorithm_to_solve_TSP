#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Point.hh"
#include "tsp-ga.hh"

using namespace std;

int main(int argc, char **argv)
{
	int num_P;
	double x, y, z;
	int population = (int)atoi(argv[1]); 
	int generations = (int)atoi(argv[2]); 
	int keep = (int)((float)atof(argv[3]) * population) ;
	int mutate = (int)(((float)atof(argv[4])) * population);
	vector<int> order;
	vector<Point> points;


	printf("How many points?");
	
	cin >> num_P;
	for (int i = 0; i < num_P; i++)
	{
		
		cout << "Point " << i << ": ";
		cin >> x >> y >> z;
		points.push_back(Point(x, y, z));
	}
	TSPGenome myGenome(num_P);
	myGenome = findAShortPath(points, population, generations, keep, mutate);
	
	


	cout << "Best order: [";
	for (int i = 0; i < myGenome.getOrder().size(); i++)
	{	
		cout << myGenome.getOrder()[i] << " ";
	}
	
	cout << "]\n Shotest distance:" << myGenome.getCircuitlenght() << "\n";

	return 0;
}



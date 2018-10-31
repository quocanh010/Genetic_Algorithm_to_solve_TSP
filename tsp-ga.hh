
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class TSPGenome
{
	private:
		vector<int> order;
		double circuit_length;
	public:
		//CONSTRUCTORS

		//Default constructor
		TSPGenome() : order(0), circuit_length(0) {};
		TSPGenome(int numPoints);
		TSPGenome(const vector<int> &order);

		//MEMBER FUNCTIONS 
		vector<int> getOrder() const;
		void computeCircuitLength(const vector<Point> &points);
		double getCircuitlenght() const;
		void mutate();
		void setOrder(const vector<int> norder);

		//DESTRUCTOR
		~TSPGenome();



};

// None member functions
TSPGenome crosslink(const TSPGenome &g1, const TSPGenome &g2);

TSPGenome findAShortPath(const vector<Point> &points,
	int populationSize, int numGenerations,
	int keepPopulation, int numMutations);
#include "Point.hh"
#include "math.h"
#include "tsp-ga.hh"
#include <vector>
#include <cstdlib>
#include <set>
bool isShorterPath(const TSPGenome &g1, const TSPGenome &g2);

TSPGenome::TSPGenome(int numPoints)
{
	vector<int> temp;
	for (int i = 0; i < numPoints; i++)
	{
		temp.push_back(i);
	}
	random_shuffle(temp.begin(), temp.end());
	circuit_length = -1;
	order = temp;
}

TSPGenome::TSPGenome(const vector<int> &order)
{
	this->order = order;
	circuit_length = -1;
}

vector<int> TSPGenome::getOrder() const
{
	return order;
	
}

void TSPGenome::computeCircuitLength(const vector<Point> &points)
{
	circuit_length = 0;
	for (int i = 0; i + 1 < order.size() ; i++)
	{
		circuit_length = circuit_length + points[order[i]].Distance(points[order[i + 1]]);
	}
	circuit_length = circuit_length + points[order[0]].Distance(points[order[order.size() - 1]]);
}

double TSPGenome::getCircuitlenght() const
{
	return circuit_length;
}

TSPGenome::~TSPGenome() {}

void TSPGenome::setOrder(const vector<int> norder)
{
	order = norder;
}

//Mutate
void TSPGenome::mutate()
{
	int index1, index2, temp;
	index1 = rand() % order.size();
	do 
	{
		index2 = rand() % order.size();
	} while (index1 == index2);
	temp = order[index1];
	order[index1] = order[index2];
	order[index2] = temp;
}

//Crosslink
TSPGenome crosslink(const TSPGenome &g1, const TSPGenome &g2)
{
	vector<int> osOrder;
	set<int> hashTrack;
	// Create a random index in range [2, .. , Genomesize - 2]
	int rand_i = (rand() % (g1.getOrder().size() - 3)) + 2;
	for (int j = 0; j < rand_i; j++) 
		{
			osOrder.push_back(g1.getOrder()[j]);
			hashTrack.insert(g1.getOrder()[j]);
			
		}
	for (int i = 0; i < g2.getOrder().size(); i++)
	{
			
				if (!hashTrack.count(g2.getOrder()[i]))
				{
					osOrder.push_back(g2.getOrder()[i]);		
				}
			
		
	}
	TSPGenome newGenome(osOrder);
	return newGenome;
}

bool isShorterPath(const TSPGenome &g1, const TSPGenome &g2)
{
	if (g1.getCircuitlenght() < g2.getCircuitlenght()) return true;
	return false;
}

TSPGenome findAShortPath(const vector<Point> &points,
	int populationSize, int numGenerations,
	int keepPopulation, int numMutations)
{
	int g1, g2, j;
	vector<TSPGenome> population;

	for (int i = 0; i < populationSize; i++)
	{
		TSPGenome tempGenome(points.size());
		population.push_back(tempGenome);
	}

		


	for ( j = 0; j < numGenerations; j++)
	{

		for (TSPGenome& tempGenome : 	population)
		{
			//int hardArr[12] = { 1, 11, 10, 9, 0, 5, 7, 3, 8, 2, 6, 4 };
			//vector<int> hardOrder(hardArr, hardArr + sizeof(hardArr) / sizeof(hardArr[0]));
			//population[0].setOrder(hardOrder);
			tempGenome.computeCircuitLength(points);
			 
		}
		
		sort(population.begin(), population.end(), isShorterPath);
		// gen is the generation #; it starts at 0
		// population is the vector of TSP genomes
		cout << "\n";
		if (j % 10 == 0) {
			cout << "Generation " << j << ":  shortest path is " << population[0].getCircuitlenght() << endl;
		}
		//cout << keepPopulation  << endl;
		//cout << populationSize << endl;
		// Cross link
		for (int i = keepPopulation; i < populationSize; i++)
		{
			//cout << keepPopulation << "/n";
			//cout << populationSize << "/n";

			g1 = rand() % keepPopulation;
			do
			{
				g2 = rand() % keepPopulation;
			} while (g1 == g2);
			population[i] = crosslink(population[g1], population[g2]);
		}
		//Mutation
		for (int i = 0; i < numMutations; i++)
		{
			int index = 1 + rand() % (populationSize - 1);
			population[index].mutate();
		}
	}
	return population[0];

}
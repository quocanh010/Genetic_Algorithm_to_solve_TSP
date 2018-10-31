#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Point.hh"
using namespace std;
//template< class BidirIt >
//bool next_permutation( BidirIt first, BidirIt last );
double circuitLength(const vector<Point> &points, const vector<int> &order);
vector<int> findShortestPath(const vector<Point> &points);

int main()
{
  int num_P;
  double x,y,z;
  double shortest_dis = 0;

  vector<int> order;
  vector<Point> points;
  printf("How many points?");
  //scanf("%d",&num_P);
  cin >> num_P;
  for(int i = 0; i < num_P; i++)
  {
    //printf("Point %d:", i);
    cout << "Point " << i <<": ";
    //scanf("%lf %lf %lf",&x,&y,&z);
    cin >> x >> y >> z;
    points.push_back(Point(x,y,z));
  }
  order =  findShortestPath(points);
  shortest_dis = circuitLength(points,order);
  cout << "Best order: [";
  for(int i = 0; i < order.size(); i++)
  {
  //  printf("%d ", order[i]);
  cout << order[i]<< " ";

  }
  //printf("]\n Shotest distance: %lf\n", shortest_dis);
  cout << "]\n Shotest distance:" << shortest_dis << "\n";



  return 0;
}

double circuitLength(const vector<Point> &points,const vector<int> &order)
{
  double dis = 0;
  for(int i = 0; i+1 < order.size(); i++)
  {
    dis = dis + points[order[i]].Distance(points[order[i+1]]);
  }
  //printf("Dis forward = %lf", dis);
  dis = dis + points[order[0]].Distance(points[order[order.size()-1]]);
  //printf("Dis backward = %lf", dis);
  return dis;
}


vector<int> findShortestPath(const vector<Point> &points)
{
  double shortest_dis = 0,temp = 0;
  vector <int> order;
  vector <int> best_path;
  for(int i = 0; i < points.size(); i++)
  {
    order.push_back(i);
    best_path.push_back(i);
  }
   shortest_dis = circuitLength(points,order);
while( next_permutation(begin(order),end(order)))
{
  if (shortest_dis > (temp = circuitLength(points, order)) )
  {
    shortest_dis = temp;
    for(int i = 0; i < points.size(); i++)
    {
      //order.pushback(i);
      best_path[i] = order[i];
    }
  }
}


  return best_path;
}

// bool next_permutation(BidirIt first, BidirIt last)
// {
//     if (first == last) return false;
//     BidirIt i = last;
//     if (first == --i) return false;
//
//     while (true) {
//         BidirIt i1, i2;
//
//         i1 = i;
//         if (*--i < *i1) {
//             i2 = last;
//             while (!(*i < *--i2))
//                 ;
//             std::iter_swap(i, i2);
//             std::reverse(i1, last);
//             return true;
//         }
//         if (i == first) {
//             std::reverse(first, last);
//             return false;
//         }
//     }
// }

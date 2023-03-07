#include <iostream>
#include <vector>       
#include <list>
#include <unordered_set>
#include <iterator>    // back_inserter
#include <algorithm>   // transform
#include <numeric>     // accumulate

#include "HigherOrderFunctions.h"

using namespace std;

const int s = 5;

const int one_to_three[] = {1, 2, 3};
const int four_to_five[] = {4, 5, 6};
const int unordered_one_to_five[] = {2, 2, 3, 4, 3, 5, 1, 1, 5};
const int size_of_uo = sizeof(unordered_one_to_five) / sizeof(int);

int double_int(int x)
{
  return x * 2;
}  

void twice(int* xs, int size)
{
  transform(xs, xs + size,
            xs,
            [](auto x) { return x * 2; });
}

void twice_vector0(vector<int> xs, vector<int> &ys)
{
  auto i = xs.begin();
  auto j = ys.begin();
  for (; i != xs.end(); i++, j++)
  {
    *j = *i * 2;
  }
}  

void twice_vector(vector<int> xs, vector<int> &ys)
{
  transform(xs.begin(), xs.end(),
            ys.begin(),
            [](auto x) { return x * 2; });
}

int sum_set0(unordered_set<int> s)
{
  int res = 0;
  for (auto i : s)
  {
    res += i;
  }
  return res;
}


int sum_set(unordered_set<int> s)
{
  return accumulate(s.begin(), s.end(), 0, [](auto x, auto y) { return x + y; });
}

int scalar_product0(list<int> xs, list<int> ys)
{
  auto i = xs.begin();
  auto j = ys.begin();
  list<int> zs;
  for (; i != xs.end() && j != ys.end(); i++, j++)
  {
    zs.push_back((*i) * (*j));
  }
  int res = 0;
  for (auto k : zs)
  {
    res += k;
  }
  return res;
}

int scalar_product(list<int> xs, list<int> ys)
{
  list<int> zs;
  transform(xs.begin(), xs.end(),
            ys.begin(), back_inserter(zs),
            [](auto x, auto y){ return x * y; });
  return accumulate(zs.begin(), zs.end(),
                    0, [](auto x, auto y) { return x + y; });
}

int main()
{
  // Map on arrays
  int xs[s] = {1, 2, 3, 4, 5};
  twice(xs, s);
  for (int i = 0; i < s; i++)
  {
    cout << xs[i] << " ";
  }
  cout << "\n";

  // Map on vectors
  vector<int> ys(xs, xs+s);
  vector<int> zs(s);
  twice_vector0(ys, zs);          
  for (auto i : zs)
  {
    cout << i << " ";
  }
  cout << "\n";
  // use the same vector for input and output
  twice_vector(ys, ys);
  for (auto i : ys)
  {
    cout << i << " ";
  }
  cout << "\n";

  // Fold on sets
  unordered_set<int> s(unordered_one_to_five, unordered_one_to_five + size_of_uo);
  cout << sum_set0(s) << "\n";
  cout << sum_set(s) << "\n";

  // ZipWith and Fold on lists
  list<int> as(one_to_three, one_to_three + 3);
  list<int> bs(four_to_five, four_to_five + 3);
  cout << scalar_product0(as, bs) << "\n";
  cout << scalar_product(as, bs) << "\n";
          
  return 0;          
}

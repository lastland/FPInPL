#include <iostream>

using namespace std;

#include "List.h"

int main()
{
  List<int> xs(1);
  cout << xs.head() << "\n";
  List<int>* ys = cons(2, &xs);
  cout << ys->head() << "\n";
  
  List<int>* zs = cons(3, ys);
  List<int>* ts = take(4, zs);
  for (auto i = ts; i != nullptr; i = i->tail())
  {
    cout << i->head() << " ";
  }
  cout << "\n";
  
  free(ys);
  free(zs);
  return 0;
}

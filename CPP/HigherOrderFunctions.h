#ifndef HIGHERORDERFUNCTIONS_H_
#define HIGHERORDERFUNCTIONS_H_

#include <iostream>
#include <vector>
#include <list>

void twice(int* xs, int size);

void twice_vector(std::vector<int> xs, std::vector<int> &ys);

int scalar_product(std::list<int> xs, std::list<int> ys);

#endif // HIGHERORDERFUNCTIONS_H_

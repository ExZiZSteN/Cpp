#pragma once
#include <cmath>
#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<int>>;


void makeFile(int& N,const char * fileName);
int findMaxRowProizv(const Matrix&M, int N);
void printMatrix(const Matrix&M, int N);
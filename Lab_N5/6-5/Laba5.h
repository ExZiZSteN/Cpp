#pragma once
#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>

using Matrix = std::vector<std::vector<int>>;


bool hasDigit(const std::string& s);
void makeFile(const char * fileName);
int findMaxRowProizv(const Matrix&M, int N);
void printMatrix(const Matrix&M, int N);

struct Toy{
    char name[50];
    int price;
    int minAge;
    int maxAge;
};

void save();
#pragma once

bool isAboveDiagonal(int i, int j);
bool isBelowDiagonal(int i, int j);
long long sumMainDiagonal(long long** a, int n, bool (*predicate)(long long));
void replaceAboveDiagonal(long long** a, int n);

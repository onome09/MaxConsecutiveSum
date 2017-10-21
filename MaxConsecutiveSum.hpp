#pragma once
#include<vector>

class MaxConsecutiveSum{
private:
  std::vector<int> numbers;
  int startPosition;
  int endPosition;
  int startOfNeg;
  int size;
  bool isNeg;
  int fullMax;
  void recalculateMax();
  void recalculatePositive(const int& val);
  void recalculateNegative(const int& val);
public:
  MaxConsecutiveSum();
  int getCurrentMax();
  void insertNumber(const int& number);
};

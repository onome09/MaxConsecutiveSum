#include"MaxConsecutiveSum.hpp"


MaxConsecutiveSum::MaxConsecutiveSum(){
  numbers = std::vector<int>();
  endPosition = 0;
  startPosition = 0;
  size = 0;
  isNeg=false;
  fullMax = 0;
}
 
void MaxConsecutiveSum::recalculatePositive(const int& val){
  int m = 0;
  if (isNeg){
    int res = 0;

    for (int i= startOfNeg; i < size-1; i++){
      res+=numbers[i];
    }
    if( val >= (0-res)){
      endPosition = size-1;
      m = 0;
      for (int i = startPosition; i <= endPosition; i++){
	m += numbers[i];
      }
      isNeg = false;
    }    
  } else {
    m = 0;
    endPosition = size-1;
    for (int i = startPosition; i <= endPosition; i++){
      m += numbers[i];
    } 
  }
  if (m > fullMax){
    fullMax =m;
  }
}
 
void MaxConsecutiveSum::recalculateMax(){
  int val = numbers[size-1];
  if (val <0 ){
    recalculateNegative(val);
  } else {
    recalculatePositive(val);
  }
}
void MaxConsecutiveSum::recalculateNegative(const int& val){
  if (!isNeg){ 
    isNeg = true;
    startOfNeg = size-1;    
  }
  int endSum = 0;
  for (int i = startPosition; i < size-1; i++){
    endSum += numbers[i];
  }
  
  if ((0-endSum)>=val){
    startPosition = 0;
    size = 0;
    numbers.clear();
    isNeg = false;
  } 
}
 
void MaxConsecutiveSum::insertNumber(const int& number){
 
  numbers.push_back(number);
  size++;
  recalculateMax();
}
 
int MaxConsecutiveSum::getCurrentMax(){
  return fullMax;
}

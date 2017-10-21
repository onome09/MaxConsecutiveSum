#include<iostream>
#include<vector>
#include<fstream>
#include"MaxConsecutiveSum.hpp"

using namespace std;

int main(){
  int N,x;
  MaxConsecutiveSum nt;
  N = 8943;//number of integers
  ifstream f;
  f.open("integers.txt");//file to read integers from
  if (N == 0){
    cout << 0;
    return 0;
  }
  for (int i = 0; i < N; i++){
    f >> x;
    nt.insertNumber(x);
  }
  cout << "The maximum consecutive sum of integers is " << nt.getCurrentMax()<< endl;//get maxiumum consecutive sum of integers
  f.close();
  return 0;
}

// File: my_parallel.cc
// Author: Nick Schuler
// Purpose: Computes the last six digits of the
// sum from 1 to n (given as input) of i^i
// 
// I used https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/ as a reference for how to compute
// powers with modular arithmetic

#include <iostream>
#include <iomanip>
#include <omp.h>

using namespace std;

//
// Computes the last 6 digits of a^b using modular arithmetic
// Could be more efficient if I used bitwise comparison but I wanted to leave room for
// the parallelism to improve speed as much as possible
//
int power(long long a, unsigned int b, int n) {
  int res = 1;
  
  a = a % n;

  if (a == 0){
    return 0;
  }

  //#pragma omp parallel
  //{
    //#pragma omp for
      for(int i = b; i > 0; i--){
        if ((b % 2) != 0){
          res = (res*a) % n;
        }
        b = b/2;
        a = (a*a) % n;
      }   
  //}

  return res;
}

int main() {
  int n;
  cin >> n;
  long long sum = 0;
  #pragma omp parallel
  {
    #pragma omp for reduction(+:sum)
    for (int i=1;i<=n;i++) {
      sum+=power(i,i, 1000000);
    }
  }
  cout << setw(6) << setfill('0') << sum%1000000 << endl;
}

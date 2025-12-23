#include <iostream>
#include <cmath>
using namespace std;

bool isSafe(int q[], int c) {
   for (int i = 0; i < c; ++i)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
         return false;
   return true;
}

int nQueensSolutions(int n) {
   int* queens = new int[n];
   queens[0] = 0;
   int col = 0, solutions = 0;

   while (col >= 0) {
      if (col == n - 1) {
         ++solutions;
         --col;
      } else {
         queens[++col] = -1;
      }

      while (col >= 0) {
         ++queens[col];
         if (queens[col] == n)
            --col;
         else if (isSafe(queens, col))
            break;
      }
   }

   delete[] queens;
   return solutions;
}

int main() {
   int n;
   cout << "Input a number: ";
   cin >> n;
   
   for (int i = 1; i <= n; ++i)
      cout << "There are " << nQueensSolutions(i) << " solutions to the " << i << " queens problem.\n";

   return 0;
}

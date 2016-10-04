#include <iostream>
#include <cmath>
#include <cassert>

class solution {
  public:
  //   int countNumUniqDigits(int n) {
  //       return (int)pow(10, n) - countNumWithDupDigits(n);
  //   }

  // private:
  //   int countNumWithDupDigits(int n) {
  //       int result;
  //       if (n == 1)
  //           result = 0;
  //       else if (n == 2)
  //           result = 9;
  //       else if (n == 3) {
  //           result = 0;
  //           result += int(std::pow(10, n)-1)/int(std::pow(10,n-1));
            
  //       }
  //       else {
  //           result = 0;
  //           int prev = countNumWithDupDigits(n-1);
  //           std::cout << "prev = " << prev << std::endl;
  //           result += prev + 8*prev + 9*(n-1)*prev;
  //           std::cout << "curr result = " << result << std::endl;
  //           int max = (int)std::pow(10, n)-1;
  //           std::cout << "max = " << max << std::endl;
  //           for (int i = 2; i <= n-1; i++)
  //               result += max/((int)std::pow(10, i));
  //           std::cout << "result = " << result << std::endl;
  //       }
  //       return result;
  //   }

  //   int numOfNumsWithNDupDigits(int n) {
  //       int result = 0;
  //       if (n == 1)
  //           result = 0;
  //       else if (n == 2)
  //           result = 9;
  //       else {
  //           result += 9+8*numOfNumsWithNDupDigits(n-1)+;
  //       }
  //   }

    int countNumUniqDigits(int n) {
        int result;
        if (n == 1)
            result = NChooseK(10, n);
        else if (n == 2) {
            result = 0;
            result += NChooseK(10,1)+NChooseK(9,1)*NChooseK(9,1);
        }
        else {
            result = 0;
            result += countNumUniqDigits(n-1);
            int temp = NChooseK(9,1);
            for (int i = 1; i < n; i++) {
                if (i < 10)
                    temp *= NChooseK(10-i,1);
                else {
                    temp = 0;
                    break;
                }
            }
            result += temp;
        }
        return result;
    }

    int correctResult(int n) {
        if (n == 0)
            return 1;
        int res = 10, uniqueDigits = 9, availNum = 9;
        while (n-- > 1 && availNum > 0) {
            uniqueDigits = uniqueDigits * availNum;
            res += uniqueDigits;
            availNum--;
        }
        return res;
    }

  private:
    int NChooseK(int n, int k) {
        assert(n >= k);
        if (k == 0)
            return 1;
        else {
            return n*NChooseK(n-1, k-1)/k;
        }
    }
};

int main() {
    int n = 7;
    solution soln;
    int num = soln.countNumUniqDigits(n);
    std::cout << "The number of numbers with unique digits is:\n";
    std::cout << num << std::endl;

    std::cout << "Correct solution is:\n";
    std::cout << soln.correctResult(n) << std::endl;
}

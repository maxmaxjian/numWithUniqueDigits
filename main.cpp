#include <iostream>
#include <cmath>

class solution {
public:
  int countNumUniqDigits(int n) {
    return (int)pow(10, n) - countNumWithDupDigits(n);
  }
  
  int countNumWithDupDigits(int n) {
    int result;
    if (n == 1)
      result = 0;
    else if (n == 2)
      result = 9;
    else {
      result = 0;
      int prev = countNumWithDupDigits(n-1);
      std::cout << "prev = " << prev << std::endl;
      result += prev + 8*prev + 9*(n-1)*prev;
      std::cout << "curr result = " << result << std::endl;
      int max = (int)std::pow(10, n)-1;
      std::cout << "max = " << max << std::endl;
      for (int i = 2; i <= n-1; i++)
	result += max/((int)std::pow(10, i));
      std::cout << "result = " << result << std::endl;
    }
    return result;
  }
};

int main() {
  int n = 5;
  solution soln;
  int num = soln.countNumUniqDigits(n);
  std::cout << "The number of numbers with unique digits is:\n";
  std::cout << num << std::endl;
}

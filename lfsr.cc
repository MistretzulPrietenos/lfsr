#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

namespace sample {
class lfsr {
public:
  lfsr(const std::string &seed, int tap) : seed(seed), tap(tap) {}

  std::string compute() {
      int bit = bchartoi(seed[0]);
      int size = seed.size();
      int tapIdx = size - tap;
      int tapBit = bchartoi(seed[tapIdx-1]);
      int xorResult = bit ^ tapBit;
      // shift and then replace end with xor bit
      std::stringstream ss;
      ss << xorResult;
      seed = seed.substr(1,size) + ss.str();
      return seed;
  }
private:
  int bchartoi(char c) {
      if (c == '1') 
          return 1;
      else
          return 0;
  }
  std::string seed;
  int tap;
};
}

int main(int argc, char *argv[]) {
    // allocate on the stack
    std::string seed = "01101000010";
    int tap = 8;
    int iterations = 5;
    sample::lfsr lfsr(seed, tap);
    std::cout << "Running a linear feedback shift register with parameters:" << std::endl;
    std::cout << "\tseed = " << seed << std::endl;
    std::cout << "\ttap = " << tap << std::endl;
    std::cout << "\titerations = " << iterations << std::endl;
    std::cout << "Begin:"<< std::endl;
    for (int i = 0; i < iterations; i++) {
        std::cout << "iteration[" << i+1 << "]: " <<  lfsr.compute() << std::endl;
    }
    return 0;
}

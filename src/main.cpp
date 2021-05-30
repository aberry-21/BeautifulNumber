#include <iostream>
#include <vector>
#include <memory>
#include <boost/multiprecision/cpp_int.hpp>

int g_system;

std::vector<int> Multiplicate(std::vector<int>& multiplier,
                              std::vector<int>& multiplicand) {
  std::vector <int> res(g_system * g_system / 2);
  for(size_t i = 0; i < multiplier.size(); ++i){
    for(size_t j = 0; j < multiplicand.size(); ++j){
      res[i + j] += multiplier[i] * multiplicand[j];
    }
  }
  return res;
}

int main() {
  std::cout << "Please enter number system [2 : 20]: ";
  std::cin >> g_system;

  std::vector<int> res(g_system * g_system / 2);
  std::vector<int> multiplicand(g_system);
  for (int j = 0; j < g_system; ++j) {
    ++res[j];
  }
  multiplicand = res;
  for (int i = 0; i < g_system / 2 - 1; ++i) {
    res = Multiplicate(res, multiplicand);
  }
  boost::multiprecision::uint1024_t sum = 0;
  for (auto item : res) {
    boost::multiprecision::uint1024_t add_val  = item;
    sum += add_val * add_val;
  }
  std::cout << "The number of " << g_system 
            << "-digit beautiful numbers in the " << g_system
            << "-digit numeral system: ";
  if (g_system % 2) {
    std::cout << sum * g_system << std::endl;
  } else {
    std::cout << sum << std::endl;
  }
  return 0;
}

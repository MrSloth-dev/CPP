#include <iostream>
#include <istream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>

int main() {
  std::vector<int> original;
  std::vector<int> sorted;
  std::string line;
  std::cout << "Checking in" << std::endl;
  while (std::cin >> line) {
    if (line.find("Before:") != line.npos) {
      while (std::cin >> line && line.find("After:") == line.npos) {
        original.push_back(std::atoi(line.c_str()));
      }
    }
    if (line.find("After:") != line.npos) {
      while (std::cin >> line && line.find("Time") == line.npos) {
        sorted.push_back(std::atoi(line.c_str()));
      }
    }
  }
  std::cout << "Original Before" << std::endl;
  for (std::vector<int>::iterator ite = original.begin(); ite < original.end(); ite++)
    std::cout << *ite << " ";
  std::cout << std::endl;
  std::cout << "Sorted After" << std::endl;
  for (std::vector<int>::iterator ite = sorted.begin(); ite < sorted.end(); ite++)
    std::cout << *ite << " ";
  std::cout << std::endl;
  std::cin.clear();
  std::sort(original.begin(), original.end());
  if (original == sorted)
    std::cout << "Sorted!" << std::endl;
  else
    std::cerr << "Not Sorted!" << std::endl;

}

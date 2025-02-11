/**
 * @file parsing.cpp
 * @author Miguel Ferrer (mferrer@inbiot.es)
 * @brief  Parsing a file in C++
 * @version 0.1
 * @date 2025-02-11
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <fstream>
#include <iostream>

using namespace std;

/**
 * @brief Entry point of the program.
 *
 * This function opens a file named "stats.txt" and reads its contents line by
 * line. Each line is expected to have a format where a string and an integer
 * are separated by a colon. The function prints each string and its
 * corresponding integer to the standard output.
 *
 * @return int Returns 1 if the file could not be opened, otherwise returns 0.
 */
int main() {
  ifstream file("stats.txt");
  if (!file.is_open()) {
    return 1;
  } else {
    string line;
    while (getline(file, line, ':')) {
      int population;
      file >> population; // Read the population
      file >> ws;         // Discard whitespace
      cout << line << " -- " << population << endl;
    }
    file.close();
  }
  return 0;
}
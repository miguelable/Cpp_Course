/**
 * @file standard_exceptions.cpp
 * @author Miguel Ferrer
 * @brief  Standard exceptions in C++
 * @version 0.1
 * @date 2025-01-24
 *
 * This program demonstrates how to use standard exceptions in C++.
 * Examples of standard exceptions are:
 * - runtime_error
 * - out_of_range
 * - invalid_argument
 * - logic_error
 * - domain_error
 * - length_error
 * - overflow_error
 * - range_error
 * - underflow_error
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <stdexcept>
using namespace std;

/**
 * @brief  Class that throws a bad_alloc exception
 *
 */
class canGoWrong {
public:
  canGoWrong() {
    char *pMemory = new char[99999999999];
    delete[] pMemory;
  }
};

/**
 * @brief Function that may throw various standard exceptions based on certain
 * conditions.
 *
 * This function checks several boolean flags and throws different standard
 * exceptions if the corresponding flag is set to true. The possible exceptions
 * that can be thrown are:
 * - std::runtime_error: if error1 is true
 * - std::out_of_range: if error2 is true
 * - std::invalid_argument: if error3 is true
 * - std::logic_error: if error4 is true
 * - std::domain_error: if error5 is true
 * - std::length_error: if error6 is true
 * - std::overflow_error: if error7 is true
 * - std::range_error: if error8 is true
 * - std::underflow_error: if error9 is true
 *
 * @throws std::runtime_error if error1 is true
 * @throws std::out_of_range if error2 is true
 * @throws std::invalid_argument if error3 is true
 * @throws std::logic_error if error4 is true
 * @throws std::domain_error if error5 is true
 * @throws std::length_error if error6 is true
 * @throws std::overflow_error if error7 is true
 * @throws std::range_error if error8 is true
 * @throws std::underflow_error if error9 is true
 */
void mightThrow() {
  bool error1 = true;
  bool error2 = false;
  bool error3 = false;
  bool error4 = false;
  bool error5 = false;
  bool error6 = false;
  bool error7 = false;
  bool error8 = false;
  bool error9 = false;

  if (error1) {
    throw runtime_error("Runtime error occurred");
  }
  if (error2) {
    throw out_of_range("Out of range error occurred");
  }
  if (error3) {
    throw invalid_argument("Invalid argument error occurred");
  }
  if (error4) {
    throw logic_error("Logic error occurred");
  }
  if (error5) {
    throw domain_error("Domain error occurred");
  }
  if (error6) {
    throw length_error("Length error occurred");
  }
  if (error7) {
    throw overflow_error("Overflow error occurred");
  }
  if (error8) {
    throw range_error("Range error occurred");
  }
  if (error9) {
    throw underflow_error("Underflow error occurred");
  }
}

/**
 * @brief Entry point of the program.
 *
 * This function demonstrates the usage of exception handling in C++.
 * It contains two try-catch blocks to handle different types of exceptions.
 *
 * The first try-catch block attempts to create an instance of the `canGoWrong`
 * class and catches any `bad_alloc` exceptions that may be thrown.
 *
 * The second try-catch block calls the `mightThrow` function and catches
 * various standard exceptions including `runtime_error`, `out_of_range`,
 * `invalid_argument`, `logic_error`, `domain_error`, `length_error`,
 * `overflow_error`, `range_error`, `underflow_error`, and any other general
 * `exception`.
 *
 * After handling exceptions, the program waits for the user to press ENTER
 * before exiting.
 *
 * @return int Returns 0 upon successful execution.
 */
int main() {
  try {
    canGoWrong wrong;
  } catch (bad_alloc &e) {
    cout << "Caught exception: " << e.what() << endl;
  }

  try {
    mightThrow();
  } catch (runtime_error &e) {
    cout << "Caught runtime_error: " << e.what() << endl;
  } catch (out_of_range &e) {
    cout << "Caught out_of_range: " << e.what() << endl;
  } catch (invalid_argument &e) {
    cout << "Caught invalid_argument: " << e.what() << endl;
  } catch (logic_error &e) {
    cout << "Caught logic_error: " << e.what() << endl;
  } catch (domain_error &e) {
    cout << "Caught domain_error: " << e.what() << endl;
  } catch (length_error &e) {
    cout << "Caught length_error: " << e.what() << endl;
  } catch (overflow_error &e) {
    cout << "Caught overflow_error: " << e.what() << endl;
  } catch (range_error &e) {
    cout << "Caught range_error: " << e.what() << endl;
  } catch (underflow_error &e) {
    cout << "Caught underflow_error: " << e.what() << endl;
  } catch (exception &e) {
    cout << "Caught exception: " << e.what() << endl;
  }

  // Wait for user to press ENTER
  cout << "Press ENTER to exit...";
  cin.get();

  return 0;
}
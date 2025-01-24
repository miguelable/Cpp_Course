/**
 * @file exception_catching_order.cpp
 * @author Miguel Ferrer (mferrer@inbiot.es)
 * @brief Order of exception catching in C++
 * @version 0.1
 * @date 2025-01-24
 *
 * This program demonstrates the importance of the order of catch blocks when
 * handling exceptions in C++. The most specific exception (std::runtime_error)
 * should be caught first, followed by the more general exception
 * (std::exception), and finally a catch-all handler for any other exceptions.
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>

using namespace std;

/**
 * @brief Throws exceptions based on certain error conditions.
 *
 * This function checks for two error conditions and throws exceptions
 * accordingly:
 * - If `error1` is true, it throws a `runtime_error` with the message "Error 1
 * occurred".
 * - If `error2` is true, it throws a generic `exception`.
 *
 * @throws std::runtime_error if `error1` is true.
 * @throws std::exception if `error2` is true.
 */
void throwSomeException() {
  bool error1 = true;
  bool error2 = false;

  if (error1) {
    throw runtime_error("Error 1 occurred");
  }

  if (error2) {
    throw exception();
  }
}

/**
 * @brief Entry point of the program.
 *
 * Demonstrates the importance of the order of catch blocks when handling
 * exceptions. The most specific exception (std::runtime_error) is caught first,
 * followed by the more general exception (std::exception), and finally a
 * catch-all handler for any other exceptions.
 *
 * If the order of the catch blocks is incorrect, the program will not compile.
 *
 * @return int Exit status of the program.
 */
int main() {

  // The order of the catch blocks is important. The most specific exception
  // should be caught first, followed by more general exceptions. If the order
  // is incorrect, the program will not compile.
  // warning: exception of type 'std::runtime_error' will be caught by earlier
  // handler
  //   try {
  //     throwSomeException();
  //   } catch (exception &e) {
  //     cout << "Caught runtime_error: " << e.what() << endl;
  //   } catch (runtime_error &e) {
  //     cout << "Caught exception: " << e.what() << endl;
  //   } catch (...) {
  //     cout << "Caught unknown exception" << endl;
  //   }

  try {
    throwSomeException();
  } catch (runtime_error &e) {
    cout << "Caught runtime_error: " << e.what() << endl;
  } catch (exception &e) {
    cout << "Caught exception: " << e.what() << endl;
  } catch (...) {
    cout << "Caught unknown exception" << endl;
  }

  // Wait for user to press ENTER
  cout << "Press ENTER to exit...";
  cin.get();

  return 0;
}
/**
 * @file custom_exceptions.cpp
 * @author Miguel Ferrer (mferrer@inbiot.es)
 * @brief  Custom exceptions in C++
 * @version 0.1
 * @date 2025-01-24
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>

using namespace std;

/**
 * @brief  Class that throws a custom exception
 *
 */
class myException : public exception {
public:
  /**
   * @brief Returns a C-style string describing the custom exception.
   *
   * This method overrides the what() function from the std::exception class.
   * It provides a custom message indicating that a custom exception has
   * occurred.
   *
   * @return const char* A C-style string with the custom exception message.
   */
  virtual const char *what() const throw() {
    return "My custom exception occurred";
  }
  virtual ~myException() throw() {}
};

/**
 * @brief Class that throws a custom exception
 * @param message Message to be thrown
 */
class testException {
public:
  /**
   * @brief Throws a custom exception of type myException.
   *
   * This function is designed to throw an exception of type myException.
   * It can be used to test exception handling mechanisms or to signal
   * an error condition that should be handled by the caller.
   *
   * @throws myException Always throws this exception when called.
   */
  void throwException() { throw myException(); }
  /**
   * @brief Simulates a runtime error by dereferencing a null pointer.
   *
   * This function checks if a pointer is null and throws a runtime_error
   * exception if it is. The purpose is to simulate a runtime error for
   * testing or demonstration purposes.
   *
   * @throws std::runtime_error if the pointer is null.
   */
  void throwRuntimeError() {
    // Simular un error en tiempo de ejecución
    int *ptr = nullptr;
    if (ptr == nullptr) {
      throw runtime_error("Simulated runtime error: null pointer dereference");
    }
  }
  /**
   * @brief Throws a range error if the provided index is out of bounds.
   *
   * This function simulates a range error by iterating through an array
   * and throwing a range_error exception if the index exceeds the array bounds.
   *
   * @param index The index to iterate up to.
   * @throws std::range_error if the index is greater than or equal to 5.
   */
  void throwRangeError(int index) {
    // Simular un error de rango
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < index; i++) {
      if (i >= 5) {
        throw range_error("Simulated range error: index out of bounds");
      }
      cout << arr[i] << endl;
    }
  }
  /**
   * @brief Throws an underflow_error if the result of subtracting b from a is
   * negative.
   *
   * This function simulates an underflow error by checking if the result of the
   * subtraction (a - b) is less than 0. If it is, it throws an underflow_error
   * exception with a descriptive message. Otherwise, it prints the result of
   * the subtraction.
   *
   * @param a The minuend in the subtraction operation.
   * @param b The subtrahend in the subtraction operation.
   *
   * @throws std::underflow_error If the result of a - b is negative.
   */
  void throwUnderflowError(int a, int b) {
    // Simular un error de desbordamiento
    if (a - b < 0) {
      throw underflow_error("Simulated underflow error: subtraction overflow");
    } else {
      cout << a - b << endl;
    }
  }
  /**
   * @brief Simulates an overflow error when adding two integers.
   *
   * This function checks if the sum of two integers results in an overflow.
   * If the sum is less than 0, it throws an overflow_error exception.
   * Otherwise, it prints the sum of the two integers.
   *
   * @param a The first integer to add.
   * @param b The second integer to add.
   *
   * @throws std::overflow_error If the sum of a and b is less than 0.
   */
  void throwOverflowError(int a, int b) {
    // Simular un error de desbordamiento
    if (a + b < 0) {
      throw overflow_error("Simulated overflow error: addition overflow");
    } else {
      cout << a + b << endl;
    }
  }
};

/**
 * @brief Demonstrates handling of custom and standard exceptions in C++.
 *
 * This program creates an instance of the `testException` class and calls
 * various methods that throw different types of exceptions. Each exception is
 * caught and handled in a corresponding `catch` block, and an appropriate
 * message is printed to the console.
 *
 * The following exceptions are demonstrated:
 * - `myException`: A custom exception type.
 * - `runtime_error`: A standard runtime error.
 * - `range_error`: A standard range error.
 * - `underflow_error`: A standard underflow error.
 * - `overflow_error`: A standard overflow error.
 *
 * After handling the exceptions, the program waits for the user to press ENTER
 * before exiting.
 *
 * @return int Returns 0 upon successful execution.
 */
int main() {
  testException test;
  try {
    test.throwException();
  } catch (myException &e) {
    cout << "Caught myException: " << e.what() << endl;
  }
  try {
    test.throwRuntimeError();
  } catch (runtime_error &e) {
    cout << "Caught runtime_error: " << e.what() << endl;
  }
  try {
    test.throwRangeError(6);
  } catch (range_error &e) {
    cout << "Caught range_error: " << e.what() << endl;
  }
  try {
    test.throwUnderflowError(10, 20);
  } catch (underflow_error &e) {
    cout << "Caught underflow_error: " << e.what() << endl;
  }
  try {
    test.throwOverflowError(123456789, 20);
  } catch (overflow_error &e) {
    cout << "Caught overflow_error: " << e.what() << endl;
  }

  // Wait for user to press ENTER
  cout << "Press ENTER to exit...";
  cin.get();

  return 0;
}

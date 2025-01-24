/**
 * @file basic_exceptions.cpp
 * @author Miguel Ferrer
 * @brief  Basic exception handling in C++
 * @version 0.1
 * @date 2025-01-24
 *
 * This program demonstrates the basic usage of exception handling in C++.
 * It contains two functions that may throw exceptions of different types.
 * The main function calls these functions and catches the exceptions.
 *
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
using namespace std;

/**
 * @brief Enumerated type for error codes.
 *
 */
enum errorCode { ERROR_0, ERROR_1, ERROR_2 };

/**
 * @brief Retrieves the error message corresponding to the given error code.
 *
 * This function takes an error code and returns a string describing the error.
 *
 * @param code The error code for which the message is to be retrieved.
 * @return const char* A string describing the error.
 *         - "Error number 0" for ERROR_0
 *         - "Error number 1" for ERROR_1
 *         - "Error number 2" for ERROR_2
 *         - "Unknown error" for any other error code
 */
const char *getErrorMessage(errorCode code) {
  switch (code) {
  case ERROR_0:
    return "Error number 0";
  case ERROR_1:
    return "Error number 1";
  case ERROR_2:
    return "Error number 2";
  default:
    return "Unknown error";
  }
}

/**
 * @brief Function that may throw different types of exceptions based on certain
 * conditions.
 *
 * This function checks several boolean flags and throws exceptions of different
 * types if the corresponding flag is set to true.
 *
 * @throws const char* If error1 is true, throws a C-style string literal.
 * @throws std::string If error2 is true, throws a std::string object.
 * @throws float If error3 is true, throws a float value.
 * @throws bool If error4 is true, throws a boolean value.
 */
void mightGoWrong() {
  bool error1 = false;
  bool error2 = false;
  bool error3 = true;
  bool error4 = true;

  if (error1) {
    throw "Something went wrong";
  }
  if (error2) {
    throw string("Something else went wrong");
  }
  if (error3) {
    throw float(1.234);
  }
  if (error4) {
    throw true;
  }
}

/**
 * @brief Function that may throw different errors based on certain conditions.
 *
 * This function checks three boolean conditions (error1, error2, error3) and
 * throws corresponding errors if any of the conditions are true.
 *
 * @throws ERROR_0 if error1 is true.
 * @throws ERROR_1 if error2 is true.
 * @throws ERROR_2 if error3 is true.
 */
void mightGoWrong2() {
  bool error1 = true;
  bool error2 = true;
  bool error3 = true;

  if (error1) {
    throw ERROR_0;
  }

  if (error2) {
    throw ERROR_1;
  }

  if (error3) {
    throw ERROR_2;
  }
}

/**
 * @brief Calls functions that might throw exceptions.
 *
 * This function calls two other functions, mightGoWrong() and mightGoWrong2(),
 * which may throw exceptions. It does not handle any exceptions itself, so
 * any exceptions thrown by these functions will propagate to the caller.
 */
void useMightGoWrong() {
  mightGoWrong();
  mightGoWrong2();
}

/**
 * @brief Entry point of the program.
 *
 * This function demonstrates the use of exception handling in C++.
 * It calls the function `useMightGoWrong()` which may throw different types of
 * exceptions. The exceptions are caught and handled in the corresponding catch
 * blocks.
 *
 * The following exceptions are handled:
 * - int: Prints the error code.
 * - const char*: Prints the error message.
 * - string: Prints the string error message.
 * - errorCode: Prints the error message obtained from `getErrorMessage(e)`.
 * - float: Prints the float error code.
 * - double: Prints the double error code.
 * - bool: Prints the boolean error as "Yes" or "No".
 *
 * After handling exceptions, the program continues to run and waits for the
 * user to press ENTER before exiting.
 *
 * @return int Returns 0 upon successful execution.
 */
int main() {
  try {
    useMightGoWrong();
  } catch (int e) {
    cout << "Error code: " << e << endl;
  } catch (const char *e) {
    cout << "Error message: " << e << endl;
  } catch (string &e) {
    cout << "String error message: " << e << endl;
  } catch (errorCode e) {
    cout << "Error code: " << getErrorMessage(e) << endl;
  } catch (float e) {
    cout << "Float error code: " << e << endl;
  } catch (double e) {
    cout << "Double error code: " << e << endl;
  } catch (bool e) {
    cout << "Boolean error: " << (e ? "Yes" : "No") << endl;
  }

  cout << "Still running" << endl;

  // Wait for user to press ENTER
  cout << "Press ENTER to exit...";
  cin.get();

  return 0;
}

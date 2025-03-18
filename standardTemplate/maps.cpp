#include <conio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

// Custom class to use as a key in the map
class CustomKey
{
public:
  int    id;
  string name;

  CustomKey(int id, string name) : id(id), name(name)
  {
  }

  bool operator<(const CustomKey& other) const
  {
    if (id == other.id) {
      return name < other.name;
    }
    else {
      return id < other.id;
    }
  }
};

// Custom class to use as a value in the map
class CustomValue
{
public:
  int    age;
  string address;

  CustomValue() : age(0), address("")
  {
  } // Default constructor

  CustomValue(int age, string address) : age(age), address(address)
  {
  }
};

// Function to print the elements of the map
template <typename K, typename V>
void print_map(const map<K, V>& m)
{
  for (const auto& pair : m) {
    cout << "Name: " << pair.first.name << " ID(" << pair.first.id << ") -> Age: " << pair.second.age << ", Address: " << pair.second.address << endl;
  }
}

void show_menu(const string options[], int num_options, int selection)
{
  system("cls"); // Clear the screen
  for (int i = 0; i < num_options; ++i) {
    if (i == selection) {
      cout << "> " << options[i] << " <" << endl;
    }
    else {
      cout << "  " << options[i] << endl;
    }
  }
}

void wait_for_enter()
{
  // Wait for the user to press ENTER
  cout << "Press ENTER to continue...";
  cin.get();
  cin.get();
}

void insert(map<CustomKey, CustomValue>& m)
{
  int    id, age;
  string name, address;

  cout << "Enter ID: ";
  cin >> id;
  cout << "Enter name: ";
  cin >> name;
  cout << "Enter age: ";
  cin >> age;
  cin.ignore();
  cout << "Enter address: ";
  std::getline(std::cin, address);

  CustomKey   key(id, name);
  CustomValue value(age, address);
  m[key] = value;

  print_map(m);
}

void modify(map<CustomKey, CustomValue>& m)
{
  int id;
  cout << "Enter the ID of the key to modify: ";
  cin >> id;

  for (auto& pair : m) {
    if (pair.first.id == id) {
      int    age;
      string address;

      cout << "Enter new age: ";
      cin >> age;
      cin.ignore();
      cout << "Enter new address: ";
      std::getline(std::cin, address);

      pair.second.age     = age;
      pair.second.address = address;
      break;
    }
  }
  print_map(m);
}

void remove(map<CustomKey, CustomValue>& m)
{
  int id;
  cout << "Enter the ID of the key to remove: ";
  cin >> id;

  for (auto it = m.begin(); it != m.end(); ++it) {
    if (it->first.id == id) {
      m.erase(it);
      break;
    }
  }

  print_map(m);
}

void find(const map<CustomKey, CustomValue>& m)
{
  int id;
  cout << "Enter the ID of the key to find: ";
  cin >> id;

  for (const auto& pair : m) {
    if (pair.first.id == id) {
      cout << "Found ID: " << pair.first.id << " Name: " << pair.first.name << " -> Age: " << pair.second.age << ", Address: " << pair.second.address
           << endl;
      return;
    }
  }

  cout << "Key not found" << endl;
}

void clear(map<CustomKey, CustomValue>& m)
{
  m.clear();
  print_map(m);
}

void empty(const map<CustomKey, CustomValue>& m)
{
  if (m.empty()) {
    cout << "The map is empty" << endl;
  }
  else {
    cout << "The map is not empty" << endl;
  }
}

void map_size(const map<CustomKey, CustomValue>& m)
{
  cout << "The size of the map is: " << m.size() << endl;
}

int main()
{
  map<CustomKey, CustomValue> myMap;

  const int numOptions          = 9;
  string    options[numOptions] = {"Insert", "Modify", "Remove", "Find", "Clear", "Empty", "Size", "Predefine", "Exit"};
  int       selection           = 0;

  while (true) {
    show_menu(options, numOptions, selection);

    int key = _getch();
    if (key == 224) { // Special key (arrows)
      key = _getch();
      if (key == 72) { // Up arrow
        selection = (selection - 1 + numOptions) % numOptions;
      }
      else if (key == 80) { // Down arrow
        selection = (selection + 1) % numOptions;
      }
    }
    else if (key == 13) { // Enter
      system("cls");      // Clear the screen
      if (options[selection] == "Insert") {
        insert(myMap);
        wait_for_enter();
      }
      else if (options[selection] == "Modify") {
        modify(myMap);
        wait_for_enter();
      }
      else if (options[selection] == "Remove") {
        remove(myMap);
        wait_for_enter();
      }
      else if (options[selection] == "Find") {
        find(myMap);
        wait_for_enter();
      }
      else if (options[selection] == "Clear") {
        clear(myMap);
        wait_for_enter();
      }
      else if (options[selection] == "Empty") {
        empty(myMap);
        wait_for_enter();
      }
      else if (options[selection] == "Size") {
        map_size(myMap);
        wait_for_enter();
      }
      else if (options[selection] == "Predefine") {
        CustomKey   key1(1, "Alice");
        CustomValue value1(25, "123 Main St");
        myMap[key1] = value1;

        CustomKey   key2(2, "Bob");
        CustomValue value2(30, "456 Elm St");
        myMap[key2] = value2;

        CustomKey   key3(3, "Charlie");
        CustomValue value3(35, "789 Oak St");
        myMap[key3] = value3;

        print_map(myMap);
        wait_for_enter();
      }
      else if (options[selection] == "Exit") {
        break;
      }
    }
  }

  return 0;
}
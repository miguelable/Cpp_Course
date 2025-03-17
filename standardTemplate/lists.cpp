#include <conio.h>
#include <iostream>
#include <list>

using namespace std;

// Función para imprimir los elementos de una lista
void print_list(const list<int>& l)
{
  cout << "Lista: ";
  for (const auto& elem : l) {
    cout << elem << ' ';
  }
  cout << '\n';
}

void show_menu(const string options[], int num_options, int selection)
{
  system("cls"); // Limpiar la pantalla
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
  // wait for the user to press ENTER
  cout << "Press ENTER to continue...";
  cin.get();
  cin.get();
}

void push_back(list<int>& l)
{
  // ask for a number to add to the list
  int number;
  cout << "Enter a number to add to the list: ";
  cin >> number;
  l.push_back(number);
  print_list(l);
}

void push_front(list<int>& l)
{
  // ask for a number to add to the list
  int number;
  cout << "Enter a number to add to the list: ";
  cin >> number;
  l.push_front(number);
  print_list(l);
}

void insert(list<int>& l)
{
  // ask for a number to add to the list
  int number;
  cout << "Enter a number to add to the list: ";
  cin >> number;
  // ask for a position to insert the number
  int position;
  cout << "Enter a position to insert the number: ";
  cin >> position;
  auto it = l.begin();
  advance(it, position);
  l.insert(it, number);
  print_list(l);
}

void remove(list<int>& l)
{
  // ask if the user wants to remove a specific number or all occurrences of a number
  cout << "Do you want to remove a specific position or all occurrences of a number? (1 or 2): ";
  int option;
  cin >> option;
  if (option == 1) {
    // ask for a position to remove the number
    cout << "Enter a position to remove the number: ";
    int position;
    cin >> position;
    auto it = l.begin();
    advance(it, position);
    l.erase(it);
    print_list(l);
  }
  else if (option == 2) {
    // ask for a number to remove from the list
    int number;
    cout << "Enter a number to remove from the list: ";
    cin >> number;
    l.remove(number);
    print_list(l);
  }
  else {
    cout << "Invalid option";
  }
}

void sort(list<int>& l)
{
  l.sort();
  print_list(l);
}

void reverse(list<int>& l)
{
  l.reverse();
  print_list(l);
}

void merge(list<int>& l1, list<int>& l2, list<int>& l3)
{
  // clear list3
  l3.clear();
  // merge l1 and l2 into l3
  l3.merge(l1);
  l3.merge(l2);
  print_list(l3);
}

void clear(list<int>& l)
{
  l.clear();
  print_list(l);
}

void empty(list<int>& l)
{
  if (l.empty()) {
    cout << "The list is empty\n";
  }
  else {
    cout << "The list is not empty\n";
  }
}

void list_size(list<int>& l)
{
  cout << "The size of the list is: " << l.size() << '\n';
  cout << "The maximum size of the list is: " << l.max_size() << '\n';
}

int main()
{
  // Crear una lista vacía de enteros
  list<int> list1;
  list<int> list2;
  list<int> list3;

  const int numOpciones           = 12;
  string    opciones[numOpciones] = {"Print",   "Push back", "Push front", "Insert", "Remove", "Sort",
                                  "Reverse", "Merge",     "Clear",      "Empty",  "Size",   "Exit"};
  int       seleccion             = 0;

  while (true) {
    show_menu(opciones, numOpciones, seleccion);

    int tecla = _getch();
    if (tecla == 224) { // Tecla especial (flechas)
      tecla = _getch();
      if (tecla == 72) { // Flecha arriba
        seleccion = (seleccion - 1 + numOpciones) % numOpciones;
      }
      else if (tecla == 80) { // Flecha abajo
        seleccion = (seleccion + 1) % numOpciones;
      }
    }
    else if (tecla == 13) { // Enter
      system("cls");        // Limpiar la pantalla
      if (opciones[seleccion] == "Print") {
        // ask for a list to print
        cout << "Enter the list number (1 or 2): ";
        int list_number;
        cin >> list_number;
        if (list_number == 1) {
          print_list(list1);
        }
        else if (list_number == 2) {
          print_list(list2);
        }
        else {
          cout << "Invalid list number.\n";
        }
        wait_for_enter();
      }
      else if (opciones[seleccion] == "Push back") {
        // ask for a list to add the number
        cout << "Enter the list number (1 or 2): ";
        int list_number;
        cin >> list_number;
        if (list_number == 1) {
          push_back(list1);
        }
        else if (list_number == 2) {
          push_back(list2);
        }
        else {
          cout << "Invalid list number." << endl;
        }
        wait_for_enter();
      }
      else if (opciones[seleccion] == "Push front") {
        // ask for a list to add the number
        cout << "Enter the list number (1 or 2): ";
        int list_number;
        cin >> list_number;
        if (list_number == 1) {
          push_front(list1);
        }
        else if (list_number == 2) {
          push_front(list2);
        }
        else {
          cout << "Invalid list number." << endl;
        }
        wait_for_enter();
      }
      else if (opciones[seleccion] == "Insert") {
        // ask for a list to add the number
        cout << "Enter the list number (1 or 2): ";
        int list_number;
        cin >> list_number;
        if (list_number == 1) {
          insert(list1);
        }
        else if (list_number == 2) {
          insert(list2);
        }
        else {
          cout << "Invalid list number." << endl;
        }
        wait_for_enter();
      }
      else if (opciones[seleccion] == "Remove") {
        // ask for a list to remove the number
        cout << "Enter the list number (1 or 2): ";
        int list_number;
        cin >> list_number;
        if (list_number == 1) {
          remove(list1);
        }
        else if (list_number == 2) {
          remove(list2);
        }
        else {
          cout << "Invalid list number." << endl;
        }
        wait_for_enter();
      }
      else if (opciones[seleccion] == "Sort") {
        // ask for a list to sort
        cout << "Enter the list number (1 or 2): ";
        int list_number;
        cin >> list_number;
        if (list_number == 1) {
          sort(list1);
        }
        else if (list_number == 2) {
          sort(list2);
        }
        else {
          cout << "Invalid list number." << endl;
        }
        wait_for_enter();
      }
      else if (opciones[seleccion] == "Reverse") {
        // ask for a list to reverse
        cout << "Enter the list number (1 or 2): ";
        int list_number;
        cin >> list_number;
        if (list_number == 1) {
          reverse(list1);
        }
        else if (list_number == 2) {
          reverse(list2);
        }
        else {
          cout << "Invalid list number." << endl;
        }
        wait_for_enter();
      }
      else if (opciones[seleccion] == "Merge") {
        merge(list1, list2, list3);
        wait_for_enter();
      }
      else if (opciones[seleccion] == "Clear") {
        // ask for a list to clear
        cout << "Enter the list number (1 or 2): ";
        int list_number;
        cin >> list_number;
        if (list_number == 1) {
          clear(list1);
        }
        else if (list_number == 2) {
          clear(list2);
        }
        else {
          cout << "Invalid list number." << endl;
        }
        wait_for_enter();
      }
      else if (opciones[seleccion] == "Empty") {
        // ask for a list to check if it's empty
        cout << "Enter the list number (1 or 2): ";
        int list_number;
        cin >> list_number;
        if (list_number == 1) {
          empty(list1);
        }
        else if (list_number == 2) {
          empty(list2);
        }
        else {
          cout << "Invalid list number." << endl;
        }
        wait_for_enter();
      }
      else if (opciones[seleccion] == "Size") {
        // ask for a list to get its size
        cout << "Enter the list number (1 or 2): ";
        int list_number;
        cin >> list_number;
        if (list_number == 1) {
          list_size(list1);
        }
        else if (list_number == 2) {
          list_size(list2);
        }
        else {
          cout << "Invalid list number." << endl;
        }
        wait_for_enter();
      }
      else if (opciones[seleccion] == "Exit") {
        break;
      }
    }
  }

  return 0;
}
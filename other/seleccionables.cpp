#include <conio.h> // Para _getch()
#include <iostream>

using namespace std;

void mostrarMenu(const string opciones[], int numOpciones, int seleccion)
{
  system("cls"); // Limpiar la pantalla
  for (int i = 0; i < numOpciones; ++i) {
    if (i == seleccion) {
      cout << "> " << opciones[i] << " <" << endl;
    }
    else {
      cout << "  " << opciones[i] << endl;
    }
  }
}

int main()
{
  const int numOpciones           = 3;
  string    opciones[numOpciones] = {"Opcion 1", "Opcion 2", "Opcion 3"};
  int       seleccion             = 0;

  while (true) {
    mostrarMenu(opciones, numOpciones, seleccion);

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
      cout << "Has seleccionado: " << opciones[seleccion] << endl;
      break;
    }
  }

  return 0;
}

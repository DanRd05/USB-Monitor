#include <iostream>
#include <windows.h>
#include "interfaz.h"
#include "dispositivos.h"

using namespace std;

const int MAX_USB = 26;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	menuInicial();
	
	string anteriores[MAX_USB];
    string actuales[MAX_USB];
    int cantidadAnterior = 0;
    int cantidadActual = 0;
    
    while (true)
    {
        Sleep(1000);
        cantidadActual = reconocerUSB(actuales);
        // Revisar nuevas conexiones.
        for (int i = 0; i < cantidadActual; i++)
        {
            if (!USBexiste(actuales[i], anteriores, cantidadAnterior))
            {
                cout << "[CONECTADO] Unidad USB: "
                     << actuales[i] << endl;
            }
        }

        // Revisar desconexiones.
        for (int i = 0; i < cantidadAnterior; i++)
        {
            if (!USBexiste(anteriores[i], actuales, cantidadActual))
            {
                cout << "[DESCONECTADO] Unidad USB: "
                     << anteriores[i] << endl;
            }
        }

        // Actualizar el historial de unidades.
        cantidadAnterior = cantidadActual;
        for (int i = 0; i < cantidadActual; i++)
        {
            anteriores[i] = actuales[i];
        }
    }
	
	return 0;
}
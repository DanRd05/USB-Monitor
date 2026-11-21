#ifndef dispositivos_H
#define dispositivos_H

#include <iostream>
#include <string>
#include <windows.h>
#include <setupapi.h>
#include <usbiodef.h>
#include <initguid.h>
 
const int MAX_USB = 26;

 //Parte más importante del código, ya que esta sirve para reconocer los dispositivos que estan conectados desde windows.
int reconocerUSB(std::string USBs[]){
	DWORD unidades = GetLogicalDrives(); //esta sirve para las unidades extraibles USB, pq checa las letras ya ocupadas y las regresa, por ejemplo unidad D:\\
	int canti = 0;
	
	for (int i = 0; i < MAX_USB; i++){
		if (unidades & (1 << i)){
			char unidad[] = "A:\\";
			unidad[0] = 'A' + i;
 			
			if (GetDriveTypeA(unidad) == DRIVE_REMOVABLE){ //este if checa si es un disco extraible, por ejemplo si es un disco nativo de la pc no lo tomará.
				USBs[canti] = unidad;
				canti++;
			}
		}
	}
	return canti;
}
 
bool USBexiste(std::string unidad, std::string dispositivos[], int canti){
	for (int i = 0; i < canti; i++){
		if (dispositivos[i] == unidad){
			return true;
		}
	}
	return false;
}

#endif
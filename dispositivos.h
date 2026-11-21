#ifndef dispositivos_H
#define dispositivos_H

#include <iostream>
#include <string>
#include <windows.h>
 
 int reconocerUSB(std::string USBs[]){
 	DWORD unidades = GetLogicalDrives();
 	int cantidad = 0;
 	for (int i = 0; i < 26; i++){
 		if (unidades & (1 << i)){
 			
			 char unidad[] = "A:\\";
 			unidad[0] = 'A' + i;
 			
 			if (GetDriveTypeA(unidad) == DRIVE_REMOVABLE){
 				USBs[cantidad] = unidad;
 				cantidad++;
			 }
		 }
	 }
	 return cantidad;
 }
 
 bool USBexiste(std::string unidad, std::string dispositivos[], int cantidad){
 	for (int i = 0; i < cantidad; i++){
 		if (dispositivos[i] == unidad){
 			return true;
		 }
	 }
	 return false;
 }

#endif
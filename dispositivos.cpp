#ifndef dispositivos_H
#define dispositivos_H

#include <vector>
#include <string>

struct USB {
	int id;
	std::string nombre;
	std::string tipo;
	std::string fabricante;
	std::string modelo;
	std::string fechaDeRegistro;
	std::string estado;
	int conexiones;
};
 
 
int asignarID(const std::vector<USB>& registros){
	int nuevoID = 100;
	
	for (size_t i = 0; i < registros.size(); i++){
		if(registros[i].id >= nuevoID){
			nuevoID = registros[i].id + 1;
		}
	}
	
	return nuevoID;
}
 
bool consultarID(const std::vector<USB>& registros, int ID){//Revisa que el usb al que esta asignado el ID exista y devuelve true o false al manejador de eventos para que se encargue del resto
	for(size_t i = 0; i <= registros.size(); i++){
		if (registros[i].id == ID){
			return true;
		}
	}
	return false;
} 

bool actualizarUSB(std::vector<USB>& registros, int ID, const std::string& nuevoNombre, const std::string& nuevoTipo, const std::string& nuevoFabricante, const std::string& nuevoModelo){
	for(size_t i = 0; i < registros.size(); i++){
		if (registros[i].id == ID){
			registros[i].nombre = nuevoNombre;
			registros[i].tipo = nuevoTipo;
			registros[i].fabricante = nuevoFabricante;
			registros[i].modelo = nuevoModelo;
			return true;
		}
	}
	return false;
}

#endif
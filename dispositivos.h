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
 
 
int asignarID(const std::vector<USB>& registros);
 
bool consultarID(const std::vector<USB>& registros, int ID);

bool actualizarUSB(std::vector<USB>& registros, int ID, const std::string& nuevoNombre, const std::string& nuevoTipo, const std::string& nuevoFabricante, const std::string& nuevoModelo);

#endif
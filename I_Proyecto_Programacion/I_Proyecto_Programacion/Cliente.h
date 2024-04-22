#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
class Cliente{
private:
	std::string cedula;
	double totalVentas;
public:
	Cliente();
	Cliente(std::string cedula, double totalVentas);
	std::string getCedula();
	double getTotalVentas();
	void setCedula(std::string cedula);
	void setTotalVentas(double totalVentas);
	void incrementarTotalVentas(double monto);
	bool operator==(const Cliente&);
};

#endif
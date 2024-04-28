#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
class Cliente {
private:
	std::string cedula;
	double tVentas;
public:
	Cliente(std::string ced, double v);
	virtual ~Cliente();
	std::string getCedula();
	double getTVentas();
	void setCedula(std::string ced);
	void setTVentas(double v);
	//sobrecarga operadorese
	bool operator==(const Cliente& c);
	bool operator<(const Cliente& c);
	
	Cliente& operator=(const Cliente& c);
};

#endif
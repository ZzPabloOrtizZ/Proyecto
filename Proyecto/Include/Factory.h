#pragma once
#include "Prerequisites.h"


//Esta clase creara el objeto principal
class
Vehiculo {
public:
virtual
	void
	Descripcion() {
	cout<<"Vehiculo"<<endl;
	}
};

//Aqui crearemos los tipos de vehiculos que podemos crear
class
ConcreteCoche : public Vehiculo{
public:
	void
	Descripcion() override{
	 cout<<"Vehiculo clasico"<<endl;
	}
};


class
ConcreteBicicleta : public Vehiculo {
public:
	void
	Descripcion() override {
	cout<<"Bicicleta basica"<<endl;
	}
};

//Aqui se crean los vehiculos
class
FabricaVehiculos {
public:
virtual
Vehiculo*
crearVehiculos() = 0;
};

class ConcreteFabricaCoches : public FabricaVehiculos {
public:
	Vehiculo* crearVehiculos() override {
	return new ConcreteCoche();
	}
};

class ConcreteFabricaBicicletas : public FabricaVehiculos {
public:
	Vehiculo* crearVehiculos() override {
	return new ConcreteBicicleta();
	}
};

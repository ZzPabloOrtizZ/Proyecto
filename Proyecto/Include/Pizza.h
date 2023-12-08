#pragma once
#include "Prerequisites.h"
using namespace std;

//Crear las Pizzas
class 
Pizza {
public:

	void 
	//Partes y ingredientes
	AddPart(const string _part) { 
	 m_parts.push_back(_part);
	 }

	void
	print() {
	cout<<"Ingredientes de la Pizza: ";
	for (int i = 0; i < m_parts.size(); i++)
	{
	cout<<m_parts[i]<<", ";
	}
	cout<< "" <<endl;
	}

private:
  vector<string> m_parts;
};

//Ingredientes para nuestra Pizza
class Cook
{
public:
	virtual
		void Mass() = 0;

	virtual
		void Cheese() = 0;

	virtual
		void Sauce() = 0;

	virtual
		void Toppings() = 0;

	virtual
		Pizza* getProduct() = 0;
};

//Crear las diferentes pizzas
class ClasicPizza : public Cook {
public:
	ClasicPizza() {
		m_product = new Pizza();
	}

	void
		Mass() override {
		m_product->AddPart("Masa Clasica");
	}

	void
		Cheese() override {
		m_product->AddPart("Queso Clasico");
	}

	void
		Sauce() override {
		m_product->AddPart("Salsa de tomate");
	}

	void
		Toppings() override {
		m_product->AddPart("Pepperoni");
	}

	Pizza* getProduct() override {
		return m_product;
	}

private:
	Pizza* m_product;
};

class ChessePizza : public Cook {
public:
	ChessePizza() {
		m_product = new Pizza();
	}

	void
		Mass() override {
		m_product->AddPart("Masa con Queso");
	}

	void
		Cheese() override {
		m_product->AddPart("Queso Extra");
	}

	void
		Sauce() override {
		m_product->AddPart("Salsa de tomate con queso");
	}

	void
		Toppings() override {
		m_product->AddPart("Mas Queso");
	}

	Pizza* getProduct() override {
		return m_product;
	}

private:
	Pizza* m_product;
};

//Crear una pizza con ingredientes especificos
class Chef {
public:
	Chef(Cook* _cooking) : m_builder(_cooking) {}

	void
		build() {
		m_builder->Mass();
		m_builder->Cheese();
		m_builder->Sauce();
		m_builder->Toppings();
	}

private:
	Cook* m_builder;
};
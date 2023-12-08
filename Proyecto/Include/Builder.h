#pragma once
#include "Prerequisites.h"

//Clase para el objeto a construir
class
BuildProduct 
{
public:
	void
	//Agregar nuevas partes
	AddPart(const string& _parts) {
	m_parts.push_back(_parts);
	}
	void
	print() 
	{
		cout << "Materiales en la mesa de trabajo: ";
		for (int i = 0; i < m_parts.size(); i++)
		{
			cout << m_parts[i] << " ";
		}
		}
private:
vector<string> m_parts;
};

//Partes del objeto
class Builder
{
public:
virtual
void buildPart_A() = 0;

virtual
void buildPart_B() = 0;

virtual
BuildProduct* GetProduct() = 0;
};

//Implementar las partes del producto
class BuilderConcreto : public Builder 
{
public:
BuilderConcreto() {
m_product = new BuildProduct();
}
	void
	buildPart_A() override {
	m_product->AddPart("Parte 1");
	}

	void
	buildPart_B() override {
	m_product->AddPart("Parte 2");
	}

	BuildProduct* GetProduct() override {
	return m_product;
	}
private:
BuildProduct* m_product;
};

//Contrucción del producto
class Director 
{
public:
Director(Builder* _builder) : m_builder(_builder) {}

	void
	build() 
	{
	m_builder->buildPart_A();
	m_builder->buildPart_B();
	}
private:
Builder* m_builder;
};
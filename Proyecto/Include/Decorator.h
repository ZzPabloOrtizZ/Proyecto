#pragma once
#include "Prerequisites.h"
using namespace std;

//Interfaz base
class Component {
public:
virtual void operacion() = 0;
};

// Clase concreta
class
ConcreteComponent : public Component {
public:
void operacion() override {

  cout<<"Operacion de componentes concreta"<<endl;
  }
};

//Decorador base
class
Decorator : public Component {
public:
Decorator(Component * _component)
: m_component(_component){}

void operacion() override {
m_component->operacion();
}

private:
Component* m_component;
};

//Decorador concreto A
class 
ConcreteDecoratorA : public Decorator {
public:
ConcreteDecoratorA(Component* _component)
:Decorator(_component){}

  void operacion() override {
  Decorator::operacion();
  cout << "Operacion del operador A" << endl;
  }
};

//Decorador concreto B
class ConcreteDecoratorB : public Decorator {
public:
ConcreteDecoratorB(Component* _component)
  :Decorator(_component) {}

  void operacion() override {
  Decorator::operacion();
  cout << "Operacion del operador B" << endl;
  }
};
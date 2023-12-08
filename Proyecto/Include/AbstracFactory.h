#include "Prerequisites.h"
#include <iostream>
using namespace std;

//Interfaz base para el Componente X
class Component_X {
public:
    virtual void Operation_X() = 0;
    virtual ~Component_X() {}
};

// Interfaz base para el Componente Y
class Component_Y {
public:
    virtual void Operation_Y() = 0;
    virtual ~Component_Y() {}
};

class AbstractComponentFactory {
public:
    virtual Component_X* CreateComponent_X() = 0;
    virtual Component_Y* CreateComponent_Y() = 0;
    virtual ~AbstractComponentFactory() {}
};

//Component_X
class Component_X_Impl : public Component_X {
public:
    void Operation_X() override {
        cout << "Ejecutando operación en Componente X" << endl;
    }
};

//Component_Y
class Component_Y_Impl : public Component_Y {
public:
    void Operation_Y() override {
        cout << "Ejecutando operación en Componente Y" << endl;
    }
};

//Implementación
class ConcreteComponentFactory : public AbstractComponentFactory {
public:
    Component_X* CreateComponent_X() override {
        return new Component_X_Impl();
    }
    Component_Y* CreateComponent_Y() override {
        return new Component_Y_Impl();
    }
};

// Función principal
int main() {
    AbstractComponentFactory* factory = new ConcreteComponentFactory();

    Component_X* componentX = factory->CreateComponent_X();
    Component_Y* componentY = factory->CreateComponent_Y();

    componentX->Operation_X();
    componentY->Operation_Y();

    delete componentX;
    delete componentY;
    delete factory;

    return 0;
}

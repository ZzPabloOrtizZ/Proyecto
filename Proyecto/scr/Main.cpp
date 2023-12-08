#include <iostream>
#include "Singleton.h"
#include "RegistroActividad.h"
#include "Factory.h"
#include "AbstractFactory.h"
#include "Builder.h"
#include "Pizza.h"
#include "Adapter.h"
#include "Adapter Circle.h"
#include "Prototype.h"
#include "DocumentPrototype.h"
#include "Decorator.h"
#include "CafeDecorator.h"
#include "Composite.h"
#include "ArchivoComposite.h"


int main() {

    //Ejemplo Singleton
    Singleton* SingleMan = Singleton::getInstance();
    SingleMan->setValue(36);

    Singleton* SingleMan2 = Singleton::getInstance();
    cout << "Value: " << SingleMan2->getValue() << endl;

    //Ejercicio Singleton
    Singleton* singletonInstance = Singleton::getInstance();
    singletonInstance->setValue(42);
    cout << "Singleton Value: " << singletonInstance->getValue() << endl;

    //Ejercicio Factory
    VehicleFactory* carFactory = new CarFactory();
    Vehicle* car = carFactory->createVehicle();
    car->describe();

    VehicleFactory* bikeFactory = new BikeFactory();
    Vehicle* bike = bikeFactory->createVehicle();
    bike->describe();
    delete carFactory;
    delete bikeFactory;

    //Ejercicio Abstract Factory
    AbstractFactory* factory = new ConcreteFactory();
    ProductA* productA = factory->createProductA();
    ProductB* productB = factory->createProductB();
    productA->operationA();
    productB->operationB();
    delete factory;
    delete productA;
    delete productB;

    //Ejemplo Builder
    Builder* construct = new BuilderConcreto();

    Director director(construct);
    director.build();

    BuildProduct* producto = construct->GetProduct();
    producto->print();

    delete construct;
    delete producto;

    //Ejercicio Builder
    Builder* builder = new ConcreteBuilder();
    Director* director = new Director(builder);
    director->construct();
    Product* product = builder->getProduct();
    product->display();
    delete director;
    delete builder;
    delete product;

    //Ejemplo Adapter
    interfazVieja* ObjetoViejo = new interfazVieja();
    interfazNueva* ObjetoNuevo = new adapter(ObjetoViejo);

    ObjetoNuevo->NewMethod();

    delete ObjetoNuevo;
    delete ObjetoViejo;

    //Ejercicio de Adapter
    Circle* circle = new Circle();
    Square* square = new Square();

    Drawing* fitCircle = new FitCircle(circle);
    Drawing* fitSquare = new FitSquare(square);

    fitCircle->Draw();
    fitSquare->Draw();

    delete circle;
    delete square;
    delete fitCircle;
    delete fitSquare;

    //Ejemplo Prototype
    Prototype* original = new ConcretePrototype();
    original->configure("Example");
    Prototype* cloned = original->clone();
    original->display();
    cloned->display();
    delete original;
    delete cloned;

    //Ejercicio de Prototype
    DocumentoPrototype* prototipoTexto = new DocumentoTexto();
    prototipoTexto->config("Texto");

    DocumentoPrototype* prototipoImagen = new DocumentoImagen();
    prototipoImagen->config("Imagen");

    DocumentoPrototype* copiaTexto = prototipoTexto->clone();
    DocumentoPrototype* copiaImagen = prototipoImagen->clone();

    copiaTexto->config("Texto Nuevo");
    copiaImagen->config("Imagen Nueva");

    prototipoImagen->config("Imagen OG");
    prototipoTexto->config("Texto OG");

    prototipoTexto->clone()->show();
    copiaTexto->show();

    prototipoImagen->clone()->show();
    copiaImagen->show();

    delete prototipoTexto;
    delete prototipoImagen;
    delete copiaTexto;
    delete copiaImagen;

    //Decorator
    ConcreteComponent* Objeto = new ConcreteComponent();
    ConcreteDecoratorA* decoratorA = new ConcreteDecoratorA(Objeto);
    ConcreteDecoratorB* decoratorB = new ConcreteDecoratorB(decoratorA);

    Objeto->operacion();
    decoratorA->operacion();
    decoratorB->operacion();

    //Ejercicio Decorator
    Component* component = new ConcreteComponent();
    Decorator* decorator = new ConcreteDecorator(component);
    decorator->operation();
    delete decorator;
    delete component;

    //Ejemplo Composite
    leaf* hoja1 = new leaf();
    leaf* hoja2 = new leaf();
    Composite* composite = new Composite();

    composite->addLeaf(hoja1);
    composite->addLeaf(hoja2);

    composite->operacion();

    delete hoja1;
    delete hoja2;
    delete composite;


    //Ejercicio Composite
    Leaf* leaf1 = new Leaf();
    Leaf* leaf2 = new Leaf();
    Composite* composite = new Composite();
    composite->addChild(leaf1);
    composite->addChild(leaf2);
    composite->operation();
    delete leaf1;
    delete leaf2;
    delete composite;

    return 0;
}

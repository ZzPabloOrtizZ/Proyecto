#pragma once
#include "Prerequisites.h"

// Clase Componente que define la interfaz
class
Component {
public:
    virtual void operacion() = 0; //Método virtual puro para la operación
};

//Clase que representa componentes individuales
class Leaf:
    public Component {
public:
    void operacion() override {
        cout << "Operación en hoja" << endl;
    }
};

// Clase Composite que representa componentes compuestos
class
Composite:
    public Component {
public:
    void 
    operacion() override {
        cout << "Operación composite. Contiene: " << m_leafs.size() << " leafs." << endl;

        // Realiza la operación para cada hoja
        for (auto hoja : m_leafs) {
            hoja->operacion();
        }
    }

    // Agrega una hoja al Composite
    void addLeaf(Component* _leaf) {
        m_leafs.push_back(_leaf);
    }

private:
    vector<Component*> m_leafs; // Almacena las hojas dentro del Composite
};

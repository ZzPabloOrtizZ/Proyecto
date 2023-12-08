#pragma once
#include "Prerequisites.h"
using namespace std;

class
DocumentoPrototype {
public:
    virtual DocumentoPrototype* clone() = 0;
    virtual void config(string _value) = 0;
    virtual void show() = 0;
};

//Clase que concreta al prototipo (Texto)
class DocumentoTexto : public DocumentoPrototype {
public:
    DocumentoPrototype* clone() override {
    DocumentoTexto* copy = new DocumentoTexto();
    copy->config(m_value);
    return copy;
    }

    void config(string _value) override {
    m_value = _value;
    }

    void show() override {
    cout<<"Texto: "<<m_value<<endl;
    }

private:
    string m_value;
};

//Clase que concreta al prototipo (Imagen)
class DocumentoImagen : public DocumentoPrototype {
public:
    DocumentoPrototype* clone()  override {
    DocumentoImagen* copy = new DocumentoImagen();
    copy->config(m_value);
    return copy;
    }

    void config(string _value) override {
    m_value = _value;
    }

    void show() override {
    cout<<"Imagen: "<<m_value<<endl;
    }

private:
string m_value;
};
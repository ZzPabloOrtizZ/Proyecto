#pragma once
#include "Prerequisites.h"
using namespace std;

class Prototype
{
public:

  virtual Prototype* clone() = 0;
  virtual void configurar(string _value) = 0;
  virtual void print() = 0;

};

class PrototipoConcreto : public Prototype{

public:
  Prototype* clone()override {
  PrototipoConcreto* copy = new PrototipoConcreto();
  copy->configurar(m_value);
  return copy;
  }

  void configurar(string _value) override {
  m_value = _value;
  }

  void print()override {
  cout<<"value: "<<m_value<<endl;
  }

private:
string m_value;
};
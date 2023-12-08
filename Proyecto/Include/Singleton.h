#pragma once

class Singleton
{
public:
Singleton() : value(0) {};

static
Singleton*
getInstance() {
if (m_instance != nullptr) {
return m_instance;
}
else {
m_instance = new Singleton;
}
return m_instance;
}

~Singleton() = default;

//El valor de m_value
void
setValue(int _v) {
m_value = _v;
}

//Obtiene el valor de m_value
int
getValue() {
return value;
}
private:
int value;
static Singleton* m_instance;
};
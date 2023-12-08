#include <iostream>
#include <vector>
using namespace std;

class RegistroActividad {
public:
    static RegistroActividad* getInstance() {
        if (m_instance != nullptr) {
        return m_instance;
        }
        else {
        m_instance = new RegistroActividad;
        }
        return m_instance;
    }

    ~RegistroActividad() = default;

    void
    //Agregar el numero de actividades
    SetActivity(string m_act) {
    m_action.push_back(m_act);
    }

    void
    //Muestra el numero de actividades ingresadas
    GetActivity(){
    for (int i = 0; i < m_action.size(); i++) {
    cout<<"Actividad actual: "<<m_action[i]<<endl;
    }
    }

private:
    vector<string> m_action;
    static RegistroActividad* m_instance;
};
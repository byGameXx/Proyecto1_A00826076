#include <iostream>
#include<fstream>
#include <string>
using namespace std;
int a,b,c,d,e,f;
string plantilla, dato;
string info,cli,cuen,dir,sal,fec,emp;

void cliente1(string& linea, string old){
int posicion = info.find(old);
if(posicion!=-1){
cli = info.erase(posicion,info.find('>')+2);
}
}

void cuenta1(string& linea, string old){
int posicion = info.find(old);
if(posicion!=-1){
cuen = info.erase(posicion,info.find('>')+2);
}
}

void direccion1(string& linea, string old){
int posicion = info.find(old);
if(posicion!=-1){
dir = info.erase(posicion,info.find('>')+2);
}
}

void empresa1(string& linea, string old){
int posicion = info.find(old);
if(posicion!=-1){
emp = info.erase(posicion,info.find('>')+2);
}
}

void fecha1(string& linea, string old){
int posicion = info.find(old);
if(posicion!=-1){
fec = info.erase(posicion,info.find('>')+2);
}
}

void saldo1(string& linea, string old){
int posicion = info.find(old);
if(posicion!=-1){
sal = info.erase(posicion,info.find('>')+2);
}
}

void cliente(string& linea, string old, string nuevo){
int posicion = plantilla.find(old);
   while(posicion!=-1){
        plantilla.replace(posicion,old.size(),nuevo);
        posicion = plantilla.find(old, posicion + nuevo.size());
        }
}

void saldo(string& linea, string old, string nuevo){
int posicion = plantilla.find(old);
   while(posicion!=-1){
        plantilla.replace(posicion,old.size(),nuevo);
        posicion = plantilla.find(old, posicion + nuevo.size());
        }
}

void direccion(string& linea, string old, string nuevo){
int posicion = plantilla.find(old);
   while(posicion!=-1){
        plantilla.replace(posicion,old.size(),nuevo);
        posicion = plantilla.find(old, posicion + nuevo.size());
        }
}

void fecha(string& linea, string old, string nuevo){
int posicion = plantilla.find(old);
   while(posicion!=-1){
        plantilla.replace(posicion,old.size(),nuevo);
        posicion = plantilla.find(old, posicion + nuevo.size());
        }
}

void cuenta(string& linea, string old, string nuevo){
int posicion = plantilla.find(old);
   while(posicion!=-1){
        plantilla.replace(posicion,old.size(),nuevo);
        posicion = plantilla.find(old, posicion + nuevo.size());
        }
}

void empresa(string& linea, string old, string nuevo){
int posicion = plantilla.find(old);
   while(posicion!=-1){
        plantilla.replace(posicion,old.size(),nuevo);
        posicion = plantilla.find(old, posicion + nuevo.size());
        }
}


int main()
{   string nombre;
    ifstream plantillas, datos;
    ofstream documento;
    plantillas.open("plantilla.txt");
    datos.open("datos.txt");
    cout << "Por favor escriba el nombre deseado para el documento de texto (recuerda incluir .txt al final)" << endl;
    cin>>nombre;
    documento.open(nombre.c_str());

    while(getline(datos, info)){
        cliente1(info,"<cliente>");
        cuenta1(info,"<cuenta>");
        direccion1(info,"<direccion>");
        saldo1(info,"<saldo>");
        fecha1(info,"<fecha>");
        empresa1(info,"<empresa>");

  }

    while(getline(plantillas,plantilla)){
      cliente(plantilla, "<cliente>", cli);
      fecha(plantilla, "<fecha>", fec);
      direccion(plantilla, "<direccion>", dir);
      cuenta(plantilla, "<cuenta>", cuen);
      empresa(plantilla, "<empresa>", emp);
      saldo(plantilla, "<saldo>", sal);
      documento << plantilla << endl;
    }

    plantillas.close();
    datos.close();
    documento.close();
    return 0;
}

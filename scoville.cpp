#include <iostream>
using namespace std;


//------ Creacion de nodo y de arbol ------
enum comparacion{
    menorque,mayorque,igualque
};
enum colores{
    verde, rojo, amarillo, anaranjado
};

struct Tipo_chile{
    string nombre;
    int SHU;
    colores color; 
};
typedef struct Tipo_chile T;

struct Nodo{
    T info;
    struct Nodo *izq;
    struct Nodo *der;
};
typedef struct Nodo *Arbol;

Arbol crearArbol(T x);

//------ Agregar nodos a un arbol ------
void asignarIzq(Arbol a, T unDato);
void asignarDer(Arbol a, T unDato);
void agregarNodo(Arbol a);

//------ Recorrer un arbol (in, pre y post orden) ------
void preorden(Arbol a);
void inorden(Arbol a);
void postorden(Arbol a);
void mostrarDato(T);
Tipo_chile solicitarDato();

int main(){
    cout<<"Inicializando arbol...\n"
        <<"Agrega tu primer chile: "
        <<endl;

    Arbol arbol = crearArbol(solicitarDato());
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\nMenu de organizacion de chiles: \n";
        cout << "\t1) Agregar chile\n";
        cout << "\t2) Mostrar todos los chiles\n";
        cout << "\t3) Mostrar todos los chiles rojos\n";
        cout << "\t4) Mostrar todos los chiles con mas de 50000 SHU\n";
        cout << "\t5) Salir\n";
        cout << "\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: 
                    system("cls");
                    agregarNodo(arbol);
                    system("cls");
                        break;
            case 2: 
                    system("cls");
                    inorden(arbol); 
                        break;
            case 3: 
                    system("cls");
                    preorden(arbol);
                        break;
            case 4: 
                    system("cls");
                    postorden(arbol);
                        break;
            case 5: continuar = false; break;
            
            default: 
                    system("cls");
                    cout << "El chile que buscas no existe!" << endl;
                        break;
        }
    }while(continuar);
    
    return 0;
}

// Implementacion de funciones de arboles
Arbol crearArbol(T x){
    Arbol p = new Nodo;
    p->info = x;
    p->izq = NULL;
    p->der = NULL;
    return p;
}
//------ Agregar nodos a un arbol ------
void asignarIzq(Arbol a, T unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->izq != NULL)
        cout << "Error: subarbol IZQ ya existe" << endl;
    else
        a->izq = crearArbol(unDato);
}

void asignarDer(Arbol a, T unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->der != NULL)
        cout << "Error: subarbol DER ya existe" << endl;
    else
        a->der = crearArbol(unDato);
}

void agregarNodo(Arbol a){
    //solicitar informacion (dato a agregar)
    cout << "## Datos a agregar: "<<endl;
    T unDato = solicitarDato();
    
    Arbol p = a;
    
    //desplazarse hasta el lugar adecuado
    while(true){
        //if(comparar(unDato, igualque, p->info)){
        if((a->info).SHU == unDato.SHU){
            cout << "Error: dato ya existe!" << endl;
            return;
        }
        //else if(comparar(unDato, menorque, p->info)){//ir a la izquierda
        else if((a->info).SHU > unDato.SHU){//ir a la izquierda
            if(p->izq == NULL)
                break;
            else
                p = p->izq;
        }
        else{//ir a la derecha
            if(p->der == NULL)
                break;
            else
                p = p->der;
        }
    }
    
    //agregar el nuevo nodo
    if(unDato.SHU < (p->info).SHU)
        asignarIzq(p, unDato);
    else
        asignarDer(p, unDato);
}

//------ Recorrer un arbol (in, pre y post orden) ------
void preorden(Arbol a){
    if(a != NULL){
        cout << " "; 
        if((a->info).color == rojo){
            mostrarDato(a->info);
        }
        preorden(a->izq);
        preorden(a->der);
    }
}
void inorden(Arbol a){
    if(a != NULL){
        inorden(a->izq);
        cout << " "; mostrarDato(a->info);
        inorden(a->der);
    }
}
void postorden(Arbol a){
    if(a != NULL){
        postorden(a->izq);
        postorden(a->der);
        cout << " ";
        if((a->info).SHU > 50000){
            mostrarDato(a->info);
        }
    }
}

Tipo_chile solicitarDato(){
    Tipo_chile *hoja = new Tipo_chile;
    
    cin.ignore();
    cout << "Agrega el nombre del chile: ";
        getline(cin,hoja->nombre); 
    
    cout << "Agrega el SHU del chile: ";
        cin>>hoja->SHU;
    
    int option;
    bool salir = false;
    cout << "Agrega el color del chile: "<<endl;
    do{
        cout <<"1)Verde"<<endl;
        cout <<"2)Rojo"<<endl;
        cout <<"3)Amarillo"<<endl;
        cout <<"4)Anarajado"<<endl;
        cin>>option;
        switch (option)
        {
        case 1:
            hoja->color=verde;
            salir = true;
            break;
        case 2:
            hoja->color=rojo;
            salir = true;
            break;
        case 3:
            hoja->color=amarillo;
            salir = true;
            break;
        case 4:
            hoja->color=anaranjado;
            salir = true;
            break;
        
        default:
            break;
        } 
    }while(!salir);

    system("cls");
    return *hoja;
}

void mostrarDato(T unDato){
    cout << "# Nombre: "<< unDato.nombre<<endl;
    cout << "\t# SHU: "<< unDato.SHU<<endl;
   
    switch (unDato.color)
        {
        case verde:
            cout << "\t\t# Color: "<<"Verde";
            
            break;
        case rojo:
            cout << "\t\t# Color: "<<"Rojo";
            
            break;
        case amarillo:
            cout << "\t\t# Color: "<<"Amarillo";
            
            break;
        case anaranjado:
            cout << "\t\t# Color: "<<"Anaranjado";
            
            break;
        
        default:
            cout << "No reconozco ese color"<<endl;
            break;
        }
        cout << endl;
}


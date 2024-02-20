#include <iostream>
#include <vector>
using namespace std;

// Ordenamiento por insercion

void insercion(vector<int>&arreglo){
    for(int i = 1; i < arreglo.size(); i++){
        int j = i;
        int aux = arreglo[i];
        // Desplazamiento de elementos mayores hacia la derecha
        while(j > 0 && aux < arreglo[j-1]){
            arreglo[j] = arreglo[j-1];
            j--;
        }
        arreglo[j] = aux;
    }
}

// Ordenamiento por mezcla

void mezcla(vector<int>&arreglo,int inicio, int mitad, int final){
    int i,j,k;
    int elementosIzq = mitad - inicio + 1;
    int elementosDer = final - mitad;

    vector<int>izquierda(elementosIzq);
    vector<int>derecha(elementosDer);

    for(int i = 0; i < elementosIzq; i++){
        izquierda[i] = arreglo[inicio+i];
    }
    for(int j = 0; j < elementosDer; j++){
        derecha[j] = arreglo[mitad + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;

    while(i < elementosIzq && j < elementosDer){
        if(izquierda[i] <= derecha[j]){
            arreglo[k] = izquierda[i];
            i++;
        }else{
            arreglo[k] = derecha[j];
            j++;
        }
        k++;
    }

    while(j < elementosDer){
        arreglo[k] = derecha[j];
        j++;
        k++;
    }

    while(i < elementosIzq){
        arreglo[k] = izquierda[i];
        i++;
        k++;
    }

}

void mezclaMitades(vector<int>&arreglo,int inicio, int final){
    if(inicio < final){
        int mitad = inicio + (final - inicio)/2;
        mezclaMitades(arreglo,inicio,mitad);
        mezclaMitades(arreglo,mitad+1,final);
        mezcla(arreglo,inicio,mitad,final);
    }
}

void imprimirArreglo(vector<int>arreglo){
    for(int i = 0; i < arreglo.size(); i++){
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

int main(){
    vector <int> prueba1 = {10,5,7,1,6,64};
    vector <int> prueba2 = {10,5,7,1,6,64};

    std::cout<<endl;

    std::cout<< "Ordenamiento por insercion" << endl;
    imprimirArreglo(prueba1);
    insercion(prueba1);
    imprimirArreglo(prueba1);

    std::cout<<endl;

    std::cout<< "Ordenamiento por mezcla" << endl;
    imprimirArreglo(prueba2);
    mezclaMitades(prueba2,0,prueba2.size()-1);
    imprimirArreglo(prueba2);
}

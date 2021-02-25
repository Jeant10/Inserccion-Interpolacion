#include <iostream>
#include <fstream>
using namespace std;

void algoritmoInserccion(int a[], int n);

void algoritmoInterpolacion (int a[], int n);

void impirmirElementos(int a[], int n);
void impirmirElementos2(int a[], int n);


int main()
{

    int A[7]= {1,5,8,9,2,3,7};
  
    impirmirElementos2(A,7);
    cout<<"\n";
    algoritmoInserccion(A,7);
    cout<<"\n";
    impirmirElementos (A,7);
    cout<<"\n";
    algoritmoInterpolacion(A,7);


}
void impirmirElementos2(int a[], int n)
{    
    int i;
    float sum=0;
    ofstream archivo;
    archivo.open("Ordenamiento.txt",ios::app);
    for(int i=0; i<n; i++)
    {
       cout<<"|"<<a[i]<<"|";
       archivo<<"|"<<a[i]<<"|";
    }
    archivo<<"\n";
}

void impirmirElementos(int a[], int n)
{    
    int i;
    float sum=0;
    ofstream archivo;
    archivo.open("Ordenamiento.txt",ios::app);
    for(int i=0; i<n; i++)
    {
       cout<<"|"<<a[i]<<"|";
       archivo<<"|"<<a[i]<<"|";
       sum=sum+a[i];
    }
    archivo<<"\nLa suma:"<<sum;
    archivo<<"\nEl total del arreglo es:"<<n;
    cout<<"\nLa suma:"<<sum;
    cout<<"\nEl total del arreglo es:"<<n;
    archivo<<"\n";
}


void algoritmoInserccion(int a[], int n)
{
    int pos,aux;
    for(int i=0; i<n; i++)
    {
        pos=i;

        aux=a[i];

        while((pos>0)&&(a[pos-1]>aux))
        {
            a[pos] = a[pos-1];

            pos--;

        }

        a[pos]=aux;
    }
}


void algoritmoInterpolacion (int a[], int n)
{
    int primero = 0;

    int ultimo = n-1;

    int medio;

    int cont=0;

    int num=7;
    ofstream archivo2;
    archivo2.open("Almacenamiento.txt",ios::app);
    cout<<"El arreglo de elementos:";
    archivo2<<"El arreglo de elementos:";
    for(int i=0; i<n; i++)
    {
       cout<<"|"<<a[i]<<"|";
       archivo2<<"|"<<a[i]<<"|";
    }
    while(a[primero] != num && cont<=7 )
    {
        medio = primero + ((num - a[primero])*(ultimo-primero))/(a[ultimo]-a[primero]);
        if(a[medio]<num)
        {
            primero = medio +1;
        }
        else if(a[medio]>num)
        {
            ultimo = medio-1;
        }
        else
        {
            primero = medio;
        }
        cont++;
    }
    if(a[primero]==num)
    {
       
        cout<<"\nEl elemento a buscar:"<<num;
        cout<<"\nELEMENTO ENCONTRADO";
        cout<<"\nLa posicion del elemento:"<<a[primero];
        archivo2<<"\nEl elemento a buscar:"<<num;
        archivo2<<"\nELEMENTO ENCONTRADO";
        archivo2<<"\nLa posicion del elemento:"<<a[primero];
    }
    else
    {
        cout<<"ELEMENTO NO ENCONTRADO";
        archivo2<<"ELEMENTO NO ENCONTRADO";

    }
}





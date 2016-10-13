/*Autor: Natalia Hernandez
Funcion del programa: Calculadora de matrices
Fecha:05/10/2016*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <math.h>
#define L 5
#define d 4
#define largo 100
using namespace std;
//Mostrar menu
int menu();
void llenarMatriz(int[L][L], int orden);
void mostrarMatriz(int[L][L], int orden);
int determinanteMatriz(int[L][L], int orden);
int cofactor(int matriz[L][L], int orden, int fila, int columna);
void transpuestaMatriz (int [L][L], int [L][L], int orden);
void mostrarT (int [L][L], int orden);
void escalarMatriz (int [L][L], int orden);
int menuMatriz (int [L][L], int orden);
void producto (int [L][L],int, int orden);
int potenciaMatriz (int [L][L], int potencia, int orden);
void restarMatriz (int, int [L][L], int [L][L], int [L][L]);
void sumarMatriz(int, int [L][L], int [L][L], int [L][L]);
void multiplicarMatriz (int, int [L][L], int [L][L], int [L][L]);
void burbuja();
void insercion();
void seleccion();
void shell();
void quicksort(int A[],int izq, int der );
void leeCadena(int cant,int n[]);
void muestraCadena(int cant,int n[]);
void limpiarPantalla ();
//Funcion principal
int main ()
{
    system ("color");

    //Crear matriz
    int opcion = menu();

    return 0;
}
int menu(){
    int matriz [L][L];
    int orden;
    int escalar;
    int potencia;
    int T [L][L];
    int A[L][L];
    int B[L][L];
    int R[L][L];
    int M[L][L];
    int opcion;

    cout << "Ingresa el orden de la matriz (maximo " << L << "): ";
    cin >> orden;
    while (orden < 0 || orden > L) {
      cout << "\nEl orden de la matriz no puede ser mayor que " << L << endl;
      cout << "Ingrese nuevamente el orden de la matriz: ";
      cin >> orden;
      }

    do{

    cout << "Calcuadora de matrices" << endl;
    cout << "Marque una opcion de menu" << endl;
    cout << "1.Llenar matriz" << endl;
    cout << "2.Mostrar matriz" << endl;
    cout << "3.Determinante matriz" << endl;
    cout << "4.Traspuesta matriz" << endl;
    cout << "5.Multiplicar matriz Escalar" << endl;
    cout << "6.Potencia matriz" << endl;
    cout << "7.Matriz A + Matriz B" << endl;
    cout << "8.Matriz A - Matriz B" << endl;
    cout << "9.Matriz A * Matriz B" << endl;
    cout << "10.Metodos de Ordenamiento" << endl;
    cout << "11.Limpieza" << endl;
    cout << "0.Salir" << endl;
    cin >> opcion;


    }while(opcion>11 || opcion<1);
   switch(opcion){

       case 0: cout << "Programa finalizar" << endl;
            exit(0);
        break;
       case 1: cout << "Llenar matriz" << endl;
           llenarMatriz(matriz,orden);
           menu ();
       break;
       case 2: cout << "Mostrar matriz" << endl;
           mostrarMatriz(matriz,orden);
           menu ();
       break;
       case 3: cout << "Determinante matriz" << endl;
            llenarMatriz(matriz,orden);
            mostrarMatriz(matriz,orden);
            cout << determinanteMatriz(matriz,orden) << endl;
            menu();
       break;
       case 4: cout << "traspuestaMatriz" << endl;
            llenarMatriz(matriz,orden);
            transpuestaMatriz(matriz,T,orden);
            cout << "Matriz Original" << endl;
            mostrarMatriz(matriz,orden);
            cout << "Matriz transpuesta" <<  endl;
            mostrarT(T,orden);
            menu();
       break;
       case 5: cout << "escalarMatriz" << endl;
           llenarMatriz(matriz,orden);
           cout << "Ingrese el escalar de la matriz"<< endl;
           cin >> escalar;

           producto (matriz,escalar,orden);
           escalarMatriz(matriz,orden);
           menu();
       case 6: cout << "potenciaMatriz" << endl;
           potenciaMatriz(matriz,potencia,orden);
            menu();
       break;
       case 7: cout << "sumaMatriz" << endl;
           sumarMatriz(orden, A, B, R);
           menu();
       break;
       case 8: cout << "restaMatriz" << endl;
           restarMatriz(orden, A, B, R);
           menu();
       break;
       case 9: cout << "multipliMatriz" << endl;
           multiplicarMatriz(orden, A, B, M);
           menu();
       break;
       case 10:
           int x;
            cout<<"Metodos de ordenamiento";
            cout<<endl;
            cout<<endl;
            cout<<"1.-Ordenamiento por Metodo Burbuja";
            cout<<endl;
            cout<<"2.-Ordenamiento por Metodo Insercion";
            cout<<endl;
            cout<<"3.-Ordenamiento por Metodo Seleccion";
            cout<<endl;
            cout<<"4.-Ordenamiento por Metodo Shell";
            cout << endl;
            cout << "5.-Ordenamiento por Metodo QuickSort";
            cout<<endl;
            cout<<endl;
            cout<<"ELIGE UNA OPCION:";
            cin>>x;
            cout<<endl;
            cout<<endl;switch (x){
            case 1:burbuja();
            break;
            case 2:insercion();
            break;
            case 3:seleccion();
            break;
            case 4:shell();
            break;
            case 5:
                int A[largo],n;
                    do{
                        cout<<"Cantidad de numeros a ingresar: ";
                    cin>>n;
                        if(n<=0||n>largo)
                            cout<<"Debe ingresar un valor > a 0 y < a "<<largo<<endl;
                        }
                        while(n<=0||n>largo);
                            leeCadena(n,A);
                            quicksort(A,0,n-1);
                            muestraCadena(n,A);
            break;
            default: cout<<"ERROR EN LA SECCION";
        }
        menu();
       break;
       case 11:
           cout << "Limpiar" << endl;
            limpiarPantalla () ;
            menu ();
       break;
       default: cout << "Opcion no valida" << endl;

    }
    return opcion;


}
void llenarMatriz(int matriz[L][L],int orden){
    for (int j=0;j<orden;j++) {
        for (int i=0;i<orden;i++) {
               matriz [j][i]=  rand ()%100;
                cout << matriz [j][i]<< "\t";
    }
    cout << endl;
    }
    cout << endl << "Matriz llenada con exito" << endl << endl << endl;
}
void mostrarMatriz(int matriz[L][L],int orden){
    for (int j=0;j<orden;j++) {
        for (int i=0;i<orden;i++) {
               matriz [j][i]=  rand ()%100;

               cout << matriz [j][i]<< "\t";
        }
    cout << endl << endl;
    }

}
int determinanteMatriz(int matriz[L][L], int orden) {

    int det = 0;

   if (orden == 1) {
      det = matriz[0][0];
   } else {
      for (int j = 0; j < orden; j++) {
         det = det + matriz[0][j] * cofactor(matriz, orden, 0, j);
      }
   }

   return det;
}

 int cofactor(int matriz[L][L], int orden, int fila, int columna)
{
   int submatriz[L][L];
   int n = orden - 1;

   int x = 0;
   int y = 0;
   for (int i = 0; i < orden; i++) {
      for (int j = 0; j < orden; j++) {
         if (i != fila && j != columna) {
            submatriz[x][y] = matriz[i][j];
            y++;
            if (y >= n) {
               x++;
               y = 0;
            }
         }
      }
   }

   return pow(-1.0, fila + columna) * determinanteMatriz(submatriz, n);

}
void transpuestaMatriz(int matriz[L][L], int T[L][L],int orden){
    for(int j = 0; j < orden; j++){
        for(int i = 0; i < orden; i++){
            T[j][i] = matriz[i][j];

        }
    cout << endl;
    }

}
void mostrarT(int T[L][L],int orden){
    for(int j = 0; j < orden; j++){
        for(int i = 0; i < orden; i++){
            cout<<T[j][i] << "\t";
        }
        cout<<endl;
    }
}
int menuMatriz(int matriz[L][L], int orden){

int escalar;

    for (int i=0;i<orden;i++){
        for (int j=0;j<orden;j++){
            matriz[i][j]=rand()%100;
        }
    }
    cout << "Matriz" << endl;
    cout << endl;
    cout << "Cual es la escarla de la matriz" << endl;
    cin >> escalar;
        int Producto (int escalar,int matriz, int orden);
        cout << endl;
        int escalarMatriz  (int matriz, int orden);
    cout << endl;
}
void escalarMatriz(int matriz[L][L],int orden){
    for (int i=0;i<orden;i++){
        for (int j=0;j<orden;j++){
            cout << matriz [orden*(i+j)] << "\t";

        }
        cout << endl;
    }
}
void producto (int matriz[L][L],int escalar, int orden){
    int total= orden*orden;
        for (int i=0;i<total;i++){
            matriz[i][i]=escalar;
        }
        cout << endl;
}
int potenciaMatriz(int matriz[L][L], int potencia, int orden){
    cout << "Ingrese la pontencia" << endl;
           cin >> potencia;
    for (int j=0;j<orden;j++) {
        for (int i=0;i<orden;i++) {
               matriz [j][i]=  rand ()%100;
        }
        }
    for (int j=0;j<orden;j++) {
        for (int i=0;i<orden;i++) {
               cout << matriz [j][i]<< "\t";


    }
    cout << endl << endl;
    }
    for (int j=0;j<orden;j++) {
        for (int i=0;i<orden;i++) {
               matriz [j][i] = pow (matriz[j][i], potencia);
               cout << matriz [j][i] <<"\t";

        }
        cout << endl;
    }

}
void sumarMatriz(int orden,int A [L][L], int B [L][L], int R [L][L]){

    cout<<"llenar matriz A"<<endl;
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

           A[i][j]=rand ()%10;
        }
    }
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

          cout << A[i][j] << "\t";
        }
        cout << endl;
    }



    cout<<"llenar matriz B"<<endl;
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

             B[i][j]=rand ()%30;
        }
    }
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

           cout <<B[i][j] << "\t";
        }
        cout << endl;
    }
    for( int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){
            R[i][j]=A[i][j]+B[i][j];
        }
    }
    cout<<"el resultado de suma es"<<endl;
    for( int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){
            cout<<R[i][j]<<" \t";
        }
        cout<<endl;
    }
}
void restarMatriz(int orden,int A [L][L], int B [L][L], int R [L][L]){
    cout<<"llenar matriz A"<<endl;
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

           A[i][j]=rand ()%10;
        }
    }
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

          cout << A[i][j] << "\t";
        }
        cout << endl;
    }



    cout<<"llenar matriz B"<<endl;
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

             B[i][j]=rand ()%30;
        }
    }
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

           cout <<B[i][j] << "\t";
        }
        cout << endl;
    }
    for( int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){
            R[i][j]=A[i][j]-B[i][j];
        }
    }
    cout<<"el resultado de la resta es"<<endl;
    for( int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){
            cout<<R[i][j]<<" \t";
        }
        cout<<endl;
    }
}
void multiplicarMatriz(int orden,int A [L][L], int B [L][L], int M [L][L]){

    cout<<"llenar matriz A"<<endl;
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

           A[i][j]=rand ()%10;
        }
    }
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

          cout << A[i][j] << "\t";
        }
        cout << endl;
    }



    cout<<"llenar matriz B"<<endl;
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

             B[i][j]=rand ()%30;
        }
    }
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

           cout <<B[i][j] << "\t";
        }
        cout << endl;
    }
    for( int i=0;i<orden;i++){
        int N=0;
        for(int j=0;j<orden;j++){
            M[i][j]=(A[i][j]*B[j][N]+
                    A[i][j]*B[j][N]+
                    A[i][j]*B[j][N]);
                N+=1;
        }
    }
    cout<<"el resultado de multiplicacion es"<<endl;
    for( int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){
            cout<<M[i][j]<<" \t";
        }
        cout<<endl;
    }
}
void burbuja()
{
        char salir;
        int N,Aux,J,opcion;
        int V[10];
        int I;


        cout<<"¿Cuantos numeros va a ingresar al vector?, maximo 10:";
        cin>>N;
        for(I=0; I<N; I++){
            cout<<"Ingrese dato "<<I+1<<":";
            cin>>V[I];
        }
            for (I=0; I<N-1; I++){
                for (J=0; J<(N-1)-I; J++){
                    if (V[J]>V[J+1]){
                        Aux=V[J];
                        V[J]=V[J+1];
                        V[J+1]=Aux ;
                    }
                }
            }
        cout<<"Los numeros de forma ordenada son:";
            for(I=0; I<N; I++)
        cout<<endl<<V[I];
}




void insercion()
{
    int N,Aux,J,SW;
    int V[10];
    int I;
        cout<<"¿Cuantos numeros va a ingresar al vector?, maximo 10:";
        cin>>N;
            for(I=0; I<N; I++){
                cout<<"Ingrese dato "<<I+1<<":";
                cin>>V[I];
            }
            for (I=1; I<N;I++){
            Aux=V[I];
            J=I-1;
            SW=1;
            while (SW&&J>=0){
                if (Aux<V[J]){
                    V[J+1]=V[J];
                    J--;
                }else{
                SW=0;
                }
            }
            V[J+1]=Aux;
            }
    cout<<"Los numeros de forma ordenada son:";
    for(I=0; I<N; I++)
    cout<<endl<<V[I];
}




void seleccion()
{
    int J,I,N,K;
    int V[10];
    int Sw;
    int Aux;

    cout<<"¿Cuantos numeros va a ingresar al vector?, maximo 10:";
    cin>>N;
        for(I=0; I<N; I++){
            cout<<"Ingrese dato "<<I+1<<":";
            cin>>V[I];
        }
        for(I=0; I<N-1; I++){
            K=I;
            for (J=I+1; J<N; J++)
                if (V[J]<V[K])
                    K=J;
                    Aux=V[I];
                    V[I]=V[K];
                    V[K]=Aux;
        }
    cout<<"Los numeros de forma decrecciente son:";
    for(I=N-1; I>=0; I--)
    cout<<endl<<V[I];
}



void shell()
{
    int J,I,N,K,INC,TMP;
    int V[10];
    int Sw;
    int Aux;

        cout<<"¿Cuantos numeros va a ingresar al vector?, maximo 10:";
        cin>>N;
    for(I=0; I<N; I++){
        cout<<"Ingrese dato "<<I+1<<":";
        cin>>V[I];
    }
    INC=N/2;
    do {
            for(I=INC; I<N; I++){
            TMP=V[I];
            J=I-INC;
        while ((J>=0)&&(TMP<V[J])){
            V[J+INC]=V[J];
            J-=INC;
        }
            V[J+INC]=TMP;
            }
        INC/=2;
    }
    while(INC!=0);
    cout<<"Los numeros de forma decrecciente son:";
    for(I=0; I<N; I++)
    cout<<endl<<V[I];
}



void quicksort(int A[],int izq, int der )
{
    int i, j, x , aux;
    i = izq;
    j = der;
    x = A[ (izq + der) /2 ];
        do{
            while( (A[i] < x) && (j <= der) )
            {
                i++;
            }

            while( (x < A[j]) && (j > izq) )
            {
                j--;
            }

            if( i <= j )
            {
                aux = A[i]; A[i] = A[j]; A[j] = aux;
                i++;  j--;
            }

        }while( i <= j );

            if( izq < j )
                quicksort( A, izq, j );
            if( i < der )
                quicksort( A, i, der );
}


void leeCadena(int cant,int n[])
{
    int i;for(i=0;i<cant;i++)
    {
        cout<<"Ingresa numero "<<i+1<<": ";
        cin>>n[i];
        }
    }
void muestraCadena(int cant,int n[])
{
    int i;for(i=0;i<cant;i++)
{
cout<<n[i]<<endl;
}
}
void limpiarPantalla () {
    system ("cls");
}

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


void Valores(int n, float A[][10], float b[10], float xo[10]) //1. Ingresa los vlaores de los elementos de A,b, y xo
{
int i,j;

cout <<  "Ingresa la matriz A: " << endl; //Pide los elementos de la matriz A.
   for(i=0;i<n;i++){
       for (j=0;j<n;j++){
           cout << "Ingresa el elemento a" << i+1 << j+1 << " de la matriz A: " << endl;
           cin >> A[i][j];
       }
   }

cout << "Ingresa los elementos de b: " << endl; //Elementos del arreglo b
for(i=0;i<n;i++){
        cout << "Ingresa el elemento b" << i+1 << " de la matriz b: " << endl;
        cin >> b[i];
}

cout << "Ingresa los elementos de xo: " << endl; //Elementos del arreglo xo
for(i=0;i<n;i++){
        cout << "Ingresa el elemento x" << i+1 << " de la matriz xo: " << endl;
        cin >> xo[i];
      }
}


void Imprimir (float A[][10], int n) //Imprime matrices cuadradas
{
  int i,j;

   for(i=0;i<n;i++){
       cout << "|";
       for (j=0;j<n;j++){
           cout << " " << A[i][j] << " ";
       }
       cout << "|" << endl;
   }

}

void Imprimir2 (float M[10], int n) //Imprime arreglos de [1][n]
{
  int i,j;

   for(i=0;i<n;i++){
           cout << "| " << M[i]<< " |" <<endl;
     }
   }

void Suma (float A[][10], float B[][10], int n, float suma[][10]) //3. Funcion suma de dos matrices
{
  int i,j;
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      suma[i][j] = A[i][j] + B[i][j];
    }
  }
}

void RestaVect (float A[10], float B[10], int n, float resta[10]) //3. Funcion suma de dos matrices
{
  int i,j;
  for(i = 0; i < n; i++)
  {
      resta[i]= A[i] - B[i];
    }
  }

void Mult (float A[][10], float B[][10], int n, float mult[][10]) //4. funcion multiplicacion de dos matrices
{
int i,j,k;

for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
          mult[i][j]=0;
          for(int k=0;k<6;k++){
  mult[i][j]= mult[i][j]+ A[i][k] * B[k][j];
  }
  }
}
}

void MultVector (float A[][10], float b[10], int n, float multi[10]) //5. Mult matriz por vector
{
  int i,j,k;

  for(int i=0;i<n;i++){
    multi[i]=0;
    for(int j=0;j<n;j++){
    multi[i]= multi[i]+ A[i][j] * b[j];
    }
    }
}

void InversaD (float A[][10], float D[][10], int n){ //2. llena los elementos de la diagonal de D con 0, y los dem'as con 1/aij
  int i,j;
for(i=0;i<n;i++){
       for (j=0;j<n;j++){
         D[i][j]=0;
         if(j==i)
         D[i][j]=1.00/(A[i][j]);
           }
         }
       }

void MatrizL(float A[][10], float L[][10], int n) { //Saca la matriz L con la parte triangular inferior de A
  int i,j;
  for(i=0;i<n;i++){
         for (j=0;j<n;j++){
           L[i][j]=0;
             if (i>j)
             L[i][j]=A[i][j];
         }
       }
     }


void MatrizU(float A[][10], float U[][10], int n) { //Saca la matriz U con la parte triangular superior de A
  int i,j;
  for(i=0;i<n;i++){
         for (j=0;j<n;j++){
           U[i][j]=0;
             if (i<j)
             U[i][j]=A[i][j];
         }
       }
     }



int main (void)
{
     int n;
     float A[10][10], b[10], xo[10], x[10], D[10][10], L[10][10], U[10][10], T[10][10], R[10][10] ,C[10];

     cout << "Ingresa la dimensión N de la matriz cuadrada A: "<< endl; //Pide la dimension tanto de la matriz, como de los vectores
     cin>>n;
     Valores(n,A,b,xo);
     cout << "La Matriz A es: " <<": " << endl;
     Imprimir(A,n);
     cout << "b es : " <<": " << endl;
     Imprimir2(b,n);

     InversaD(A,D,n);
     cout << "La Matriz D es: " <<": " << endl;
     Imprimir(D,n);

     MatrizL(A,L,n);
     cout << "La Matriz L es: " <<": " << endl;
     Imprimir(L,n);

     MatrizU(A,U,n);
     cout << "La Matriz U es: " <<": " << endl;
     Imprimir(U,n);

     MultVector(D,b,n,C);
     cout << "El Vector C es: " <<": " << endl;
     Imprimir2(C,n);

     Suma(L,U,n,R);
     cout << "La Matriz R resultante de L+U es: " <<": " << endl;
     Imprimir(R,n);

     Mult(D,R,n,T);
     cout << "La Matriz T es: " <<": " << endl;
     Imprimir(T,n);



// Metodo de Jacobi, usando las operaciones anteriores

float restbr[10],resmult[10],res[10], multAx[10], Axbres[10], Axb[10], Ax[10], aux=0, B=100;
int i, I=100, contador;


  while (abs(aux-B)>0.0001)
  {
    contador++;
    for (i=0;i<n;i++)
    {
      x[i]=0;
      MultVector(R,xo,n,resmult);
      RestaVect(b,resmult,n,restbr);
      MultVector(D,restbr,n,res);
      x[i]=res[i];
      xo[i]=x[i];
      cout << x[i]<<endl;
    }

    B=0;
    aux=0;

    for (i=0;i<n;i++)
    {
      Axb[i]=0;
      MultVector(A,x,n,multAx);
      //RestaVect(multAx,b,n,Axbres);
    }
    Ax[i]= aux + multAx[i];
    B= B + b[i];
  }

  cout << "Tu vector solución es: "<< endl;
  for (i=0; i<n; i++)
  {
      cout << "| ";
      cout << x[i] << " ";
      cout << " |" << endl;
    }

cout << "Se hicieron " << contador << " iteraciones." << endl;


  return 0;
}

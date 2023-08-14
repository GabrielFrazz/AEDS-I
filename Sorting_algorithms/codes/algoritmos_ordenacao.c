# include <stdio.h>
# include <stdlib.h>

// Selecion Sort
void Selecao(int *A, int n){
  int i, j, Min;
  int x;
  for (i = 1; i <= n - 1; i++){
      Min = i;
      for (j = i + 1; j <= n; j++)
        if (A[j] < A[Min])
           Min = j;
      x = A[Min];
      A[Min] = A[i];
      A[i] = x;
  } 
}

// Insertion Sort algorithm
void Insercao(int *A, int n){
  int i, j;
  int x;
  for (i = 2; i <= n; i++){
      x = A[i];
      j = i - 1;
      A[0] = x;
      while (x < A[j]){
           A[j+1] = A[j];
           j--;
      } 
      A[j+1] = x;
    } 
} 

// Método da Bolha: borbulha os maiores elemento para o final do arranjo
void Bubblesort(TipoVetor A[], int n){
 TipoItem x;
 int i,j;
 for(i = 1; i < n; i++){
  for(j = n; j > i; j--){
     if(A[j].chave < A[j - 1].chave){
        x = A[j];
        A[j] = A[j - 1];
        A[j - 1] = x;
     }
  } 
 }
} 

// Método Shellsort: extensão do Inserção com a sequência h-ordenada
void Shellsort(TipoItem ∗A, TipoIndice n){
   int i , j ; int h = 1;
   TipoItem x;
   do{
      h = h ∗ 3 + 1;
   }while (h < n);
   do{
     h /= 3;
     for (i = h + 1; i <= n; i++){
        x = A[ i ] ;
        j = i ;
        while (A[ j − h] .Chave > x.Chave){
           A[ j ] = A[ j − h] ;
           j −= h;
           if ( j <= h)
              goto L999;
        }
        L999: A[ j ] = x;
     }
   } while (h != 1);
}

// Função recursiva para verificar as condições do heap
void MaxHeapify(TipoItem *A,int i, int n){
    TipoItem aux;
    int esq = 2*i;
    int dir = 2*i+1;
    int maior;
    if((A[i].Chave < A[esq].Chave) && (esq <= n) && esq >= 1){
        maior = esq;
    }else{
        maior = i;
    }
    if((A[maior].Chave < A[dir].Chave) && (dir <= n) && (dir >= 1)){
        maior=dir;
    }
    if(maior != i){
        aux = A[maior];
        A[maior] = A[i];
        A[i] = aux;
        MaxHeapify(A, maior, n);
    }
}

// Função para construir o heap
void BuildMaxHeap(TipoItem *A, int n){
    int i;
    for(i = n/2; i > 0; i--){
        MaxHeapify(A, i, n);
    }
}

// Método Heapsort
void HeapSort(TipoItem *A,int n){
    TipoItem aux;
    int tam = n;
    int i;
    BuildMaxHeap(A, n);
    for(i = 1; i <= n - 1; i++){
        aux = A[1];
        A[1] = A[tam];
        A[tam] = aux;
        tam--;
        MaxHeapify(A, 1, tam);
    }

}

void Merge(TipoItem *A, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].Chave <= R[j].Chave) {
            A[k] = L[i];
            i++;
        }else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

// Método Mergesort
void Mergesort(TipoItem *A,int l,int r){
    if(l >= r)
        return;
    int m = l + (r - l)/2;
    mergeSort(A, l, m);
    mergeSort(A, m + 1, r);
    merge(A, l, m, r);
}

// Função partição: realiza o particionamento do Quicksort
int Particao(TipoItem *A, int p, int r){
    TipoItem x;
    x = A[r];
    i = p - 1;
    for(j = p; j < r; j++){
        if (A[j].Chave <= x.Chave){
            i = i + 1;
            Aux = A[i];
            A[i] = A[j];
            A[j] = Aux;
        }
    }
    Aux = A[i + 1];
    A[i + 1] = A[r];
    A[r] = Aux;
    return i + 1;
}

// Método Quicksort: função recursiva que divida o vetor em duas metades
void Quicksort(TipoItem *A, int p, int r){
    if(p < r){
        q = Particao(A, p, r);
        Quicksort(A, p, q - 1);
        Quicksort(A, q + 1, r);
    }
}

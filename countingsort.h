#include <cstring>
/*
Só funciona para valores que podem ser mapeados para inteiros (por exemplo, se for
racional, que se possa transformar em inteiro multiplicando por uma potência de 10)
É linear se RANGE E O(n), se não O(n+k)
*/
 
// The main function that sort the given string arr[] in
// alphabetical order
void countsort(int arr[], int size, int RANGE) {
    // The output character array that will have sorted arr
    int output[size];

    // Create a count array to store count of individual
    // characters and initialize count array as 0
    int count[RANGE + 1];
    memset(count, 0, sizeof(count));

    // Store count of each character
    for (int i = 0; i < size; ++i)
        ++count[arr[i]];
 
    // Para garantir que repetições tenham
    // espaço suficiente reservado
    for (int i = 1; i <= RANGE; ++i) {
        count[i] += count[i - 1];
    }
 
    // Build the output character array
    // é decrescente para preservar a ordem
    // de elementos vistos como equivalentes
    // Ex: se o vetor tiver dois 0s, eles vão
    // continuar na mesma ordem
    for (int i = size-1; i > -1; --i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    
    // Copy the output array to arr, so that arr now
    // contains sorted characters
    for (int i = 0; i < size; ++i) {
        arr[i] = output[i];
    }
}

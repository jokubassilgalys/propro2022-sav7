#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*masyvo uzpildymas atsitiktiniais skaiciais intervalo ribose*/

void generateArray(int data[], int size, int low, int high)
{
    for(int i = 0; i < size; ++i){
        data[i] = (rand() % (high - low + 1)) + low;
        printf("%d ", data[i]);
    }
}

int main()
{
    int data[100], size, low, high;
    
    srand(time(NULL));
    generateArray(data, size, low, high);

    return 0;
}
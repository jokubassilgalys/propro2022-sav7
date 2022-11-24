#include <stdio.h>

/*funkcija patikrinti ar skaicius yra intervalo ribose*/

int isInRange(int number, int low, int high)
{
    if(number < low || number > high){
        return 0;
    }
    return 1;
}

int main()
{
    int number, low, high;

    printf("%d", isInRange(number, low, high));

    return 0;
}
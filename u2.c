#include <stdio.h>

/*funkcija apskaicuoti faktoriala*/

int getFactorial(int number)
{
    if (number >= 1){
        return number * getFactorial(number - 1);
    }
    else{
        return 1;
    }
}

int main()
{
    int number;
    
    if(number >= 0){
        printf("%d", getFactorial(number));
    }
    else{
        printf("0");
    }
    

    return 0;
}
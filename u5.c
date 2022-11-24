#include <stdio.h>

/*failo dydzio apsakiciavimo funkcija*/

long getFileSize(char *fileName)
{
    FILE *inputFile = fopen(fileName, "r");

    if(inputFile == 0){
        return -1;
    }
    
    fseek(inputFile, 0L, SEEK_END);

    long int size = ftell(inputFile);
    fclose(inputFile);

    return size;
}

int main()
{
    char *fileName;
    printf("%ld", getFileSize(fileName));

    return 0;
}
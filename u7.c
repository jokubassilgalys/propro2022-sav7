#include <stdio.h>
#include <unistd.h>

/*funkcijos faile saugomiems skaičiams apdoroti*/

int getValue(FILE *file, int index)
{
    int number = 5;

    fseek(file, index, SEEK_SET);

    fscanf(file, "%d", &number);

    return number;
}

void setValue(int value, FILE *file, int index)
{
    fseek(file, index, SEEK_SET);

    fprintf(file, "%d", value);

    return;
}

void addValue(int value, FILE *file, int index, long fileSize)
{
    char append[sizeof(char) * fileSize-index];
    int n = 0;

    fseek(file, index, SEEK_SET);
    if(file != 0){
        do{
            append[n] = fgetc(file);
            ++n;
        }
        while(append[n-1] != EOF);
    }
    
    setValue(value, file, index);

    for(int i = 0; i < n-1; ++i){
        fprintf(file, "%c", append[i]);
    }

    return;
}

void remValue(int value, FILE *file, int index, long fileSize)
{
    char append[sizeof(char) * fileSize-index];
    int n = 0;

    fseek(file, index+1, SEEK_SET);
    if(file != 0){
        do{
            append[n] = fgetc(file);
            ++n;
        }
        while(append[n-1] != EOF);
    }

    fseek(file, index, SEEK_SET);
    for(int i = 0; i < n-1; ++i){
        fprintf(file, "%c", append[i]);
    }
    ftruncate(fileno(file), fileSize-1);

    return;
}

long getFileSize(FILE *file, int index)
{
    if(file == 0){
        return -1;
    }
    
    fseek(file, 0L, SEEK_END);

    long int size = ftell(file);

    return size;
}

int main()
{
    int index, value;
    //FILE *file = fopen("input.txt", "r+");

    long fileSize = getFileSize(file, index);

    if(fileSize != -1){ 
        printf("%d", getValue(file, index));

        setValue(value, file, index);

        addValue(value, file, index, fileSize);

        remValue(value, file, index, fileSize);
    }
    else {
        fclose(file);
        return -1;
    }

    fclose(file);
    return 0;
}
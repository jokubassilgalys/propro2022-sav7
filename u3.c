#include <stdio.h>

/*fukcija nuskaityti teigiamo skaiciaus vartotojo ivesti*/

int getPositiveNumber(char *msg)
{
    int ats;
    printf("%s\n", msg);

    if(scanf("%d", &ats) == 1 && ats > 0){
        return ats;
    }
    else {
        int ch;
        do{
            ch = getchar();
        }
        while (ch != EOF && ch != '\n');

        getPositiveNumber(msg);
    }
}

int main()
{
    char *msg;
    printf("%d", getPositiveNumber(msg));


    return 0;
}
#include <stdio.h>

/*pasirinkimu menu spausdinimo funkcija*/

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg)
{
    int number;

    printf("%s\n", menuTitle);

    for(int i = 0; i < 4; ++i){
        printf("%s\n", menuOptions[i]);
    }

    printf("%s\n", inputMsg);

    if(scanf("%d", &number) != 1){
            int ch;
            do{
                ch = getchar();
            }
            while (ch != EOF && ch != '\n');
    }

    if(number < menuSize && number >= 1){
        return number;
    }
    else{
        showMenu(menuTitle, menuOptions,  menuSize,  inputMsg);
    }
}

int main()
{
    char *menuTitle, *menuOptions[4], *inputMsg;
    int menuSize = 4;

    printf("%d", showMenu(menuTitle, menuOptions,  menuSize,  inputMsg));
    
    return 0;
}
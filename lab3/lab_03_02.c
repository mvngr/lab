#include<stdio.h>
#include<string.h>

int main()
{
    char str1[7];
    str1[0] = 'W';
    str1[1] = 'o';
    str1[2] = 'r';
    str1[3] = 'l';
    str1[4] = 'd';
    str1[5] = '!';
    
    printf("%s \n", str1);
    
    char str2[20] = "Hello, ";
    printf("%s", str2);
    
    char str3[7];
    strcpy(str3,str1);
    printf("%s \n", str3);

    if(strcmp(str1, str3) == 0)
        printf("str1 = str3\n");
        else
        printf("str1 != str3\n");
    
    strcat(str2,str1);
    printf("%s \n", str2);

    for (int i = 0; i < strlen(str2); i++)
    printf("%c", str2[i]);
    
    printf("\n");
    
    char s1[30] = "Good morning, ", s2[30] = "Good evening, ";
    int compared = strcmp(s1,s2);
    printf("%d\n", compared);
    
    char name[7] = "Mikhail";
    strcat(s1, name);
    
    for (int i = 0; i < strlen(s1); i++)
        printf("%c", s1[i]);
        
    printf("\n");
    
    strncat(s2, name, 2);
    
    for (int i = 0; i < strlen(s2); i++){
        printf("%c", s2[i]);
    }
    
    for (int i = 0; i < strlen(str1); i++)
         if (str1[i] == 'r')
            printf("\n\nIndex r: %d\n", i);
        
    char str4[200] = "strofafka1;stroka2;strofsfska3;stroka4;"; //Люблю тебя, Петра творенье; Люблю твой строгий, стройный вид; Невы державное теченье; Береговой ее гранит.
    char sArr[4][50];
    
    for (int i = 0; i< 4; i++)
        for(int j=0; j<50; j++)
        sArr[i][j]=NULL;
    
    int col = 0, st_ind = 0;
    
    for (int i = 0; i < strlen(str4); i++){
        if (str4[i] == ';'){
            int temp = 0;
            for (int j = st_ind; j < i; j++){
                sArr[col][temp] = str4[j];
                temp++;
            }
            st_ind = i+1;
            col++;
        }
            
    }
    printf("\n\n");
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 50; j++)
            printf("%c", sArr[i][j]);
        printf(" - конец %d\n", i);
    }
    
    
    return 0;
}
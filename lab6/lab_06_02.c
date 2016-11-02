#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    FILE *fileIn;
    FILE *fileOut;
    int col,row;
    
    int i, j;
    
double power(int num)
{
    int cpyNum = num;
    double res = 1;
    while (cpyNum > 0)
    {
        res *= 0.1;
        cpyNum /= 10;
    }
    return num*res;
}
double ** createArray(char *link)
{
    double **arr;
    fileIn = fopen(link, "r");
    if (!fileIn)
        printf("AHTUNG!");
        else
        {
            int i=0;
            int ch;
            ch = fgetc(fileIn);
            
            char tmp[10];
            for(i = 0; i < 10; i ++)
                tmp[i] = 0;
            i=0;
            while (ch!=',')
            {
                tmp[i]=ch;
                ch = fgetc(fileIn);
                i++;
            }
            col = atoi(tmp);
            
            for(i = 0; i < 10; i ++)
                tmp[i] = 0;
            
            ch = fgetc(fileIn);
            i= 0;
            while (ch!='\n')
            {
                tmp[i]=ch;
                ch = fgetc(fileIn);
                i++;
            }
            row = atoi(tmp);
            
            printf("%d   %d\n", col, row);
            
            
            arr = (double **)malloc(col * sizeof(double*));
            
            for (i = 0; i < col; i++)
                arr[i]=(double *)malloc(row*sizeof(double));
                
            char temp[10]; 
            int changeTempTmp; //0 - целая часть, 1 - дробная
            for (i = 0; i < col; i++){
                for (j = 0; j < row; j++)
                {
                    changeTempTmp = 0;
                    int m;
                    for(m = 0; m < 10; m ++){ //чистим
                        tmp[m] = 0; //целая часть
                        temp[m] = 0; //дробная часть
                    }
                        
                    ch = fgetc(fileIn); //первый символ
                    int f = 0;
                    while (ch!=',' && ch!='\n' && !feof(fileIn))
                    {
                        
                        // printf("%c ", ch);
                        if (ch == '.'){
                            changeTempTmp = 1;
                            f = 0;
                        }
                        else{
                            if (changeTempTmp == 0)//смотрим записывать в целую часть или дробную
                                tmp[f]=ch;
                                else
                                temp[f] = ch;
                            f++;
                        }
                        
                        ch = fgetc(fileIn);
                            
                            
                    }
                    int bbb = atoi(tmp);
                    bbb = atoi(temp);
                    printf(" %d,%d) ", i, j);
                    arr[i][j] = (double)(atoi(tmp) + power(atoi(temp)));
                    printf("%lf ", arr[i][j]);
                    
                    if(ch == ',')
                        ch = fgetc(fileIn); //пропускаем пробел после ,
                }
                printf("\n");
            }
        }
    
    fclose(fileIn);
    return arr;
}

int createCSV(double ** arr)
{
    fileOut = fopen("lab_06_f01.csv", "w");
    if (!fileOut){ 
        printf("AHTUNG!!1");}
    else{
        fprintf(fileOut, "%d, ", col);
        fprintf(fileOut, "%d\n", row);
        for (i = 0; i < col; i++){
            for (j = 0; j < row; j++)
                if(j != row-1)
                    fprintf(fileOut,"%lf, ",arr[i][j]);
                    else
                    fprintf(fileOut,"%lf",arr[i][j]);
            fprintf(fileOut, "\n");
        }
    }
        
    fclose(fileOut);
    return 0;
}
void greetMe(char * link, char * name)
{
    fileIn = fopen(link, "r");
    
    char tmp[150] = "";
    int index;
    
    if (!fileIn)
        printf("AHTUNG!");
    else{
        int ch;
        i = 0;
        ch = fgetc(fileIn);
        while (!feof(fileIn))
        {
            if (ch != '_'){
                tmp[i] = ch;
                i++;
            }
            else
                index = i;
            
            ch = fgetc(fileIn);
            
            
            /*if (ch == '_'){
            int _for;
            for (_for = 0; _for < strlen(name); _for++)
                fputc(name[_for], fileIn);
            }
            ch = fgetc(fileIn);*/
        }
    }
    fclose(fileIn);
    
    fileOut = fopen(link, "w");
    
    if (!fileOut){ 
        printf("AHTUNG!!1");}
    else{
        for (i = 0; i < index; i++)
            fprintf(fileOut, "%c", tmp[i]);
        for (i = 0; i < strlen(name); i++)
            fprintf(fileOut, "%c", name[i]);
        for (i = index; i < strlen(tmp); i++)
            fprintf(fileOut, "%c", tmp[i]);
    }
    
    fclose(fileOut);
    return;
}
void copy(char * file1, char * file2)
{
    FILE *f1 = fopen(file2, "w");
    FILE *f2 = fopen(file1, "r");
    int c;
    
    if (!f1) 
        printf("AHTUNG..");
    else{
        c = fgetc(f2);
        while (!feof(f2)){
        fputc(c,f1);
        c = fgetc(f2);
        }
    }
    fclose(f1);
    fclose(f2);
}
void deleteFile(char * file)
{
    printf("Delete it?");
    char answer[10];
    gets(answer);
    if (answer[0] == 'y'){
        if(remove(file) != 0)
            printf("AHTUNG");
    }
}
int main()
{
    createCSV( createArray("lab_06_f01.txt"));
        
    char name[20] = "";
    printf("Input your name: ");
    gets(name);
    greetMe("lab_06_f02.txt", name);
    copy("lab_06_f02.txt", "lab_06_f03.txt"); 
    deleteFile("lab_06_f02.txt");
    return 0;
}
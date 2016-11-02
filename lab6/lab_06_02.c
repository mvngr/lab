#include <stdio.h>
#include <string.h>

    FILE *fileIn;
    FILE *fileOut;
    
void main() {
    
    int i,c;
    
    char read[20];
    fileIn = fopen("file_in.txt", "r");
    if (!fileIn) 
        printf("Error!");
    else{
        i = 0;
        c = fgetc(fileIn);
        while (!feof(fileIn)) {
            read[i] = c;
            c = fgetc(fileIn);
            i++;
        }
    }
    printf("%s \n",read);
    fclose(fileIn);
    
    fileOut = fopen("file_out.txt", "w");
    if (!fileOut) printf("Error!");
    else{
    fputs("Числа, кратные трем:\n",fileOut);
    for (i = 0; i < 15; i++) {
    fprintf(fileOut,"%d\n",i);
    }
    }
    fclose(fileOut);
    
    char *oldName = "file_in.txt",
    *newName = "fileIn.txt";
    if(rename(oldName, newName) == 0) {
    printf("%s был переименован %s.\n", oldName, newName);
    }
    else {
    printf("Ошибка переименования. %s \n", oldName);
    }
    // копирование файла (file2 -> file1)
    char *file1 = "file_in.txt",
    *file2 = "fileIn.txt";
    FILE *f1 = fopen(file1, "a");
    FILE *f2 = fopen(file2, "r");
    if (!f1) printf("Ошибка чтения файла");
    else{
    c = fgetc(f2);
    while (!feof(f2)) {
    fputc(c,f1);
    c = fgetc(f2);
    }
    printf("Данные %s были скопированы в %s\n",file2,file1);
    }
    fclose(f1);
    fclose(f2);
    // удаление файла
    char *filename = "fileIn.txt";
    if(remove(filename) == 0) {
    printf("Файл '%s' был удален.\n", filename);
    }
    else {
    printf("Ошибка удаления %s\n", filename);
    }
}

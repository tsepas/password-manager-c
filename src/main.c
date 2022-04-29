/*
  ATHANASIOS TSEPAS - ict21111
  --EIMAI TO PERIEGO PAIDI--
*/
#include "../h/pass.h"

struct entry{
    char title[MAX_TITLE];
    char password[MAX_PASSWORD];
    char username[MAX_USERNAME];
    char cat[20];
    char crypted[MAX_PASSWORD];
};

typedef struct entry entry;

/*
TODO:
1.ORA STIS EGGRAFES - OK
2.kryptografhsh kodikou kata thn eggrafh - OK
3.apokritpografisi -
4. ANAZITISI -
*/

int main(void){
    short int choice;
    /*Check the choice*/

    do{
        printf("------Welcome to password manager!-----\n");
        printf("1.Add a new password\n");
        printf("2.Open a password\n");
        printf("3.Delete a password\n");
        printf("4.Display sites\n");
        printf("5.Display categories\n");
        printf("6.About manager\n");
        scanf("%hd", &choice);

        if (choice < 1 || choice > 7){
            printf("\n\n");
            printf("Oops! Enter a valid choice!\n");
        }

    } while (choice < 1 || choice > 5);
    /*Controller*/
    switch (choice){
    case 1:
        add_pass();
        break;
    case 2:
        open_pass();
        break;
    case 3:
        delete_pass();
        break;
    case 4:
        display_pass();
        break;
    }

    return 0;
}

int add_pass(){
    entry rec;

    printf("Enter the reference:\n");
    scanf("%s", &rec.title);

    printf("Enter your username:\n");
    scanf("%s", &rec.username);

    printf("Enter the password:\n");
    scanf("%s", &rec.password);

    printf("Enter category:\n");
    scanf("%s", &rec.cat);

    FILE *fp;
    fp = fopen("./src/vault.txt", "a"); // open file

    /*If file doesn't exist!*/
    if (fp == NULL){
        printf("Oops!Failed to open file.\n");
        return -7;
    }
    /*If file found*/
    else{
        /*From time.h Documentation to get time of the system*/
        struct tm *ptr;
        time_t t;
        t = time(NULL);
        ptr = gmtime(&t);
        /*-----Crypt password-------*/
        for (int i = 0; i < strlen(rec.password); i++){
            rec.crypted[i] = rec.password[i] ^ 'P'; // p = XOR Key
        }
        /*------Write to file--------*/
        printf("Your password has been encrypted and saved into ./src/vault.txt\n");
        fprintf(fp, "--------\n%s\n%s\n%s\n%s\n%s", rec.title, rec.username, rec.crypted, rec.cat, asctime(ptr));
        fclose(fp);
        exit(0);
    }
}

int open_pass(){
    /*Open file*/
    FILE *fp;
    fp = fopen("./src/vault.txt", "r"); // READ FILE (R)
    /*If file not found*/
    if (fp == NULL){
        printf("Oops!File doesn't exist!\n");
        exit(1);
    }
    /*File found!*/
    else{
        /*Get file size*/
        fseek(fp, 0, SEEK_END);    // seek to end of file
        int FILE_SIZE = ftell(fp); // get current file pointer
        fseek(fp, 0, SEEK_SET);    // seek back to beginning of file
        /*Start with declare some variables*/
        entry rec;
        int res;
        char input_ref[MAX_TITLE]; // INPUT TO SEARCH

        printf("Enter the reference:\n");
        scanf("%s", &input_ref);
        /*--Search the reference--*/
        /*Checκ the title of entry in the file*/
        for (int i = 0; i < FILE_SIZE; i++){
            fscanf(fp, "%s", &rec.title);
            res = strcmp(input_ref, rec.title);
            if (res == 0){
                fscanf(fp, "%s\n%s\n%s", &rec.username, &rec.crypted, &rec.cat);
                break;
            }
        }
        // If reference exist strcmp == 0
        if (res == 0){
            printf("----The reference you have entered found!----\n");
            /*Decrypt password*/
            for (int i = 0; i < strlen(rec.crypted); i++){
                rec.password[i] = rec.crypted[i] ^ 'P'; // p = XOR Key
            }
            printf("Username: %s\nPassword: %s\nCategory: %s\n", rec.username, rec.password, rec.cat);
        }
        else{
            printf("Not Found\n");
        }
        fclose(fp);
    }
}

int delete_pass(){
    FILE *fp;
    fp = fopen("./src/vault.txt", "r");

    if (fp == NULL){
        printf("Oops!Something went wrong!\n");
        return -7;
    }
    else{
         /*Get file size*/
        fseek(fp, 0, SEEK_END);    // seek to end of file
        int FILE_SIZE = ftell(fp); // get current file pointer
        fseek(fp, 0, SEEK_SET);    // seek back to beginning of file
        /*Start with declare some variables*/
        entry rec;
        int res;
        char input_ref[MAX_TITLE]; // INPUT TO SEARCH

        printf("Enter the reference:\n");
        scanf("%s", &input_ref);
        /*--Search the reference--*/
        /*Checκ the title of entry in the file*/
        for (int i = 0; i < FILE_SIZE; i++){
            fscanf(fp, "%s", &rec.title);
            res = strcmp(input_ref, rec.title);
            if (res == 0){
                fscanf(fp, "%s\n%s\n%s", &rec.username, &rec.crypted, &rec.cat);
                break;
            }
        }
        // If reference exist strcmp == 0
        
        fclose(fp);
    }
}

int display_pass(){
    FILE *fp;
    fp = fopen("./src/vault.txt", "r");

    if (fp == NULL){
        printf("Oops!Something went wrong!\n");
        return -7;
    }
    else{

        fclose(fp);
    }
}
/*
  ATHANASIOS TSEPAS - ict21111
  NIKOLAOS ZAGKOTSIS - ict 21055
*/
#include "../h/pass.h"

/*
TODO:
1.ORA STIS EGGRAFES
2.kryptografhsh kodikou kata thn eggrafh
3.apokritpografisi
4...
*/
int main(int argc, char const *argv[]){
    int choice; 
    /*Check the choice*/
    
    do{
        printf("------Welcome to password manager!-----\n");
        printf("1.Add a new password\n");
        printf("2.Open a password\n");
        printf("3.Delete a password\n");
        printf("4.Display sites\n");
        printf("5.Display categories\n");
        printf("6.About manager\n");
        scanf("%d",&choice); 

        if(choice < 1 || choice > 7 ){
            printf("\n\n");
            printf("Oops! Enter a valid choice!\n");
        }

    }while(choice < 1 || choice > 5 );
    /*Controller*/
    switch(choice){
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
    char  website[100],password[100],username[100],cat[20],crypted[100];

    printf("Enter the reference:\n");
    scanf("%s",&website);

    printf("Enter your username:\n");
    scanf("%s",&username);

    printf("Enter the password:\n");    
    scanf("%s",&password);

    printf("Enter category:\n");
    scanf("%s",&cat);

    FILE *fp;
    fp = fopen("./src/vault.txt","a"); //open file

    /*If file doesn't exist!*/
    if(fp == NULL){
        printf("Oops!Failed to open file.\n");
        return -7;
    }
    /*If file found*/
    else{
        /*From time.h Documentation to get time of the system*/
        struct tm* ptr;
        time_t t;
        t = time(NULL);
        ptr = gmtime(&t);
        /*-----Crypt password-------*/
        for (int i = 0; i < strlen(password); i++){
            crypted[i] = password[i] ^ 'P'; // p = XOR Key
        }               
        /*------Write to file--------*/
        printf("Your password has been encrypted and saved into ./src/vault.txt\n");
        fprintf(fp,"--------\nReference:%s\nUsername:%s\nPassword:%s\nCategory:%s\nDate:%s",website,username,crypted,cat, asctime(ptr));
        fclose(fp);
        exit(0);
    }
}

int open_pass(){
    /*Open file*/
    FILE *fp; 
    fp = fopen("./src/vault.txt","r"); //READ FILE (R)
    /*If file not found*/
    if(fp == NULL){
        printf("Oops!Something went wrong!\n");
        return -7;
    }
    /*File found!*/
    else{
        char ref[100];
        printf("Enter the reference:\n");
        scanf("%s",&ref);
        /*--Search the reference--*/
        

        fclose(fp); 
    }
}

int delete_pass(){
    FILE *fp; 
    fp = fopen("./src/vault.txt","r"); 

    if(fp == NULL){
        printf("Oops!Something went wrong!\n");
        return -7;
    }
    else{

        fclose(fp); 
    }
}

int display_pass(){
    FILE *fp; 
    fp = fopen("./src/vault.txt","r"); 

    if(fp == NULL){
        printf("Oops!Something went wrong!\n");
        return -7;
    }
    else{

        fclose(fp); 
    }
}
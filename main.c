
#include<stdlib.h>
#include<stdio.h>

// function to create seats

int main(){

printf("Welcome to Airline Database Management System \n");
printf("1) Create Databases \n");
printf("2) Open Databases  \n");
printf("3) Remove Databases \n");

char option;
option = getchar();


// create database
if(option == '1'){
printf("Create database \n");


int row =0;
printf("Enter number of rows in your plane \n");
scanf(" %d" , &row);
int col = 5;

int  Rseats[row];
char  Cseats[5] = {'A', 'B' , 'C', 'D'};


// Creates table here
for(int i=0; i<row; i++){
int go = i+1;
Rseats[i] = go;
}

//View table
for(int k=0; k<row; k++){
printf(" %i " , Rseats[k]);
for(int l=0; l<col; l++){
printf(" %c " , Cseats[l]);
}
printf(" \n");
}

printf("Database Created Sucessfully\n");
printf("Enter unique name for this datbase \n");
char databaseName[100];
scanf(" %s" , databaseName);
puts(databaseName);
FILE *fp;

fp = fopen("db", "a");
fprintf(fp , "%s" , databaseName);

for(int ck=0; ck<row; ck++){
fprintf(fp , "%i " , Rseats[ck]);
for(int cl=0; cl<col; cl++){
fprintf( fp , "%c" , Cseats[cl]);
}
}


}



// open database
else if(option =='2'){
printf("Select Database you want to open \n");
}


// delete database
else if (option == '3'){
  printf("Select Database you want to remove \n");
}

else{
  printf("Invalid Input \n");
}



return 0;
}






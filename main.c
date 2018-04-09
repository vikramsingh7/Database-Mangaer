
#include<stdlib.h>
#include<stdio.h>

// function to create seats

int main(){

printf("Welcome to Airline Database Management System \n");
printf("1) Create Databases \n");
printf("2) Open Databases  \n");
printf("3) Remove Databases \n");
printf("4) Create Archive \n");
char option;
option = getchar();


// create database
if(option == '1'){
printf("Create database \n");


int row =0;
printf("Enter number of rows in your plane \n");
scanf(" %d" , &row);
int col = 5;
int charGoing = 0;



    //character being sent
      charGoing = 6*row;



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
  

  FILE *fp; //table file
  FILE *mfp; //metadata file
  fp = fopen("db", "a");//table file
  mfp = fopen("metaData", "a"); //metadata file

  
  //tablename being sent here
  fprintf(mfp , "%s" , databaseName);
  fputs(":" , mfp);
  fprintf(mfp , "%d" , charGoing);
  fprintf(mfp, "%s" , " ");


  //table being sent here
  for(int ck=0; ck<row; ck++){
  fprintf(fp , "%i" , Rseats[ck]);
  for(int cl=0; cl<col; cl++){
  fprintf( fp , "%c" , Cseats[cl]);
  }
  fputs(" ",fp);
   }
fputs(":", fp);
  fclose(fp);
  fclose(mfp);
}



// open database
else if(option =='2'){
 FILE *meta;
if(( meta = fopen("metaData" , "r+") ) == NULL){
printf("File Is Missing. Find it \n");
exit(1);
}

int sizeBN;

// GETS EXACT size to be used
fseek(meta, 0L, SEEK_END);
sizeBN = ftell(meta);
rewind(meta);
char bufferName[sizeBN];

printf("Select Database you want to open \n");
printf("Following are the available databases in system \n");


 fgets(bufferName, sizeBN , meta);
 

//extract alog

 int tt =0;
 for(int ba=0; ba<sizeBN; ba++){
  if(bufferName[ba]==':'){
  tt = ba;
  
 }

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






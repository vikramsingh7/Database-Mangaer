#include<string.h>
#include<stdlib.h>
#include<stdio.h>



int  getSubString(char *source, char *target,int from, int to)
{
        int length=0;
        int i=0,j=0;

        //get length
        while(source[i++]!='\0')
                length++;

        if(from<0 || from>length){
                printf("Invalid \'from\' index\n");
                return 1;
        }
        if(to>length){
                printf("Invalid \'to\' index\n");
                return 1;
        }

        for(i=from,j=0;i<=to;i++,j++){
                target[j]=source[i];
        }

        //assign NULL at the end of string
        target[j]='\0';

        return 0;
}
//The above function is taken from a website for the functionality to extract a substring from a string
//Link: //http://www.includehelp.com/c-programs/extract-a-portion-of-string-substring-extracting.aspx


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
  fprintf(fp , "%s;" , databaseName);
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

// Creates a buffer to load a file content that has the name of all the databases.
char bufferName[sizeBN];

printf("Select Database you want to open \n");
printf("Following are the available databases in system \n");

 fgets(bufferName, sizeBN , meta);
 
//extract alog0
char subStr[100];

 int fs =0;
 int ls =0;
 
         for(int ba=0; ba<sizeBN; ba++){
         if(bufferName[ba]==':'){
         ls = ba;
         getSubString(bufferName, subStr,fs, ls-1);
         printf("--%s \n" ,subStr);
         }
         else if(bufferName[ba]==' '){
         fs = ba+1;
         }
         }


 // Grabbing number of chars in database
       printf("Enter name of database to open: ");
       char nameEntered[100];
       scanf(" %s" , nameEntered);
       int cmp = -1;
       char sizeOfD[10];
       
         
  
         for(int bba=0; bba<sizeBN; bba++){
         if(bufferName[bba]==':'){
         ls = bba;
         getSubString(bufferName, subStr,fs, ls-1);
         cmp = strcmp(subStr, nameEntered);
         if(cmp == 0){
          for(int baa=ls+1; baa<sizeBN; baa++){
              if(bufferName[baa]==' '){
                     getSubString(bufferName, sizeOfD, bba+1, baa-1);
                     //Gets Extracted
                                      }
                                             }
                     }
                                  }

         else if(bufferName[bba]==' '){
         fs =bba+1;
                                      }
                                            }




  // LOAD TABLE HERE          NEED ALGO 
    
  

   }// section ends











// delete database
else if (option == '3'){
  printf("Select Database you want to remove \n");
}

else{
  printf("Invalid Input \n");
}



return 0;
}






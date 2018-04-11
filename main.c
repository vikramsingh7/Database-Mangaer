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
  fprintf(mfp, "%s" , ";");


  //table being sent here
 
fprintf(fp, "%s" ," ");
fprintf(fp , "%s" , databaseName);
 fprintf(fp , "%s" , ";");
for(int ra=0; ra<row; ra++){
fprintf(fp, "%i" , Rseats[ra]);
fputs(Cseats ,fp );
}
fprintf(fp ,"%s" ,":");

  fclose(fp);
  fclose(mfp);


}//lAst



  // open database
  else if(option =='2'){


 FILE *meta;
 if(( meta = fopen("metaData" , "r+") ) == NULL){
  printf("File Is Missing. Find it \n");
  exit(1);
                                                  }
//Size of names file
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
 
//printing names of database from metaData file
char subStr[100];

 int fs =0;
 int ls =0;
 
         for(int ba=0; ba<sizeBN; ba++){
         if(bufferName[ba]==':'){
         ls = ba;
         getSubString(bufferName, subStr,fs, ls-1);
         printf("--%s \n" ,subStr);
         }
         else if(bufferName[ba]==';'){
         fs = ba+1;
         }
         }
    

        // setting them 0 so can be used again
        fs =0;
        ls =0;

       // User enters name here
       printf("Enter name of database to open: ");
       char nameEntered[100];
       scanf(" %s" , nameEntered);
       int cmp = -1;
       char sizeOfD[10];
 
         // Size of database gets extracted here
         for(int bba=0; bba<sizeBN; bba++){
         if(bufferName[bba]==':'){
         ls = bba;
         getSubString(bufferName, subStr,fs, ls-1);
         cmp = strcmp(subStr, nameEntered);
         if(cmp == 0){
         for(int baa=ls+1; baa<sizeBN; baa++){

         if((bufferName[baa]==';') || (bufferName[baa]=='\n')){ // Implement chagne here
         getSubString(bufferName, sizeOfD, bba+1, baa);
         //Gets Extracted
         
            break;
                                      }
                                             }

                     }



                                  }
         else if(bufferName[bba]==';'){
         fs =bba+1;
                                      }
                                            }// For loop ends here

     fclose(meta);




//Convert String into int which is extracted size of dtabase
int  intDSize;
sscanf(sizeOfD, "%d" , &intDSize);





















  
  // LOAD TABLE HERE NEED ALGO 
    FILE *dap;
    dap = fopen("db" ,"r+");
    int sizOFile =0;
  

  // GETS EXACT size of database file to be used
    fseek(dap, 0L, SEEK_END);
    sizOFile = ftell(dap);
    rewind(dap);
 
  // printf("Name Entered %s \n" , nameEntered);
  // printf("Size of Database file %d \n", sizOFile);
  // printf("Size of table to be extracted %d \n" , intDSize);
   char bigBuffer[sizOFile];





   //File data gets loaded to array bigbuffer
   fread(bigBuffer, 1000 , 1, dap);
   

    //Name that will be extracted from file and table that will be extracted
    char extractedName[100];
    char outputTable[intDSize];


              // Redeclaring variables
              fs=0;
              ls=0;

           for(int sahil=0; sahil<sizOFile; sahil++){
           if(bigBuffer[sahil]==' '){
           fs=sahil+1;
                                    }
           else if(bigBuffer[sahil] == ';'){
           ls = sahil-1;
           getSubString(bigBuffer, extractedName,fs, ls);
           if(strcmp(extractedName, nameEntered)==0){
           int upto = intDSize + sahil;
           getSubString(bigBuffer, outputTable, sahil+1, upto-1);
           puts(outputTable);
           break;
                                                     }

                                              }
                                                        }//for loop ends here



 fclose(dap);

//HERE COMES THE BOOKING

//Formatting algo

printf("Seat Table: \n");
for(int song=0; song<intDSize; song++){

if(outputTable[song]==':'){
break;
                          }
if((outputTable[song]=='A') || (outputTable[song]=='B') || (outputTable[song]=='C') || (outputTable[song]=='D')){
printf(" ");
                                                          }

printf("%c" ,outputTable[song]);

if(outputTable[song]=='D'){
printf("\n");
                          }
                                     }


//Asking seat number
char seatNumber[100];

printf("The booked seat will be marked as X \n");
printf("Enter seat number (For example 2A) \n");

scanf("%s--" , seatNumber); 

puts(seatNumber);


   }// section ends // check if file closed











// delete database
else if (option == '3'){
  printf("Select Database you want to remove \n");
}

else{
  printf("Invalid Input \n");
}



return 0;
}






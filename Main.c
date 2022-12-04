/*
<------------------------------------------------------------------------------------------------------------>
Team Members:
1 Pavas Garg 2021A7PS2587H
2 Saksham Bajaj 2021A7PS1315H
<------------------------------------------------------------------------------------------------------------>
*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void sortArrayInDescendingOrder(int* arr,int n){
    int temp=0;
    for (int i=0; i<n; i++){
        for (int j=i+1;j<n;j++){
            if (*(arr+i) < *(arr+j)){
                temp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = temp;
            }
        }
    }
}

int main(int argc, char* argv[]){

    // fp is a file pointer
    FILE *fp;
    int n,e;

    // opening the file using FILE pointer in read mode
    fp=fopen(argv[1],"r");

    // for finding the name of file
    char fileSuffix = argv[1][7];

    // if file is not found
    if(fp == NULL){
        printf("\nInput File Not Found !\n\n");
        exit(0);
    }

    // reading the contents of the file
    fscanf(fp,"%d",&n);
    fscanf(fp,"%d",&e);

    int adjMat[n][n];
    // initialising all the values to zero
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            adjMat[i][j]=0;
        }
    }

    int i=0,j=0;
    // reading the contents of file till the end
    while(!feof(fp)){
        fscanf(fp,"%d %d",&i,&j);
        // if there is edge between two vertex then make adjMat matrix value 1
        adjMat[i-1][j-1]=1;
        adjMat[j-1][i-1]=1;        
    }

    // array for storing the degree sequence
    int cnt = 0;
    int degSequence[n];
    for (int i=0;i<n;i++){
        cnt=0;
        for (int j=0;j<n;j++){
            cnt+=adjMat[i][j];
        }
        degSequence[i]=cnt;
    }

    // sorting the array in descending order
    sortArrayInDescendingOrder(degSequence,n);

    // closing the input file
    fclose(fp);

    // for finding the new name of file
    char fileName[] = "./Test/output.txt";
    char newFileName[30];

    for(int i=0;i<10;i++){
        *(newFileName+i) = fileName[i];
    }

    *(newFileName+10) = '-';
    *(newFileName+11) = fileSuffix;

    for(int i = 12;i<16;i++){
        *(newFileName+i) = fileName[i+1];
    }

    // will modify the existing file output.txt in Test folder, if not there it will create a new file
    fp=fopen(newFileName,"w+");

    printf("\nThe degree sequence is:\n");
    fprintf(fp,"The degree sequence is:\n");

    for (int i=0;i<n;i++){
        printf("%d ",degSequence[i]);
        fprintf(fp,"%d ",degSequence[i]);
    }

    printf("\n\n");
    fclose(fp);

    return 0;
}


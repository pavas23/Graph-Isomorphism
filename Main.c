/*
<------------------------------------------------------------------------------------------------------------>
Team Members:
1 Pavas Garg 2021A7PS2587H
2 Saksham Bajaj 2021A7PS1315H
<------------------------------------------------------------------------------------------------------------>
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    // fp is a file pointer
    FILE *fp;
    int n,e;

    // opening the file using FILE pointer in read mode
    fp=fopen(argv[1],"r");

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
    int degSequence[n];
    for (int i=0;i<n;i++){
        int cnt=0;
        for (int j=0;j<n;j++){
            cnt+=adjMat[i][j];
        }
        degSequence[i]=cnt;
    }

    // sorting the array in descending order
    int temp;
    for (i=0; i<n; i++){
        for (j=i+1;j<n;j++){
            if (degSequence[i]<degSequence[j]){
                temp=degSequence[i];
                degSequence[i]=degSequence[j];
                degSequence[j] = temp;
            }
        }
    }

    // closing the input file
    fclose(fp);

    // will modify the existing file output.txt in Test folder, if not there it will create a new file
    fp=fopen("./Test/output.txt","w+");

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


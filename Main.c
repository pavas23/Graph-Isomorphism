/*
<------------------------------------------------------------------------------------------------------------>
Team Number 8
Team Members:
1 Pavas Garg 2021A7PS2587H
2 Saksham Bajaj 2021A7PS1315H
<------------------------------------------------------------------------------------------------------------>
*/

#include <stdio.h>
#include <stdlib.h>

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

    while (1){
        
        // if file is not found
        if(fp == NULL){
            printf("\nInput File Not Found !\n\n");
            break;
        }

        // reading the number of nodes
        fscanf(fp,"%d",&n);

        
        // if file is empty
        if(feof(fp)){
            printf("\nInput File Is Empty!\n\n");
            break;
        }
        
        // if number of nodes are 0
        if(n==0){
            printf("\nNumber of nodes=0!\n\n");
            break;
        }

        // if number of edges not mentioned
        if(feof(fp)){
            printf("\nNumber of Edges Not Mentioned!\n\n");
            break;
        }
        
        // reading the number of edges
        fscanf(fp,"%d",&e);

        //making an adjacency matrix
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

        printf("\nThe degree sequence is:\n");
        for (int i=0;i<n;i++){
            printf("%d ",degSequence[i]);
            fprintf(fp,"%d ",degSequence[i]);
        }
        printf("\n\n");
        break;
    }
}



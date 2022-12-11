/*
<------------------------------------------------------------------------------------------------------------>
Team Number: 8
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

void swapArrayElemenets(int x, int y,int *arr){
    int temp=0; 
    temp = arr[x]; 
    arr[x]= arr[y]; 
    arr[y] = temp;
}

int compareTwoArrays(int* arr1,int* arr2,int n){
    for (int i=0;i<n;i++){
        if(arr1[i]!=arr2[i]){
            return 0;
        }
    }
    return 1;
}

// This function will take two index and swap the rows and columns corresponding to that index
void rotateMatrix(int n,int **array1,int a,int b){

    // for interchanging the rows a and b
    for (int i = 0; i < n;i++){
        int c=0;
        c = array1[a-1][i];
        array1[a-1][i]=array1[b-1][i];
        array1[b-1][i]= c;
    }

    // for interchanging the columns a and b
    for (int i = 0; i < n; ++i){
        int c=0;
        c = array1[i][a-1];
        array1[i][a-1]=array1[i][b-1];
        array1[i][b-1]= c;
    }
    
}

int compareTwoMatrices(int** matrix1,int** matrix2,int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(matrix1[i][j]!=matrix2[i][j]){
                return 0;
            }
        }
    }
    return 1;
}

int checkIsopmorphism(int n,int** matrix1,int** matrix2,int* arr,int l){
 
    if(l==(n-1)){
        if(compareTwoMatrices(matrix1,matrix2,n)){
                return 1;   
            }
    }
    
    else{
        for(int i=l;i<n;i++){
            swapArrayElemenets(l,i,arr);
            rotateMatrix(n,matrix2,l+1,i+1);
            
            if(checkIsopmorphism(n,matrix1,matrix2,arr,l+1)==1){
                return 1;
            }
            
            swapArrayElemenets(l,i,arr);
            rotateMatrix(n,matrix2,l+1,i+1);
        }
    }
    return 0;

}

int main(int argc, char* argv[]){

    // fp is a file pointer
    FILE *fp1,*fp2;
    int n1=-1,e1=-1,n2=-1,e2=-1;

    // opening the file using FILE pointer in read mode
    fp1=fopen(argv[1],"r");
    fp2=fopen(argv[2],"r");

    while (1){

        // if file is not found
        if(fp1 == NULL){
            printf("\nInput File Not Found !\n\n");
            break;
        }

        if(fp2 == NULL){
            printf("\nOnly 1 Input File Found\n\n");
            break;
        }

        // reading the number of nodes
        fscanf(fp1,"%d",&n1);
        fscanf(fp2,"%d",&n2);

        // if file is empty
        if(n1==-1){
            printf("\nFirst Input File Is Empty!\n\n");
            exit(0);
        }

        if(n2==-1){
            printf("\nSecond Input File Is Empty!\n\n");
            exit(0);
        }
        
        // if number of nodes are 0
        if(n1==0){
            printf("\nNumber of Nodes of Graph 1 = 0\n\n");
            exit(0);
        }

        if(n2==0){
            printf("\nNumber of Nodes of Graph 2 = 0\n\n");
            exit(0);
        }

        // if number of nodes are different 
        if(n1!=n2){
            printf("\nNot Isomorphic, Number of Nodes Not Equal!\n\n");
            exit(0);
        }
        
        int n=n1;

        // reading the number of edges
        fscanf(fp1,"%d",&e1);
        fscanf(fp2,"%d",&e2);

        // if number of edges not mentioned
        if(e1==-1){
            printf("\nNumber of Edges in Graph 1 Not Mentioned!\n\n");
            exit(0);
        }

        if(e2==-1){
            printf("\nNumber of Edges in Graph 2 Not Mentioned!\n\n");
            exit(0);
        }

        // if number of edges are not equal
        if(e1!=e2){
            printf("\nNot Isomorphic, Number of Edges Not Equal!\n\n");
            exit(0);
        }

        // if number of edges are equal and 0
        if(e1==0 && e2==0){
            printf("\nIsomorphic.\n");
            for (int i=0;i<n;i++){
                printf("%d %d\n",i+1,i+1);
            }
            exit(0);
        }
    
        //making an adjacency matrix
        int** adjMat1,**adjMat2;

        // allocating memory to the adjMat1 as it will contain n pointers of datatype int*
        adjMat1 = (int**) malloc(n*sizeof(int*));
        
        /* allocating memory to adjMat1 as at each index of adjMat1 there is a pointer that
        will take n*4 bytes of memory */
        for(int i=0;i<n;i++){
            int* temp = (int*)malloc(n*sizeof(int));
            adjMat1[i] = temp;
        }

        // allocating memory to the adjMat2 as it will contain n pointers of datatype int*
        adjMat2 = (int**) malloc(n*sizeof(int*));
        
        /* allocating memory to adjMat2 as at each index of adjMat2 there is a pointer that
        will take n*4 bytes of memory */
        for(int i=0;i<n;i++){
            int* temp = (int*)malloc(n*sizeof(int));
            adjMat2[i] = temp;
        }

        // initialising all the values to zero
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                adjMat1[i][j]=0;
                adjMat2[i][j]=0;
            }
        }

        int i=0,j=0;
        // reading the contents of file till the end
        while(!feof(fp1)){
            fscanf(fp1,"%d %d",&i,&j);
            // if there is edge between two vertex then make adjMat matrix value 1
            adjMat1[i-1][j-1]=1;
            adjMat1[j-1][i-1]=1;        
        }
        while(!feof(fp2)){
            fscanf(fp2,"%d %d",&i,&j);
            // if there is edge between two vertex then make adjMat matrix value 1
            adjMat2[i-1][j-1]=1;
            adjMat2[j-1][i-1]=1;        
        }
        
        // array for storing the degree sequence
        int cnt1,cnt2;
        int degSequence1[n];
        int degSequence2[n];
        for (int i=0;i<n;i++){
            cnt1=0;
            cnt2=0;
            for (int j=0;j<n;j++){
                cnt1+=adjMat1[i][j];
                cnt2+=adjMat2[i][j];
            }
            degSequence1[i]=cnt1;
            degSequence2[i]=cnt2;
        }

        // sorting the array in descending order
        sortArrayInDescendingOrder(degSequence1,n);
        sortArrayInDescendingOrder(degSequence2,n);

        // closing the input file
        fclose(fp1);
        fclose(fp2);

        // comparing the degree sequences
        if (compareTwoArrays(degSequence1,degSequence2,n)){
            int bijectionArr[n];
            for (int i=0;i<n;i++){
                bijectionArr[i]=i+1;
            }
            if(checkIsopmorphism(n,adjMat1,adjMat2,bijectionArr,0)){
                printf("\nIsomorphic.\n");
                for (int i=0;i<n;i++){
                    printf("%d %d\n",i+1,bijectionArr[i]);
                } 
                printf("\n\n");
                break;
            }
            else{
                printf("\nNot Isomorphic, No Bijection Found\n\n");
                break;
            }
        }
        else{
            printf("\nNot Isomorphic\n\n");
            exit(0);
        }
    }
    return 0;
}

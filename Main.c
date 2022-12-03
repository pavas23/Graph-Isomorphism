#include <stdio.h>
#include <stdlib.h>

void main(int argc, char* argv[]){
    FILE *fp;
    int n,e;
    fp=fopen(argv[1],"r");
    fscanf(fp,"%d",&n);
    fscanf(fp,"%d",&e);
    int adj[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            adj[i][j]=0;
        }
    }
    int i=0,j=0;
    while(!feof(fp)){
        fscanf(fp,"%d %d",&i,&j);
        adj[i-1][j-1]=1;
        adj[j-1][i-1]=1;        
    }
    int arr[n];
    for (int i=0;i<n;i++){
        int cnt=0;
        for (int j=0;j<n;j++){
            cnt+=adj[i][j];
        }
        arr[i]=cnt;
    }
    int a;
    for (i=0; i<n; ++i){
        for (j=i+1;j<n;++j){
            if (arr[i]<arr[j]){
                a=arr[i];
                arr[i]=arr[j];
                arr[j] = a;
            }
        }
    }
    fclose(fp);
    fp=fopen("output.txt","w+");
    printf("The degree sequence is: ");
    fprintf(fp,"The degree sequence is:\n");
    for (int i=0;i<n;i++){
        printf("%d",arr[i]);
        fprintf(fp,"%d",arr[i]);
    }
    fclose(fp);
}

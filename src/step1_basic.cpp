//
// Created by 86159 on 2025/12/8.
//
#include <stdio.h>
#include <iostream>
using namespace std;
void addMatrix(int A[][3],int B[][3],int result[][3],int row,int line)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<line;j++)
        {
            result[i][j]=A[i][j]+B[i][j];
        }
    }
}
void printMatrix(int A[][3],int row,int line)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<line;j++)
        {
            cout<< A[i][j];
        }
        cout<<endl;
    }
}
void multipalMatrix(int A[][3],int reslut[][3],int m,int row,int line)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < line; j++) {
            reslut[i][j] = A[i][j] * m;
        }
    }
}
int main()
{
    int A[1][3]={1,2,3};
    cout<<"矩阵A"<<endl;
    printMatrix(A,1,3);
    int B[1][3]={4,5,6};
    cout<<"矩阵B"<<endl;
    printMatrix(B,1,3);
    int C[1][3];
    addMatrix(A,B,C,1,3);
    cout<<"矩阵C：矩阵A+矩阵B"<<endl;
    printMatrix(C,1,3);
    int D[1][3];
    multipalMatrix(B,D,2,1,3);
    cout<<"矩阵D：矩阵B*2"<<endl;
    printMatrix(D,1,3);
}
//
// Created by 86159 on 2025/12/9.
//
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
typedef vector<vector<int>> Matrix;
//矩阵打印
void printMatrix(Matrix A)
{
    for(int i=0;i<A.size();i++)
    {
        vector<int> B=A[i];
        for(int j=0;j<A[0].size();j++)
        {
            cout<< setw(4)<<B[j];
        }
        cout<<endl;
    }
}
//创建矩阵
Matrix creatMatrix(int row,int lien,int value=0)
{
    return Matrix(row,vector<int>(lien,value));
}
//矩阵加法
Matrix addMatrix(Matrix A,Matrix B)
{
    int row=A.size();
    int line=A[0].size();
    Matrix result= creatMatrix(row,line);
    for (int i = 0; i < row; i++) {
        for(int j=0;j<line;j++)
        {
            result[i][j]=A[i][j]+B[i][j];
        }
    }
    return result;
}
//矩阵减法
Matrix subMatrix(Matrix A,Matrix B)
{
    int row=A.size();
    int line=A[0].size();
    Matrix result= creatMatrix(row,line);
    for (int i = 0; i < row; i++) {
        for(int j=0;j<line;j++)
        {
            result[i][j]=A[i][j]-B[i][j];
        }
    }
    return result;
}
//矩阵转置
Matrix zhuanMatrix(Matrix A)
{
    int row=A.size();
    int line=A[0].size();
    Matrix result= creatMatrix(line,row);
    for (int i = 0; i < row; i++) {
        for(int j=0;j<line;j++)
        {
            result[j][i]=A[i][j];
        }
    }
    return result;
}
int main()
{
    Matrix A={
            {1,2,3},
            {4,5,6}
    };
    cout<<"矩阵A"<<endl;
    printMatrix(A);
    Matrix B={
            {1,3,5},
            {2,4,6}
    };
    cout<<"矩阵B"<<endl;
    printMatrix(B);
    //矩阵加法
    Matrix C=addMatrix(A,B);
    cout<<"矩阵C=矩阵A+矩阵B"<<endl;
    printMatrix(C);
    //矩阵减法
    Matrix D= subMatrix(B,A);
    cout<<"矩阵C=矩阵B-矩阵A"<<endl;
    printMatrix(D);
    //矩阵转置
    Matrix E= zhuanMatrix(A);
    cout<<"矩阵A的转置"<<endl;
    printMatrix(E);
}
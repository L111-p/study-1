//
// Created by 86159 on 2025/12/10.
//
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
class Matrix
{
private:
    int row;
    int line;
    vector<vector<int>> data;
    static int total_matrix;  // 静态成员：总的矩阵数
public:
    Matrix(int r,int l,int value=0)
    {
        row=r;
        line=l;
        data=vector<vector<int>>(row,vector<int>(line,value));
        cout<<"构造函数运行"<<endl;
        cout<<"创建"<<row<<"x"<<line<<"矩阵"<<endl;
        total_matrix++;
    }
    int getrow()
    {
        return row;
    }
    int getline()
    {
        return line;
    }
    static int getTotal() {
        return total_matrix;
    }
    void set(int i, int j, int value)
    {
        data[i][j] = value;
    }
    //输出矩阵
    void printMatrix(Matrix A)
    {
        for(int i=0;i<A.row;i++)
        {
            for(int j=0;j<A.line;j++)
            {
                cout<<setw(4)<<A.data[i][j];
            }
            cout<<endl;
        }
    }
    //矩阵加法
    Matrix addMatrix(Matrix B)
    {
        Matrix result(row,line);
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<line;j++) {
                result.data[i][j]=data[i][j]+B.data[i][j];
            }
        }
        return result;
    }
    //矩阵转置
    Matrix zhuanMatrix(Matrix o)
    {
        Matrix result(line,row);
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<line;j++) {
                result.data[j][i]=o.data[i][j];
            }
        }
        return result;
    }
    int sum()
    {
        int total=0;
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<line;j++)
            {
                total += data[i][j];
            }
        }
        return total;
    }
    ~Matrix()
    {
        cout<<"析构函数运行"<<endl;
    }

};
int Matrix::total_matrix=0;
int main()
{
    Matrix A(2,3);
    A.set(0, 0, 1); A.set(0, 1, 2); A.set(0, 2, 3);
    A.set(1, 0, 4); A.set(1, 1, 5); A.set(1, 2, 6);
    A.printMatrix(A);
    Matrix B(2,3);
    B.set(0, 0, 7); B.set(0, 1, 8); B.set(0, 2, 9);
    B.set(1, 0, 10); B.set(1, 1, 11); B.set(1, 2, 12);
    B.printMatrix(B);

    cout << "\n总矩阵数: " << Matrix::getTotal() << endl;

    // 矩阵运算
    cout << "\n执行矩阵加法" << endl;
    Matrix C = A.addMatrix(B);
    C.printMatrix(C);
    cout << "\n矩阵转置" << endl;
    Matrix AT = A.zhuanMatrix(A);
    AT.printMatrix(AT);
    cout << "\n矩阵统计信息:" << endl;
    cout << "A 的元素和: " << A.sum() << endl;
    cout << "B 的元素和: " << B.sum() << endl;
    cout << "C 的元素和: " << C.sum() << endl;
    cout << "\n程序结束前总矩阵数: " << Matrix::getTotal() << endl;
    return 0;
}
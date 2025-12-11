//
// Created by 86159 on 2025/12/11.
//
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Matrix
{
private:
    vector<vector<int>> data;
    int row;
    int line;
public:
    Matrix(int r,int l,int value=0)
    {
        row=r;
        line=l;
        data=vector<vector<int>>(row,vector<int>(line,value));
    }
    Matrix(vector<vector<int>> value)
    {
        row=value.size();
        line=value[0].size();
        data=value;
    }
    int getrow()
    {
        return row;
    }
    int getline()
    {
        return line;
    }
    //矩阵打印，测试
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
    //运算符重载：+
    Matrix operator+(Matrix& other)
    {
        Matrix result(row,line);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < line; j++)
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    // 运算符重载：-
    Matrix operator-(Matrix& other)
    {
        Matrix result(row,line);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < line; j++)
            {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }
    // 运算符重载：*
    Matrix operator*(int value)
    {
        Matrix result(row, line);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < line; j++) {
                result.data[i][j] = data[i][j] * value;
            }
        }
        return result;
    }
    // 运算符重载：==
    bool operator==(Matrix& other)
    {
        if (row!= other.row||line!= other.line)
        {
            return false;
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < line; j++) {
                if (data[i][j] != other.data[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    // 友元函数：标量在左边的乘法
    friend Matrix operator*(int value,Matrix& mat)
    {
        return mat * value;
    }

    // 友元函数：输出流重载
    friend ostream& operator<<(ostream& os, Matrix& mat)
    {
        os << mat.row << "x" << mat.line << " 矩阵:" << endl;
        for (const auto& row1 : mat.data)
        {
            for (int val : row1)
            {
                os << setw(4) << val;
            }
            os << endl;
        }
        return os;
    }
};
int main()
{
    Matrix A({{1, 2}, {3, 4}});
    Matrix B({{5, 6}, {7, 8}});
    A.printMatrix(A);
    //测试+
    Matrix C=A + B;
    C.printMatrix(C);
    //测试-
    Matrix D=A-B;
    D.printMatrix(D);
    //测试*
    Matrix E=A*2;
    E.printMatrix(E);
    //测试== <<
    Matrix H = A + B;
    Matrix I({{6, 8}, {10, 12}});
    cout << "H = A + B =\n" << H;
    cout << "I =\n" << I;
    cout << "H == I ? " << (H == I ? "是" : "否") << endl;
    cout << "H == C ? " << (H == C ? "是" : "否") << endl;
    // 链式运算
    cout << "\n=== 链式运算 ===" << endl;
    Matrix result = A + B + A + B;
    cout << "A + B + A + B =\n" << result;
    Matrix J=C*2;
    cout << "J == result ? " << (J == result ? "是" : "否") << endl;
}
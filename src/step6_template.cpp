//
// Created by 86159 on 2025/12/12.
//
/**
 * Step 6: 模板编程
 *
 * 学习目标：
 * - 类模板
 * - 支持不同数据类型（int, double, float）
 * - 泛型编程
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <complex>
#include <type_traits>
using namespace std;

// 模板矩阵类
template<typename T>
class Matrix {
private:
    vector<vector<T>> data;
    int row;
    int line;

public:
    Matrix(int r,int l,T value=T())
    {
        row=r;
        line=l;
        data=vector<vector<T>>(row,vector<T>(line,value));
    }
    Matrix(vector<vector<T>> value)
    {
        row=value.size();
        line=value[0].size();
        data=value;
    }

    // Getter
    int getrow()
    {
        return row;
    }
    int getline()
    {
        return line;
    }
    // 运算符重载：+
    Matrix<T> operator+(const Matrix<T>& other) const
    {
        Matrix<T> result(row, line);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < line; j++)
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // 运算符重载：*
    Matrix<T> operator*(T scalar) const
    {
        Matrix<T> result(row, line);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < line; j++)
            {
                result.data[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    // 求和
    T sum() const
    {
        T total = T();
        for (const auto& row1 : data)
        {
            for (const T& val : row1)
            {
                total += val;
            }
        }
        return total;
    }

    // 求平均值
    T average()
    {
        return sum() / static_cast<T>(row * line);
    }
    // 友元函数：输出流重载
    friend ostream& operator<<(ostream& os, const Matrix<T>& mat)
    {
        os << mat.row << "x" << mat.line << " 矩阵:" << endl;
        for (const auto& row : mat.data)
        {
            for (const T& val : row)
            {
                os << setw(8) << setprecision(3) << fixed << val;
            }
            os << endl;
        }
        return os;
    }

    // 友元函数：标量乘法
    friend Matrix<T> operator*(T scalar, const Matrix<T>& mat)
    {
        return mat * scalar;
    }

    // 获取类型名称
    static string getTypeName()
    {
        if (is_same<T, int>::value) return "int";
        if (is_same<T, float>::value) return "float";
        if (is_same<T, double>::value) return "double";
        return "unknown";
    }
};

int main() {
    //int类型矩阵
    cout << "\n" << string(50, '=') << endl;
    cout << "测试 int 类型矩阵" << endl;
    cout << string(50, '=') << endl;

    Matrix<int> intMat1({{1, 2, 3}, {4, 5, 6}});
    Matrix<int> intMat2({{10, 20, 30}, {40, 50, 60}});

    cout << "\nA (int):\n" << intMat1;
    cout << "\nB (int):\n" << intMat2;
    cout << "\nA + B:\n" << (intMat1 + intMat2);
    cout << "\nA * 5:\n" << (intMat1 * 5);
    cout << "A 的和: " << intMat1.sum() << endl;
    cout << "A 的平均值: " << intMat1.average() << endl;

    //double 类型矩阵
    cout << "\n" << string(50, '=') << endl;
    cout << "测试 double 类型矩阵" << endl;
    cout << string(50, '=') << endl;

    Matrix<double> doubleMat1({{1.5, 2.5}, {3.5, 4.5}});
    Matrix<double> doubleMat2({{0.5, 1.5}, {2.5, 3.5}});

    cout << "\nC (double):\n" << doubleMat1;
    cout << "\nD (double):\n" << doubleMat2;
    cout << "\nC + D:\n" << (doubleMat1 + doubleMat2);
    cout << "\nC * 2.5:\n" << (doubleMat1 * 2.5);
    cout << "C 的和: " << doubleMat1.sum() << endl;
    cout << "C 的平均值: " << doubleMat1.average() << endl;

    //float 类型矩阵
    cout << "\n" << string(50, '=') << endl;
    cout << "测试 float 类型矩阵" << endl;
    cout << string(50, '=') << endl;

    Matrix<float> floatMat({{1.1f, 2.2f, 3.3f}, {4.4f, 5.5f, 6.6f}});
    cout << "\nE (float):\n" << floatMat;
    cout << "\nE * 3:\n" << (floatMat * 3.0f);
    cout << "E 的和: " << floatMat.sum() << endl;
    cout << "E 的平均值: " << floatMat.average() << endl;

    //类型信息
    cout << "\n" << string(50, '=') << endl;
    cout << "类型信息" << endl;
    cout << string(50, '=') << endl;
    cout << "Matrix<int> 类型: " << Matrix<int>::getTypeName() << endl;
    cout << "Matrix<double> 类型: " << Matrix<double>::getTypeName() << endl;
    cout << "Matrix<float> 类型: " << Matrix<float>::getTypeName() << endl;
    cout << "Matrix<float> 类型: " << Matrix<complex<double>>::getTypeName() << endl;
    return 0;
}

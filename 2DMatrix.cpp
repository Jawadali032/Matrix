#include <iostream>
using namespace std;
class Matrix
{
public:
    virtual double getElem(int i, int j) {}
    virtual void setElem(int i, int j) {}
    virtual Matrix add(Matrix &obj) {}
    virtual Matrix multiply(Matrix &obj) {}
};
class TwoDMatrix : public Matrix
{
    double **data;
    int height;
    int width;

public:
    TwoDMatrix()
    {
        cout << "Enter the number of rowS : " << endl;
        cin >> width;
        cout << "Enter the number of ColumnS : " << endl;
        cin >> height;
        data = new double *[width];
        for (int i = 0; i < width; i++)
        {
            data[i] = new double[height];
        }
    }
    TwoDMatrix(int row, int column)
    {
        width = row;
        height = column;
        data = new double *[width];
        for (int i = 0; i < width; i++)
        {
            data[i] = new double[height];
        }
    }
    void setValue()
    {
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                cout << "ENter value at " << i + 1 << " X " << j + 1 << " place " << endl;
                cin >> data[i][j];
            }
        }
    }
    void setElem(int i, int j, double value)
    {
        data[i][j] = value;
    }
    double getElem(int i, int j)
    {
        return data[i][j];
    }
    TwoDMatrix add(TwoDMatrix &obj)
    {
        TwoDMatrix temp(obj.height, obj.width);
        for (int i = 0; i < obj.width; i++)
        {
            for (int j = 0; j < obj.height; j++)
            {
                temp.data[i][j] = this->data[i][j] + obj.data[i][j];
            }
        }
        return temp;
    }
    TwoDMatrix multiply(TwoDMatrix &obj)
    {
        TwoDMatrix temp(obj.height, obj.width);
        for (int i = 0; i < obj.width; i++)
        {
            for (int j = 0; j < obj.height; j++)
            {
                for (int k = 0; k < obj.height; k++)
                {
                    temp.data[i][j] = temp.data[i][j] + (this->data[i][k] * obj.data[k][j]);
                }
            }
        }
        return temp;
    }
    friend ostream &operator<<(ostream &out, const TwoDMatrix &obj)
    {
        out << "---- THe Given matrix is -----" << endl;
        for (int i = 0; i < obj.width; i++)
        {
            for (int j = 0; j < obj.height; j++)
            {
                out << obj.data[i][j] << "\t";
            }
            out << endl;
        }
    }
    ~TwoDMatrix()
    {
        for (int i = 0; i < width; i++)
        {
            delete[] data[i];
        }

        delete[] data;
        data = nullptr;
        cout << "deleting ......" << endl;
    }
    void rowWiseTransversal()
    {
        for (int i = 0; i < this->width; i++)
        {
            for (int j = 0; j < this->height; j++)
            {
                data[i][j]++;
            }
        }
    }
    void ColumnWiseTransversal()
    {
        for (int i = 0; i < this->width; i++)
        {
            for (int j = 0; j < this->height; j++)
            {
                data[j][i]++;
            }
        }
    }
};
class MatrixLin
{
    int n;
    double *data1;
    int height;
    int width;

public:
    MatrixLin()
    {
        cout << "Enter the size of linear Matrix!" << endl;
        cin >> n;
        data1 = new double[n];
        for (int i = 0; i < n; i++)
        {
            cout << "Enter value at " << i << " place " << endl;
            cin >> data1[i];
        }
    }
    void delinearize()
    {
        cout << "Enter rowsize to reshape " << endl;
        cin >> width;
        cout << "Enter columnsize to reshape " << endl;
        cin >> height;
        int check;
        check = height * width;
        if (check == n)
        {
            int **ptr;
            ptr = new int *[width];
            for (int i = 0; i < width; i++)
            {
                ptr[height] = new int[height];
            }
            for (int i = 0; i < width; i++)
            {
                static int count = 0;
                for (int j = 0; j < height; j++)
                {
                    ptr[i][j] = this->data1[count];
                    count++;
                }
            }
            for (int i = 0; i < width; i++)
            {
                for (int j = 0; j < height; j++)
                {
                    cout << ptr[i][j] << "\t";
                }
                cout << endl;
            }
            for (int i = 0; i < width; i++)
            {
                delete[] ptr[i];
            }
            delete[] ptr;
        }
    }
    ~MatrixLin()
    {
        delete[] data1;
        data1 = nullptr;
    }
};
int main()
{
    TwoDMatrix m1;
    m1.setValue();
    cout << m1;
    TwoDMatrix m2;
    m2.setValue();
    cout << m2;
    TwoDMatrix m3 = m1.multiply(m2);
    cout << m3;
    MatrixLin l1;
    l1.delinearize();
    return 0;
}

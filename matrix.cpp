#include<iostream>
#include<vector>
using namespace std;
class Matrix;

class AbsMatrix{
    public:
        virtual Matrix operator+(Matrix &obj)=0;
        virtual Matrix operator*(Matrix &obj)=0;
        virtual Matrix transpose(Matrix &obj)=0;
        virtual Matrix deLinearization(Matrix &obj)=0;
        virtual void rowTraversal(Matrix &obj)=0;
        virtual void colTraversal(Matrix &obj)=0;    
        virtual void setElem(int i, int j, float value)=0;
        virtual float getElem(int i, int j)=0;
};

class Matrix:public AbsMatrix{
    private:
        int rows;
        int columns;
        static int count;
        vector <vector<float>> matrx;
        vector <float> matrx1d; 

    public:
        Matrix(){
            count++;
            cout<<"The number of matrix initiated is "<<count<<endl;
        }
        // setting the number of rows and columns from the user by taking input
        void set2dMatrix(){
            cout<<"ENTER THE NUMBER OF ROWS "<<endl;
            cin>>rows;
            cout<<"ENTER THE NUMBER OF COLUMNS "<<endl;
            cin>>columns;
        }

        void setMatrix1d(){
            cout<<"ENTER THE LENGTH OF 1D MATRIX"<<endl;
            
            cin>>columns;
            for(int i=0;i<columns;i++){
                float elements;\
                cout<<"ENTER THE ELEMENTS OF THE 1D MATRIX"<<endl;
                cin>>elements;
                matrx1d.push_back(elements);
            }
        }

        // taking input the the elements of the matrix
        void matrix2dInput(){
            for(int i = 0;i<rows;i++){
                vector <float> col;
                for(int j = 0; j<columns; j++){
                    cout<<"ENTER THE ELEMENTS OF THE MATRIX " <<i <<"X"<< j<< endl;
                    float elements;
                    cin>>elements;
                    col.push_back(elements);
                }
                matrx.push_back(col);
            }
        }
        void setElem(int i, int j, float value){
            matrx[i][j] = value;
        }

        float getElem(int i, int j){
            return matrx[i][j];
        }
        
       
        // adding the two matrices and overloading the sum operator
        Matrix operator+(Matrix &obj){
            Matrix m;
            for(int i=0; i<obj.matrx.size(); i++){
                vector <float> temp;
                for(int j=0; j<obj.matrx[i].size();j++){
                 temp.push_back(this->matrx[i][j]+obj.matrx[i][j]);
                }
                m.matrx.push_back(temp);
            }
            return m;
        }

        // insertion operator overloading
        friend ostream & operator <<(ostream &out,Matrix  &m){
            for (int i = 0; i<m.matrx.size(); i++){   
                for(int j=0; j< m.matrx[i].size();j++){
                cout<< m.matrx[i][j]<<" ";
                }
            cout<<endl;
            return out;
            }
        }
        
        // multiplying the two matrices and overloading the product operator
        Matrix operator*(Matrix &obj){
            Matrix m;
            // creating a null matrix 
            for(int i=0;i<obj.matrx.size();i++){
                vector <float> temp;
                for(int j=0; j < obj.matrx[i].size(); j++){
                    temp.push_back(0);
                }
                m.matrx.push_back(temp);
            }

            // multiplying the both matrices and assiging them to null matrix
            for(int i=0;i<obj.matrx.size();i++){
                for(int j=0; j < obj.matrx[i].size(); j++){
                    for(int k=0; k < obj.matrx[i].size(); k++){
                        m.matrx[i][j]=m.matrx[i][j] + (this->matrx[i][k] * obj.matrx[k][j]);
                    }
                }
            }
            return m;  
        }

        // matrix transpose
        Matrix transpose(Matrix &obj){
            Matrix m;
            for(int i=0; i<obj.matrx.size(); i++){
                vector<float> temp;
                for(int j=0; j<obj.matrx[i].size(); j++){
                    temp.push_back(obj.matrx[j][i]);
                }
                m.matrx.push_back(temp);
            }
            return m;
        }
        // taking a 1d vector and converting it into a 2d vector
        Matrix deLinearization(Matrix &obj){
            Matrix temporary;
            int row;
            cout<<"enter number of rows to resize:"<<endl;
            cin>>row;

            int col;
            cout<<"enter number of columns to resize:"<<endl;
            cin>>col;
            int check = row * col;

            if(check==obj.matrx1d.size()){
                for(int i =0;i<row;i++){
                    vector <float > temp;
                    static int count=0;
                    for(int j=0;j<col;j++){
                        temp.push_back(obj.matrx1d[count]);
                        (count=count+1);
                    }
                temporary.matrx.push_back(temp);  
                }
                return temporary;
            }

            else{
                cout<<"ENTER CORRECT SIZE TO RESHAPE THE MATRIX "<<endl;
            }
        }
        // traversing the values of 2d vector row-wise
        void rowTraversal(Matrix &obj){
            for(int i=0;i<obj.matrx.size();i++){
                for(int j=0;i<obj.matrx[i].size();j++){
                    cout<<obj.matrx[i][j]<<" ";
                }  
            }
        }
        
        // traversing the values of 2d vector column-wisw
        void colTraversal(Matrix &obj){
            for(int i=0;i<obj.matrx.size();i++){
                for(int j=0;j<obj.matrx[i].size();j++){
                    cout<<obj.matrx[j][i]<<" ";
                }  
            }   
        }

        
};

int Matrix :: count;
int main(){
    Matrix M;

    
   return 0;
}
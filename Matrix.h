#pragma once

class Vector;
class Matrix
{
    private:
        float* data;
        int row, col;
    public:
        Matrix();
        Matrix(int row,int col):row(row), col(col)
        {
            data = new float[row*col];
        }
//        Matrix (float m11,float m12,float m13,float m14,
//                float m21,float m22,float m23,float m24,
//                float m31,float m32,float m33,float m34,
//                float m41,float m42,float m43,float m44)
//                {
//                    data = new float[16];
//                    data[0]=m11; data[1]=m12; data[2]=m13; data[3]=m14;data[4]=m21;data[5]=m22;data[6]=m23;data[7]=m24;
//                    data[8]=m31; data[9]=m32; data[10]=m33; data[11]=m34;data[12]=m41;data[13]=m42;data[14]=m43;data[15]=m44;
//                }
        Matrix(const Matrix& mat)
        {
            row = mat.row;
            col = mat.col;
            data = new float[row*col];

            for (int i =0;i<row*col;i++)
                (*this)(i) = mat(i);
        }
        Matrix retMat(const Vector& vec);
        void operator=(const Matrix& mat)
        {
            delete[] data;
            row = mat.row;
            col = mat.col;
            data = new float[row*col];

            for (int i =0;i<row*col;i++)
                (*this)(i) = mat(i);
        }
        float& operator() (int r, int c);   //mat(i,j)
        float& operator() (int pos) ;       //mat(pos)
        const float operator() (int r, int c) const;   //mat(i,j)
        const float operator() (int pos) const;       //mat(pos)


        Matrix operator * (Matrix& mat);    // M = T * M
        Matrix operator + (Matrix& mat);    // C = A + B
        Matrix operator - (Matrix& mat);    // C = A - B
        Matrix operator / (float val);      // C[] = C[] / val
        float dot(Matrix& mat);             // A.dot(B) == (A = A DOT B)
        float magnitude();                  //returns the square root of sum of squares of all element

        ~Matrix(){
            delete[] data;
        }

};

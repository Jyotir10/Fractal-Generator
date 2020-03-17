#ifndef Sharma_Jyotirmay_2488983641_ECQ1_H_INCLUDED
#define Sharma_Jyotirmay_2488983641_ECQ1_H_INCLUDED


class array2D {
protected:
    int xRes,yRes;
    float **xtable;
public:
    //Constructor
    array2D(int xResolution,int yResolution);
    //Destructor
    ~array2D();
    //Methods Declaration
    void getSize(int &xResolution, int &yResolution);
    void setValue(int x,int y,int val);
    int getValue(int x,int y);

};

class PGMImage: public array2D{
protected:
    std::string filename;
public:
    //Constructor
    PGMImage(int xResolution,int yResolution,std::string imagefilename);
    ~PGMImage();
    //Methods declaration
    void getResolution(int& xResolution,int& yResolution);
    void setPixel(int x,int y,int val);
    int getPixel(int x,int y);
    void writeFile();
 };

 class ComplexNumber{
 private:
     double real,imaginary;
 public:
    //constructor
    ComplexNumber(double i,double j);
    //methods declaration
    ComplexNumber add(ComplexNumber c2); //outputs a sum, as a new complex number
    ComplexNumber squared(); //outputs a squared value, as a new complex number
    double abs(); //outputs the magnitude of the complex number: sqrt(real*real+imag*imag)
    void prt(); //does cout in the form of 'real + imag j'

 };





#endif // EC1RE_H_INCLUDED

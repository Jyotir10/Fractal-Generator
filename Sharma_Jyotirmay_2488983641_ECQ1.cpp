#include <iostream>
#include <cmath>
#include <fstream>
#include "Sharma_Jyotirmay_2488983641_ECQ1.h"

using namespace std;
//Definition of Constructor of array2D
array2D::array2D(int xResolution,int yResolution){
    xRes=xResolution;
    yRes=yResolution;
    if (xResolution<=0 || yResolution<=0){
        cout<<"you are entering invalid xres or yres"<<endl;
        exit(1);  //For abnormal termination of program due to error
    }
        xtable = new float*[yRes];//Memory allocation in heap for a pointer of array of yres
        for(int i=0;i < yRes;i++) {
      xtable[i] = new float[xRes];
    }

    for(int i=0;i < yRes;i++){
       for(int j=0;j < xRes;j++){
           xtable[i][j]=45; // store 45 for pixel data, "for now"
       }
    }
    }
//Definition of Destructor for array2D
array2D::~array2D(){
    for (int i=0;i<yRes;i++){
        delete xtable[i];
    }
    delete[] xtable;
    }
//Method definition of array2D
void array2D::setValue(int x,int y,int val){
xtable[y][x]=val;
}

int array2D::getValue(int x,int y){
return xtable[y][x];  //in xtable, y would be the rowID, x, the columnID
}

void array2D::getSize(int &xResolution, int &yResolution){
xResolution=xRes;
yResolution=yRes;
}
PGMImage::PGMImage(int xResolution,int yResolution,std::string imagefilename):array2D(xResolution,yResolution){
{
    filename=imagefilename;
    }
}
//Destructor for PGMImage
PGMImage::~PGMImage(){
};
//Method definition of PGMImage
void PGMImage::getResolution(int& xResolution,int& yResolution){
getSize(xResolution,yResolution);
}
void PGMImage::setPixel(int x,int y,int val){
    setValue(x,y,val);
}
int PGMImage::getPixel(int x,int y){
    return getValue(x,y);
}
void PGMImage::writeFile(){
 ofstream pgmFile(filename+".pgm");
    // header
    pgmFile << "P2" << endl;
    pgmFile << xRes << " " << yRes << endl; // how many columns, how many rows
    pgmFile << 255 << endl; // largest pixel value we'll be outputting (below)

    //cout << "3" << endl;
    // pixel data
    for(int i=0;i<yRes;i++){
        for(int j=0;j<xRes;j++){
                //cout << i << " " << j << endl;
            pgmFile << getPixel(j,i) << " ";
        }// next column
        pgmFile << endl;
    }// next row

    // all done!
    pgmFile.close();
}
//ComplexNumber Constructor Definition
ComplexNumber::ComplexNumber(double i=0,double j=0){
    real=i;
    imaginary=j;
    }
//Method definition of ComplexNumber
    ComplexNumber ComplexNumber::add(ComplexNumber c2){
ComplexNumber outp=ComplexNumber(0,0);
outp.real=real+c2.real;
outp.imaginary=imaginary+c2.imaginary;
return outp;
    }
    ComplexNumber ComplexNumber::squared(){
ComplexNumber sq;
double resq,imsq;
resq=(real*real)-(imaginary*imaginary);
imsq=(2*real*imaginary);
sq.real=resq;
sq.imaginary=imsq;
return sq;
    }
double ComplexNumber::abs(){
    return sqrt((real*real)+(imaginary*imaginary));
}
void ComplexNumber::prt(){
        cout<< real << "+" <<imaginary<<"j"<<endl;
}
int main()
{
double cxmin=-1.35,cymin=0.01,cxmax=-1.240,cymax=0.125;

    string fileName = "sub_fractal";
    PGMImage *mandelbrot=new PGMImage(640,480,fileName);
    int xRes, yRes;

    mandelbrot->getResolution(xRes,yRes);

    int maxiter=255;
    int iter=0;

    ComplexNumber c8;

    for (int i=0;i<yRes;i++){
        for (int j=0;j<xRes;j++){
                double rl= cxmin + j/((double)xRes-1)*(cxmax-cxmin);
        double img=cymin + i/((double)yRes-1)*(cymax-cymin);

            ComplexNumber c8(rl,img);

            ComplexNumber z;
            iter=0;

            while (iter<maxiter && z.abs()<2) {
                z=(z.squared()).add(c8);
                iter++;
            }
            if(z.abs()>=2){
                mandelbrot->setPixel(j,i,iter);
            }
            else {
                mandelbrot->setPixel(j,i,0);
            }

        }
    }

    mandelbrot->writeFile();
    delete mandelbrot;

    return 0;
}

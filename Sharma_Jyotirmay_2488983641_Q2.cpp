#include <iostream>
#include <fstream>

#include "Sharma_Jyotirmay_2488983641_Q2.h"

using namespace std;

array2D::array2D(int xr,int yr){
        xRes=xr;
        yRes=yr;
        if (xr<=0 || yr<=0){
        cout<<"you are entering invalid xres or yres"<<endl;
        exit(1);  //For abnormal termination of program due to error
    }
        xtable=new float*[yRes];
        for(int i=0;i<yRes;i++){
            xtable[i]=new float[xRes];
        }
        for(int i=0;i < yRes;i++){
       for(int j=0;j < xRes;j++){
           xtable[i][j]=45; // store 45 for pixel data, "for now"
       }
    }
    }

array2D:: ~array2D() {
        for (int i=0;i<yRes;i++){
            delete[] *xtable;
        }
    delete[] xtable;
    }

void array2D::setValue(int x,int y,int val){
    xtable[y][x]=val;
}

void array2D::getSize(int &xResolution, int &yResolution){
    xResolution=xRes;
    yResolution=yRes;

}

int array2D::getVal(int x,int y){
return xtable[y][x];
}

PGMImage::PGMImage(int xResolution,int yResolution,string imageFilename):array2D(xResolution,yResolution) {
             filename=imageFilename;
             }
PGMImage::~PGMImage(){


    }

void PGMImage::getResolution(int& xResolution,int& yResolution){
    getSize(xResolution,yResolution);
}
void PGMImage::setPixel(int x,int y,int val){
    setValue(x,y,val);
}
int PGMImage::getPixel(int x,int y){
    return getVal(x,y);
}
void PGMImage::writeFile(){
    ofstream pgmFile(filename+".pgm");
    //header
    pgmFile << "P2" <<endl;
    pgmFile << xRes << " " << yRes << endl;
    pgmFile << 255 << endl;
    //pixel data
    for (int i=0;i<yRes;i++){
        for (int j=0;j<xRes;j++){
            pgmFile<<xtable[i][j]<< " ";
        }//next column
        pgmFile<<endl;
    }//next row

    pgmFile.close();

}



int main()
{
    string inputfilename="test";
    PGMImage *p=new PGMImage(320,240,inputfilename);
    int xRes,yRes;
    p->getResolution(xRes,yRes);

    for(int i=0;i < yRes;i++){
   for(int j=0;j < xRes;j++){
       p->setPixel(j,i,130); // constant value of 100 at all locations
   }


}

p->writeFile();
    for(int i=0;i < yRes;i++){
   for(int j=0;j < xRes;j++){
       cout << p->getPixel(j,i) << " ";
   }
   cout << endl;
}
delete p;
return 0;

}

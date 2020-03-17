#ifndef Sharma_Jyotirmay_2488983641_Q2_H_INCLUDED
#define Sharma_Jyotirmay_2488983641_Q2_H_INCLUDED


using namespace std;
//array2D class
class array2D{
protected:
    int xRes,yRes;
    float **xtable;
public:
    array2D(int xr,int yr);//constructor()

    ~array2D();  //destructor()
    //Methods of array2D class
    void setValue(int x,int y,int val);
    int getVal(int x,int y);
    void getSize(int &xResolution, int &yResolution);
};


//PGMImage class
class PGMImage: public array2D{
protected:
    string filename;
public:
    //Constructor
PGMImage(int xResolution,int yResolution,string imageFilename);
    //Destructor
~PGMImage();
void getResolution(int& xResolution,int& yResolution);
void setPixel(int x,int y,int val);
int getPixel(int x,int y);
void writeFile();
};





#endif // Q2_H_INCLUDED

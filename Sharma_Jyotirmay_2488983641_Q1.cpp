#include <iostream>

using namespace std;
//array2D class
class array2D{
protected:
    int xRes,yRes;
    float **xtable;
public:
    array2D(int xr,int yr);//constructor()
    ~array2D(); //destructor()
    //declaring class array2D methods
    void setValue(int x,int y,int val);
    int getVal(int x,int y);
    void getSize(int &xResolution, int &yResolution);
};
//array2D() constructor definition
array2D::array2D(int xr,int yr){
    xRes=xr; //xr is x-resolution passed by the user
    yRes=yr; //yr is y-resolution passed by the user
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
//array2D destructor definition
array2D::~array2D() {
        for (int i=0;i<yRes;i++){
            delete[] *xtable;
        }
    delete[] xtable;
    }

//defining class array2D methods
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

int main()
{
array2D *a = new array2D(320,240);
int xRes, yRes;
a->getSize(xRes,yRes);

//NOTE the j,i ordering below (twice), since we specify co-ords as (x,y) [not (y,x)]
for(int i=0;i < yRes;i++){
   for(int j=0;j < xRes;j++){
       a->setValue(j,i,100); // constant value of 100 at all locations
   }
}
for(int i=0;i < yRes;i++){
   for(int j=0;j < xRes;j++){
       cout << a->getVal(j,i) << " ";
   }
   cout << endl;
}

delete a;

} //main()

#include "Bitmap/bitmap.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(int argc, char* argv[])
{
  
  cout << argc << " arguments!" << endl;
  cout << argv[1] << endl;





  if (argc!=2)
{
  cout<<"Please specify one image file!\n";

}


  string filename=argv[1];
  Bitmap image;

  image.open(filename);

  if(image.isImage())
{  
  vector<vector< Pixel> > imagePixels = image.toPixelMatrix();
  cout<<" kendall.bmp is "<< imagePixels.size()<<"wide and "<<imagePixels[0].size()  << "high."<<endl;
}
  else
{ 
  cout<< "Image file must be a bitmap with 24-bit color depth.\n";
}
return 0;
}

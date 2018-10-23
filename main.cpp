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
  vector<vector<Pixel> > imagePixels;

  image.open(filename);

  if(image.isImage())
  {  
    imagePixels = image.toPixelMatrix();
    cout<<" kendall.bmp is "<< imagePixels.size()<<"wide and "<<imagePixels[0].size()  << "high."<<endl;
  }
  else
  { 
    cout<< "Image file must be a bitmap with 24-bit color depth.\n";
  }
    for(int col=0;col<imagePixels.size();col++)
    { 
      for(int row=0;row<imagePixels[col].size();row++)
      {
        Pixel color=imagePixels[col][row];
        color.green=0;
        color.blue=0;
        imagePixels[col][row]=color;
      }
    }
  image.fromPixelMatrix(imagePixels);
  image.save("redness.bmp");
  return 0;
}

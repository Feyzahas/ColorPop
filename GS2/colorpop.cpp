
#include<Magick++.h>

#include<iostream>
#include <cmath>

using namespace std;

using namespace Magick;

inline void normalize(Color c, double d[]) {
  d[0] = (double) c.redQuantum();
  d[1] = (double) c.greenQuantum();
  d[2] = (double) c.blueQuantum();

  double norm = sqrt(d[0]*d[0] + d[1]*d[1] + d[2]*d[2]);
  for (unsigned int i = 0; i < 3; ++i) {
    d[i] /= norm;
  }
}

inline double getL2Distance(Color c1, Color c2) {
  double d = 0;
  double d1[3], d2[3];
  normalize(c1, d1);
  normalize(c2, d2);
  for (unsigned int i = 0; i < 3; ++i) {
    d += pow(d1[i]-d2[i], 2.0);
  }
  return d;
}

void convert(double threshold, string filePath, float fx, float fy)
{
  

  Image image(filePath);

  int x_coord = fx * image.columns();
  int y_coord = fy * image.rows();
  
  Quantum red;
  Quantum green;
  Quantum blue;

  Quantum grayRed;
  Quantum grayGreen;
  Quantum grayBlue;
  //Color grayShade;


  Color baseColor = image.pixelColor(x_coord, y_coord);
  
  image.type(TrueColorType);
  image.modifyImage();
  Pixels view(image);

  PixelPacket *pixels = view.get(0,0,image.columns(), image.rows());

  for (unsigned int i = 0; i < image.rows(); ++i) {
    for (unsigned int j = 0; j < image.columns(); ++j) {

      Color tmp = image.pixelColor(j,i);
      double d = getL2Distance(tmp, baseColor);
      if (d < (threshold*threshold)) continue;
      red = tmp.redQuantum();
      green = tmp.greenQuantum();
      blue = tmp.blueQuantum();

      grayRed = (red + green + blue)/3;
      grayGreen = (red + green + blue)/3;
      grayBlue = (red + green + blue)/3;

      Color grayShade(grayRed, grayGreen, grayBlue);
      pixels[i*(image.columns()) + j] = grayShade;
    }
  }
  view.sync();
  image.write("graytest.jpg");
  printf("done\n");

}

int main2(int argc, char *argv[])
{
  InitializeMagick(*argv);
  convert(0.1, "test.jpg", 10, 10);
  return 0;
}



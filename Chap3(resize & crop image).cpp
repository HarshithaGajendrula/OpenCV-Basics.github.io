
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Resize and crop images  //////////////////////

void main() {

    string path = "resources/test.jpg";
    Mat img = imread(path);
    Mat imgResize, imgCrop;
    
    //--------------    resize image   --------------//
    
    //cout << img.size() << endl;    //to know image size.
    resize(img, imgResize, Size(500, 400));   
    //resize(img, imgResize, Size(), 0.5, 0.5);    //to resize the image by 50% you can choose any num.

    //--------------     crop image    --------------//

    Rect roi(100, 100, 200, 200);        //(x, y, Width, Height)
    imgCrop = img(roi);



    imshow("image", img);
    imshow("image Resize", imgResize);
    imshow("image Crop", imgCrop);
    waitKey(0);

}
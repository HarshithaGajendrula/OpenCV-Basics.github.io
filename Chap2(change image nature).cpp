
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Images  //////////////////////

void main() {

    string path = "resources/test.jpg";
    Mat img = imread(path);
    Mat imgGray , imgBlur, imgCanny, imgDil, imgErode;

    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, Size(7, 7), 3, 0);
    Canny(imgBlur, imgCanny,48 ,25);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
    dilate(imgCanny, imgDil, kernel);
    erode(imgDil, imgErode, kernel);

    imshow("image", img);
    imshow("image Gray", imgGray);
    imshow("image Blur", imgBlur);
    imshow("image Canny", imgCanny);
    imshow("image Dileation", imgDil);
    imshow("image Erode", imgErode);
    waitKey(0);

}
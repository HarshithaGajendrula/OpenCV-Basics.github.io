#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;



int main()
{
    // Load the cascade
    CascadeClassifier faceCascade;
    faceCascade.load("Resources/haarcascade_frontalface_default.xml");

    // Open the webcam
    VideoCapture cap(0);

    // Check if the webcam is opened successfully
    if (!cap.isOpened())
    {
        cout << "Failed to open the webcam" << endl;
        return -1;
    }

    // Create a window to display the webcam feed
    namedWindow("Face Detection", WINDOW_NORMAL);

    while (true)
    {
        // Read the current frame from the webcam
        Mat frame;
        cap.read(frame);

        // Convert the frame to grayscale
        Mat grayFrame;
        cvtColor(frame, grayFrame, COLOR_BGR2GRAY);

        // Detect faces in the frame
        vector<Rect> faces;
        faceCascade.detectMultiScale(grayFrame, faces, 1.1, 4);

        // Draw rectangles around the detected faces
        for (const auto& face : faces)
        {
            rectangle(frame, face, Scalar(0, 255, 0), 2);
        }

        // Display the frame with detected faces
        imshow("Face Detection", frame);

        // Check for 'Esc' key press to exit
        if (waitKey(1) == 27)
        {
            break;
        }
    }

    // Release the webcam and destroy the windows
    cap.release();
    destroyAllWindows();

    return 0;
}

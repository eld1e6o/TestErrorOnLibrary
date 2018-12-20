#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "processmatinlibrary_pub.h"

using namespace std;
using namespace cv;

#define _MAKE_ASSERT_OPENCV 1
//#define _MAKE_SEGFAULT_ 1

void testEmpty(cv::Mat test_img, std::string msg)
{
    cout << "* Check empty " << msg ;
    if(test_img.empty())
    {
        cout << ": Image is Empty " << endl;
        exit(1);
    }
    else cout << ": Image is not empty " << endl;
}

int main(int argc, char* argv[])
{
    // Classify and get probabilities
    Mat test_img = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    testEmpty(test_img, "After load image");

    cv::resize(test_img, test_img, cv::Size(256, 256));

    cout << " After resize " << endl;

    testEmpty(test_img, "Before initialize library ");

    ProcessMatInLibrary matToLibrary;

#ifdef _MAKE_SEGFAULT_
    return 0; // If I comment this line, I got a segmentation fault: Segmentation Fault (`core' generated)

#endif
    testEmpty(test_img, "After initialize library ");

    bool b = matToLibrary.flip(test_img);

    testEmpty(test_img, "After use function in library ");

    cout << "In main " << endl;
    /*
     * If I define _MAKE_ASSERT_OPENCV, I got errors
    OpenCV(3.4.1) Error: Assertion failed (0 <= _dims && _dims <= 32) in setSize, file /home/diego/Code/opencv/modules/core/src/matrix.cpp, line 209
    terminate called after throwing an instance of 'cv::Exception'
      what():  OpenCV(3.4.1) /home/diego/Code/opencv/modules/core/src/matrix.cpp:209: error: (-215) 0 <= _dims && _dims <= 32 in function setSize
    */
#ifndef _MAKE_ASSERT_OPENCV
    imshow("Test before close", test_img); //If i comment this two lines, I got segmentation faults (OpenCV exception)
    waitKey(0);
#endif
}

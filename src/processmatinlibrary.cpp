#include "processmatinlibrary.h"

using namespace std;
using namespace cv;

#include <iostream>

ProcessMatInLibrary::ProcessMatInLibrary()
{
    cout << "Initialized " << endl;
}

bool ProcessMatInLibrary::flip(cv::Mat image)
{
    cout << "** Inside Library: " << endl;
    if(image.empty())
    {
        cout << " Image is empty" << endl;
        return false;
    }
    cout << " Image is not empty " << endl;

    //    return false;
    Mat image2;
    cv::flip(image, image2, 0);

    imshow("Image in library", image);
    imshow("Image2 in library", image2);
    waitKey(0);

    cout << "Inside Library: Image is not empty" << endl;
    return true;
}


bool ProcessMatInLibrary::myTest(cv::Mat one)
{
    one.copyTo(_img);
}

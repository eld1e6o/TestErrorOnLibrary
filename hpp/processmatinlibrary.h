#ifndef PROCESSMATINLIBRARY_LIB_H
#define PROCESSMATINLIBRARY_LIB_H

#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>

class ProcessMatInLibrary
{
public:
    ProcessMatInLibrary();
    bool flip(cv::Mat image);
    bool myTest(cv::Mat one);
private:
    cv::Mat _img;
};

#endif // PROCESSMATINLIBRARY_LIB_H

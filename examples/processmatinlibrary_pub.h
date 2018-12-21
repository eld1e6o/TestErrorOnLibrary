#ifndef PROCESSMATINLIBRARY_H
#define PROCESSMATINLIBRARY_H

#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>

class ProcessMatInLibrary
{
public:
    ProcessMatInLibrary();
    bool flip(cv::Mat image);
    bool myTest(cv::Mat one);
    char discard[sizeof(cv::Mat)];
};

#endif // PROCESSMATINLIBRARY_H

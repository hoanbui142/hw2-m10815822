#include <iostream>
#include <fstream>

#include "hw2-m10815822.hpp"
#include "opencv2/calib3d/calib3d.hpp"

void ProjectiveGeometry::createSlave()
{
    cv::Mat img1 = cv::imread("First.JPG");
    cv::Mat mask = cv::imread("FirstMASK.bmp");
    cv::Mat slave;
    cv::bitwise_or(img1, mask, slave);
    //cv::imshow("Slave", slave);
    //cv::waitKey();
    cv::imwrite("Slave.JPG",slave);    

}

void ProjectiveGeometry::readCorrespondencesParams()
{
    
    list_First.push_back(cv::Point2f(263,282));
    list_First.push_back(cv::Point2f(336,383));
    list_First.push_back(cv::Point2f(463,397));
    list_First.push_back(cv::Point2f(677,278));
    list_First.push_back(cv::Point2f(711,447));
    list_First.push_back(cv::Point2f(788,383));

    list_Second.push_back(cv::Point2f(440,255));
    list_Second.push_back(cv::Point2f(498,332));
    list_Second.push_back(cv::Point2f(594,344));
    list_Second.push_back(cv::Point2f(752,263));
    list_Second.push_back(cv::Point2f(774,382));
    list_Second.push_back(cv::Point2f(827,339));

}

void ProjectiveGeometry::HomographyMat()
{
    cv::Mat im_src = cv::imread("Second.JPG");
    cv::Mat im_dst = cv::imread("Slave.JPG");
    cv::Mat h = cv::findHomography(list_Second, list_First);
    //std::cout << "H = \n" << h << std::endl;
    cv::Mat im_out;

    cv::warpPerspective(im_src, im_out, h, im_dst.size());

    //cv::imshow("Source Image:", im_src);
    //cv::imshow("Destination Image:", im_dst);
    //cv::imshow("Warped Source Image:", im_out);
    cv::imwrite("Warped.JPG",im_out);  
    //cv::waitKey();
}

void ProjectiveGeometry::InpainWhiteRegion()
{
    cv::Mat slave = cv::imread("FirstMASK.bmp");
    cv::Mat warped = cv::imread("Warped.JPG");
    cv::Mat inpain;
    cv::bitwise_and(slave, warped, inpain);
    //cv::imshow("Inpain", inpain);
    //cv::waitKey();
    cv::imwrite("Inpain.JPG",inpain); 
}
void ProjectiveGeometry::CombineIMG()
{
    cv::Mat slave = cv::imread("Slave.JPG");
    cv::Mat inpain = cv::imread("Inpain.JPG");
    cv::Mat combine;

    for (int i=0; )
    //cv::bitwise_and(slave, inpain, combine);
    cv::imshow("Combine", combine);
    cv::waitKey();
    cv::imwrite("M10815822.JPG",combine);    
}

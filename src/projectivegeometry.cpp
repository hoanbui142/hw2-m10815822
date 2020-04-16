#include "hw2-m10815822.hpp"
#include <iostream>
#include <fstream>

void ProjectiveGeometry::createSlave()
{
    cv::Mat img1 = cv::imread("First.JPG");
    cv::Mat mask = cv::imread("FirstMASK.bmp");
    cv::Mat slave;
    cv::bitwise_or(img1, mask, slave);
    //cv::imshow("Slave", slave);
    //cv::waitKey(0);
    cv::imwrite("Slave.JPG",slave);    

}

void ProjectiveGeometry::readCorrespondencesParams()
{
    std::ifstream paramFile("correspondences_params.txt");
    std::string line;

    while (std::getline(paramFile, line))
    {
        if (line.find("#First") != std::string::npos)
        {
            double First_CorrespondencesValue[3];
            for (int i = 0; i < 3; i++)
            {
                std::getline(paramFile, line);
                std::istringstream iss(line);
                iss >> First_CorrespondencesValue[i * 3 + 0] >> First_CorrespondencesValue[i * 3 + 1] >> First_CorrespondencesValue[i * 3 + 2];
            }
            First.push_back(cv::Mat(1, 3, CV_64F, First_CorrespondencesValue).clone());
        }
        else if (line.find("#Second") != std::string::npos)
        {
            double Second_CorrespondencesValue[3];
            for (int i = 0; i < 3; i++)
            {
                std::getline(paramFile, line);
                std::istringstream iss(line);
                iss >> Second_CorrespondencesValue[i * 3 + 0] >> Second_CorrespondencesValue[i * 3 + 1] >> Second_CorrespondencesValue[i * 3 + 2];
            }
            Second.push_back(cv::Mat(1, 3, CV_64F, Second_CorrespondencesValue).clone());
        }
        else
        {
            continue;
        }
    }
}

/*void ProjectiveGeometry::HomographyMat()
{

}

void ProjectiveGeometry::exportJPGFile()
{

}
*/
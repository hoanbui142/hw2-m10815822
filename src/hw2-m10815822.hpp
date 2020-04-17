#pragma once


#include <map>
#include <string>
#include <vector>

#include "opencv2/opencv.hpp"

struct Coord2dPoint
{
    float x;
    float y;
    float z = 1;
};
class ProjectiveGeometry
{
public:
    std::vector<cv::Point2f> list_First;
    std::vector<cv::Point2f> list_Second;

    void createSlave();
    void readCorrespondencesParams();
    void HomographyMat();
    void InpainWhiteRegion();
    void CombineIMG();
};
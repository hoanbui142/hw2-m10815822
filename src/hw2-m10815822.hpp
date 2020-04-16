#pragma once


#include <map>
#include <string>
#include <vector>

#include "opencv2/opencv.hpp"

/*struct Coord2dPoint
{
    int x;
    int y;
    int z = 1;
}; */
class ProjectiveGeometry
{
public:
    //ProjectiveGeometry (std::string CorrespondencesViewDataDir): correspondencesViewDataDir (CorrespondencesViewDataDir)
    std::vector<cv::Mat> First;
    std::vector<cv::Mat> Second;

    void createSlave();
    void readCorrespondencesParams();
    /*void HomographyMat();
    void exportJPGFile(std::string JPGFileURL);*/
};
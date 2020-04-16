#include <iostream>
#include <string>
#include <vector>

#include "opencv2/opencv.hpp"

struct Coord2dPoint
{
    int x;
    int y;
    int z = 1;
};
class ProjectiveGeometry
{
public:
    //ProjectiveGeometry (std::string CorrespondencesViewDataDir): correspondencesViewDataDir (CorrespondencesViewDataDir)
    void readCorrespondencesParams();
    void createSlave();
    void HomographyMat();
    void exportJPGFile(std::string JPGFileURL);
};
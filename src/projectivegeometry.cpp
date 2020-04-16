#include "hw2-m10815822.hpp"

void ProjectiveGeometry::createSlave()
{
    
}

void ProjectiveGeometry::readCorrespondencesParams()
{
    std::ifstream paramFile("correspondences_params.txt");
    std::string line;

    while (std::getline(paramFile, line))
    {
        if (line.find("#First") != std::string::npos)
        {
            continue;
        }
        else if (line.find("#Second") != std::string::npos)
        {
            continue;
        }
        else
        {
            continue;
        }
    }
}

void ProjectiveGeometry::HomographyMat()
{

}

void ProjectiveGeometry::exportJPGFile()
{

}

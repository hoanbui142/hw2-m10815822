#include "hw2-m10815822.hpp"

int main(int argc, char const *argv[])
{
    ProjectiveGeometry project2D;
    project2D.createSlave();
    project2D.readCorrespondencesParams();
    project2D.HomographyMat();
    project2D.InpainWhiteRegion();
    project2D.CombineIMG();

    return 0;    
}
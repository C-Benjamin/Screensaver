#ifndef PBM_H_INCLUDED
#define PBM_H_INCLUDED

typedef struct Plane Plane;
struct Plane
{
    int direction;
    int xpos;
    int ypos;
    int planeImage[6][6];

};

typedef struct Background Background;
struct Background
{
    Plane plane;
    int height;
    int width;
    int** grid;

};

void fillGridWithImage(int** &background.grid, char* imageName);

#endif // PBM_H_INCLUDED

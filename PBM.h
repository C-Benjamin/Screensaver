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

typedef struct Pbm Pbm;
struct Pbm
{
    int width;
    int height;
    char imageName[100];
};


#endif // PBM_H_INCLUDED

#ifndef CAMERA_H
#define CAMERA_H

#include "hittable.h"
#include "utils.h"

class camera{
    public:
        double aspectRatio = 1.0;
        int imageWidth = 100;
        int samplePerPixel = 10;
        int maxDepth = 10;

        double vfov = 90;

        point3 lookFrom = point3(0,0,0);
        point3 lookAt = point3(0,0,-1);
        vec3 vUp = vec3(0,1,0);

        double defocusAngle = 0.0;
        double focusDist = 10.0;

        void render(const hittable& world);



        

    private:
        int    imageHeight;   // Rendered image height
        double pixelSampleScale;
        point3 center;         // Camera center
        point3 pixel00Loc;    // Location of pixel 0, 0
        vec3   pixelDeltaU;  // Offset to pixel to the right
        vec3   pixelDeltaV;  // Offset to pixel below

        vec3 u,v,w;
        vec3 defocusDiskU;
        vec3 defocusDiskV;

        //void initialize(double ,vfov double aspectRatio, double aperture, double focusDist);
        void initialize();
        color rayColor(const ray& r,int depth, const hittable& world) const;
        ray getRay(int i, int j) const;
        vec3 sampleSquare() const;

        point3 defocusDiskSample() const;
};


#endif
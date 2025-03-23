#include <iostream>
#include <iomanip>
#include <thread>
#include "vec3.h"
#include "color.h"
#include "ray.h"

double hit_sphere(const point3& center, double radius, const ray& r){
    vec3 oc = center - r.origin();
    auto a = r.direction().length_squared();
    auto h = dot(oc, r.direction());
    auto c = oc.length_squared() - radius*radius;
    auto discriminant = h*h - a*c;
    
    if (discriminant < 0)
    {
        return -1.0;
    }
    else
    {
        return (h - std::sqrt(discriminant)) / (a);
    }
}
color ray_color(const ray& r){

    // std::clog << r.direction() << "\n";
    // std::this_thread::sleep_for(std::chrono::milliseconds(100));

    auto t = hit_sphere(point3(0,0,-1), 0.5, r);
    //std::clog << t << "\n";

    if(t > 0.0)
    {
        vec3 N = unit_vector(r.at(t) - vec3(0,0,-1));
        return 0.5*color(N.x()+1, N.y()+1, N.z()+1);
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}



int main() {

    //Image 

    auto aspectRatio = 16.0 / 9.0;
    int imageWidth = 400;

    //Calculate the height of the image
    int imageHeight = static_cast<int>(imageWidth / aspectRatio);
    imageHeight = (imageHeight < 1 ) ? 1: imageHeight;

    //Camera
    auto focalLength = 1.0;
    auto viewportHeight = 2.0;
    auto viewportWidth = aspectRatio * viewportHeight;
    auto cameraCenter = point3(0,0,0);

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    auto viewportU = vec3(viewportWidth, 0, 0);
    auto viewportV = vec3(0, -viewportHeight, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    auto pixelDeltaU = viewportU / imageWidth;
    auto pixelDeltaV = viewportV / imageHeight;

    // Calculate the location of the upper left pixel.
    auto viewportUpperLeft = cameraCenter - vec3(0,0, focalLength) - viewportU/2 - viewportV/2;
    auto pixel00Loc = viewportUpperLeft + 0.5 * (pixelDeltaU + pixelDeltaV);

    std::clog << "viewportWidth: " << viewportWidth << " viewportHeight: " << viewportHeight << "\n";
    std::clog << "viewportU: " << viewportU << " viewportV: " << viewportV << "\n";
    std::clog << "imageWidth: " << imageWidth << " imageHeight: " << imageHeight << "\n";
    std::clog << "pixelDeltaU: " << pixelDeltaU << " pixelDeltaV: " << pixelDeltaV << "\n";

    std::clog << "viewportUpperLeft: " << viewportUpperLeft << "\n";
    std::clog << "pixel00Loc: " << pixel00Loc << "\n";

    // Render

    std::cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";
    for (int j = 0; j < imageHeight; j++)
    {
        std::clog << "\rScanlines remaining: " << (imageHeight - j) << ' ' << std::flush;
        for (int i = 0; i < imageWidth; i++)
        {
            auto pixelCenter = pixel00Loc + (i * pixelDeltaU) + (j * pixelDeltaV);
            auto rayDirection = pixelCenter - cameraCenter;
            ray r(cameraCenter, rayDirection);
            color pixelColor = ray_color(r);
            write_color(std::cout, pixelColor);
        }
        
    }
    


    
}
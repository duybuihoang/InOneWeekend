#include "utils.h"
#include "hittableList.h"
#include "sphere.h"
#include "camera.h"
#include "material.h"
#include "lambertian.h"
#include "metal.h"
#include "dielectric.h"

int main() {

    hittableList world;

    //TODO: THỬ DÙNG GƯƠNG CẦU LÕM ĐỂ PHẢN XẠ ÁNH SÁNG
    
    auto materialGround = std::make_shared<lambertian>(color(0.8, 0.8, 0.0));
    auto materialCenter = std::make_shared<lambertian>(color(0.1, 0.2, 0.5));
    //auto materialLeft = std::make_shared<metal>(color(0.8, 0.8, 0.8), 0.3);
    auto materialLeft = std::make_shared<dielectric>(1.5);
    auto materialBubble = std::make_shared<dielectric>(1.0 / 1.5);
    auto materialRight = std::make_shared<metal>(color(0.8, 0.6, 0.2), 0.8);


    world.add(std::make_shared<sphere>(point3(0,-100.5,-1), 100, materialGround));
    world.add(std::make_shared<sphere>(point3(0,0,-1.2), 0.5, materialCenter));
    world.add(std::make_shared<sphere>(point3(-1,0,-1), 0.5, materialLeft));
    world.add(std::make_shared<sphere>(point3(-1,0,-1), 0.2, materialBubble));
    world.add(std::make_shared<sphere>(point3(1,0,-1), 0.5, materialRight));

    // auto R = cos(pi/4);

    // auto materialLeft = std::make_shared<lambertian>(color(0, 0, 1));
    // auto materialRight = std::make_shared<lambertian>(color(1, 0, 0));

    // world.add(std::make_shared<sphere>(point3(-R, 0, -1), R, materialLeft));
    // world.add(std::make_shared<sphere>(point3( R, 0, -1), R, materialRight));

   camera cam;
   cam.aspectRatio = 16.0 / 9.0;
   cam.imageWidth = 800;
   cam.samplePerPixel = 100;
   cam.maxDepth = 50;

   cam.vfov = 90;
   cam.lookFrom = point3(-2, 2, 1);
    cam.lookAt = point3(0, 0, 0);
    cam.vUp = vec3(0, 1, 0);

   cam.render(world);

   return 0;  


    
}
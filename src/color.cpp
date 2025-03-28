#include "color.h"

void write_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    //convert to gamma corrected value
    r = linearToGamma(r);
    g = linearToGamma(g);
    b = linearToGamma(b);


    // Translate the [0,1] component values to the byte range [0,255].
    static const interval intensity (0.000, 0.999);
    int rbyte = int(256 * intensity.clamp(r));
    int gbyte = int(256 * intensity.clamp(g));
    int bbyte = int(256 * intensity.clamp(b));

    // Write out the pixel color components.
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

double linearToGamma(double linearComponent) {
    if(linearComponent > 0.0) {
        return sqrt(linearComponent);
    }
    return 0.0;
}
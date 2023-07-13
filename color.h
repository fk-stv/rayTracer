#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <iostream>


// write_color() function
// returns void
// parameters: reference to ostream, color (vec3) object
/*
void write_color(std::ostream &out, color pixel_color) {
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}
*/

/*New write_color function, with multi-sampling for antialiasing*/
void write_color(std::ostream &out, color pixel_color, int samples_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();
    
    // Divide color by number of samples
    auto scale = 1.0 / samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;
    
    // Write translated [0,255] value of each color component
    out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}


/*
What did I learn coding this?

static_cast<destination type>(source type)
    unary operator that casts one type to anyther
    compile-time casts
    implicit and explicit conversions
    
255.999 explanation
    this was lost on me earlier
    our range of colors, while doing math and stuff, is 0-255
    but our color range in the image output should be 1-256
    therefore, we do this fancy stuff with 255.999 to adjust our domain

*/

#endif
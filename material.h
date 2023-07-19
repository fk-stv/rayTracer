#ifndef MATERIAL_H
#define MATERIAL_H

#include "rtweekend.h"

struct hit_record;

class material {
	public:
	/* shirley says we use 'hit_record' here to 'avoid a bunch of arguments so we can stuff w.e. info we want here' ... 
		not entirely sure what that means ...
		apparently, hit_record is a way for us to 'stuff a bunch of arguments into a struct'
			slightly better explanation... but still ... kind of an odd way to describe a struct in my amateur opinion
		when a ray hits a surface, the material pointer in hit_record will be set to the surface's material pointer that
		was given to it during initialization from main()
	*/
		virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const = 0;
};

#endif


/* WDIL 19JUL23 
	we make this abstract material class in order to render multiple materials
	generally, there are two options:
		we can have a universal material and when a ray impacts a material, that specific material has
		properties that zero-out some of the universal properties, giving us our desired material
			shirley says this is not a bad approach, but there is another ...
		the second approach involves writing a class that 'encapsulates' this behavior
			this is the approach we are gonna use, which means the class must achieve two things:
				1 produce a scattered ray (or absorb the incident ray)
				2 if scattered, say how much the ray should be attenuated (reduced in effect/force)
*/
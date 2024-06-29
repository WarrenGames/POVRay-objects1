#version 3.7;

#declare Radiosity = true;

global_settings{ assumed_gamma 1.0 
	#if( Radiosity 
	)
		#default{ finish{ ambient 0 } }
		radiosity{
			pretrace_start 64 / image_width
			pretrace_end 2 / image_width
			count 800
			nearest_count 9
			error_bound 0.2
			recursion_limit 1
			gray_threshold 0.65
			brightness 0.95
		}
	#end
}

camera{
	location < 1, 5, -4 >
	look_at < 0, 2, 0 >
}

light_source{ < -2, 10, -5 > * 100 color srgb < 1, 0.9, 0.8 > }

#include "pneumaticBoat.inc"

#declare PneumaticBoatSize = max_extent( PneumaticBoat ) - min_extent( PneumaticBoat );
#declare BoatScale = 0.01;

object{ PneumaticBoat translate -PneumaticBoatSize / 2 scale BoatScale rotate 75 * y translate < 0, PneumaticBoatSize.y * BoatScale * 0.75, 4 > }

#declare ColorBrigthness = 0.85;

#declare SandTexture = 
texture{
	pigment{ color srgb < 1 * ColorBrigthness, 0.9 * ColorBrigthness, 0.65 * ColorBrigthness > }
	normal{ granite 0.95 scale 0.05 }
	finish{ 
		specular 0.1
		roughness 0.05
	}
}

#declare GroundPig = 
pigment{ bumps color_map {
						[ 0 color srgb 0.5 ]
						[ 0.5 color srgb 0.525 ]
						[ 1.0 color srgb 0.5 ] }
						scale < 0.035, 0.035, 1 >
}

height_field{
	function 2048, 2048 
	{ 
		pigment{ GroundPig }
	}
	smooth 
	translate < -0.5, 0, -0.5 >
	rotate 10 * x
	scale < 40, 3, 40 >
	translate < 0, 0, -20 >
	texture{ SandTexture }
}

#declare WaterTexture = 
texture{
	pigment{ color srgb < 0.02 * 1.2, 0.1 * 1.2, 0.15 * 1.2 > }
	finish{ ambient 0.15 diffuse 0.55 brilliance 6.0 phong 0.8 phong_size 120 reflection 0.45 emission 0 }
	normal{ bumps 0.5 scale <1,0.25,0.25> turbulence 0.6 }
}	

plane{ y, 0 texture{ WaterTexture } }

#macro MakeSky( BottomBlue, TopBlue, EmissionVect )
	#declare SkyPigment = pigment{ gradient y color_map{
													[0.0 BottomBlue ]
													[0.75 TopBlue ]
													}
						}
	sky_sphere{ pigment{SkyPigment} }
						
	sphere{0, 1 
		pigment{ SkyPigment }
		finish{ diffuse 0 emission EmissionVect }
		hollow on 
		no_shadow
		no_image
		no_reflection
		scale 40000
	}
#end

MakeSky( color srgb < 0.8, 0.8, 1 >, color srgb < 143 / 255, 195 / 255, 251 / 255 >, 3 )
#version 3.7;

global_settings{ assumed_gamma 1.0 }

#include "mushroom1.inc"

camera{
	location < 0, 2, -5>
	look_at < 0, 2, 0>
	right image_width / image_height * x
	up y
	sky y
}

light_source{ <1, 1, -3> * 100 color srgb 1 }

plane{ y, 0 pigment{ color srgb < 128, 85, 59 > / 255 } }

MakeCustomMushroom( 5, 79230, 0.2, < 5, 0, 4 >, < -2, 0, 0 >, 1 )
MakeCustomMushroom( 3, 1789, 0.3, < -5, 0, -4 >, < 0, 0, 0 >, 1 )
MakeCustomMushroom( 4, 79, 0.25, < 0, 0, 0 >, < 2, 0, 0 >, 1 )

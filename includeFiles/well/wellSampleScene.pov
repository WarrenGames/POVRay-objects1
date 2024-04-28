/*
This is a sample scene for the well (in ./includes/well.inc file )
	The 'well.inc' include file is independant, so you can
	use it without the need of including other files before.
	'well.inc' needs 'woods.inc', but this latter file is a POVRay
	standard file installed with any recent versions of POVRay.
*/

#version 3.7;

#declare Radiosity = true;

global_settings{ assumed_gamma 1.0 
	#if( Radiosity )
		#default{ finish{ ambient 0 } }

		radiosity{
			pretrace_start 64 / image_width
			pretrace_end 2 / image_width
			error_bound 0.25
			minimum_reuse 0.01
			nearest_count 9
			count 800
			recursion_limit 1
			always_sample off
			gray_threshold 0.6
			low_error_factor 0.7
			brightness 1
			adc_bailout 0.01/2
			normal on
			media on
		}
	#end
}

background{ color srgb < 167 / 255, 213 / 255, 220 / 255 > }

camera{
	right image_width / image_height * x
	up y
	location < 0, 2.25, -2.5 >
	look_at < 0, 2, 0 >
}

light_source{ < 1 , 4, -4 > * 100 color srgb 1 }

#declare WellThingsPosition = < 0, 0, 3.5 >;

#include "includes/well.inc"
#include "includes/wellSide.inc"

object{ CompleteWell rotate 48 * y translate WellThingsPosition }

object{ WellBottomStones translate WellThingsPosition - < 0, 0.125, 0 > }

plane{ y, -0.2 pigment{ checker color srgb 0.7, color srgb 0.5 } }
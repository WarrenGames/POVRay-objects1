#version 3.7;

#declare Radiosity = true;

global_settings
{
	assumed_gamma 1.0 		
	#default{ finish{ambient 0} }
	#if( Radiosity 
	)
		radiosity{
			pretrace_start 64 / image_width
			pretrace_end   2 / image_width
			error_bound 0.2
			minimum_reuse 0.01
			nearest_count 9
			count 800
			recursion_limit 1
			always_sample off
			low_error_factor 0.7
			gray_threshold 0
			brightness 1
			normal on
			media on
		}
	#end
}

background{ color srgb 1 }

camera{
	location < 1, 2, -4 >
	look_at < 0, 1.65, 0 >
	sky y
	right x * image_width / image_height
	up y
}

light_source{ < 3, 7, -5 > * 1000 color srgb 1.2 }

plane{ y, 0 pigment{ checker color srgb 0.65, color srgb 0.6 } }

#include "outdoorsLamp.inc"

#declare Position = < 0, 0, 0 >;
#declare Scale = 1 / 225;

object{ CompleteLamp scale Scale rotate 30 * y translate Position }


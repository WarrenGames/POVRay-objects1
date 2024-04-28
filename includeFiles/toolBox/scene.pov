#version 3.7;

global_settings{ assumed_gamma 1.0
		#declare P_start = 64 / image_width;
		#declare P_end_final = 2 / image_width;
		#default{ finish{ambient 0} }
		
		radiosity{
			pretrace_start P_start
			pretrace_end   P_end_final
			error_bound 0.1
			minimum_reuse 0.01
			nearest_count 9
			count 800
			recursion_limit 1
			always_sample off
			low_error_factor 0.5
			gray_threshold 0.65 //More than 0.5
			brightness 1
			normal on
			media on
		}
}

camera{
	location < 6, 7, -8 >
	look_at < 0, 3.5, -2 >
	sky y
	right image_width / image_height * x
	up y
}

light_source{ < 4, 8, -5 > * 1000 color srgb 1 }

#include "toolsBox.inc"

object{ ToolsBox }

plane{ y, 0 pigment{ checker color srgb 0.7, color srgb 0.8 } }
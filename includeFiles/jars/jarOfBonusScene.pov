#version 3.7;

#declare Radiosity = true;

global_settings{ assumed_gamma 1.0 
	max_trace_level 30
	#if( Radiosity )
		#default{ finish{ ambient 0 } }
		radiosity{
				pretrace_start 64 / image_width
				pretrace_end 2 / image_width
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

camera{
	location < 0, 5, -16 >
	look_at < 0, 3.75, 0 >
	right image_width / image_height * x
	up y
	sky y
	
}

light_source{ < 2, 8, -4 > * 1000 color srgb 1 }

plane{ y, 0 
	pigment{ checker color srgb 0.5, color srgb 0.65 }
}

plane{ z, 6
	pigment{ checker color srgb < 119, 69, 87 >/ 255, color srgb < 183, 231, 102 > / 255 }
}

#include "jarOfBonus.inc"

//A jar with yellow cap
CreateSimpleCompleteJar( 1, < -6, 0.001, 0 >, color srgb < 1, 1, 0> )

//A labelled jar with blue cap
CreateLabeledCompleteJar( 1, < 0, 0.001, 0>, color srgb < 0, 0, 1> , "timbre.png", 1.5, -70)

//A jar with red cap without label
CreateSimpleCompleteJar( 1, < 6, 0.001, 0 >, color srgb < 1, 0, 0> )

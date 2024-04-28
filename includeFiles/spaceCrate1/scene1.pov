#version 3.7;

global_settings{ assumed_gamma 1.0 
	#default{ finish{ ambient 0 } }
	radiosity{
		pretrace_start 64 / image_width
		pretrace_end 2 / image_width
		error_bound 0.1 
		minimum_reuse 0.01
		nearest_count 9
		count 800
		recursion_limit 2
		always_sample off
		low_error_factor 0.7
		gray_threshold 0
		brightness 1
		normal on
		media on
	}
}

camera{
    location < -3, 4, -4 >
    look_at < 0, 2.6, 0 >
}

light_source{ < -4, 8, -3 > * 100 color srgb 1 }

#include "spaceCrate1.inc"

object{ SpCr1_CompleteCover translate < 3, 0, 4 >}

object{ SpCr1_CompleteCoverWithAttachs rotate 180 * x rotate 5 *y translate < 1, SpCr1_CoverHeight, 1 > }

object{ SpCr1_CompleteCrateWithCover rotate 63 * y translate < -1, 0, 4.5 > }

object{ SpCr1_ContainBox translate < 4, 0, 0 > }

plane{ y, 0 pigment{ checker color srgb 0.5, color srgb 0.65 } }

plane{ -z, -10 pigment{ checker color srgb 0.5, color srgb 0.65 } }
plane{ -x, -10 pigment{ checker color srgb 0.5, color srgb 0.65 } }
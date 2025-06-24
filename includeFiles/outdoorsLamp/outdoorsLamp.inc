//An outdoor lamp
/*
	Author: Antoine FAURE.
	Licence of this file: free for educational, commercial or other usage.
	
	To use the lamp in any of your scene just add this line after having included this 
		file to your scene:
	'object{ CompleteLamp }'
	Of course any translate, rotate, or scale works fine for that object.
	All of the declared pigment, finish, normal, texture, macro, or objects have
	been prefixed with 'Lamp_' to avoid collision with anything else in a scene.
*/

#declare Lamp_FootSplinePtNum = 50;
#declare Lamp_BaseFootSide = 40;
#declare Lamp_BasePyramidSide = Lamp_BaseFootSide - 10;
#declare Lamp_BasePyramidHighness = 274;
#declare Lamp_FootLength = 47;

#declare Lamp_StructColor = color srgb < 66 / 255, 49 / 255, 42 / 255 >;
#declare Lamp_StructFinish = finish{ specular 0.05 roughness 0.25 metallic }
#declare Lamp_StructTexture = texture{ pigment{ Lamp_StructColor } finish{ Lamp_StructFinish } }                              

#declare Lamp_FirstRingRadius = 25;
                              
#declare Lamp_Foot =
lathe{
    linear_spline
    Lamp_FootSplinePtNum + 2,
    < 0, 0 >
    #for( It, 0, Lamp_FootSplinePtNum - 1 )
		< 	Lamp_FootLength - vrotate( <0, -7,0 >, < 0, 0, 90 / ( Lamp_FootSplinePtNum - 1 ) * It >).x,
			7 + vrotate( <0, -7,0 >, < 0, 0, 90 / ( Lamp_FootSplinePtNum - 1 ) * It >).y >
    
    #end
    < 0, 0 >
    sturm
    texture{ Lamp_StructTexture }
}
    
#declare Lamp_BasePyramid =
prism{ conic_sweep linear_spline 1, 0.5, 5 < -Lamp_BasePyramidSide / Lamp_BasePyramidHighness, 0>, 
                                           < 0, Lamp_BasePyramidSide / Lamp_BasePyramidHighness >, 
                                           < Lamp_BasePyramidSide / Lamp_BasePyramidHighness, 0 >, 
                                           < 0, -Lamp_BasePyramidSide / Lamp_BasePyramidHighness>,
                                           < -Lamp_BasePyramidSide / Lamp_BasePyramidHighness, 0> 
    rotate 180*x
    rotate 45*y
    translate y                                           
    scale Lamp_BasePyramidHighness
    texture{ Lamp_StructTexture }
}

#declare Lamp_BumpPyramid =
prism{ conic_sweep linear_spline 0.95, 0.55, 5 < -Lamp_BasePyramidSide / Lamp_BasePyramidHighness, 0>, 
                                           < 0, Lamp_BasePyramidSide / Lamp_BasePyramidHighness >, 
                                           < Lamp_BasePyramidSide / Lamp_BasePyramidHighness, 0 >, 
                                           < 0, -Lamp_BasePyramidSide / Lamp_BasePyramidHighness>,
                                           < -Lamp_BasePyramidSide / Lamp_BasePyramidHighness, 0> 
    rotate 180*x
    rotate 45*y
    translate y                                           
    scale < Lamp_BasePyramidHighness * 1.15, Lamp_BasePyramidHighness, Lamp_BasePyramidHighness * 0.7 >
    texture{ Lamp_StructTexture }
}

//Rings
#declare Lamp_FR_TorusSmallRadius = 7;
#declare Lamp_FR_TorusBigRadius = 18;
#declare Lamp_FR_SphereRadius = Lamp_FR_TorusSmallRadius + Lamp_FR_TorusBigRadius;
#declare Lamp_FR_BottomSphere = sphere{ 0, 1 scale < Lamp_FR_SphereRadius, 
												(Lamp_FR_SphereRadius) / 1.5 , 
												Lamp_FR_SphereRadius > }
#declare Lamp_FR_MiddleTorus = torus{ Lamp_FR_TorusBigRadius, Lamp_FR_TorusSmallRadius sturm }

#declare Lamp_FirstRingYScale = 0.8;
#declare Lamp_SecondRingYScale = 1.3;
#declare Lamp_FirstRingYPos = Lamp_BasePyramidHighness * 0.5 + 14;
#declare Lamp_SecondRingYPos = Lamp_FirstRingYPos + (Lamp_FR_TorusSmallRadius * 2 + Lamp_FR_SphereRadius / 1.5 ) * Lamp_FirstRingYScale;

#declare Lamp_SmallRingYPos = Lamp_SecondRingYPos + Lamp_SecondRingYScale * (Lamp_FR_TorusSmallRadius * 2 + Lamp_FR_SphereRadius / 1.5 );
#declare Lamp_LongStalkHighness = 414;

#declare Lamp_CompleteFirstRing = 
union{
	difference{
		object{ Lamp_FR_BottomSphere }
		box{ < -Lamp_FR_SphereRadius, 0, -Lamp_FR_SphereRadius >, < Lamp_FR_SphereRadius, Lamp_FR_SphereRadius, Lamp_FR_SphereRadius > }
		translate Lamp_FR_SphereRadius / 1.5 * y 
	}
	object{ Lamp_FR_MiddleTorus translate Lamp_FR_SphereRadius / 1.5 * y }
	difference{
		cylinder{ <0,0,0>, <0, -Lamp_FR_TorusSmallRadius,0>, Lamp_FR_TorusBigRadius }
		object{ Lamp_FR_MiddleTorus }
		translate (Lamp_FR_TorusSmallRadius * 2 + Lamp_FR_SphereRadius / 1.5) * y
	}
	texture{ Lamp_StructTexture }
}

#declare Lamp_CageScale = 48 / 2;
#declare Lamp_BrancheRadius = 3.5 / Lamp_CageScale;
#declare Lamp_BrancheHorizStart = 0.25;
#declare Lamp_BrancheYPos = Lamp_SmallRingYPos + Lamp_LongStalkHighness;
#declare Lamp_CageYPos = Lamp_SmallRingYPos + Lamp_LongStalkHighness + Lamp_CageScale;

#declare Lamp_CageBranche =
sphere_sweep{
	cubic_spline
	7,
	< -Lamp_BrancheHorizStart, -1, - Lamp_BrancheHorizStart>, Lamp_BrancheRadius,
	< -Lamp_BrancheHorizStart, -0.5, - Lamp_BrancheHorizStart>, Lamp_BrancheRadius,
	< -0.4, 0, -0.4>, Lamp_BrancheRadius,
	< -0.6, 0.25, -0.6>, Lamp_BrancheRadius,
	< -0.8, 0.35, -0.8>, Lamp_BrancheRadius,
	< -1, 0.5, -1>, Lamp_BrancheRadius,
	< -1.125, 0.5, -1.125>, Lamp_BrancheRadius
	//tolerance 1.0e-4
	translate 0.5 * y
	scale Lamp_CageScale
	texture{ Lamp_StructTexture }
}

#declare Lamp_CageEdgeFactor = 1/32;
#declare Lamp_CageScaleMin = 0.9;
#declare Lamp_CageScaleMax = 1.5;

#declare Lamp_Cage = 
difference{
	prism{ conic_sweep linear_spline 1, 2/3, 5, < -0.5, 0.5 >, < 0.5, 0.5 >, < 0.5, -0.5 >, < -0.5, -0.5 >, < -0.5, 0.5 >
		translate -2 / 3 * y
	}
	prism{ conic_sweep linear_spline 1 - Lamp_CageEdgeFactor, 2/3 + Lamp_CageEdgeFactor, 5
		, < -0.5, 0.5 >, < 0.5, 0.5 >, < 0.5, -0.5 >, < -0.5, -0.5 >, < -0.5, 0.5 >
		translate -2 / 3 * y
		scale < Lamp_CageScaleMin, 1, Lamp_CageScaleMax >
	}
	prism{ conic_sweep linear_spline 1 - Lamp_CageEdgeFactor, 2/3 + Lamp_CageEdgeFactor, 5
		, < -0.5, 0.5 >, < 0.5, 0.5 >, < 0.5, -0.5 >, < -0.5, -0.5 >, < -0.5, 0.5 >
		translate -2 / 3 * y
		scale < Lamp_CageScaleMax, 1, Lamp_CageScaleMin >
	}
	scale < 3, 9, 3>
	scale Lamp_CageScale
	translate Lamp_CageYPos * y
	texture{ Lamp_StructTexture }
}

#declare Lamp_FirstHatYPos = Lamp_CageYPos + 3 * Lamp_CageScale;
#declare Lamp_FirstHatSide = 3;
#declare Lamp_FirstHatYScale = 1.2;

#declare Lamp_FirstHat =
prism{ conic_sweep linear_spline 1, 0.75,5,
		< -Lamp_FirstHatSide, Lamp_FirstHatSide >, < Lamp_FirstHatSide, Lamp_FirstHatSide >,
		< Lamp_FirstHatSide,-Lamp_FirstHatSide>, < -Lamp_FirstHatSide, -Lamp_FirstHatSide>, < -Lamp_FirstHatSide, Lamp_FirstHatSide >
	rotate 180*x
	translate y
	scale Lamp_CageScale * < 0.6, Lamp_FirstHatYScale, 0.6 >
	translate Lamp_FirstHatYPos * y
	texture{ Lamp_StructTexture }
}

#declare Lamp_SecondHatYPos = Lamp_FirstHatYPos + 0.25 * Lamp_FirstHatYScale;
#declare Lamp_SecondHatSide = 1/3;
#declare Lamp_SecondHatScale = <4,5.5,4>;

#declare Lamp_SecondHat =
prism{ conic_sweep linear_spline 1, 7/9, 5, 
		< -Lamp_SecondHatSide, Lamp_SecondHatSide >,< Lamp_SecondHatSide, Lamp_SecondHatSide >,
		< Lamp_SecondHatSide, -Lamp_SecondHatSide>,< -Lamp_SecondHatSide, -Lamp_SecondHatSide >, < -Lamp_SecondHatSide, Lamp_SecondHatSide >
	rotate 180*x
	translate y
	scale Lamp_CageScale * Lamp_SecondHatScale
	translate Lamp_SecondHatYPos * y
	texture{ Lamp_StructTexture }
}

#declare CompleteLamp =
    union{
        object{ Lamp_Foot }
        object{ Lamp_Foot scale < 1 / Lamp_FootLength * Lamp_BaseFootSide, 1, 1 / Lamp_FootLength * Lamp_BaseFootSide> translate 7 * y }
        object{ Lamp_BasePyramid translate 14 * y }
        object{ Lamp_BumpPyramid translate 14 * y }
        object{ Lamp_BumpPyramid translate 14 * y rotate 90 * y }
        object{ Lamp_CompleteFirstRing scale < 1, Lamp_FirstRingYScale, 1 > translate Lamp_FirstRingYPos * y }
        object{ Lamp_CompleteFirstRing scale < 0.8, Lamp_SecondRingYScale, 0.8 > translate Lamp_SecondRingYPos * y }
		cylinder{ 	< 0, Lamp_FirstRingYPos, 0 >, 
					< 0, Lamp_SecondRingYPos + Lamp_SecondRingYScale * ( Lamp_FR_TorusSmallRadius * 2 + Lamp_FR_SphereRadius / 1.5 ) * 0.5, 0 >,
					Lamp_FR_TorusBigRadius - Lamp_FR_TorusSmallRadius
					texture{ Lamp_StructTexture }
		}
		torus{ Lamp_FR_TorusSmallRadius, Lamp_FR_TorusSmallRadius / 2 
				translate Lamp_SmallRingYPos * y
				texture{ Lamp_StructTexture } }
		cylinder{ < 0, Lamp_SmallRingYPos, 0  >,< 0, Lamp_SmallRingYPos + Lamp_LongStalkHighness, 0>, Lamp_FR_TorusSmallRadius 
				texture{ Lamp_StructTexture } }
		torus{ Lamp_FR_TorusSmallRadius + Lamp_FR_TorusSmallRadius / 2, Lamp_FR_TorusSmallRadius 
				translate ( Lamp_SmallRingYPos + Lamp_LongStalkHighness ) * y 
				texture{ Lamp_StructTexture } }
		#for( Rot, 0, 3 )
			object{ Lamp_CageBranche rotate Rot * 90 * y translate Lamp_BrancheYPos * y }
		#end
		object{ Lamp_Cage }
		object{ Lamp_FirstHat }
		object{ Lamp_SecondHat }
    }

#macro PlaceLight( LampPosParam, LampScaleParam, LightColor )
	#local Lamp_NewPosition = LampPosParam + < 0, LampCageYPos * LampScaleParam * 1.05, 0>;
	sphere{ 0, 1 hollow no_shadow pigment{ color srgbft <0, 0, 0, 0, 1> }
		interior{
			media{
				emission color srgb 1 samples 1, 30 intervals 10
				density{ spherical density_map{
											[0 color srgb 0 ]
											[0.2 color srgb <1, 1, 0> ]
											[0.5 color srgb <1, 0, 0> ]
											[1 color srgb <1, 0, 0> ]
									}
					warp{ turbulence < 0.25, 0.5, 0.25 > }
				}
			}
		}
		scale 0.25
		translate Lamp_NewPosition
	}
	light_source{ Lamp_NewPosition color srgb < 0.5, 0.45, 0.4 > * 0.8 fade_distance 40 fade_power 1 }
#end

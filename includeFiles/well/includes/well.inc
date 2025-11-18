/*
	Author: Antoine FAURE.
	Licence of this file: free for educational, commercial or other usage.
	
	To use the well in any of your scene just add this line after having included this 
		file to your scene:
	'object{ CompleteWell }'
	Of course any translate, rotate, or scale works fine for that object.
	All of the declared pigments, finishes, normals, textures, macros, or objects have
	been prefixed with 'Well_' in order to avoid any collisions with anything else in a scene.
*/
	
#include "woods.inc" //This is a standard povray file, you don't need to download it anywhere

#macro Well_AffineSet( PointA, PointB, CurrentX )
    #if( PointA.x = PointB.x 
    )
        #error "Can't render, because both x coordinates have equal values"
    #end
    
	#local DirCoef = (PointB.y - PointA.y) / ( PointB.x - PointA.x );
	#local OriginOffset = PointA.y - (DirCoef * PointA.x);
	(DirCoef * CurrentX) + OriginOffset;
#end

//Textures, pigments, normals and finishes                                                         
#declare Well_StalksTexture = texture{ T_Wood16 }
#declare Well_RoofTexture = texture{ T_Wood12 }

#declare Well_StoneColor = color srgb 1;
#declare Well_MortarColor = color srgb 0.65;

#declare Well_StonesPig = pigment{ wood color_map{ 
											[ 0.705 Well_StoneColor ]//0.711
											[ 0.705 Well_MortarColor]
											[ 0.9 Well_MortarColor ]
											[ 0.9 Well_StoneColor ]
											[ 1.0 Well_StoneColor ] } 
							rotate 90 * x
							scale < 2.24, 1, 2.24 >
						}
						
#declare Well_StoneNormal = normal{ wrinkles 1 scale 0.0025 }

#declare Well_BaseTexture = texture{ 
								pigment{ Well_StonesPig } 
								normal{ Well_StoneNormal } 
							}
							
#declare Well_CoverTexture = texture{
								pigment{ Well_StoneColor }
								normal{ Well_StoneNormal }
							}

#declare Well_RopeBarTexture = texture{ pigment{color srgb 0.5 } finish{specular 0.2 roughness 0.01} }

#declare Well_RopeColor = color srgb < 190 / 255, 183 / 255, 181 / 255 >;
#declare Well_RopeTexture = texture{ pigment{ Well_RopeColor } finish{ specular 0.001 roughness 0.001 } }

#declare Well_BucketMetalTexture = texture{ pigment{ color srgb 0.5 } finish{ specular 0.1 roughness 0.1 } }

//End textures enums

#declare Well_Stalk1_Z_Base = 1;
#declare Well_Stalk1_Highness = 0.4;
#declare Well_Stalk1_Large = 0.75;
#declare Well_Stalk1_Width = 0.1;
      
#declare Well_Stalk2_Width = 0.125;

#declare Well_Stalk3_Width = 0.1;    
#declare Well_Stalk3_Z_BottomStart = 0.5;
#declare Well_Stalk3_Large = 0.45;

#declare Well_Stalk4_Width = 0.075;
#declare Well_Stalk4_Large = Well_Stalk1_Large - 0.15;
               
#declare Well_LinearStalk1_PointA = < 0, Well_Stalk1_Z_Base + Well_Stalk1_Highness >;
#declare Well_LinearStalk1_PointB = < -Well_Stalk1_Large, Well_Stalk1_Z_Base >;

#declare Well_Stalk5_X_Decal = 0.08;
#declare Well_Stalk5_Width = 0.07;
#declare Well_Stalk5_MajorZ = Well_AffineSet( Well_LinearStalk1_PointA, Well_LinearStalk1_PointB, -Well_Stalk5_X_Decal ) 
#declare Well_Stalk5_MinorZ = Well_AffineSet( Well_LinearStalk1_PointA, Well_LinearStalk1_PointB, -Well_Stalk5_X_Decal - Well_Stalk5_Width ) 

#declare Well_RoofWidth = 2.1;
#declare Well_RoofThickness = 0.025;

#declare Well_Stalk1_Obj =
prism{
    linear_sweep linear_spline
    Well_Stalk1_Width / 2, -Well_Stalk1_Width / 2, 7
    //Start from top coord
    < 0, Well_Stalk1_Z_Base + Well_Stalk1_Highness + Well_Stalk1_Width >, 
    < -Well_Stalk1_Large, Well_Stalk1_Z_Base + Well_Stalk1_Width >, 
    < -Well_Stalk1_Large, Well_Stalk1_Z_Base >,
    < 0, Well_Stalk1_Z_Base + Well_Stalk1_Highness >, 
    < Well_Stalk1_Large, Well_Stalk1_Z_Base >,
    < Well_Stalk1_Large, Well_Stalk1_Z_Base + Well_Stalk1_Width >,
    < 0, Well_Stalk1_Z_Base + Well_Stalk1_Highness + Well_Stalk1_Width >    
    
    texture{ Well_StalksTexture }
}

#declare Well_Stalk2_Obj =
box{
    < -Well_Stalk2_Width / 2, -Well_Stalk2_Width / 2, 0 >, < Well_Stalk2_Width / 2, Well_Stalk2_Width / 2, Well_Stalk1_Z_Base >
    texture{ Well_StalksTexture }
}

#declare Well_Stalk3_Obj =
prism{
    linear_sweep linear_spline
    -Well_Stalk3_Width / 2, Well_Stalk3_Width / 2, 5
    < Well_Stalk2_Width / 2, Well_Stalk3_Z_BottomStart >,
    < Well_Stalk2_Width / 2, Well_Stalk3_Z_BottomStart + Well_Stalk3_Width >,
    < Well_Stalk3_Large, Well_Stalk1_Z_Base >,
    < Well_Stalk3_Large + Well_Stalk3_Width, Well_Stalk1_Z_Base >,
    < Well_Stalk2_Width / 2, Well_Stalk3_Z_BottomStart >
    
    texture{ Well_StalksTexture }
}   

#declare Well_Stalk4_Obj =
box{
    < -Well_Stalk4_Large, -Well_Stalk4_Width, Well_Stalk1_Z_Base >,
    < Well_Stalk4_Large, Well_Stalk4_Width, Well_Stalk1_Z_Base + Well_Stalk4_Width > 
    texture{ Well_StalksTexture }
}
   
#declare Well_Stalk5_Obj =
prism{
    linear_sweep linear_spline
    -Well_Stalk5_Width / 2, Well_Stalk5_Width / 2, 5
    < -Well_Stalk5_X_Decal, Well_Stalk1_Z_Base + Well_Stalk4_Width >,
    < -Well_Stalk5_X_Decal - Well_Stalk5_Width, Well_Stalk1_Z_Base + Well_Stalk4_Width >,
    < -Well_Stalk5_X_Decal - Well_Stalk5_Width, Well_Stalk5_MinorZ >,
    < -Well_Stalk5_X_Decal, Well_Stalk5_MajorZ >,
    < -Well_Stalk5_X_Decal, Well_Stalk1_Z_Base + Well_Stalk4_Width >     
    texture{ Well_StalksTexture }
}
   
#declare Well_Side =
union{
    object{ Well_Stalk1_Obj }
    object{ Well_Stalk2_Obj }
    object{ Well_Stalk3_Obj } 
    object{ Well_Stalk3_Obj rotate 180 * z }  
    object{ Well_Stalk4_Obj }    
    object{ Well_Stalk5_Obj }
    object{ Well_Stalk5_Obj rotate 180 * z }
}        

#declare Well_RoofObj =
prism{
	linear_sweep linear_spline
	-Well_RoofWidth / 2, Well_RoofWidth / 2, 7
	< 0, Well_Stalk1_Z_Base + Well_Stalk1_Highness + Well_Stalk1_Width >, 
	< Well_Stalk1_Large, Well_Stalk1_Z_Base + Well_Stalk1_Width >, 
	< Well_Stalk1_Large, Well_Stalk1_Z_Base + Well_Stalk1_Width + Well_RoofThickness >, 
	< 0, Well_Stalk1_Z_Base + Well_Stalk1_Highness + Well_Stalk1_Width + Well_RoofThickness >,
	< -Well_Stalk1_Large, Well_Stalk1_Z_Base + Well_Stalk1_Width + Well_RoofThickness >, 
	< -Well_Stalk1_Large, Well_Stalk1_Z_Base + Well_Stalk1_Width >, 
	< 0, Well_Stalk1_Z_Base + Well_Stalk1_Highness + Well_Stalk1_Width >
	
	texture{ Well_RoofTexture }
}

#declare Well_BaseRadius = 1;
#declare Well_BaseDiffRadius = 0.8;
#declare Well_BaseCoverRadius = 1.025;
#declare Well_BaseThickness = 0.2; 
#declare Well_Highness = 0.65;
#declare Well_BaseCoverHighness = 0.05;

#declare Well_CylinderFunc = function{ x * x + z * z - Well_BaseRadius * Well_BaseRadius }
#declare Well_CylinderDiffFunc = function{ x * x + z * z - Well_BaseDiffRadius * Well_BaseDiffRadius }
#declare Well_CylinderCoverFunc = function{ x * x + z * z - Well_BaseCoverRadius * Well_BaseCoverRadius }

#declare Well_InsideCracklePigFunc = function{ pigment{ crackle pigment_map{
															[ 0.06 color srgb 0.1 ]// 0.06 color srgb 0.1 
															[ 0.09 color srgb 0.2 ]// 0.09 color srgb 0.2
													}
										scale < 0.02, 0.075, 1 > * 1.5
										warp{ cylindrical }
									}
							}

#declare Well_OutsideCracklePigFunc = function{ pigment{ crackle pigment_map{
															[ 0.06 color srgb 0.1 ]// 0.06 color srgb 0.1 
															[ 0.09 color srgb 0.2 ]// 0.09 color srgb 0.2
													}
										scale < 0.015, 0.075, 1 > * 1.5
										warp{ cylindrical }
									}
							}
							
#declare Well_WrinklesPig = pigment{ wrinkles }

#declare Well_WrinklesPigFunc = function{ pigment{ Well_WrinklesPig } }

#declare Well_BaseReal =
isosurface{
	function{ Well_CylinderFunc(x,y,z) 
				- Well_OutsideCracklePigFunc(x,y,z).gray 
	}
	threshold 0
	accuracy 0.005
	max_gradient 46.2
	contained_by{ box{  < -Well_BaseRadius * 1.0086, 0 , -Well_BaseRadius * 1.0086 >, 
                        < Well_BaseRadius * 1.0086, Well_Highness, Well_BaseRadius * 1.0086 > } 
	}
    max_trace 2
    texture{ Well_BaseTexture }
}

#declare Well_BaseDiff =
isosurface{
	function{  Well_CylinderDiffFunc(x,y,z) 
				+ Well_InsideCracklePigFunc(x,y,z).gray 
	}
	threshold 0
	accuracy 0.005
	max_gradient 46.2
	contained_by{ box{  < -Well_BaseDiffRadius * 0.999, -1, -Well_BaseDiffRadius * 0.999 >, 
                        < Well_BaseDiffRadius * 0.999, Well_Highness + 1, Well_BaseDiffRadius * 0.999 > } 
	}
	max_trace 2
	texture{ Well_BaseTexture }
}

#declare Well_BaseCover =
isosurface{
	function{ Well_CylinderCoverFunc(x,y,z)
			- Well_WrinklesPigFunc(x,y,z).gray * 0.1
	}
	threshold 0
	accuracy 0.005
	max_gradient 3.47
	contained_by{ box{  < -Well_BaseCoverRadius * 1.035, 0, -Well_BaseCoverRadius * 1.035 >, 
                        < Well_BaseCoverRadius * 1.035, Well_BaseCoverHighness, Well_BaseCoverRadius * 1.035 > }
	}
	max_trace 2
	texture{ Well_CoverTexture }
}

#declare Well_Base =
difference{
	object{ Well_BaseReal }
	object{ Well_BaseDiff }
	texture{ Well_BaseTexture }
}

#declare Well_FinalBaseCover =
difference{
	object{ Well_BaseCover }
	object{ Well_BaseCover translate -Well_BaseCoverHighness / 2 * y 
		scale < Well_BaseDiffRadius / Well_BaseCoverRadius, 2.1, Well_BaseDiffRadius / Well_BaseCoverRadius > }
	translate Well_Highness * y
}

#declare Well_BarRadius = 0.04;
#declare Well_BarHalfSide = Well_BaseRadius + Well_BaseThickness / 2;
#declare Well_BarYPosition = Well_Highness * 2.25;

#declare Well_RopeBar =
cylinder{ 	< 0, Well_BarYPosition, -Well_BarHalfSide >,
			< 0, Well_BarYPosition, Well_BarHalfSide > , Well_BarRadius 
			texture{ Well_RopeBarTexture }
}

#declare Well_RoundNumber = 60;
#declare Well_PerRoundSpheresNumber = 36;
#declare Well_TotalSpheresNumber = Well_RoundNumber * Well_PerRoundSpheresNumber;
#declare Well_RopeRadius = 0.01;
#declare Well_RopeZStart = Well_BarHalfSide * 8 / 10;


#declare Well_Rope =
sphere_sweep{
	linear_spline
	Well_TotalSpheresNumber,
	#for( It, 0, Well_TotalSpheresNumber - 2 )
		#local Well_SpherePos = vrotate( < Well_BarRadius + Well_RopeRadius, 0, Well_RopeZStart - It * Well_RopeRadius * 2 / Well_PerRoundSpheresNumber >, 
									< 0, 0, It * 360 / Well_PerRoundSpheresNumber - 180 >);
		Well_SpherePos, Well_RopeRadius,  
	#end
	#declare Well_FinalRopeSpherePos = vrotate( < Well_BarRadius + Well_RopeRadius, 0, Well_RopeZStart - Well_TotalSpheresNumber * Well_RopeRadius * 2 / Well_PerRoundSpheresNumber >, 
									< 0, 0, Well_TotalSpheresNumber * 360 / Well_PerRoundSpheresNumber - 180 >);
	Well_FinalRopeSpherePos, Well_RopeRadius
	//#debug concat("Last Sphere position: ", vstr( 3, FinalRopeSpherePos, ", ", 0, 8), "\n")
	translate Well_BarYPosition * y
	texture{ Well_RopeTexture }
}
//Last Sphere of rope coord is: < -0.06, 0, 0.08 >

#declare Well_BucketMaxRadius = 0.2;
#declare Well_BucketMinRadius = 0.16;
#declare Well_BucketReservoirHighness = 0.3;
#declare Well_AttacheMinRadius = 0.01;
#declare Well_AttacheMaxRadius = 0.05;
#declare Well_BucketTrunk = cone{ < 0, 0, 0 >, Well_BucketMinRadius, < 0, Well_BucketReservoirHighness, 0 >, Well_BucketMaxRadius }
#declare Well_BucketReservoir =
difference{
	object{ Well_BucketTrunk }
	object{ Well_BucketTrunk translate 0.01 * y scale < 0.96, 1, 0.96 >}
}
#declare Well_BucketAttache = 
difference{ 
	torus{ Well_AttacheMaxRadius, Well_AttacheMinRadius rotate 90 * z}
	box{ < -1,-1,-1>,<1,0, 1 > }
}

#declare Well_BucketAnse =
difference{
	torus{ Well_BucketMaxRadius - Well_AttacheMaxRadius, Well_AttacheMinRadius rotate 90 * z }
	box{ < -1, -1, -1 >, < 1, 0, 1 > }
}

#declare Well_CompleteBucket =
union{
	object{ Well_BucketReservoir }
	object{ Well_BucketAttache rotate 90 * y translate < 0, Well_BucketReservoirHighness, -Well_BucketMaxRadius > }
	object{ Well_BucketAttache rotate 90 * y translate < 0, Well_BucketReservoirHighness, Well_BucketMaxRadius > }
	object{ Well_BucketAttache rotate 180 * z translate < 0, Well_BucketReservoirHighness + 2 * Well_AttacheMaxRadius - Well_AttacheMinRadius * 2, -Well_BucketMaxRadius > }
	object{ Well_BucketAttache rotate 180 * z translate < 0, Well_BucketReservoirHighness + 2 * Well_AttacheMaxRadius - Well_AttacheMinRadius * 2, Well_BucketMaxRadius > }
	object{ Well_BucketAnse translate < 0, Well_BucketReservoirHighness + Well_AttacheMaxRadius - Well_AttacheMinRadius * 2 + Well_AttacheMaxRadius, 0 > }
	texture{ Well_BucketMetalTexture }
}

#declare Well_DirectBucketRope = 
union{
	cylinder{ Well_FinalRopeSpherePos + < 0, Well_BarYPosition, 0 >, 
			< Well_FinalRopeSpherePos.x, 
			Well_BucketReservoirHighness + Well_AttacheMaxRadius - Well_AttacheMinRadius * 2 + Well_AttacheMaxRadius + Well_BucketMaxRadius - Well_AttacheMaxRadius + Well_Highness, 
			Well_FinalRopeSpherePos.z >,
			Well_RopeRadius
	}
	sphere{ < Well_FinalRopeSpherePos.x, 
			Well_BucketReservoirHighness + Well_AttacheMaxRadius - Well_AttacheMinRadius * 2 + Well_AttacheMaxRadius + Well_BucketMaxRadius - Well_AttacheMaxRadius + Well_Highness, 
			Well_FinalRopeSpherePos.z >,
			Well_RopeRadius
	}
	texture{ Well_RopeTexture }
}

#declare Well_WheelRadius = 0.3;
#declare Well_WheelBarRadius = 0.025;

#declare Well_WheelCurvedBar =
sphere_sweep{ cubic_spline 
	9,
	< 0.05, -0.3 / 5, 0 >, Well_WheelBarRadius,
	< 0, 0, 0 >, Well_WheelBarRadius,
	< -0.01, 0.3 / 6, 0 >, Well_WheelBarRadius,
	< -0.03, 0.3 * 2 / 6, 0 >, Well_WheelBarRadius,
	< -0.04, 0.3 * 3 / 6, 0 >, Well_WheelBarRadius,
	< -0.03, 0.3 * 4 / 6, 0 >, Well_WheelBarRadius,
	< -0.01, 0.3 * 5 / 6, 0 >, Well_WheelBarRadius,
	< 0, 0.3, 0 >, Well_WheelBarRadius,
	< 0.05, 0.3 * 6 / 5, 0 >, Well_WheelBarRadius
}

#declare Well_SideWheel =
union{
	torus{ Well_WheelRadius, Well_WheelBarRadius rotate -90 * x }
	object{ Well_WheelCurvedBar }
	object{ Well_WheelCurvedBar rotate 120 * z }
	object{ Well_WheelCurvedBar rotate 240 * z }
	texture{ Well_BucketMetalTexture }
}

#declare CompleteWell =
union{
	object{ Well_Base }
	object{ Well_FinalBaseCover }
	object{ Well_RopeBar }
	object{ Well_SideWheel translate < 0, Well_BarYPosition, -Well_BarHalfSide > }
	object{ Well_SideWheel translate < 0, Well_BarYPosition, Well_BarHalfSide > }
	object{ Well_Rope }
	object{ Well_DirectBucketRope }
	object{ Well_CompleteBucket translate Well_Highness * y translate < Well_FinalRopeSpherePos.x, 0, Well_FinalRopeSpherePos.z > }
	object{ Well_RoofObj rotate -90 * x translate (Well_Highness + Well_BaseCoverHighness) * y }
    object{ Well_Side rotate -90 * x translate < 0, Well_Highness + Well_BaseCoverHighness, -Well_BaseRadius + Well_BaseThickness / 2 > }
    object{ Well_Side rotate -90 * x translate < 0, Well_Highness + Well_BaseCoverHighness,  Well_BaseRadius - Well_BaseThickness / 2 > }
    object{ Well_Stalk1_Obj rotate -90 * x translate < 0, Well_Highness + Well_BaseCoverHighness, -(Well_BaseRadius + Well_BaseThickness / 2 ) / 2 > }
    object{ Well_Stalk1_Obj rotate -90 * x translate < 0, Well_Highness + Well_BaseCoverHighness,  (Well_BaseRadius + Well_BaseThickness / 2 ) / 2 > }
    object{ Well_Stalk1_Obj rotate -90 * x translate < 0, Well_Highness + Well_BaseCoverHighness,  0 > }
}

#declare Well_BoundariesMax = max_extent( CompleteWell );
#declare Well_BoundariesMin = min_extent( CompleteWell );
#declare Well_Size = Well_BoundariesMax - Well_BoundariesMin;
#debug concat( "Size of well is: ", vstr( 3, Well_Size, ", ", 0, 2 ), " \n")


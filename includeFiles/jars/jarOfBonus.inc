/*
	Author: Warren
	This POVRay include file can be used to create Labelled (optional) jars with the user color choice for the jar cap.
	For this purpose, just invoke the two macros:
		'CreateSimpleCompleteJar( JarScale, Position, CapColor )'
		for a jar without label, or:
		'CreateLabeledCompleteJar( JarScale, Position, CapColor , StickerImgPath, StickerYPos, StickerYRotation)'
		for a labelled jar with the image path for the label of your choice.
*/

#declare CapFinish = finish{ specular 0.1 roughness 0.05 metallic }

#declare GlassTexture = texture{
									pigment{ color srgbt <1, 1, 1, 0.98>}
									finish{ diffuse 0.6 brilliance 1.0 }
						}

#declare JarEmptySmallRadius = 0.75;
#declare JarBigRadius = 1;
#declare JarWidthRadius = 2;

#declare SolidJar = merge{ 
						torus{ JarWidthRadius - JarBigRadius, JarBigRadius translate y} 
						cylinder{ <0,JarBigRadius,0>,<0,5,0>, JarWidthRadius } 
						torus{JarWidthRadius - JarBigRadius, JarBigRadius translate 5*y }
						cylinder{<0,0,0>,<0,5 + JarBigRadius,0>, JarWidthRadius - JarBigRadius } //For a flat bottom of the jar
					}
					
#declare ThreadingWidth = 0.025;					
#declare BottleNeckThreadingTorus = torus{ JarWidthRadius - JarBigRadius + 0.2, ThreadingWidth }
	
#declare EmptyJar = difference{
						merge{
							object{ SolidJar }
							cylinder{<0, 5, 0>, <0, 6.5, 0>, JarWidthRadius - JarBigRadius + 0.2 }
						}
						object{ BottleNeckThreadingTorus translate 6.1*y }
						object{ BottleNeckThreadingTorus translate 6.2*y }
						object{ BottleNeckThreadingTorus translate 6.3*y }
						object{ BottleNeckThreadingTorus translate 6.4*y }
						object{ SolidJar translate (-(min_extent(SolidJar) + max_extent(SolidJar) ) / 2 ) scale 0.95 translate (min_extent(SolidJar) + max_extent(SolidJar) ) / 2 }
						cylinder{ <0, 4, 0>,< 0, 8, 0> , JarWidthRadius - JarBigRadius + 0.1}
						//box{ <-4,-2,0>,<4,8,-8> }//To have a profil of the jar (only to debug)
					}

#declare CapTorusSmallRadius = 0.1;
#declare JarCap = 	difference{
						merge{
							cylinder{<0,6,0>,<0,6.6,0>, JarWidthRadius - JarBigRadius + 0.35 }
							torus{ JarWidthRadius - JarBigRadius + 0.35 - CapTorusSmallRadius, CapTorusSmallRadius translate 6.6*y}
							cylinder{ <0,6.6,0>,<0,6.6 + CapTorusSmallRadius,0>, JarWidthRadius - JarBigRadius + 0.35 - CapTorusSmallRadius }
						}
						torus{ JarWidthRadius - JarBigRadius + 0.35, ThreadingWidth translate 6.1 * y }
						torus{ JarWidthRadius - JarBigRadius + 0.35, ThreadingWidth translate 6.2 * y }
						torus{ JarWidthRadius - JarBigRadius + 0.35, ThreadingWidth translate 6.3 * y }
						torus{ JarWidthRadius - JarBigRadius + 0.35, ThreadingWidth translate 6.4 * y }
						torus{ JarWidthRadius - JarBigRadius + 0.35, ThreadingWidth translate 6.5 * y }
						cylinder{<0,5,0>,<0,6.5,0>, JarWidthRadius - JarBigRadius + 0.35 - CapTorusSmallRadius }
					}

#macro CreateSimpleCompleteJar( JarScale, Position, CapColor )
	union{
		object{ EmptyJar material{ texture{ GlassTexture } interior{ ior 1.5 } } }
		object{ JarCap texture{ pigment{ CapColor } finish{ CapFinish } } }
		scale JarScale
		translate Position
	}
#end

#macro CreateLabeledCompleteJar( JarScale, Position, CapColor , StickerImgPath, StickerYPos, StickerYRotation)
	#local StickerPig = pigment{ image_map { png StickerImgPath gamma srgb map_type 2 once interpolate 2 } };
	
	union{
		object{ EmptyJar 
			material{ 
				texture{ GlassTexture }
				texture{ pigment{ StickerPig scale <1, 2, 2> translate StickerYPos*y rotate StickerYRotation * y } }
				interior{ ior 1.5 }
			}
		}
		object{ JarCap texture{ pigment{ CapColor } finish{ CapFinish } } }
		scale JarScale
		translate Position
	}
#end

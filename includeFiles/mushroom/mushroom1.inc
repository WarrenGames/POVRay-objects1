//A file for a mushroom with a round red hat and a white stalk

#include "macroAffineFunc.inc"
#include "transforms.inc"

#declare HatColor = color srgb <1, 0, 0>;
#declare StalkColorA = color srgb 1;
#declare StalkColorB = color srgb 0.95;

#declare StalkPigment = pigment{ radial color_map{	[0 StalkColorA ]
												[0.5 StalkColorA ]
												[0.5 StalkColorB ]
												[1 StalkColorB ]
									}
							frequency 128 
							warp{ turbulence <0.25, 0, 0.25> } 
					}

#declare StalkHighness = 2.2;

#declare MushroomHatTop = difference{
								sphere{ 0, 1 scale < 1, 1.25, 1 > }
								box{ -2, < 2, 0, 2 > }
							}
							
#declare MushroomHatBottom = difference{
								sphere{ 0, 1 scale < 1, 1/2, 1 > }
								box{ <-2,0,-2>, 2 }
							}
							
#declare FinalMushroomHat = merge{
								object{ MushroomHatTop }
								object{ MushroomHatBottom }
								pigment{ HatColor }
							}

#declare WhiteDotRadius = 0.15;
#declare DotSphereFunc = function{ x * x + y * y * 1.75 + z * z - WhiteDotRadius * WhiteDotRadius }
#declare WrinklesPattern = function{ pattern{ wrinkles } }

#declare HatWhiteDot = isosurface{
							function{  
								DotSphereFunc(x,y,z)
								- WrinklesPattern(x,y,z) * 0.5
							}
							accuracy 0.0001
							max_gradient 1.15
							contained_by{ sphere{ 0, WhiteDotRadius * 3} }
							pigment{ StalkColorA }
							scale 0.25
						}

#macro MakeWhiteDots( DotsRowNumber, SeedNumber, RandSpacingForce )
	#local RandomPosSeed = seed( SeedNumber );
	#local Norm = < 0, 0, 0 >;
	#for( ItX, -DotsRowNumber / 2, DotsRowNumber / 2 )
		#for( ItZ, -DotsRowNumber / 2, DotsRowNumber / 2 )
			#local OnXRotation = AffineSetBoundOnly( -DotsRowNumber, DotsRowNumber,-90, 90, ItX + (rand(RandomPosSeed) - 0.5 ) * DotsRowNumber * RandSpacingForce);
			#local OnZRotation = AffineSetBoundOnly( -DotsRowNumber, DotsRowNumber,-90, 90, ItZ + (rand(RandomPosSeed) - 0.5 ) * DotsRowNumber * RandSpacingForce);
			#local StartingPoint = vrotate( < 0, 100, 0 >, < OnXRotation, 0, OnZRotation > );
			#local DotPosition = trace( FinalMushroomHat, StartingPoint, -StartingPoint, Norm );
			#if( Norm.x != 0 | Norm.y != 0 | Norm.z != 0 )
				object{ HatWhiteDot Reorient_Trans(y, Norm) translate DotPosition }
			#end
		#end
	#end
#end

#declare MushroomStalk = cylinder{ < 0, 0, 0> ,< 0, StalkHighness, 0>, 0.5 
								pigment{ StalkPigment }
							}
							
#macro MakeCustomMushroom( DotsRowNumber, DotsRandomSeed, RandSpacingForce, Rotation, Translation, Scale )
	union{
		object{ MushroomStalk }
		object{ FinalMushroomHat translate StalkHighness*y}
		union{
			MakeWhiteDots(DotsRowNumber, DotsRandomSeed, RandSpacingForce ) 
			translate StalkHighness*y
		}
		scale Scale
		rotate Rotation
		translate Translation	
	}
#end
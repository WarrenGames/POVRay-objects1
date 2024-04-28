/*
	Author: Antoine FAURE.
	Licence of this file: free for educational, commercial or other usage.
	
		This file contains code to place a space crate in a POVRay scene
		Most of the time, you should only use one or several of these three 
	alias in an object statement (without the single quotes):
		
		'object{ SpCr1_CompleteCover }'	
			>> ( only the top of the crate without clips )
		
		'object{ SpCr1_ContainBox }'				
			>> ( only the container, no top )
		
		'object{ SpCr1_CompleteCrateWithCover }' 
		 	>> ( the complete crate: container, top and clips )
		
		'object{ SpCr1_CompleteCoverWithAttachs }'
			>> ( only the top with its clips )
			 
		The complete crate is centered on the 'x' and 'z' axes and the 
	bottom of the crate lies at 0 on the 'y' axis. The vertical of 
	the crate is the 'y' axis.
*/

#declare SpCr1_Width = 2;
#declare SpCr1_Height = 2; // 2.2

#declare SpCr1_CoverHeight = SpCr1_Height / 5;
#declare SpCr1_ContainHeight = SpCr1_Height - SpCr1_CoverHeight;
#declare SpCr1_BothInnerRemoveScale = 0.85;

#declare SpCr1_CoverRoundRadius = SpCr1_CoverHeight / 2;
#declare SpCr1_CoverRounds_PtA = < -SpCr1_Width / 2 + SpCr1_CoverRoundRadius, SpCr1_CoverHeight / 2, -SpCr1_Width / 2 + SpCr1_CoverRoundRadius>;
#declare SpCr1_CoverRounds_PtB = < SpCr1_Width / 2 - SpCr1_CoverRoundRadius, SpCr1_CoverHeight / 2, -SpCr1_Width / 2 + SpCr1_CoverRoundRadius>;
#declare SpCr1_CoverRounds_PtC = < SpCr1_Width / 2 - SpCr1_CoverRoundRadius, SpCr1_CoverHeight / 2, SpCr1_Width / 2 - SpCr1_CoverRoundRadius>;
#declare SpCr1_CoverRounds_PtD = < -SpCr1_Width / 2 + SpCr1_CoverRoundRadius, SpCr1_CoverHeight / 2, SpCr1_Width / 2 - SpCr1_CoverRoundRadius>;
#declare SpCr1_CoverLargeRemoverWidth = SpCr1_Width / 2;
#declare SpCr1_CoverSmallRemoverWidth = SpCr1_Width / 3;
#declare SpCr1_CoverDarkRemoverRadius = SpCr1_CoverRoundRadius * 3 / 4;
#declare SpCr1_CoverStickerY_Position = SpCr1_CoverRoundRadius * 2 + 0.001;
#declare SpCr1_CoverStickerWidthPercent = 0.88;

#declare SpCr1_StrapDeepness = 0.03;
#declare SpCr1_StrapWidth = 0.175;
#declare SpCr1_BothStrapDistance = SpCr1_Width / 8 + SpCr1_StrapWidth;
#declare SpCr1_PullRadius = 0.025;
#declare SpCr1_PullLength = 0.2;
#declare SpCr1_PullYPosition = 0.725;
#declare SpCr1_PullDeepnessRatio = 0.75;
#declare SpCr1_HermeticPartsScale = 0.15;
#declare SpCr1_AttachLength = SpCr1_CoverHeight * SpCr1_HermeticPartsScale * 3;

#declare SpCr1_ContainRoundRadius = SpCr1_CoverRoundRadius;
#declare SpCr1_ContainRounds_PtA = < -SpCr1_Width / 2 + SpCr1_ContainRoundRadius, SpCr1_ContainRoundRadius, -SpCr1_Width / 2 + SpCr1_ContainRoundRadius >;
#declare SpCr1_ContainRounds_PtB = < SpCr1_Width / 2 - SpCr1_ContainRoundRadius, SpCr1_ContainRoundRadius, -SpCr1_Width / 2 + SpCr1_ContainRoundRadius >;
#declare SpCr1_ContainRounds_PtC = < SpCr1_Width / 2 - SpCr1_ContainRoundRadius, SpCr1_ContainRoundRadius, SpCr1_Width / 2 - SpCr1_ContainRoundRadius >;
#declare SpCr1_ContainRounds_PtD = < -SpCr1_Width / 2 + SpCr1_ContainRoundRadius, SpCr1_ContainRoundRadius, SpCr1_Width / 2 - SpCr1_ContainRoundRadius >;
#declare SpCr1_ContainNarrowRemoverWidth = 0.175 * 3;
#declare SpCr1_ContainLargeRemoverWidth = 0.175 * 4.5;

#declare SpCr1_Pull_PtA = < -SpCr1_ContainLargeRemoverWidth / 2 * 0.8, SpCr1_ContainHeight * SpCr1_PullYPosition, -SpCr1_Width / 2 + SpCr1_StrapDeepness * SpCr1_PullDeepnessRatio >;
#declare SpCr1_Pull_PtB = < SpCr1_ContainLargeRemoverWidth / 2 * 0.8, SpCr1_ContainHeight * SpCr1_PullYPosition, -SpCr1_Width / 2 + SpCr1_StrapDeepness * SpCr1_PullDeepnessRatio >;
#declare SpCr1_Pull_PtC = < -SpCr1_ContainLargeRemoverWidth / 2 * 0.8, SpCr1_ContainHeight * SpCr1_PullYPosition - SpCr1_PullLength, -SpCr1_Width / 2 + SpCr1_StrapDeepness * SpCr1_PullDeepnessRatio >;
#declare SpCr1_Pull_PtD = < SpCr1_ContainLargeRemoverWidth / 2 * 0.8, SpCr1_ContainHeight * SpCr1_PullYPosition - SpCr1_PullLength, -SpCr1_Width / 2 + SpCr1_StrapDeepness * SpCr1_PullDeepnessRatio >;

#declare SprCr1_GrayMultiplier = 1.55;
#declare SpCr1_MediumGrayColor = color srgb < 106 * SprCr1_GrayMultiplier / 255, 107 * SprCr1_GrayMultiplier / 255, 113 * SprCr1_GrayMultiplier / 255 >;
#declare SpCr1_BrightGrayColor = color srgb < 192 / 255, 193 / 255, 202 / 255 >;
#declare SpCr1_DarkGrayColor = color srgb < 59 * SprCr1_GrayMultiplier / 255, 58 * SprCr1_GrayMultiplier / 255, 54 * SprCr1_GrayMultiplier / 255 >;
#declare SpCr1_NearStickersGrayColor = color srgb 95 / 255;
#declare SpCr1_YellowColor = color srgb < 226 / 255, 169 / 255, 68 / 255 >;
#declare SpCr1_BlackColor = color srgb 0;
#declare SpCr1_ClearColor = color srgbt 1;
#declare SpCr1_StripePig = pigment{ gradient x color_map{ [ 0 SpCr1_BlackColor ][0.5 SpCr1_BlackColor][ 0.5 SpCr1_ClearColor ][1.0 SpCr1_ClearColor ] } scale 1 / 6.5 rotate 45 * y translate 0.0325 * x }
#declare SpCr1_ContainPig = pigment{ gradient y color_map{ [ 0.8 SpCr1_MediumGrayColor ][ 0.8 SpCr1_YellowColor ][0.9 SpCr1_YellowColor][0.9 SpCr1_MediumGrayColor] } scale < 1, SpCr1_ContainHeight, 1 > }

#declare SpCr1_Finish = finish{ specular 0.01 roughness 0.01 }
#declare SpCr1_MediumGrayTexture = texture{ pigment{ SpCr1_MediumGrayColor } finish{ SpCr1_Finish } }
#declare SpCr1_DarkGrayTexture = texture{ pigment{ SpCr1_DarkGrayColor } finish{ SpCr1_Finish } }
#declare SpCr1_BrightGrayTexture = texture{ pigment{ SpCr1_BrightGrayColor } finish{ SpCr1_Finish } }
#declare SpCr1_StripeTexture = texture{ pigment{ SpCr1_StripePig } finish{ SpCr1_Finish } }
#declare SpCr1_YellowTexture = texture{ pigment{ SpCr1_YellowColor } finish{ SpCr1_Finish } }
#declare SpCr1_ContainTexture = texture{ pigment{ SpCr1_ContainPig } finish{ SpCr1_Finish } }

#declare SpCr1_CoverBox =
box{ SpCr1_CoverRounds_PtA, SpCr1_CoverRounds_PtC + < 0, SpCr1_CoverRoundRadius, 0 > }

#declare SpCr1_RoughCoverBoxWithRounds =
union{
    object{ SpCr1_CoverBox }
    sphere{ SpCr1_CoverRounds_PtA, SpCr1_CoverRoundRadius }
    sphere{ SpCr1_CoverRounds_PtB, SpCr1_CoverRoundRadius }
    sphere{ SpCr1_CoverRounds_PtC, SpCr1_CoverRoundRadius }
    sphere{ SpCr1_CoverRounds_PtD, SpCr1_CoverRoundRadius }
    cylinder{ SpCr1_CoverRounds_PtA, SpCr1_CoverRounds_PtB, SpCr1_CoverRoundRadius }
    cylinder{ SpCr1_CoverRounds_PtB, SpCr1_CoverRounds_PtC, SpCr1_CoverRoundRadius }
    cylinder{ SpCr1_CoverRounds_PtC, SpCr1_CoverRounds_PtD, SpCr1_CoverRoundRadius }
    cylinder{ SpCr1_CoverRounds_PtD, SpCr1_CoverRounds_PtA, SpCr1_CoverRoundRadius }
}

#declare SpCr1_CoverBoxBottom =
union{
	cylinder{ SpCr1_CoverRounds_PtA, SpCr1_CoverRounds_PtA - < 0 , SpCr1_CoverHeight / 2, 0 >, SpCr1_CoverRoundRadius }
    cylinder{ SpCr1_CoverRounds_PtB, SpCr1_CoverRounds_PtB - < 0 , SpCr1_CoverHeight / 2, 0 >, SpCr1_CoverRoundRadius }
    cylinder{ SpCr1_CoverRounds_PtC, SpCr1_CoverRounds_PtC - < 0 , SpCr1_CoverHeight / 2, 0 >, SpCr1_CoverRoundRadius }
    cylinder{ SpCr1_CoverRounds_PtD, SpCr1_CoverRounds_PtD - < 0 , SpCr1_CoverHeight / 2, 0 >, SpCr1_CoverRoundRadius }
    box{ SpCr1_CoverRounds_PtA + < -SpCr1_CoverRoundRadius, 0, 0 >, SpCr1_CoverRounds_PtC - < -SpCr1_CoverRoundRadius, SpCr1_CoverHeight / 2, 0 > }
    box{ SpCr1_CoverRounds_PtB + < 0, 0, -SpCr1_CoverRoundRadius >, SpCr1_CoverRounds_PtD - < 0, SpCr1_CoverHeight / 2, -SpCr1_CoverRoundRadius > }
}

#declare SpCr1_CoverBoxWithRounds =
union{
	object{ SpCr1_RoughCoverBoxWithRounds }
	object{ SpCr1_CoverBoxBottom }
	texture{ SpCr1_MediumGrayTexture }
}

#declare SpCr1_CoverDarkRemover =
intersection{
	cylinder{ < -SpCr1_CoverLargeRemoverWidth / 2, SpCr1_CoverRounds_PtA.y, SpCr1_CoverRounds_PtA.z >, 
			  < SpCr1_CoverLargeRemoverWidth / 2, SpCr1_CoverRounds_PtB.y, SpCr1_CoverRounds_PtB.z >, 
			  SpCr1_CoverDarkRemoverRadius }
	box{ < -SpCr1_CoverLargeRemoverWidth / 2 * 1.1, SpCr1_CoverRounds_PtA.y, SpCr1_CoverRounds_PtA.z >,
		 < SpCr1_CoverLargeRemoverWidth / 2 * 1.1, SpCr1_CoverRounds_PtA.y + SpCr1_CoverDarkRemoverRadius * 2, SpCr1_CoverRounds_PtA.z - SpCr1_CoverDarkRemoverRadius * 2 > }
	texture{ SpCr1_DarkGrayTexture }
}

#declare SpCr1_CoverBrightRemover =
difference{
	intersection{
		cylinder{ < -SpCr1_CoverLargeRemoverWidth / 2, SpCr1_CoverRounds_PtA.y, SpCr1_CoverRounds_PtA.z >,
				  < SpCr1_CoverLargeRemoverWidth / 2, SpCr1_CoverRounds_PtB.y, SpCr1_CoverRounds_PtB.z>, SpCr1_CoverRoundRadius * 2 }
		box{ < -SpCr1_CoverLargeRemoverWidth / 2 * 1.1, SpCr1_CoverRounds_PtA.y + 0.001, SpCr1_CoverRounds_PtA.z - 0.001 >,
			 < SpCr1_CoverLargeRemoverWidth / 2 * 1.1, SpCr1_CoverRounds_PtA.y + SpCr1_CoverRoundRadius, SpCr1_CoverRounds_PtA.z - SpCr1_CoverRoundRadius * 2 > }
		texture{ SpCr1_BrightGrayTexture }
	}
	object{ SpCr1_CoverDarkRemover scale < 1.1, 1, 1 > }
}

#declare SpCr1_CompleteCoverRemover =
union{
	object{ SpCr1_CoverDarkRemover translate < 0, -SpCr1_CoverRounds_PtA.y, -SpCr1_CoverRounds_PtA.z > scale < 1.01, 1.01, 1.01 > translate < 0, SpCr1_CoverRounds_PtA.y, SpCr1_CoverRounds_PtA.z > }
	object{ SpCr1_CoverBrightRemover }
}

#declare SpCr1_StripeSticker =
mesh{
	triangle{ 	< SpCr1_CoverRounds_PtA.x * SpCr1_CoverStickerWidthPercent, SpCr1_CoverStickerY_Position, SpCr1_CoverRounds_PtA.z * 0.45 >, 
				< SpCr1_CoverRounds_PtA.x * SpCr1_CoverStickerWidthPercent, SpCr1_CoverStickerY_Position, SpCr1_CoverRounds_PtA.z * 0.35 >,
				< SpCr1_CoverRounds_PtB.x * SpCr1_CoverStickerWidthPercent, SpCr1_CoverStickerY_Position, SpCr1_CoverRounds_PtB.z * 0.45 > }
	triangle{ 	< SpCr1_CoverRounds_PtA.x * SpCr1_CoverStickerWidthPercent, SpCr1_CoverStickerY_Position, SpCr1_CoverRounds_PtA.z * 0.35 >,
				< SpCr1_CoverRounds_PtB.x * SpCr1_CoverStickerWidthPercent, SpCr1_CoverStickerY_Position, SpCr1_CoverRounds_PtA.z * 0.35 >,
				< SpCr1_CoverRounds_PtB.x * SpCr1_CoverStickerWidthPercent, SpCr1_CoverStickerY_Position, SpCr1_CoverRounds_PtB.z * 0.45 > }
	texture{ SpCr1_StripeTexture }
}

#declare SpCr1_YellowSticker =
mesh{
	triangle{ 	< SpCr1_CoverRounds_PtA.x * SpCr1_CoverStickerWidthPercent, SpCr1_CoverStickerY_Position, SpCr1_CoverRounds_PtA.z * 0.50 >, 
				< SpCr1_CoverRounds_PtA.x * SpCr1_CoverStickerWidthPercent, SpCr1_CoverStickerY_Position, SpCr1_CoverRounds_PtA.z * 0.45 >,
				< SpCr1_CoverRounds_PtB.x * SpCr1_CoverStickerWidthPercent, SpCr1_CoverStickerY_Position, SpCr1_CoverRounds_PtB.z * 0.50 > }
	triangle{ 	< SpCr1_CoverRounds_PtA.x * SpCr1_CoverStickerWidthPercent, SpCr1_CoverStickerY_Position, SpCr1_CoverRounds_PtA.z * 0.45 >,
				< SpCr1_CoverRounds_PtB.x * SpCr1_CoverStickerWidthPercent, SpCr1_CoverStickerY_Position, SpCr1_CoverRounds_PtA.z * 0.45 >,
				< SpCr1_CoverRounds_PtB.x * SpCr1_CoverStickerWidthPercent, SpCr1_CoverStickerY_Position, SpCr1_CoverRounds_PtB.z * 0.50 > }
	texture{ SpCr1_YellowTexture }
}

#declare SpCr1_StickerSideRemover =
box{	< SpCr1_CoverRounds_PtA.x * SpCr1_CoverStickerWidthPercent, SpCr1_CoverStickerY_Position - 0.02, SpCr1_CoverRounds_PtA.z * 0.54 >,
		< SpCr1_CoverRounds_PtB.x * SpCr1_CoverStickerWidthPercent, SpCr1_CoverStickerY_Position + 1, SpCr1_CoverRounds_PtB.z * 0.69 >
	texture{ pigment{ SpCr1_NearStickersGrayColor } finish{ SpCr1_Finish } }
}

#declare SpCr1_PlaneFunc = function{ y }
#declare SpCr1_LeopardFunc = function{ pigment{ leopard
												color_map{ [0 color rgb 0.4][0.35 color rgb 0.75 ][0.65 color rgb 0.85][1.0 color rgb 0.9 ] } 
												} }
#declare SpCr1_MossGraniteFunc = function{ pattern{ granite } }

#declare SpCr1_CoverMoss =
isosurface{
	function{ SpCr1_PlaneFunc(x,y,z) - SpCr1_LeopardFunc(x * 20,y,z * 20).gray * 0.2
		+ SpCr1_MossGraniteFunc(x * 10, y, z * 10 ) * 0.0075
	}
	threshold 0
	contained_by{ box{ < -SpCr1_Width / 2 + SpCr1_CoverRoundRadius, 0, -SpCr1_Width / 2 + SpCr1_CoverRoundRadius >,
						< SpCr1_Width / 2 - SpCr1_CoverRoundRadius, 0.2, SpCr1_Width / 2 - SpCr1_CoverRoundRadius >
				}
	}
	accuracy 0.001
	max_gradient 3.3
	texture{ pigment{ SpCr1_DarkGrayColor } finish{ SpCr1_Finish } }
}

#declare SpCr1_CoverStrapCylRail =
difference{
	cylinder{ < 0, 0, -SpCr1_StrapWidth / 2 >,
				< 0, 0, SpCr1_StrapWidth / 2 >,
				SpCr1_CoverRoundRadius * 1.2 }
	cylinder{ < 0, 0, -SpCr1_StrapWidth / 2 * 1.1 >,
				< 0, 0, SpCr1_StrapWidth / 2 * 1.1 >,
				SpCr1_CoverRoundRadius - SpCr1_StrapDeepness }
	box{ < -SpCr1_CoverRoundRadius * 1.3, 0, -SpCr1_StrapWidth / 2 * 1.1 >, 
		 < SpCr1_CoverRoundRadius * 1.3, -100, SpCr1_StrapWidth / 2 * 1.1 > }
	box{ < 0, 0, -SpCr1_StrapWidth / 2 * 1.3 >,
		< SpCr1_CoverRoundRadius * 1.3, SpCr1_CoverRoundRadius * 1.3, SpCr1_StrapWidth / 2 * 1.1 > }
}

#declare SpCr1_CoverCompleteStrap =
union{
	object{ SpCr1_CoverStrapCylRail }
	box{ < -SpCr1_CoverRoundRadius * 1.2, 0.0001, -SpCr1_StrapWidth / 2 >,
		< -SpCr1_CoverRoundRadius + SpCr1_StrapDeepness, -SpCr1_CoverRoundRadius - 0.0001, SpCr1_StrapWidth / 2 > }
	texture{ SpCr1_MediumGrayTexture }
}

#declare SpCr1_CoverAttach =
difference{
	prism{ linear_sweep linear_spline -SpCr1_StrapWidth / 2, SpCr1_StrapWidth / 2, 11,
		< -SpCr1_AttachLength / 2, 0 >, 
		< -SpCr1_AttachLength / 2, -SpCr1_StrapDeepness >, 
		< -SpCr1_AttachLength / 2 + SpCr1_AttachLength / 3, -SpCr1_StrapDeepness * 2 >, 
		< SpCr1_AttachLength / 2 - SpCr1_AttachLength / 3, -SpCr1_StrapDeepness * 2 >, 
		< SpCr1_AttachLength / 2, -SpCr1_StrapDeepness >, 
		< SpCr1_AttachLength / 2, 0 >, 
		< SpCr1_AttachLength / 2 - SpCr1_AttachLength / 3, 0 >, 
		< SpCr1_AttachLength / 2 - SpCr1_AttachLength / 3 * 1.2, -SpCr1_StrapDeepness / 2 >,
		< -SpCr1_AttachLength / 2 + SpCr1_AttachLength / 3 * 1.2, -SpCr1_StrapDeepness / 2 >,
		< -SpCr1_AttachLength / 2 + SpCr1_AttachLength / 3, 0 >, 
		< -SpCr1_AttachLength / 2, 0 >
		
	}
	cylinder{< -SpCr1_AttachLength / 3, -SpCr1_StrapWidth, 0 >,< -SpCr1_AttachLength / 3, SpCr1_StrapWidth, 0 > , SpCr1_AttachLength / 6 * 0.5 }
	cylinder{< SpCr1_AttachLength / 3, -SpCr1_StrapWidth, 0 >,< SpCr1_AttachLength / 3, SpCr1_StrapWidth, 0 > , SpCr1_AttachLength / 6 * 0.5 }
	texture{ pigment{ SpCr1_DarkGrayColor } finish{ SpCr1_Finish } }
}
	

#declare SpCr1_CompleteCover =
union{
	difference{
		object{ SpCr1_CoverBoxWithRounds }
		object{ SpCr1_CompleteCoverRemover }
		object{ SpCr1_CompleteCoverRemover rotate 180 * y }
		object{ SpCr1_CompleteCoverRemover scale < 0.5, 1, 1 > rotate 90 * y }
		object{ SpCr1_CompleteCoverRemover scale < 0.5, 1, 1 > rotate 270 * y }
		object{ SpCr1_StickerSideRemover }
		object{ SpCr1_StickerSideRemover rotate 180 * y }
		object{ SpCr1_CoverBoxWithRounds scale SpCr1_BothInnerRemoveScale translate -0.2 * y texture{ SpCr1_DarkGrayTexture } }
		object{ SpCr1_CoverCompleteStrap rotate 180 * y translate < SpCr1_Width / 2 - SpCr1_CoverRoundRadius, SpCr1_CoverRounds_PtB.y, -SpCr1_BothStrapDistance > }
		object{ SpCr1_CoverCompleteStrap rotate 180 * y translate < SpCr1_Width / 2 - SpCr1_CoverRoundRadius, SpCr1_CoverRounds_PtB.y, SpCr1_BothStrapDistance > }
		object{ SpCr1_CoverCompleteStrap translate < -SpCr1_Width / 2 + SpCr1_CoverRoundRadius, SpCr1_CoverRounds_PtB.y, -SpCr1_BothStrapDistance > }
		object{ SpCr1_CoverCompleteStrap translate < -SpCr1_Width / 2 + SpCr1_CoverRoundRadius, SpCr1_CoverRounds_PtB.y, SpCr1_BothStrapDistance > }
	}
	object{ SpCr1_StripeSticker }
	object{ SpCr1_StripeSticker rotate 180 * y }
	object{ SpCr1_YellowSticker }
	object{ SpCr1_YellowSticker rotate 180 * y }
	object{ SpCr1_CoverMoss rotate 180 * x translate ( SpCr1_CoverHeight * SpCr1_BothInnerRemoveScale - 0.2 ) * y }
	difference{
		object{ SpCr1_CoverBoxBottom scale < 0.98, SpCr1_HermeticPartsScale, 0.98 > translate -SpCr1_CoverHeight / 2 * 0.2 * y }//Part to close hermetically the crate
		object{ SpCr1_CoverBoxBottom scale < 0.95, 1, 0.95 > translate -SpCr1_CoverHeight / 2 * 0.2 * y + < 0, -0.001, 0 > }//Part to close hermetically the crate
		texture{ SpCr1_DarkGrayTexture }
	}
}

#declare SpCr1_RoughContainBoxWithRounds =
union{
	box{ SpCr1_ContainRounds_PtA, SpCr1_ContainRounds_PtC - < 0, SpCr1_ContainRoundRadius, 0 > }
	sphere{ SpCr1_ContainRounds_PtA, SpCr1_ContainRoundRadius }
	sphere{ SpCr1_ContainRounds_PtB, SpCr1_ContainRoundRadius }
	sphere{ SpCr1_ContainRounds_PtC, SpCr1_ContainRoundRadius }
	sphere{ SpCr1_ContainRounds_PtD, SpCr1_ContainRoundRadius }
	cylinder{ SpCr1_ContainRounds_PtA, SpCr1_ContainRounds_PtB, SpCr1_ContainRoundRadius }
	cylinder{ SpCr1_ContainRounds_PtB, SpCr1_ContainRounds_PtC, SpCr1_ContainRoundRadius }
	cylinder{ SpCr1_ContainRounds_PtC, SpCr1_ContainRounds_PtD, SpCr1_ContainRoundRadius }
	cylinder{ SpCr1_ContainRounds_PtD, SpCr1_ContainRounds_PtA, SpCr1_ContainRoundRadius }
	cylinder{ SpCr1_ContainRounds_PtA, < SpCr1_ContainRounds_PtA.x, SpCr1_ContainHeight, SpCr1_ContainRounds_PtA.z >, SpCr1_ContainRoundRadius }
	cylinder{ SpCr1_ContainRounds_PtB, < SpCr1_ContainRounds_PtB.x, SpCr1_ContainHeight, SpCr1_ContainRounds_PtB.z >, SpCr1_ContainRoundRadius }
	cylinder{ SpCr1_ContainRounds_PtC, < SpCr1_ContainRounds_PtC.x, SpCr1_ContainHeight, SpCr1_ContainRounds_PtC.z >, SpCr1_ContainRoundRadius }
	cylinder{ SpCr1_ContainRounds_PtD, < SpCr1_ContainRounds_PtD.x, SpCr1_ContainHeight, SpCr1_ContainRounds_PtD.z >, SpCr1_ContainRoundRadius }
	box{ SpCr1_ContainRounds_PtA - < 0, 0, SpCr1_ContainRoundRadius >, < SpCr1_ContainRounds_PtC.x, SpCr1_ContainHeight, SpCr1_ContainRounds_PtC.z + SpCr1_ContainRoundRadius > }
	box{ SpCr1_ContainRounds_PtA - < SpCr1_ContainRoundRadius, 0, 0 >, < SpCr1_ContainRounds_PtC.x + SpCr1_ContainRoundRadius, SpCr1_ContainHeight, SpCr1_ContainRounds_PtC.z > }
}

#declare SpCr1_ContainNarrowStrapRemover = 
box{ < -SpCr1_CoverRoundRadius * 1.2, SpCr1_ContainHeight + 1, -SpCr1_StrapWidth / 2 >,
		< -SpCr1_CoverRoundRadius + SpCr1_StrapDeepness, - 1, SpCr1_StrapWidth / 2 > }

#declare SpCr1_ContainNarrowRemover =
box{ < -SpCr1_CoverRoundRadius * 1.2, SpCr1_ContainHeight * 0.78, -SpCr1_ContainNarrowRemoverWidth / 2 >,
		< -SpCr1_CoverRoundRadius + SpCr1_StrapDeepness * 2, - 1, SpCr1_ContainNarrowRemoverWidth / 2 > }

#declare SpCr1_ContainPullRemover =
box{ < -SpCr1_CoverRoundRadius * 1.2, SpCr1_ContainHeight * 0.78, -SpCr1_ContainLargeRemoverWidth / 2 >,
		< -SpCr1_CoverRoundRadius + SpCr1_StrapDeepness * 2, - 1, SpCr1_ContainLargeRemoverWidth / 2 > }

#declare SpCr1_ContainBoxPull =
union{
	cylinder{ < -SpCr1_ContainLargeRemoverWidth / 2, SpCr1_ContainHeight * SpCr1_PullYPosition, -SpCr1_Width / 2 + SpCr1_StrapDeepness * SpCr1_PullDeepnessRatio >, SpCr1_Pull_PtA, SpCr1_PullRadius }
	cylinder{ < SpCr1_ContainLargeRemoverWidth / 2, SpCr1_ContainHeight * SpCr1_PullYPosition, -SpCr1_Width / 2 + SpCr1_StrapDeepness * SpCr1_PullDeepnessRatio >, SpCr1_Pull_PtB, SpCr1_PullRadius }
	sphere{ SpCr1_Pull_PtA, SpCr1_PullRadius }
	sphere{ SpCr1_Pull_PtB, SpCr1_PullRadius }
	cylinder{ SpCr1_Pull_PtA, SpCr1_Pull_PtC, SpCr1_PullRadius }
	cylinder{ SpCr1_Pull_PtB, SpCr1_Pull_PtD, SpCr1_PullRadius }
	sphere{ SpCr1_Pull_PtC, SpCr1_PullRadius }
	sphere{ SpCr1_Pull_PtD, SpCr1_PullRadius }
	cylinder{ SpCr1_Pull_PtC, SpCr1_Pull_PtD, SpCr1_PullRadius }
	texture{ SpCr1_DarkGrayTexture }
}

#declare SpCr1_ContainBox =
union{
	difference{
		object{ SpCr1_RoughContainBoxWithRounds texture{ SpCr1_ContainTexture } }
		object{ SpCr1_RoughContainBoxWithRounds scale SpCr1_BothInnerRemoveScale translate ( SpCr1_ContainHeight - SpCr1_BothInnerRemoveScale ) * y texture{ SpCr1_DarkGrayTexture } }
		object{ SpCr1_ContainNarrowStrapRemover rotate 180 * y translate < SpCr1_Width / 2 - SpCr1_CoverRoundRadius, 0, -SpCr1_BothStrapDistance > texture{ SpCr1_ContainTexture } }
		object{ SpCr1_ContainNarrowStrapRemover rotate 180 * y translate < SpCr1_Width / 2 - SpCr1_CoverRoundRadius, 0, SpCr1_BothStrapDistance > texture{ SpCr1_ContainTexture } }
		object{ SpCr1_ContainNarrowStrapRemover translate < -SpCr1_Width / 2 + SpCr1_CoverRoundRadius, 0, -SpCr1_BothStrapDistance > texture{ SpCr1_ContainTexture } }
		object{ SpCr1_ContainNarrowStrapRemover translate < -SpCr1_Width / 2 + SpCr1_CoverRoundRadius, 0, SpCr1_BothStrapDistance > texture{ SpCr1_ContainTexture } }
		object{ SpCr1_ContainNarrowRemover rotate 180 * y translate < SpCr1_Width / 2 - SpCr1_CoverRoundRadius, 0, 0 > texture{ SpCr1_ContainTexture } }
		object{ SpCr1_ContainNarrowRemover translate < -SpCr1_Width / 2 + SpCr1_CoverRoundRadius, 0, 0 > texture{ SpCr1_ContainTexture } }
		object{ SpCr1_ContainPullRemover translate < -SpCr1_Width / 2 + SpCr1_CoverRoundRadius, 0, 0 > rotate 270 * y texture{ SpCr1_ContainTexture } }
		object{ SpCr1_ContainPullRemover translate < -SpCr1_Width / 2 + SpCr1_CoverRoundRadius, 0, 0 > rotate 90 * y texture{ SpCr1_ContainTexture } }
	}
	difference{
		object{ SpCr1_CoverBoxBottom scale < 0.95, SpCr1_HermeticPartsScale, 0.95 > translate SpCr1_ContainHeight * y }//Part to close hermetically the crate
		object{ SpCr1_CoverBoxBottom scale < 0.92, 1, 0.92 > translate SpCr1_ContainHeight * y + < 0, -0.001, 0 > }//Part to close hermetically the crate
		texture{ SpCr1_DarkGrayTexture }
	}
	object{ SpCr1_ContainBoxPull }
	object{ SpCr1_ContainBoxPull rotate 180 * y }
}

#declare SpCr1_CompleteCrateWithCover =
union{
	object{ SpCr1_CompleteCover translate ( SpCr1_ContainHeight + SpCr1_CoverHeight * SpCr1_HermeticPartsScale ) * y }
	object{ SpCr1_ContainBox }
	object{ SpCr1_CoverAttach rotate 90 * y rotate -90 * x 
			translate < -SpCr1_Width / 2 + SpCr1_StrapDeepness, ( SpCr1_ContainHeight + SpCr1_CoverHeight * SpCr1_HermeticPartsScale / 2 ), -SpCr1_BothStrapDistance > }
	object{ SpCr1_CoverAttach rotate 90 * y rotate -90 * x 
			translate < -SpCr1_Width / 2 + SpCr1_StrapDeepness, ( SpCr1_ContainHeight + SpCr1_CoverHeight * SpCr1_HermeticPartsScale / 2 ), SpCr1_BothStrapDistance > }
	object{ SpCr1_CoverAttach rotate 90 * y rotate -90 * x 
			translate < -SpCr1_Width / 2 + SpCr1_StrapDeepness, ( SpCr1_ContainHeight + SpCr1_CoverHeight * SpCr1_HermeticPartsScale / 2 ), -SpCr1_BothStrapDistance > 
			rotate 180 * y }
	object{ SpCr1_CoverAttach rotate 90 * y rotate -90 * x 
			translate < -SpCr1_Width / 2 + SpCr1_StrapDeepness, ( SpCr1_ContainHeight + SpCr1_CoverHeight * SpCr1_HermeticPartsScale / 2 ), SpCr1_BothStrapDistance > 
			rotate 180 * y }
}

#declare SpCr1_CompleteCoverWithAttachs =
union{
	object{ SpCr1_CompleteCover }
	object{ SpCr1_CoverAttach rotate 90 * y rotate -90 * x 
			translate < -SpCr1_Width / 2 + SpCr1_StrapDeepness, 0, -SpCr1_BothStrapDistance > }
	object{ SpCr1_CoverAttach rotate 90 * y rotate -90 * x 
			translate < -SpCr1_Width / 2 + SpCr1_StrapDeepness, 0, SpCr1_BothStrapDistance > }
	object{ SpCr1_CoverAttach rotate 90 * y rotate -90 * x 
			translate < -SpCr1_Width / 2 + SpCr1_StrapDeepness, 0, -SpCr1_BothStrapDistance > 
			rotate 180 * y }
	object{ SpCr1_CoverAttach rotate 90 * y rotate -90 * x 
			translate < -SpCr1_Width / 2 + SpCr1_StrapDeepness, 0, SpCr1_BothStrapDistance > 
			rotate 180 * y }
}
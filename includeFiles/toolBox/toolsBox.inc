#include "math.inc"

#declare ToolBox_RedColor = color srgb < 1, 0, 0 >;
#declare ToolBox_StalkColor = color srgb 0.85;
#declare ToolBox_PullColor = color srgb 0.15;
#declare ToolBox_BoxFinish = finish{ specular 0.15 roughness 0.2 metallic}

#declare ToolBox_MetalTexture = texture{ pigment{ ToolBox_StalkColor } finish{ ToolBox_BoxFinish } }
#declare ToolBox_PullTexture = texture{ pigment{ ToolBox_PullColor } finish{ ToolBox_BoxFinish } }

#declare ToolBox_BoxWidth = 2;
#declare ToolBox_BoxDepth = 6;
#declare ToolBox_BoxHeight = 3.5;
#declare ToolBox_BaseHeight = ToolBox_BoxHeight * 2 / 5;
#declare ToolBox_CompHeight = ToolBox_BoxHeight / 5;
#declare ToolBox_CompSpace = 0.02;

#declare ToolBox_ToolBase = box{ < -ToolBox_BoxWidth / 2, 0, -ToolBox_BoxDepth / 2 >, < ToolBox_BoxWidth / 2, ToolBox_BaseHeight, ToolBox_BoxDepth / 2 > }

#declare ToolBox_Comp = box{ < -ToolBox_BoxWidth / 4 + ToolBox_CompSpace, 0.075, -ToolBox_BoxDepth / 2 > , < ToolBox_BoxWidth / 4 - ToolBox_CompSpace, ToolBox_CompHeight, ToolBox_BoxDepth / 2> }

#declare ToolBox_LowerPoint = < -ToolBox_BoxWidth / 2 * 0.8,		 // -0.8
						ToolBox_BaseHeight * 0.8,			// 1.12
						0 >;

#declare ToolBox_UpperPoint = < -ToolBox_BoxWidth / 2 * 0.25, 					// -0.2
						0.8 * ToolBox_CompHeight + ToolBox_BoxHeight * 2 / 5, 	// 1.96
						0 >;

#declare ToolBox_StalkLength = VDist( ToolBox_LowerPoint, ToolBox_UpperPoint );
#declare ToolBox_HorizontalVector = < 1, 0, 0>;
#declare ToolBox_StalkVector = ToolBox_UpperPoint - ToolBox_LowerPoint;
#declare ToolBox_StalkAngle = VAngleD(ToolBox_StalkVector, ToolBox_HorizontalVector );
#declare ToolBox_StalkWidth = 0.15;
#declare ToolBox_StalkDepth = 0.025;

#declare ToolBox_PullRadius = 0.08;
#declare ToolBox_PullHighness = 0.7;

#declare ToolBox_StalkObject = 
union{
	sphere{ < 0, 0, -ToolBox_StalkDepth / 2 >, ToolBox_StalkWidth / 4 }
	cylinder{ < 0, 0, -ToolBox_StalkDepth >, < 0, 0, 0 >, ToolBox_StalkWidth / 2 }
	box{ < -ToolBox_StalkWidth / 2,	0, -ToolBox_StalkDepth >, < ToolBox_StalkWidth / 2, 	ToolBox_StalkLength,	 0> }
	cylinder{	< 0, ToolBox_StalkLength, -ToolBox_StalkDepth >, < 0, ToolBox_StalkLength, 0 >, ToolBox_StalkWidth / 2 }
	sphere{ < 0, ToolBox_StalkLength, -ToolBox_StalkDepth / 2 >, ToolBox_StalkWidth / 4 }
	texture{ ToolBox_MetalTexture }
}

#declare ToolBox_Pull =
union{
	box{ <-ToolBox_BoxWidth / 8, 0, -1.5>, < ToolBox_BoxWidth / 8, ToolBox_PullRadius * 2,-0.5 - ToolBox_PullRadius * 2 > texture{ ToolBox_MetalTexture } }
	box{ <-ToolBox_BoxWidth / 8, 0, 1.5>,< ToolBox_BoxWidth / 8, ToolBox_PullRadius * 2,0.5 + ToolBox_PullRadius * 2 > texture{ ToolBox_MetalTexture } }
	union{
		cylinder{ < 0, ToolBox_PullRadius, -0.5 - ToolBox_PullRadius >, < 0, ToolBox_PullRadius, -0.5 - ToolBox_PullRadius * 2 >, ToolBox_PullRadius }
		cylinder{ < 0, ToolBox_PullRadius, 0.5 + ToolBox_PullRadius >, < 0, ToolBox_PullRadius, 0.5 + ToolBox_PullRadius * 2 >, ToolBox_PullRadius }
		sphere{ < 0, ToolBox_PullRadius, -0.5 - ToolBox_PullRadius >, ToolBox_PullRadius }
		sphere{ < 0, ToolBox_PullRadius, 0.5 + ToolBox_PullRadius >, ToolBox_PullRadius }
		cylinder{ < 0, ToolBox_PullRadius, -0.5 - ToolBox_PullRadius >, < 0, ToolBox_PullHighness, -0.5 - ToolBox_PullRadius >, ToolBox_PullRadius }
		cylinder{ < 0, ToolBox_PullRadius, 0.5 + ToolBox_PullRadius >, < 0, ToolBox_PullHighness, 0.5 + ToolBox_PullRadius>, ToolBox_PullRadius }
		sphere{ < 0, ToolBox_PullHighness, -0.5 - ToolBox_PullRadius >, ToolBox_PullRadius }
		sphere{ < 0, ToolBox_PullHighness, 0.5 + ToolBox_PullRadius >, ToolBox_PullRadius }
		cylinder{ < 0, ToolBox_PullHighness, -0.5 - ToolBox_PullRadius >, < 0, ToolBox_PullHighness, 0.5 + ToolBox_PullRadius >, ToolBox_PullRadius }
		translate -ToolBox_PullRadius * y rotate -90*z translate ToolBox_PullRadius * y
		texture{ ToolBox_PullTexture }
	}
}

#declare ToolBox_SideStalks = union{
	object{ ToolBox_StalkObject rotate -(90 - ToolBox_StalkAngle) * z translate < ToolBox_LowerPoint.x, ToolBox_LowerPoint.y, -ToolBox_BoxDepth / 2 > }
	object{ ToolBox_StalkObject rotate (90 - ToolBox_StalkAngle) * z translate < -ToolBox_LowerPoint.x, ToolBox_LowerPoint.y, -ToolBox_BoxDepth / 2 >  }
	object{ ToolBox_StalkObject rotate -(90 - ToolBox_StalkAngle) * z translate < ToolBox_LowerPoint.x, ToolBox_LowerPoint.y + ToolBox_CompHeight, -ToolBox_BoxDepth / 2 > }
	object{ ToolBox_StalkObject rotate (90 - ToolBox_StalkAngle) * z translate < -ToolBox_LowerPoint.x, ToolBox_LowerPoint.y + ToolBox_CompHeight, -ToolBox_BoxDepth / 2 >  }
	object{ ToolBox_StalkObject rotate -(90 - ToolBox_StalkAngle) * z translate < ToolBox_LowerPoint.x, ToolBox_LowerPoint.y + ToolBox_CompHeight * 2, -ToolBox_BoxDepth / 2 > }
	object{ ToolBox_StalkObject rotate (90 - ToolBox_StalkAngle) * z translate < -ToolBox_LowerPoint.x, ToolBox_LowerPoint.y + ToolBox_CompHeight * 2, -ToolBox_BoxDepth / 2 >  }
}

#declare ToolsBox =
union{
	union{
		object{ ToolBox_ToolBase }
		object{ ToolBox_Comp translate < -ToolBox_BoxWidth / 4, ToolBox_BoxHeight * 2 / 5, 0 > }
		object{ ToolBox_Comp translate < ToolBox_BoxWidth / 4, ToolBox_BoxHeight * 2 / 5, 0 > }
		object{ ToolBox_Comp translate < -ToolBox_BoxWidth / 4, ToolBox_BoxHeight * 3 / 5, 0 > }
		object{ ToolBox_Comp translate < ToolBox_BoxWidth / 4, ToolBox_BoxHeight * 3 / 5, 0 > }
		object{ ToolBox_Comp translate < -ToolBox_BoxWidth / 4, ToolBox_BoxHeight * 4 / 5, 0 > }
		object{ ToolBox_Comp translate < ToolBox_BoxWidth / 4, ToolBox_BoxHeight * 4 / 5, 0 > }
		texture{ pigment{ ToolBox_RedColor } finish{ ToolBox_BoxFinish } }
	}
	object{ ToolBox_SideStalks }
	object{ ToolBox_SideStalks translate (ToolBox_BoxDepth + ToolBox_StalkDepth ) * z }
	object{ ToolBox_Pull translate ToolBox_BoxHeight * y }
}

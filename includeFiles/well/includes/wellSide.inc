
#declare MortarColor = color srgb 1;
#declare WellSideStoneColorA = color srgb < 196 / 255, 175 / 255, 166 / 255 >;
#declare WellSideStoneColorB = color srgb < 183 / 255, 151 / 255, 135 / 255 >;
#declare WellSideStonePig = pigment{ wrinkles color_map{ [ 0.05 WellSideStoneColorA ][ 0.45 WellSideStoneColorA ]
														[ 0.55 WellSideStoneColorB ][ 0.95 WellSideStoneColorB ] }
										scale 0.01 }

#declare FlatStoneRadius = 2;
#declare StonesNumber = 18;
#declare StonePrismPtsNum = 40;
#declare StoneSpacingPercent = 0.975;

#declare FlatStoneSmallRadius = Well_BaseRadius;

#declare FlatStone = 
prism{ linear_sweep linear_spline 0.1, -4,
	82
	< 0, FlatStoneSmallRadius > 
	#for( It, 0, StonePrismPtsNum - 1 )
		< vrotate( < 0, 0, FlatStoneRadius >, 
				< 0, 360 / StonesNumber / StonePrismPtsNum * It * StoneSpacingPercent, 0 >).x
		  vrotate( < 0, 0, FlatStoneRadius >, 
				< 0, 360 / StonesNumber / StonePrismPtsNum * It * StoneSpacingPercent, 0 >).z >
	#end
	#for( It, StonePrismPtsNum - 1, 0, -1 )
		< vrotate( < 0, 0, FlatStoneSmallRadius >, 
				< 0, 360 / StonesNumber / StonePrismPtsNum * It * StoneSpacingPercent, 0 >).x
		  vrotate( < 0, 0, FlatStoneSmallRadius >, 
				< 0, 360 / StonesNumber / StonePrismPtsNum * It * StoneSpacingPercent, 0 >).z >
	#end
	< 0, FlatStoneSmallRadius > 
	
	texture{ pigment{ WellSideStonePig } normal{ Well_StoneNormal } }
}

#declare StoneGroup =
union{
	#for( It, 0, StonesNumber - 1 )
		object{ FlatStone rotate 360 / StonesNumber * It * y }
	#end
}

#declare WellMortar =
cylinder{ < 0, max_extent( StoneGroup ).y - 0.0025, 0 >, < 0, -1, 0 >, FlatStoneRadius - 0.01 
	texture{ pigment{ MortarColor } }
}

#declare WellBottomStones =
union{
	object{ StoneGroup }
	object{ WellMortar }
}

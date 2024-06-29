/*
	Author: Antoine FAURE.
	Licence of this file: free for educational, commercial or other usage.

	Use the following object statement to have the pneumatic boat:
		'object{ PneumaticBoat }'
	
	Note: all declares in this file have been prefixed with 'PneuBoat_' to
		avoid any token collision at parse time. This file is completely
		independant from any other file as it doesn't contain any '#include'
		statement. The colors system are the srgb one of POVRay in order to 
		get more realism in a given scene.
*/

#declare PneuBoat_MotorBlackColor = color srgb 0.20;
#declare PneuBoat_MotorRedColor = color srgb < 0.65, 0, 0 >;

#declare PneuBoat_FloatersWhitePig = pigment{ color srgb 1 }                      
#declare PneuBoat_FloatersBluePig = pigment{ color srgb < 37 / 255, 47 / 255, 82 / 255 > }
#declare PneuBoat_MotorBlackPig = pigment{ PneuBoat_MotorBlackColor }
#declare PneuBoat_MotorRedLine = pigment{ gradient y color_map{ 
													[0.6 PneuBoat_MotorBlackColor]
													[0.6 PneuBoat_MotorRedColor ]
													[0.85 PneuBoat_MotorRedColor ]
													[0.85 PneuBoat_MotorBlackColor ] 
												} 
						} 


#declare PneuBoat_FloatersFinish = finish{ specular 0.1 roughness 0.01 }
#declare PneuBoat_MotorFinish = finish{ specular 0.05 roughness 0.1 } 


#declare PneuBoat_Rear_x = 19;
#declare PneuBoat_RearRegul_x = 174;
#declare PneuBoat_FrontLess_x = 222;
#declare PneuBoat_FrontFinal_x = 298;
#declare PneuBoat_TopRegul_z = 60; 
#declare PneuBoat_TopLess_z = 56;
#declare PneuBoat_TopFinal_z = 26;
#declare PneuBoat_FloaterRadius = 20;
#declare PneuBoat_TopFinal_y = 20;

#declare PneuBoat_RearPanel_X = 39;

//x is the forward vector of the boat
#declare PneuBoat_Pt_left_A = < PneuBoat_Rear_x, 0, PneuBoat_TopRegul_z >;
#declare PneuBoat_Pt_left_B = < PneuBoat_RearRegul_x, 0, PneuBoat_TopLess_z >;
#declare PneuBoat_Pt_left_C = < PneuBoat_FrontFinal_x, PneuBoat_TopFinal_y, PneuBoat_TopFinal_z >;
#declare PneuBoat_Pt_right_A = < PneuBoat_Rear_x, 0, -PneuBoat_TopRegul_z >;
#declare PneuBoat_Pt_right_B = < PneuBoat_RearRegul_x, 0, -PneuBoat_TopLess_z >;
#declare PneuBoat_Pt_right_C = < PneuBoat_FrontFinal_x, PneuBoat_TopFinal_y, -PneuBoat_TopFinal_z >;

#declare PneuBoat_Pt_leftTopPanel = < PneuBoat_RearPanel_X, PneuBoat_FloaterRadius, PneuBoat_TopRegul_z >;
#declare PneuBoat_Pt_rightTopPanel = < PneuBoat_RearPanel_X, PneuBoat_FloaterRadius, -PneuBoat_TopRegul_z >;
#declare PneuBoat_Pt_leftBottomPanel = < PneuBoat_RearPanel_X, 0, PneuBoat_TopRegul_z >;
#declare PneuBoat_Pt_rightBottomPanel = < PneuBoat_RearPanel_X, 0, -PneuBoat_TopRegul_z >;
                      
#declare PneuBoat_Floaters = 
merge{
	union{
		sphere{0, PneuBoat_FloaterRadius scale <0.5, 1, 1> translate PneuBoat_Pt_left_A }
		cylinder{ PneuBoat_Pt_left_A, PneuBoat_Pt_left_B, PneuBoat_FloaterRadius }
		sphere{0, PneuBoat_FloaterRadius scale <0.5, 1, 1> translate PneuBoat_Pt_right_A }
		cylinder{ PneuBoat_Pt_right_A, PneuBoat_Pt_right_B, PneuBoat_FloaterRadius }
                          
		pigment{ PneuBoat_FloatersBluePig }
		finish{ PneuBoat_FloatersFinish }
	}
	union{
		sphere{ PneuBoat_Pt_right_B, PneuBoat_FloaterRadius }
		cylinder{ PneuBoat_Pt_right_B, PneuBoat_Pt_right_C, PneuBoat_FloaterRadius }
		sphere{ PneuBoat_Pt_left_B, PneuBoat_FloaterRadius }
		cylinder{ PneuBoat_Pt_left_B, PneuBoat_Pt_left_C, PneuBoat_FloaterRadius }
		sphere{ PneuBoat_Pt_left_C, PneuBoat_FloaterRadius }
		sphere{ PneuBoat_Pt_right_C, PneuBoat_FloaterRadius }
		pigment{ PneuBoat_FloatersWhitePig }
		finish{ PneuBoat_FloatersFinish }
	}
                         
                          cylinder{ PneuBoat_Pt_left_C, PneuBoat_Pt_right_C, PneuBoat_FloaterRadius - 0.0001 
								pigment{ PneuBoat_FloatersBluePig }
								finish{ PneuBoat_FloatersFinish }
                          }
                          
                    }

#declare PneuBoat_StepWidth = 30;
#declare PneuBoat_StepInterval = 2;
#declare PneuBoat_GroundStep = 
prism{ linear_sweep linear_spline PneuBoat_TopLess_z, -PneuBoat_TopLess_z, 5, 
	< -PneuBoat_StepWidth / 2, 0 >, 
	< -PneuBoat_StepWidth / 2 + PneuBoat_StepInterval, PneuBoat_StepInterval >, 
	< PneuBoat_StepWidth / 2 - PneuBoat_StepInterval, PneuBoat_StepInterval >, 
	< PneuBoat_StepWidth / 2, 0 >, 
	< -PneuBoat_StepWidth / 2, 0 > 
	rotate -90*x 
	pigment{ PneuBoat_FloatersWhitePig }
}
                    
#declare PneuBoat_SimpleZodiacGround = 
mesh{
	triangle{ PneuBoat_Pt_left_B, PneuBoat_Pt_right_B, PneuBoat_Pt_left_C }
	triangle{ PneuBoat_Pt_left_C, PneuBoat_Pt_right_C, PneuBoat_Pt_right_B }
	triangle{ PneuBoat_Pt_leftTopPanel, PneuBoat_Pt_rightTopPanel, PneuBoat_Pt_rightBottomPanel }
	triangle{ PneuBoat_Pt_leftTopPanel, PneuBoat_Pt_rightBottomPanel, PneuBoat_Pt_leftBottomPanel }
	pigment{ PneuBoat_FloatersWhitePig }
	finish{ PneuBoat_FloatersFinish }
}

#declare PneuBoat_ComplexZodiacGround = 
union{ 
	#local PneuBoat_X_Position = PneuBoat_RearRegul_x - PneuBoat_StepWidth / 2;
	#while( PneuBoat_X_Position > PneuBoat_StepWidth / 2 )
		object{ PneuBoat_GroundStep translate < PneuBoat_X_Position, -PneuBoat_FloaterRadius / 2, 0 > }
		#local PneuBoat_X_Position = PneuBoat_X_Position - PneuBoat_StepWidth;
	#end 
}

#declare PneuBoat_MotorScale = 40;
                    
#declare PneuBoat_MotorTop = 
prism{ conic_sweep linear_spline 40 / PneuBoat_MotorScale, 30 / PneuBoat_MotorScale, 7, 
	<30, -10> / PneuBoat_MotorScale,
	< 30, 10> / PneuBoat_MotorScale, 
	<-10, 20> / PneuBoat_MotorScale ,
	<-20, 10> / PneuBoat_MotorScale,
	< -20,-10> / PneuBoat_MotorScale,
	<-10,-20> / PneuBoat_MotorScale,
	<30, -10> / PneuBoat_MotorScale 
	rotate 180*x translate y 
}
							
#declare PneuBoat_MotorBody = 
prism{ linear_sweep linear_spline 0, 20, 7, 
	< 30, -10 >,
	< 30, 10 >, 
	< -10, 20 >,
	< -20, 10 >,
	< -20,-10 >,
	< -10,-20 >,
	< 30, -10 > 
}

#declare PneuBoat_MotorGlobal = 
merge{ 
	object{ PneuBoat_MotorTop scale PneuBoat_MotorScale translate 20 * y
		pigment{ PneuBoat_MotorBlackColor }
		finish{ PneuBoat_MotorFinish }
	} 
	object{ PneuBoat_MotorBody 
		pigment{ PneuBoat_MotorRedLine scale <1, 20, 1> }
		finish{ PneuBoat_MotorFinish }
	} 
	translate < 20, 20, 0 >
}
                    
#declare PneumaticBoat = 
union{
	object{ PneuBoat_Floaters } 
	object{ PneuBoat_ComplexZodiacGround }
	object{ PneuBoat_SimpleZodiacGround }
	object{ PneuBoat_MotorGlobal }
}

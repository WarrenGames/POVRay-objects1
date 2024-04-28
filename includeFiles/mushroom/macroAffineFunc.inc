#macro AffineSetBoundOnly(x1, x2, y1, y2, CurrentX)
    #if( x1 = x2 )
        #error "Can't render, because x1 and x2 have equal values"
    #end
    
    #local DirCoef = (y2 - y1) / ( x2 - x1 );
    #local OrigineOffset = y1 - (DirCoef * x1);
    DirCoef * CurrentX + OrigineOffset
#end
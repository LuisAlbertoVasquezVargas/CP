package main

import ("fmt"
        "math"
    )
func dist(x int, y int) int{
    return (x-50)*(x-50)+(y-50)*(y-50);
}
func isInside(x int,y int)bool{
    return dist(x,y)<=50*50
}
func cross(Ax int,Ay int,Bx int,By int)int{
    return Ax*By-Ay*Bx;
}
func dot(Ax int,Ay int,Bx int,By int)int{
    return Ax*Bx+Ay*By;
}
func getAngle(cos float64,sin float64)float64{
    return math.Atan2(sin,cos);
}
/*
ld cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x; }
ld dot( const Point &A , const Point &B ){ return A.x*B.x + A.y*B.y; }
 */
 func Btoi(b bool) int {
     if b {
         return 1
     }
     return 0
  }
func main(){
    var cases int;
    fmt.Scanln(&cases);
    for tc:=0;tc<cases;tc++{
        var P,x,y int;
        fmt.Scanln(&P,&x,&y);
        var isWhite=0;
        if isInside(x,y){
            cos:=float64(dot(x-50,y-50,50-50,100-50));
            sin:=float64(cross(x-50,y-50,50-50,100-50));
            ang:=getAngle(cos,sin);
            if ang<0 {
                ang+=(2*math.Pi);
            }
            isWhite=Btoi((100.0*ang>float64(P)*2.0*math.Pi));
            /*
            fmt.Println(P,x,y);
            fmt.Println(ang/(2*math.Pi)*360);
            */
        }else{
            isWhite=1;
        }
        ans:=[2]string{"black","white"};
        fmt.Print("Case #",(tc+1),": "+ans[isWhite]);
        fmt.Println();
    }
}

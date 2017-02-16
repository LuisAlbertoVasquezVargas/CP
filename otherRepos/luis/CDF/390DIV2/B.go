package main
import "fmt"

const size int = 4;
func solve(T []string,x int,y int) bool{
    //fmt.Println(x,y);
    T[x]=T[x][:y]+string('x')+T[x][y+1:];
    possible:=false;
    for i:=0;i<size;i++{
        for j:=0;j<size;j++{
            if T[i][j]=='x'{
                for dx:=-1;dx<=1;dx++{
                    for dy:=-1;dy<=1;dy++{
                        if dx==0&&dy==0{
                            continue;
                        }
                        cnt:=0;
                        for k:=0;k<3;k++{
                            nx:=i+dx*k;
                            ny:=j+dy*k;
                            if nx>=0&&nx<size&&ny>=0&&ny<size&&T[nx][ny]=='x'{
                                cnt++;
                            }else{
                                break;
                            }
                        }
                        if cnt==3{
                            possible=true;
                        }
                    }
                }
            }
        }
    }
    T[x]=T[x][:y]+string('.')+T[x][y+1:];
    return possible;
}
func main(){
    for true{
        var T []string;
        var v string;
        if items,_:=fmt.Scanln(&v);items==0{
            break;
        }
        T=append(T,v);
        for i:=0;i<size-1;i++{
            fmt.Scanln(&v);
            T=append(T,v);
        }
        //fmt.Println(T);
        ok:=false;
        for i:=0;i<size;i++{
            for j:=0;j<size;j++{
                if T[i][j]=='.'{
                    ok=ok||solve(T,i,j);
                    //fmt.Println(T);
                }
            }
        }
        if ok{
            fmt.Println("YES");
        }else{
            fmt.Println("NO");
        }
    }
}

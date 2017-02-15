package main
import "fmt"
func main(){
    for true{
        var n int;
        if items,_:=fmt.Scan(&n);items==0{
            break;
        }
        var myVec []int;
        for i:=0;i<n;i++{
            var x int;
            fmt.Scan(&x);
            myVec=append(myVec,x);
        }
        //fmt.Println(myVec);
        ok:=true;
        var L,R []int;
        for i:=0;i<n;i++{
            ind:=-1;
            sum:=0;
            for j:=i;j<n;j++{
                sum+=myVec[j];
                if sum != 0{
                    ind=j;
                }
            }
            if ind==-1{
                ok=false;
                break;
            }
            L=append(L,i);
            R=append(R,ind);
            i=ind;
        }
        if !ok{
            fmt.Println("NO");
            continue;
        }
        fmt.Println("YES");
        fmt.Println(len(L));
        for i:=0;i<len(L);i++{
            fmt.Println(L[i]+1,R[i]+1);
        }
    }
}

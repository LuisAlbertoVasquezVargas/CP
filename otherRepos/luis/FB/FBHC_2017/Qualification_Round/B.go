package main
import ("fmt"
        "sort"
        )

func main(){
    var cases int;
    fmt.Scanln(&cases);
    for tc:=0;tc<cases;tc++{
        var n int;
        fmt.Scanln(&n);
        var vec []int;
        for i:=0;i<n;i++{
            var x int;
            fmt.Scanln(&x);
            vec=append(vec,x);
        }
        sort.Ints(vec);
        ans:=0;
        for true{
            //fmt.Println(vec);
            if len(vec)==0{
                break;
            }
            cur:=vec[len(vec)-1];
            delta:=cur;
            vec=vec[:len(vec)-1];
            for true{
                if len(vec)==0||cur>=50{
                    break;
                }
                cur+=delta;
                vec=vec[1:];
            }
            if cur>=50{
                ans++;
            }
        }
        fmt.Print("Case #",(tc+1),": ",ans);
        fmt.Println();
    }
}

package main
import ("fmt"
    "sort"
    "os"
    "bufio"
)

func main(){
    in := bufio.NewReader(os.Stdin)
    var n int;
    for true{
        if items,_:=fmt.Fscanf(in, "%d\n", &n);items!=1{
            break;
        }
        S:=0;
        var div1,div2 []int;
        for i:=0;i<n;i++{
            var c,d int;
            fmt.Fscanf(in, "%d %d\n", &c, &d)
            if d==1{
                div1=append(div1,S);
            }else{
                div2=append(div2,S);
            }
            S+=c;
        }
        sort.Ints(div1);
        sort.Ints(div2);
        if len(div2)==0 {
            fmt.Println("Infinity");
            continue;
        }
        //fmt.Println(div2,div1);
        if !(len(div1)==0||div2[(len(div2)-1)]<div1[0]){
            fmt.Println("Impossible");
            continue;
        }
        fmt.Println(1899+S-div2[(len(div2)-1)]);
    }
}

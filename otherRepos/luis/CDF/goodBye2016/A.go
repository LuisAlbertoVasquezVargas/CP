package main

import "fmt"

func main(){
    var n int
    var K int
    fmt.Scanln(&n,&K);
    var best int;
    for i:=0;i<=n;i++ {
        if 5*((i*(i+1))/2)+K<=240{
            best=i;
        }
    }
    fmt.Println(best);
}

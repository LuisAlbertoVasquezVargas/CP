package main;
import ("fmt"
        "bufio"
        "os"
        )
const (
    MAX_N=1e5+1;
)
type subTree struct{
    valid bool;
    length int;
    color int;//0 neutral -1 invalid
}
func sum(a subTree,b subTree) subTree{
    if a.color==0 {
        return b;
    }
    if b.color==0 {
        return a;
    }
    if a.valid&&b.valid&&a.color==b.color{
        return subTree{true,a.length+b.length,a.color};
    }
    return subTree{false,0,-1};
}
var G [MAX_N][]int;
var col [MAX_N]int;
var T [MAX_N]subTree;
var F [MAX_N]int;
var cnt int;
func update(color int,x int,sign int){
    if color<=0{
        return;
    }
    if sign==1{
        if F[color]==0{
            cnt++;
        }
    }else{
        if x>0&&F[color]==x{
            cnt--;
        }
    }
    F[color]+=sign*x;
    if F[color]<0{
        panic("WTF");
    }
}
func initGraph(n int){
    for i:=0;i<n;i++{
        G[i]=G[i][:0];
    }
}
func add(u int,v int){
    G[u]=append(G[u],v);
    G[v]=append(G[v],u);
}
var ans bool;
var id int;
func dfs(u int,p int){
    //fmt.Println(u+1,F);
    T[u]=subTree{true,0,0};
    for _,v:=range G[u]{
        if v==p{
            continue;
        }

        dfs(v,u);
        T[u]=sum(T[u],T[v]);
    }
    allValid:=true;
    for _,v:=range G[u]{
        if v==p{
            continue;
        }
        if T[v].valid{
            update(T[v].color,T[v].length,-1);
        }else{
            allValid=false;
        }
    }
    update(col[u],1,-1);
    //fmt.Println(u,cnt,F,T[u]);
    if cnt<=1&&allValid {
        ans=true;
        id=u;
    }
    update(col[u],1,+1);
    T[u]=sum(T[u],subTree{true,1,col[u]});
    for _,v:=range G[u]{
        if v==p{
            continue;
        }
        if T[v].valid{
            update(T[v].color,T[v].length,+1);
        }
    }
}
func main(){
    in := bufio.NewReader(os.Stdin);
    var n int;
    for true{
        if items,_:=fmt.Fscanf(in, "%d\n", &n);items!=1{
            break;
        }
        ans=false;
        initGraph(n);
        cnt=0;
        for i:=0;i<MAX_N;i++{
            F[i]=0;
        }
        for i:=0;i<n-1;i++{
            var u,v int;
            fmt.Fscanf(in, "%d %d\n", &u, &v);
            u--;v--;
            add(u,v);
        }
        for i:=0;i<n;i++{
            var x int;
            fmt.Fscanf(in, "%d\n", &x);
            col[i]=x;
            update(x,1,+1);
        }
        //fmt.Println(F);
        dfs(0,-1);
        if ans{
            fmt.Println("YES");
            fmt.Println(id+1);
        }else{
            fmt.Println("NO");
        }
    }
}

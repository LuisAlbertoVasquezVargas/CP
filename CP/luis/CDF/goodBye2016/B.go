package main
import "fmt"

func main(){
    var n int;
    for true{
        matches,_:=fmt.Scanln(&n);
        if matches!=1{
            break;
        }
        MOD:=40000;
        z:=20000;
        ok:=1;
        for i:=0;i<n;i++{
            var len int;
            var cad string;
            fmt.Scanln(&len,&cad);
            //fmt.Println(len,cad,z,ok);
            if (z==0||z==20000)&&(len>20000){
                ok=0;
                continue;
            }
            if (cad=="North"||cad=="South")&&(len>20000){
                ok=0;
                continue;
            }
            len%=MOD;
            if ok==0 {
                continue;
            }
            switch{
                case z==0:
                    if cad=="North"{
                        z=(z+len)%MOD;
                    }else{
                        ok=0;
                        //fmt.Println("kha2");
                    }
                case z==20000:
                    if cad=="South"{
                        z=(z+len)%MOD;
                    }else{
                        ok=0;
                        //fmt.Println("kha1");
                    }
                default:
                    var dir int;
                    if 0<=z&&z<=20000{
                        dir=0;
                    }else {
                        dir=1;
                    }
                    if cad=="South"{
                        dir^=1;
                    }else if cad=="North"{
                        dir^=0;
                    }else{
                        continue;
                    }
                    if dir==0{
                        nz:=(z+len)%MOD;
                        if (0<=z&&z<=20000&&0<=nz&&nz<=20000)||((z==0||z>=20000)&&(nz==0||nz>=20000)){
                            z=nz;
                        }else {
                            ok=0;
                        }
                    }else{
                        nz:=((z-len)%MOD+MOD)%MOD;
                        if (0<=z&&z<=20000&&0<=nz&&nz<=20000)||((z==0||z>=20000)&&(nz==0||nz>=20000)){
                            z=nz;
                        }else {
                            ok=0;
                        }
                    }
            }
        }
        if z!=20000{
            ok=0;
        }
        //fmt.Println(z);
        ans :=[2]string{"NO","YES"};
        fmt.Println(ans[ok]);
    }
}

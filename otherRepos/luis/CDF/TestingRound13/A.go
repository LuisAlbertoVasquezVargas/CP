package main;
import ("fmt")

func print(myVec []int){
	myF:=func (i int) int {
		if i+1==len(myVec){
			return 10;
		}
		return 32;
	};
	fmt.Println(len(myVec));
	for i,item:=range(myVec){
		fmt.Printf("%d%c",item,myF(i));
	}
}
func main() {
	var n int;
	for true{
		if items,_:=fmt.Scanln(&n);items==0{
			break;
		}
		var myVec []int;
		pivot:=1;
		for true{
			if pivot<=n{
				n-=pivot;
				myVec=append(myVec,pivot);
				pivot++;
			}else{
				myVec[len(myVec)-1]+=n;
				break;
			}
		}
		print(myVec);
	}
}

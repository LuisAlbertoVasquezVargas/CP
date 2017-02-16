
import java.math.BigDecimal;
import java.util.Locale;
import java.util.Scanner;


public class Main {


    public static void main(String[] args) 
    {
        Scanner cin = new Scanner(System.in);
        while( cin.hasNext() )
        {
            String S = cin.next(), T = cin.next();
            BigDecimal a = BigDecimal.valueOf(Double.parseDouble(S));
            int b = Integer.parseInt(T);
            String ans = a.pow(b).stripTrailingZeros().toPlainString();
            if( ans.charAt(0) == '0' )
                System.out.println(ans.substring(1));
            else    System.out.println(ans);
        }
    }
}

import java.util.*;

public class AdditionCalculation {
	public static void main(String[] args) {

	    try {
	      Scanner scanner = new Scanner(System.in);

	      System.out.print("演算タイプを選択してください\n 1: 加算\n 2: 減算\n 3: 乗算\n 4: 除算 \n>");
	      int mode = scanner.nextInt();

	      System.out.print("1つ目の値を整数で入力してください > ");
	      int fNum = scanner.nextInt();

	      System.out.print("2つ目の値を整数で入力してください > ");
	      int sNum = scanner.nextInt();

	      scanner.close();

	      int ans = 0;
	      int mod = 0;

	      switch (mode) {
	      	case 1: //加算
	      		ans = fNum + sNum;
	      		break;
	      	case 2: //減算
	      		ans = fNum + (-sNum);
	      		break;
	      	case 3: //乗算
	      		for (int i=1; i<=Math.abs(sNum); i++) {
	      			if (sNum<0) ans += (-fNum);
	      			else ans += fNum;
	      		}
	      		break;
	      	case 4: //除算
	      		mod = fNum;
	      		while (sNum <= mod) {
	      			if (sNum < fNum) {
		      			ans++;
		      		} else {
		      			ans = 0;
		      		}
		      		mod += (-sNum);
	      		}
	      		break;
	      	default:
	      		System.out.println("1-4を入力してください");
	      		System.exit(0);
	      }

	      System.out.print("答えは『" + ans + "』");
	      if(mod != 0) System.out.print("余りは『" + mod + "』");
	      System.out.print("です\n");

	    } catch (InputMismatchException e) { 
	      System.out.println("整数を入力してください。");
	    }
	}

}

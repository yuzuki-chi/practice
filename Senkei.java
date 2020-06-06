import java.io.*;
class Senkei{
	public static void main(String[] args) throws IOException {
		InputStreamReader is = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(is);
 		int [][] ndata = new int [5][5];
 		boolean exitWhile01, exitWhile02 = true;
 		int textNum = 0;

 		for(int j = 0; j < 5; j++){
			for(int i = 0; i < 5; i++){
				System.out.println(i+1 + "つ目を入力してください");
				String str1 = br.readLine();
				textNum = Integer.parseInt(str1);
				if(textNum == 999)break;
				ndata[j][i] = textNum;
			}
			if(textNum == 999)break;
		}

		for(int j = 0; j < 5; j++){
			for(int i = 0; i < 5; i++){
				System.out.print(ndata[j][i]+ "  ");
			}
			System.out.println(" ");
		}


	}
}

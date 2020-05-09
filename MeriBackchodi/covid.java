import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


class covid {

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int test = Integer.parseInt(br.readLine());
            while (test-- > 0) {
                int num = Integer.parseInt(br.readLine());
                int queries = Integer.parseInt(br.readLine());
                String disease = br.readLine();
                int[] alphanums = new int[26];
            
                for (int i = 0; i < num; i++) {
                    int ch = disease.charAt(i);
                    alphanums[ch-97] += 1;
                }

                for (int i = 0; i < queries; i++) {
                    int nummy = 0;
                    int ch = Integer.parseInt(br.readLine());
                    for (int j = 0; j < 26; j++) {
                        if (alphanums[j] > ch) {
                            nummy += (alphanums[j] - 1);
                        }
                    }
                    System.out.println(nummy);
                }

            }
        }
        catch (IOException e) {}
       
    }
}
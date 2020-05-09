import java.util.Scanner;

class Corona {

    int number;
    boolean status;

    Corona(int n, boolean s) {
        this.number = n;
        this.status = s;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int test = sc.nextInt();
        while (test-- > 0) {
            int numbers = sc.nextInt();
            int limit = sc.nextInt();
            Corona[] fList = new Corona[numbers];
            for (int i = 1; i <= limit; i++) {
                for (int j = 0; j < numbers; j++) {
                    int numInput = sc.nextInt();
                    fList[i] = new Corona(numInput, (numInput == (j+1)));
                }
            }
        }
        sc.close();
    }
}

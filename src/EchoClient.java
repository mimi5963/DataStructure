import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

public class EchoClient {
    private static final String SERVER_ADDRESS = "127.0.0.1";
    private static final int SERVER_PORT = 34522;

    public static void main(String[] args){
        try(Socket socket = new Socket(SERVER_ADDRESS,SERVER_PORT);
            //서버의 주소와 포트를 넣은 클라이언트 쪽 소켓을 만듦
            DataInputStream input = new DataInputStream(socket.getInputStream());//서버로 데이터를 받기
            DataOutputStream output = new DataOutputStream(socket.getOutputStream());//서버로 데이터 보내기
            ){
            for(int i=0; i<5; i++) {
                Scanner sc = new Scanner(System.in);
                String msg = sc.nextLine();
                output.writeUTF(msg);
                String receivedMsg = input.readUTF();
                System.out.println("Received from the server : " + receivedMsg);
            }

        }catch (IOException e){

        }
    }

}

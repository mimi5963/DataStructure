import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
public class EchoServer {
    private static final int PORT = 34522;

    public static void main(String[] args){
            try(ServerSocket server = new ServerSocket(PORT)){
                while(true){
                    Session session = new Session(server.accept());
                    session.start();
                }
            }catch (IOException e){
                e.printStackTrace();
            }

    }
}
class Session extends Thread{
    private final Socket sok;
    public Session(Socket SoketForClient){
        this.sok = SoketForClient;
    }
    public void run(){
        try(    DataInputStream input = new DataInputStream(sok.getInputStream());
                DataOutputStream output = new DataOutputStream(sok.getOutputStream())
                ){
                   for(int i=0; i<5;i++) {
                       String msg = input.readUTF();
                       output.writeUTF(msg);
                   }
                    sok.close();
        }catch (IOException e){
            e.printStackTrace();
        }
    }
}

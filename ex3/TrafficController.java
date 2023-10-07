package ex3;
import java.util.concurrent.Semaphore;


public class TrafficController {
	private Semaphore SemaphoreV = new Semaphore(1, true);
	
	private void aquireBridge() {
		try{
			SemaphoreV.acquire();
		}
		catch (InterruptedException ie) {
	        System.err.println( ie.toString());
	    }
			
	}
		
	private void releaseBridge() {
		SemaphoreV.release();
	}
    public void enterLeft() {
    	aquireBridge();
    }
    public void enterRight() {
    	aquireBridge();
    }
    public void leaveLeft() {
    	releaseBridge();
    }
    public void leaveRight() {
    	releaseBridge();
    }

}
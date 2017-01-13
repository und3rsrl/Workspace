import com.alexchiurtu.KaraokeMachine;
import com.alexchiurtu.model.Song;
import com.alexchiurtu.model.SongBook;

public class Karaoke {

	public static void main(String[] args) {



		SongBook songBook = new SongBook();
		KaraokeMachine machine = new KaraokeMachine(songBook);
    machine.run();
	}
}

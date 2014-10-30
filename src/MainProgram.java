import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import java.util.Random;
import java.util.Set;


public class MainProgram {
	
	
	public static void main(String[] args) throws IOException {
		System.out.println("---The program has started");
		//Opening a working directory and picking a random file to work with
		File directory = new File(Constants.documentsPath);
		File[] files = directory.listFiles(); 
		Random randomizer = new Random();
		int startDocumentNumber = randomizer.nextInt(files.length);
		File file = files[startDocumentNumber];
		//Getting all words with their themes
		WordMaster master = new WordMaster();
		HashMap<String, String> table = master.getWordsTable(file);
		//Choosing random next document
		int randomDocumentNumber = startDocumentNumber;
		while(randomDocumentNumber == startDocumentNumber){
			randomDocumentNumber = randomizer.nextInt(files.length);
		}
		File nextFile = files[randomDocumentNumber];
		//Taking the first word in the table and its theme
		String someWord = table.keySet().iterator().next();
		String someTheme = table.get(someWord);
		master.changeWordInDocument(nextFile, someWord, someTheme);
		System.out.println("---The work has successfully finished");
	}

}
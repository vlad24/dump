import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashMap;


public class WordMaster {
	
	public HashMap<String, String> getWordsTable(File file) throws IOException{
		String line = null;
		HashMap<String, String> table = new HashMap<String, String>();
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
		while ((line = reader.readLine()) != null){
			String[] wordBlocks = line.split(Constants.wordBlocksSeparator);
			for (String wordBlock : wordBlocks){
				String[] words = wordBlock.split(Constants.wordSeparator);
				String word = words[0];
				String theme = words[1];
				table.put(word, theme);
			}
		}
		reader.close();
		return table;
	}
	
	public void changeWordInDocument(File document, String word, String newTheme) throws IOException{
		HashMap<String, String> table = getWordsTable(document);
		if (table.containsKey(word)){
			String oldTheme = table.get(word);
			System.out.println("--The word '" + word + "' has been found in the " + document.getName() + " with theme : " + oldTheme);
			System.out.println("--Replacing its theme to " + newTheme);
			Charset charset = StandardCharsets.UTF_8;
			Path path = document.toPath();
			String content = new String(Files.readAllBytes(path), charset);
			String oldPattern = word + Constants.wordSeparator + oldTheme;
			String newPattern = word + Constants.wordSeparator + newTheme;
			content.replaceAll(oldPattern, newPattern);
			System.out.println("--Replaced!");
		}else{
			System.out.println("No word '" + word + "' found in " + document.getName());
		}
	}
	
	
}

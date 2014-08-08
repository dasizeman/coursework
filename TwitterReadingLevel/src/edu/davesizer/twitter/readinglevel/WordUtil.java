package edu.davesizer.twitter.readinglevel;

import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import com.google.gson.JsonArray;
import com.google.gson.JsonElement;
import com.google.gson.JsonParser;

public class WordUtil {
	
	private final String syllableRequestURIFormat = 
			"http://api.wordnik.com/v4/word.json/%s/hyphenation?useCanonical=false&limit=50&api_key=%s";
	private String APIKey;
	private String inputText;
	private List<String> sentences;
	private List<String> words;
	
	public WordUtil(String key)
	{
		APIKey = key;
	}
	
	private int getSyllablesFromWordnikAPI(String word)
	{
		//System.out.println("Making call for " + word);
		int numSyllables = 0;
		try {
			JsonArray root = makeAPICall(String.format(syllableRequestURIFormat, word, APIKey));
			
			numSyllables = root.size();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
		
		return numSyllables;
	}
	
	private static JsonArray makeAPICall(String urlstring) throws Exception
	{
		// This particular api returns the root type as an array
		URL url = new URL(urlstring);
		
		HttpURLConnection request = (HttpURLConnection)url.openConnection();
		request.connect();
		
		JsonParser jp = new JsonParser();
		JsonElement root = jp.parse(new InputStreamReader((InputStream)request.getContent()));
		JsonArray rootarray = root.getAsJsonArray();
		
		return rootarray;
	}
	
	public void setText(String text)
	{
		inputText = text;
		
		// Populate our sentences list (delimited by ?!.)
		sentences = Arrays.asList(inputText.split("[?\\.!]"));
		
		// Populate words list (delimited by spaces)
		words = new ArrayList<String>();
		for (String sentence : sentences)
		{
			// "Clean" words before adding them
			for (String w : sentence.split(" "))
			{
				String cleaned = w.replaceAll("[^a-zA-Z0-9]", "");
				if (!cleaned.isEmpty())
					words.add(cleaned);
			}
		}
		
	}
	
	public int numSyllables(String word)
	{
		return getSyllablesFromWordnikAPI(word);
	}
	
	public List<String> polysyllablicWords()
	{
		DecimalFormat df = new DecimalFormat("#.##");
		ArrayList<String> poly = new ArrayList<String>();
		int progress = 0;
		for (String word : words)
		{
			if (progress % 10 == 0)
				System.out.println(df.format(((double)progress/words.size() * 100)) + "%");
			
			if (numSyllables(word) >= 3)
			{
				poly.add(word);
			}
			progress++;
		}
		
		return poly;
	}
	
	public double calculateReadability(int polysyllablic)
	{
		return 
		(1.0430*Math.sqrt(polysyllablic * ((double)30/sentences.size())) + 3.1291);
	}

}

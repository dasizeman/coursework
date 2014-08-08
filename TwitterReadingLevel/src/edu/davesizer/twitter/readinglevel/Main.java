package edu.davesizer.twitter.readinglevel;

import java.text.DecimalFormat;
import java.util.List;
import java.util.Scanner;

import twitter4j.Status;

public class Main {

	public static void main(String[] args) {
		
		String TwitterAPIKey = "";
	    String TwitterAPISecret = "";
	    String wordnikAPIKey = "";
	    
	    Scanner in = new Scanner(System.in);
	    
	    System.out.println("Enter your Twitter API Key:");
	    TwitterAPIKey = in.nextLine();
	    System.out.println("Enter your Twitter API Secret:");
	    TwitterAPISecret = in.nextLine();
	    System.out.println("Enter your Wordnik API Key:");
	    wordnikAPIKey = in.nextLine();
		
		TwitterUtil tutil = new TwitterUtil(TwitterAPIKey,TwitterAPISecret, in);
		WordUtil wutil = new WordUtil(wordnikAPIKey);
		
		System.out.println("Enter a Twitter handle:");
		
		String handle = in.nextLine();
		in.close();
		
		// Build text data from 30 most recent tweets
		String input = "";
		for (Status s : tutil.getUserTimeline(handle, 1, 30))
			input += s.getText();
		
		// Set this in our word util
		wutil.setText(input);
		
		List<String> polyWords = wutil.polysyllablicWords();
		System.out.println("===============");
		System.out.println("Found the following polysyllablic words:");
		for (String s : polyWords)
			System.out.println(s);
		DecimalFormat df = new DecimalFormat("#.##");
		
		System.out.println("This user writes at a " + 
		df.format(wutil.calculateReadability(polyWords.size())) +
				" grade level");
		
		

	}

}

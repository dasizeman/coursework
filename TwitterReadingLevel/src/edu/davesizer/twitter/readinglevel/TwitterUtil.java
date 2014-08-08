package edu.davesizer.twitter.readinglevel;

import java.util.List;
import java.util.Scanner;

import twitter4j.*;
import twitter4j.auth.*;


public class TwitterUtil {
	
	private String consumerKey, consumerSecret;
	private Twitter twitter;
	
	public TwitterUtil(String key, String secret, Scanner scan)
	{
		consumerKey = key;
		consumerSecret = secret;
		twitter = TwitterFactory.getSingleton();
		
		// Do oAuth (application level)
		try {
			twitter.setOAuthConsumer(consumerKey, consumerSecret);
			RequestToken requestToken = twitter.getOAuthRequestToken();
			AccessToken accessToken = null;
			System.out.println("Go here and grant this app access:");
			System.out.println(requestToken.getAuthorizationURL());
			System.out.println("Enter the PIN if given, else press enter:");
			String pin = scan.nextLine();
			
			if (pin.length() > 0)
				accessToken = twitter.getOAuthAccessToken(requestToken, pin);
			else
				accessToken = twitter.getOAuthAccessToken();
			
			twitter.setOAuthAccessToken(accessToken);
		}
		catch (TwitterException te) {
			te.printStackTrace();
		}
		
	}
	
	public List<Status> getUserTimeline(String username, int pageno, int itemsperpage)
	{
		List<Status> statuses = null;
		Paging paging = new Paging(pageno, itemsperpage);
		try {
			statuses = twitter.getUserTimeline(username, paging);
		} catch (TwitterException e) {
			e.printStackTrace();
		}
		
		return statuses;
	}

}

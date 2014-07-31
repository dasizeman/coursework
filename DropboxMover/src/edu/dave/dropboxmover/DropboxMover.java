package edu.dave.dropboxmover;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Locale;
import java.util.Scanner;

import com.dropbox.core.DbxAccountInfo;
import com.dropbox.core.DbxAppInfo;
import com.dropbox.core.DbxAuthFinish;
import com.dropbox.core.DbxClient;
import com.dropbox.core.DbxEntry;
import com.dropbox.core.DbxException;
import com.dropbox.core.DbxRequestConfig;
import com.dropbox.core.DbxWebAuthNoRedirect;
import com.dropbox.core.DbxWriteMode;

public class DropboxMover {
	
	private String APP_KEY  = "";
	private String APP_SECRET = "";
	private static String accessToken = "";
	private static DbxAppInfo appInfo;
	private static DbxRequestConfig config;
	private static DbxWebAuthNoRedirect webAuth;
	private static DbxAuthFinish authFinish;
	private static DbxClient client;
	private static DbxAccountInfo accountInfo;
	
	/**
	 * Initialize the mover and call the OAuth function
	 * @param appkey The appkey from the API 
	 * @param appsecret The appsecret from the API
	 */
	public DropboxMover(String appkey, String appsecret)
	{
		APP_KEY = appkey;
		APP_SECRET = appsecret;
		appInfo = new DbxAppInfo(APP_KEY, APP_SECRET);
		config = new DbxRequestConfig(
				"DropboxMover/1.0", Locale.getDefault().toString());
		webAuth = new DbxWebAuthNoRedirect(config, appInfo);
		try {
		performDropboxOauth();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	/**
	 * Do the OAuth dance
	 * @throws IOException
	 * @throws DbxException
	 */
	private static void performDropboxOauth() throws IOException, DbxException
	{
		String authorizeUrl = webAuth.start();
		// Have the user sign in and authorize
		System.out.println("1. Go to: " + authorizeUrl);
		System.out.println("2. Click \"Allow\" (you might have to log in first)");
		System.out.println("3. Copy the authorization code.");
		String code = new BufferedReader(new InputStreamReader(System.in)).readLine().trim();
		
		authFinish = webAuth.finish(code);
		accessToken = authFinish.accessToken;
		
		client = new DbxClient(config, accessToken);
		accountInfo = client.getAccountInfo();
	}
	
	/**
	 * Dumps account info to the console
	 */
	public void printClientInfo()
	{
		System.out.println(accountInfo.displayName);
		System.out.println(accountInfo.userId);
		System.out.println(accountInfo.country);
		System.out.println(accountInfo.quota);
	}
	
	/**
	 * Prints the DB directory listing of a given path
	 * @param path Path to the directory to print
	 */
	public void printDirectoryListing(String path)
	{
		try {
			DbxEntry.WithChildren listing = client.getMetadataWithChildren(path);
			
			System.out.println("Files in the " + path + "path:");
			for (DbxEntry child : listing.children) {
			    System.out.println("	" + child.name);
			}
		}
		catch (DbxException dbex) {
			System.out.println("Could not list that directory!");
		}
	}
	/**
	 * Reads the __list file on the DB root, and downloads the files to the paths specified within it
	 * @throws IOException
	 */
	public void downloadListedFiles() throws IOException
	{
		// First, download the __list file from the root of the Dropbox
		FileOutputStream outputStream = new FileOutputStream("__list");
		try {
		    client.getFile("/__list", null,
		        outputStream);
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
		finally {
		    outputStream.close();
		}
		
		// Now, we will open the file, read through each line, and download the corresponding files
		Scanner fileScanner = new Scanner(new File("__list"));
		String fileToDownload = "", savePath = "", currentLine = "";
		while(fileScanner.hasNext())
		{
			currentLine = fileScanner.nextLine();
			fileToDownload = currentLine.split(" ")[0];
			savePath = currentLine.split(" ")[1];
			
			System.out.println("Downloading Dropox file [" + fileToDownload + "] to [" 
					+ savePath + "]");
			
			outputStream = new FileOutputStream(savePath + "/" + fileToDownload);
			try {
			     client.getFile("/" + fileToDownload, null, outputStream);
			}
			catch (Exception e) {
				e.printStackTrace();
			}
			finally {
			    outputStream.close();
			}
		}
		fileScanner.close();
		
		// Clear out the list file and upload it to the Dropbox so we don't don't
		// download files again
		BufferedWriter writer = new BufferedWriter(new FileWriter("__list"));
		writer.close();
		
		File inputFile = new File("__list");
		FileInputStream inputStream = new FileInputStream(inputFile);
		try {
			client.uploadFile("/__list", DbxWriteMode.force(), inputFile.length(), inputStream);
		}
		catch (Exception e) {
			e.printStackTrace();
		}
		finally {
			inputStream.close();
		}
	}
}
	
	
	





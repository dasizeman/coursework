package edu.dave.dropboxmover;

import java.io.IOException;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		// Get the appkey and secret from the user
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter app key:");
		String appkey = scan.nextLine();
		System.out.println("Enter app secret:");
		String appsecret = scan.nextLine();
		
		
		DropboxMover mover = new DropboxMover(appkey, appsecret);
		mover.printClientInfo();
		//mover.printDirectoryListing("/");
		try {
			mover.downloadListedFiles();
		}
		catch (IOException e) {
			System.out.println("Could not download the file!  Check your paths.");
		}
	}
}

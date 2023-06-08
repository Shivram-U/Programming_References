import java.io.*;
import java.util.regex.*;
public class Java_Regex
{
	public static void main(String args[])
	{
		System.out.println("Java Regular Expressions:");
		//  Pattern creation and storage.
		/*
			Pattern Class:
				-> the pattern is built-in case-sensitive .
				-> the pattern class does not have built-in Constructor, hence the Pattern class
				   class can be created using the Pattern.compile() method.
		*/	
			Pattern p1 = Pattern.compile("java");				// Case-sensitive pattern
			Pattern p2 = Pattern.compile("java",Pattern.CASE_INSENSITIVE);	// Case-insensitive pattern
		// Pattern properties provided:
			System.out.println(p1.flags());
			System.out.println(p2.flags());
		// Pattern matching || pattern search
		/*
			The pattern matching or search is done by creating a matcher class.
		*/
		
			Matcher m1 = p1.matcher("Search String/Sentence: java is a programming language");
			Matcher m2 = p1.matcher("Search String/Sentence: Java is a programming language");
			Matcher m3 = p2.matcher("Search String/Sentence: JaVa is a programming language");
		// Pattern search results in Search string 
			System.out.println("Pattern p1 found in m1 :"+m1.find());
			System.out.println("Pattern p1 found in m2 :"+m2.find());
			System.out.println("Pattern p2 found in m3 :"+m3.find());	
		// Simple Pattern Match:
			System.out.println("Pattern match:"+Pattern.matches("java is good","java"));
			System.out.println("Pattern match:"+Pattern.matches("java","java"));
			
	}	
}

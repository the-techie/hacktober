import java.util.*;

class MyException extends Exception
{
	private int num;
	MyException(int n)
	{
		num=n;
	}
	public String toString()
	{
		String s="MyException ("+num+")";
		return s;
	}
}

class Pr11
{
	static void check(int n) throws MyException
	{
		System.out.println("*******Checking....*******");
		if(n%2!=0)
			throw new MyException(n);
		System.out.println("#########NORMAL EXIT#########");
	}
	
	
	public static void main(String []args)
	{	
		Scanner sc=new Scanner(System.in);
		System.out.println("----------Enter any integer----------"); 
		int n=sc.nextInt();
		try
		{
			check(n);
		}
		catch(MyException e)
		{
			System.out.println("Exception Caught:"+e);
		}
	}
}

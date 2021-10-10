import java.util.*;

abstract class Person
{
	String name;
	
	Person(String s){
		name=s;
	}

	Person(){
		name=" ";
	}


	void input(){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter name: ");
		name=sc.next();
	}

	abstract void display();
}

class Student extends Person
{
	String course;
	double marks;
	int year;

	Student(String s,String c,double m,int y){
		super(s);
		course=c;
		marks=m;
		year=y;
	}

	Student(){
		super();
		course=" ";
		marks=0.0;
		year=0;
	}

	void display(){
		System.out.println("Name of student:"+name);
		System.out.println("Course:"+course);
		System.out.println("Marks:"+marks);
		System.out.println("Year:"+year);
	}

	void input(){
		super.input();
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter course of student:");
		course=sc.next();
		System.out.println("Enter marks of student:");
		marks=sc.nextDouble();
		System.out.println("Enter year of student:");
		year=sc.nextInt();
	}
}

class Employee extends Person
{
	String department;
	double salary;

	Employee(String s,String dept,double sal){
		super(s);
		department=dept;
		salary=sal;
	}

	Employee(){
		super();
		department=" ";
		salary=0.0;
	}

	void display(){
		System.out.println("Name of employee: "+name);
		System.out.println("Department: "+department);
		System.out.println("Salary: "+salary);
	}

	void input(){
		super.input();
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter department of employee:");
		department=sc.next();	
		System.out.println("Enter salary of employee:");
		salary=sc.nextDouble();
	}
}

class Pr10
{
	public static void main(String []args){
		Scanner sc=new Scanner(System.in);
		int choice,year;
		Person p;
		String name,dept,course;
		double sal,m;
		while(true){
			System.out.println("--------MAIN MENU--------");
			System.out.println("      1. Student         ");
			System.out.println("      2. Employee        ");
			System.out.println("      3. Exit            ");
			System.out.println("-------------------------");
			choice=sc.nextInt();
			switch(choice){
				case 1: Student ob1=new Student();
					p=ob1;
					p.input();
					System.out.println("-------------------------");
					p.display();
					break;
				case 2: Employee ob2=new Employee();
					p=ob2;
					p.input();
					System.out.println("-------------------------");
					p.display();
					break;
				case 3: System.exit(0);
				default: System.out.println("Invalid choice");
					break;
				}
			}
	}
}

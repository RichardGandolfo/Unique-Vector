#include <iostream>
#include <string>
#include "Classroom.h"
#include "catch.h"

TEST_CASE("adding/removing/containment of students preserves uniqueness","[student]"){
	Classroom myClass;

	REQUIRE( myClass.listAllStudents() == "" );
	
	// Vector contains student after being added
	REQUIRE( myClass.addStudent("Simon") == true );
	REQUIRE( myClass.containsStudent("Simon") == true );
	REQUIRE( myClass.listAllStudents() == "Simon" );
	REQUIRE( myClass.addStudent("Simon") == false);

	// Vector doesn't contain student never added
	REQUIRE( myClass.containsStudent("Aarsh") == false );

	// Stress testing (ish)
	REQUIRE( myClass.addStudent("John") == true);
	REQUIRE( myClass.addStudent("Jacob") == true);
	REQUIRE( myClass.addStudent("Jingle") == true);
	REQUIRE( myClass.addStudent("Heimer") == true);
	REQUIRE( myClass.addStudent("Schmidt") == true);
	
	REQUIRE( myClass.listAllStudents() == "Simon,John,Jacob,Jingle,Heimer,Schmidt" );
	REQUIRE( myClass.containsStudent("Schmidt") == true);
	REQUIRE( myClass.containsStudent("Heimer") == true);
	REQUIRE( myClass.containsStudent("Jingle") == true);
	REQUIRE( myClass.containsStudent("Jacob") == true);
	REQUIRE( myClass.containsStudent("John") == true);
	REQUIRE( myClass.containsStudent("Simon") == true);

	// Removing an existing student returns true
	REQUIRE( myClass.removeStudent("Simon") == true);
	REQUIRE( myClass.listAllStudents() == "John,Jacob,Jingle,Heimer,Schmidt" );
	REQUIRE( myClass.containsStudent("Simon") == false);

	REQUIRE( myClass.removeStudent("John") == true);
	REQUIRE( myClass.removeStudent("Jacob") == true);
	REQUIRE( myClass.removeStudent("Jingle") == true);
	REQUIRE( myClass.removeStudent("Heimer") == true);
	REQUIRE( myClass.removeStudent("Schmidt") == true);
	
	REQUIRE( myClass.listAllStudents() == "" );
	REQUIRE( myClass.containsStudent("Schmidt") == false);
	REQUIRE( myClass.containsStudent("Heimer") == false);
	REQUIRE( myClass.containsStudent("Jingle") == false);
	REQUIRE( myClass.containsStudent("Jacob") == false);
	REQUIRE( myClass.containsStudent("John") == false);
	REQUIRE( myClass.containsStudent("Simon") == false);
}

TEST_CASE("Alphabetically first student removal", "[alphabeticalFirst]"){
	Classroom myClass;

	SECTION("Remove from beginning"){
		REQUIRE( myClass.addStudent("A") == true );
		REQUIRE( myClass.addStudent("B") == true );
		REQUIRE( myClass.addStudent("C") == true );
		REQUIRE( myClass.addStudent("D") == true );
		REQUIRE( myClass.addStudent("E") == true );

		REQUIRE( myClass.removeAlphabeticallyFirst() == "A" );
		REQUIRE( myClass.containsStudent("A") == false );
		REQUIRE( myClass.listAllStudents() == "B,C,D,E" );

		REQUIRE( myClass.removeAlphabeticallyFirst() == "B" );
		REQUIRE( myClass.containsStudent("B") == false );
		REQUIRE( myClass.listAllStudents() == "C,D,E" );
		
		REQUIRE( myClass.removeStudent("C") == true );
		REQUIRE( myClass.listAllStudents() == "D,E" );

		REQUIRE( myClass.removeAlphabeticallyFirst() == "D" );
		REQUIRE( myClass.containsStudent("D") == false );
		REQUIRE( myClass.listAllStudents() == "E" );

	}
	
	SECTION("Remove from middle"){
		REQUIRE( myClass.addStudent("G") == true );
		REQUIRE( myClass.addStudent("H") == true );
		
		REQUIRE( myClass.addStudent("A") == true );
		REQUIRE( myClass.addStudent("B") == true );
		REQUIRE( myClass.addStudent("C") == true );
		REQUIRE( myClass.addStudent("D") == true );
		REQUIRE( myClass.addStudent("E") == true );
		REQUIRE( myClass.addStudent("F") == true );

		REQUIRE( myClass.addStudent("I") == true );
		REQUIRE( myClass.addStudent("J") == true );
		
		REQUIRE( myClass.removeAlphabeticallyFirst() == "A" );
		REQUIRE( myClass.containsStudent("A") == false );
		REQUIRE( myClass.listAllStudents() == "G,H,B,C,D,E,F,I,J" );

		REQUIRE( myClass.removeAlphabeticallyFirst() == "B" );
		REQUIRE( myClass.containsStudent("B") == false );
		REQUIRE( myClass.listAllStudents() == "G,H,C,D,E,F,I,J" );

		REQUIRE( myClass.removeStudent("C") == true );
		REQUIRE( myClass.listAllStudents() == "G,H,D,E,F,I,J" );
		
		REQUIRE( myClass.removeAlphabeticallyFirst() == "D" );
		REQUIRE( myClass.containsStudent("D") == false );
		REQUIRE( myClass.listAllStudents() == "G,H,E,F,I,J" );
		
	}

	SECTION("Remove from end"){
		REQUIRE( myClass.addStudent("E") == true );
		REQUIRE( myClass.addStudent("D") == true );
		REQUIRE( myClass.addStudent("C") == true );
		REQUIRE( myClass.addStudent("B") == true );
		REQUIRE( myClass.addStudent("A") == true );

		REQUIRE( myClass.removeAlphabeticallyFirst() == "A" );
		REQUIRE( myClass.containsStudent("A") == false );
		REQUIRE( myClass.listAllStudents() == "E,D,C,B" );
		
		REQUIRE( myClass.removeAlphabeticallyFirst() == "B" );
		REQUIRE( myClass.containsStudent("B") == false );
		REQUIRE( myClass.listAllStudents() == "E,D,C" );
		
		REQUIRE( myClass.removeStudent("C") == true );
		REQUIRE( myClass.listAllStudents() == "E,D" );
		
		REQUIRE( myClass.removeAlphabeticallyFirst() == "D" );
		REQUIRE( myClass.containsStudent("D") == false );
		REQUIRE( myClass.listAllStudents() == "E" );
	}
	
}

TEST_CASE("Alphabetically last student removal", "[alphabeticalLast]"){
	Classroom myClass;
	
	SECTION("Remove from beginning"){
		REQUIRE( myClass.addStudent("A") == true );
		REQUIRE( myClass.addStudent("B") == true );
		REQUIRE( myClass.addStudent("C") == true );
		REQUIRE( myClass.addStudent("D") == true );
		REQUIRE( myClass.addStudent("E") == true );
		
		REQUIRE( myClass.removeAlphabeticallyLast() == "E" );
		REQUIRE( myClass.containsStudent("E") == false );
		REQUIRE( myClass.listAllStudents() == "A,B,C,D" );
		
		REQUIRE( myClass.removeAlphabeticallyLast() == "D" );
		REQUIRE( myClass.containsStudent("D") == false );
		REQUIRE( myClass.listAllStudents() == "A,B,C" );
		
		REQUIRE( myClass.removeStudent("C") == true );
		REQUIRE( myClass.listAllStudents() == "A,B" );
		
		REQUIRE( myClass.removeAlphabeticallyLast() == "B" );
		REQUIRE( myClass.containsStudent("B") == false );
		REQUIRE( myClass.listAllStudents() == "A" );
		
	}
	
	SECTION("Remove from middle"){
		REQUIRE( myClass.addStudent("A") == true );
		REQUIRE( myClass.addStudent("B") == true );
		REQUIRE( myClass.addStudent("C") == true );

		REQUIRE( myClass.addStudent("G") == true );
		REQUIRE( myClass.addStudent("H") == true );
		REQUIRE( myClass.addStudent("I") == true );
		REQUIRE( myClass.addStudent("J") == true );
		
		REQUIRE( myClass.addStudent("D") == true );
		REQUIRE( myClass.addStudent("E") == true );
		REQUIRE( myClass.addStudent("F") == true );

		
		REQUIRE( myClass.removeAlphabeticallyLast() == "J" );
		REQUIRE( myClass.containsStudent("J") == false );
		REQUIRE( myClass.listAllStudents() == "A,B,C,G,H,I,D,E,F");
		
		REQUIRE( myClass.removeAlphabeticallyLast() == "I" );
		REQUIRE( myClass.containsStudent("I") == false );
		REQUIRE( myClass.listAllStudents() == "A,B,C,G,H,D,E,F");
		
		REQUIRE( myClass.removeStudent("H") == true );
		REQUIRE( myClass.listAllStudents() == "A,B,C,G,D,E,F");
		
		REQUIRE( myClass.removeAlphabeticallyLast() == "G" );
		REQUIRE( myClass.containsStudent("G") == false );
		REQUIRE( myClass.listAllStudents() == "A,B,C,D,E,F");
		
	}
	
	SECTION("Remove from end"){
		REQUIRE( myClass.addStudent("A") == true );
		REQUIRE( myClass.addStudent("B") == true );
		REQUIRE( myClass.addStudent("C") == true );
		REQUIRE( myClass.addStudent("D") == true );
		REQUIRE( myClass.addStudent("E") == true );
		
		REQUIRE( myClass.removeAlphabeticallyLast() == "E" );
		REQUIRE( myClass.containsStudent("E") == false );
		REQUIRE( myClass.listAllStudents() == "A,B,C,D" );
		
		REQUIRE( myClass.removeAlphabeticallyLast() == "D" );
		REQUIRE( myClass.containsStudent("D") == false );
		REQUIRE( myClass.listAllStudents() == "A,B,C" );
		
		REQUIRE( myClass.removeStudent("C") == true );
		REQUIRE( myClass.listAllStudents() == "A,B" );
		
		REQUIRE( myClass.removeAlphabeticallyLast() == "B" );
		REQUIRE( myClass.containsStudent("B") == false );
		REQUIRE( myClass.listAllStudents() == "A" );
	}
	
}
 
TEST_CASE("Combining classes","[combine]"){
	Classroom class1,class2;
	
	SECTION("simple combine"){
		REQUIRE( class1.addStudent("A") == true );
		REQUIRE( class1.addStudent("B") == true );
		REQUIRE( class1.addStudent("C") == true );
		REQUIRE( class1.addStudent("D") == true );
		REQUIRE( class1.addStudent("E") == true );
		REQUIRE( class1.addStudent("F") == true );
		REQUIRE( class1.addStudent("G") == true );
		REQUIRE( class1.addStudent("H") == true );

		REQUIRE( class2.addStudent("I") == true );
		REQUIRE( class2.addStudent("J") == true );
		REQUIRE( class2.addStudent("K") == true );
		REQUIRE( class2.addStudent("L") == true );
		REQUIRE( class2.addStudent("M") == true );
		REQUIRE( class2.addStudent("N") == true );
		REQUIRE( class2.addStudent("O") == true );
		REQUIRE( class2.addStudent("P") == true );

		class1.combineClasses(class2);

		REQUIRE( class1.listAllStudents() == "A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P");
	}

	SECTION("Combining non-unique classes"){
		REQUIRE( class1.addStudent("A") == true );
		REQUIRE( class1.addStudent("B") == true );
		REQUIRE( class1.addStudent("C") == true );
		REQUIRE( class1.addStudent("D") == true );
		REQUIRE( class1.addStudent("E") == true );
		REQUIRE( class1.addStudent("F") == true );
		REQUIRE( class1.addStudent("G") == true );
		REQUIRE( class1.addStudent("H") == true );
		REQUIRE( class1.addStudent("I") == true );
		REQUIRE( class1.addStudent("J") == true );
		REQUIRE( class1.addStudent("K") == true );

		REQUIRE( class2.addStudent("I") == true );
		REQUIRE( class2.addStudent("J") == true );
		REQUIRE( class2.addStudent("K") == true );
		REQUIRE( class2.addStudent("L") == true );
		REQUIRE( class2.addStudent("M") == true );
		REQUIRE( class2.addStudent("N") == true );
		REQUIRE( class2.addStudent("O") == true );
		REQUIRE( class2.addStudent("P") == true );

		class1.combineClasses(class2);

		REQUIRE( class1.listAllStudents() == "A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P" );

	}



}
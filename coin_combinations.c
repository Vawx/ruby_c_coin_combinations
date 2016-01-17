/**
 * Coin combinations
 * Kyle Langley <2016>
 * Epicodus class study : Ruby
 *
 * kyle@dotvawxgames.com
 * http://github.com/Vawx
 * http://www.epicodus.com
 */

 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>

 char* GetUserChange( int StartingCents );

 char* Pennies( int ChangeCount );
 char* Nickels( int ChangeCount );
 char* Dimes( int ChangeCount );
 char* Quarters( int ChangeCount );

 char* SingleOrPlural( int Count, const char* Single, const char* Plural );
 char* AddWhiteSpaceAtStart( const char* Of );
 void  Append( char* Of, char toAppend );

 /** globals */
 char* penniesAsWord;
 char* nickelsAsWord;
 char* dimesAsWord;
 char* quarterAsWord;
 char* intoSingleOrPlural;
 char* result;

 char*
 GetUserChange( int StartingCents )
 {
   result = malloc( 80 );
   penniesAsWord = malloc( 80 );
   nickelsAsWord = malloc( 80 );
   dimesAsWord = malloc( 80 );
   quarterAsWord = malloc( 80 );
   intoSingleOrPlural = malloc( 80 );

   if( StartingCents > 0 && StartingCents <= 4 )
   {
     result = Pennies( StartingCents );
   }
   else if( StartingCents > 4 && StartingCents <= 9 )
   {
     result = Nickels( StartingCents );
   }
   else if ( StartingCents > 9 && StartingCents <= 24 )
   {
     result = Dimes( StartingCents );
   }
   else if( StartingCents > 24 && StartingCents < 65535 )
   {
     result = Quarters( StartingCents );
   }

   return result;

   free( penniesAsWord );
   free( nickelsAsWord );
   free( dimesAsWord );
   free( quarterAsWord );
   free( intoSingleOrPlural );
   free( result );
 }

 char*
 Pennies( int ChangeCount )
 {
   return SingleOrPlural( ChangeCount, " penny", " pennies" );
 }

 char*
 Nickels( int ChangeCount )
 {
   int remainderChange = ChangeCount % 5;
   int numberOfNickels = (ChangeCount - remainderChange) / 5;
   nickelsAsWord = SingleOrPlural( numberOfNickels, " nickel", " nickels" );

   if ( remainderChange > 0 )
   {
     Append( nickelsAsWord, ' ' );
     penniesAsWord = Pennies( remainderChange );
     strncat( nickelsAsWord, penniesAsWord, 80 );
   }

   return nickelsAsWord;
 }

 char*
 Dimes( int ChangeCount )
 {
   int remainderChange = ChangeCount % 10;
   int numberOfDimes = (ChangeCount - remainderChange) / 10;
   dimesAsWord = SingleOrPlural( numberOfDimes, " dime", " dimes" );

   if( remainderChange > 0 )
   {
     Append( dimesAsWord, ' ' );
     if( remainderChange > 4 )
     {
       nickelsAsWord = Nickels( remainderChange );
       strncat( dimesAsWord, nickelsAsWord, 80 );
     }
     else
     {
       penniesAsWord = Pennies( remainderChange );
       strncat( dimesAsWord, penniesAsWord, 80 );
     }
   }

   return dimesAsWord;
 }

 char*
 Quarters( int ChangeCount )
 {
   int remainderChange = ChangeCount % 25;
   int numberOfQuaters = (ChangeCount - remainderChange) / 25;
   quarterAsWord = SingleOrPlural( numberOfQuaters, " quarter", " quarters" );

   if( remainderChange > 0 )
   {
     Append( quarterAsWord, ' ' );
     if( remainderChange > 9 )
     {
       dimesAsWord = Dimes( remainderChange );
       strncat( quarterAsWord, dimesAsWord, 80 );
     }
     else if( remainderChange > 4 )
     {
       nickelsAsWord = Nickels( remainderChange );
       strncat( quarterAsWord, nickelsAsWord, 80 );
     }
     else
     {
       penniesAsWord = Pennies( remainderChange );
       strncat( quarterAsWord, penniesAsWord, 80 );
     }
   }
   return quarterAsWord;
 }

 char*
 SingleOrPlural( int Count, const char* Single, const char* Plural )
 {
   intoSingleOrPlural = malloc( strlen( Plural ) + 8 );
   sprintf( intoSingleOrPlural, "%d", Count );
   if( Count > 1 )
   {
     strcat( intoSingleOrPlural, Plural );
   }
   else
   {
     strcat( intoSingleOrPlural, Single );
   }
   return intoSingleOrPlural;
 }

 void
 Append( char* Of, char toAppend )
 {
   int length = strlen( Of );
   Of[ length ] = toAppend;
   Of[ length + 1 ] = '\0';
 }

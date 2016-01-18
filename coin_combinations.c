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
 #include <stdlib.h>
 #include <string.h>

 #define MAX_STRING_SIZE 256

 void CurrencyConversion( int CurrentChange, char* ChangeAsWord, int Divisible, const char* Single, const char* Plural );

 char* GetUserChange( int CurrentChange );
 void  SingleOrPlural( int ChangeCountForConversion, const char* Single, const char* Plural, char* ChangeAsWord );
 void  Append( char* Of, char ToAppend );

 void
 SingleOrPlural( int ChangeCountForConversion, const char* Single, const char* Plural, char* ChangeAsWord )
 {
   char intoSingleOrPlural[ MAX_STRING_SIZE ];
   sprintf( intoSingleOrPlural, "%d", ChangeCountForConversion );

   char end[ MAX_STRING_SIZE ];

   strcpy( ChangeAsWord, intoSingleOrPlural );
   strcpy( end, ( ChangeCountForConversion > 1 ) ? Plural : Single );

   strcat( ChangeAsWord, end );
 }

 char*
 GetUserChange( int StartingCents )
 {
   char* AsChange = malloc( sizeof( char[MAX_STRING_SIZE] ) );
   if( StartingCents > 0 && StartingCents <= 4 )
   {
     CurrencyConversion( StartingCents, AsChange, 1, " penny", " pennies" );
   }
   else if( StartingCents > 4 && StartingCents <= 9 )
   {
     CurrencyConversion( StartingCents, AsChange, 5, " nickel", " nickels" );
   }
   else if ( StartingCents > 9 && StartingCents <= 24 )
   {
     CurrencyConversion( StartingCents, AsChange, 10, " dime", " dimes" );
   }
   else if( StartingCents > 24 && StartingCents < 65535 )
   {
     CurrencyConversion( StartingCents, AsChange, 25, " quarter", " quarters" );
   }
   char* ToReturn[MAX_STRING_SIZE];
   strcpy( ToReturn, AsChange );
   free( AsChange );
   return ToReturn;
 }

 void
 Append( char* Of, char ToAppend )
 {
   int length = strlen( Of );
   Of[ length ] = ToAppend;
   Of[ length + 1 ] = '\0';
 }

 void
 CurrencyConversion( int CurrentChange, char* ChangeAsWord, int Divisible, const char* Single, const char* Plural )
 {
   int remainderChange = CurrentChange % Divisible;
   int numberOfCoins = ( CurrentChange - remainderChange ) / Divisible;
   SingleOrPlural( numberOfCoins, Single, Plural, ChangeAsWord );

   if ( remainderChange > 0 )
   {
     Append( ChangeAsWord, ' ' );
     char* remainderAsWord = malloc( sizeof( char[MAX_STRING_SIZE] ) );

     if( remainderChange > 9 )
     {
       CurrencyConversion( remainderChange, remainderAsWord, 10, " dime", " dimes" );
     }
     else if( remainderChange > 4 )
     {
       CurrencyConversion( remainderChange, remainderAsWord, 5, " nickel", " nickel" );
     }
     else
     {
       CurrencyConversion( remainderChange, remainderAsWord, 1, " penny", " pennies" );
     }

     strncat( ChangeAsWord, remainderAsWord, MAX_STRING_SIZE );
     free( remainderAsWord );
   }
 }

 int
 main( int argc, char* argv[] )
{
  return 0;
}

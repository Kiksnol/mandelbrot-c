/* Dyakonov Nickolay, ND4, 30.10.2020 */

typedef double DBL;

typedef struct
{
  DBL Re, Im;
} COMPL;

COMPL ComplSet( DBL A, DBL B );
COMPL ComplMul( COMPL Z1, COMPL Z2 );
COMPL ComplAdd( COMPL Z1, COMPL Z2 );
DBL ComplNorm2( COMPL Z );
DBL ComplNorm( COMPL Z );
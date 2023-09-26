/* Dyakonov Nickolay, ND4, 30.10.2020 */
#include <math.h>

#include "COMPL.h"

COMPL ComplAdd( COMPL Z1, COMPL Z2 )
{
  COMPL Sum;

  Sum.Re = Z1.Re + Z2.Re;
  Sum.Im = Z1.Im + Z2.Im;

  return Sum;
}

COMPL ComplMul( COMPL Z1, COMPL Z2 )
{
  COMPL Mul;

  Mul.Re = Z1.Re * Z2.Re - Z1.Im * Z2.Im;
  Mul.Im = Z1.Re * Z2.Im - Z1.Im * Z2.Re;

  return Mul;
}

COMPL ComplSet( DBL A, DBL B )
{
  COMPL Set;

  Set.Re = A;
  Set.Im = B;

  return Set;
}

DBL ComplNorm( COMPL Z )
{
  return sqrt(Z.Re * Z.Re + Z.Im * Z.Im);
}

DBL ComplNorm2( COMPL Z )
{
  return Z.Re * Z.Re + Z.Im * Z.Im;
}
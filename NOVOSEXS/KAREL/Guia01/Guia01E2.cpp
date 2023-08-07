/**
 moveN - Metodo para mover certa quantidade de passos.
 @param steps - passos a serem dados.
 */
 void moveN( int steps )
 {
 // dado local
     int x = 0;
 // testar se a quantidade de passos e' maior que zero
 if ( steps > x )
 {
 // dar um passo
 move( );
 // tentar fazer de novo, com x variando de forma crescente
 x = x + 1;
 } // end if
 } // end moveN( )
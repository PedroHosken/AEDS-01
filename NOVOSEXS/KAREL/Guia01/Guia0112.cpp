#include "karel.hpp"

void decorateWorld ( const char* fileName )
{
// colocar um marcador no mundo
 world->set ( 3, 3, BEEPER );
 world->set ( 6, 3, BEEPER );
 world->set ( 6, 6, BEEPER );
// salvar a configuracao atual do mundo
 world->save( fileName );
} // decorateWorld ( )

class MyRobot : public Robot
{
 public:
 /**
 turnRight - Procedimento (acao) para virar 'a direita.
 */
 void turnRight ( )
 {
 // testar se o robo esta' ativo
 if ( checkStatus ( ) )
 {
 // o agente que executar esse metodo
 // devera' virar tres vezes 'a esquerda
 turnLeft ( );
 turnLeft ( );
 turnLeft ( );
 } // end if
 } // end turnRight ( )
 /**
 moveN - Metodo para mover certa quantidade de passos.
 @param steps - passos a serem dados.
 */
 void moveN( int steps )
 {
 // definir dado local
 int step = 0;
 // repetir contando e testando ate' atingir a quantidade de passos
 for ( step = 1; step <= steps; step = step + 1 ) // outra forma de repetir
 {
 // dar um passo por vez
 move( );
 } // end if
 } // end moveN( )
 /**
 doPartialTask - Metodo para descrever parte de uma tarefa.
 */
 void doPartialTask( )
 {
 // especificar acoes dessa parte da tarefa
 turnLeft( );
 moveN( 5 );
 turnRight();
 moveN( 5 );
 pickBeeper();
 turnRight();
 moveN( 3 );
 pickBeeper();
 turnRight();
 moveN( 3 );
 pickBeeper();
 moveN( 2 );
 turnLeft( );
 moveN( 2 );
 turnLeft( );
 } // end doPartialTask( )
 /**
 doTask - Relacao de acoes para o robo executar.
 */
 void doTask( )
 {
 // especificar acoes da tarefa
 doPartialTask( );
 doPartialTask( );
 // testar se ha' marcador antes ...
 if ( nextToABeeper( ) )
 {
 // ... de tentar carrega-lo
 pickBeeper( );
 } // end if
 doPartialTask( );
 // testar se carrega marcador antes ...
 if ( nbeepers( ) > 0 )
 {
 // ... de tentar descarrega-lo
 putBeeper( );
 } // end if
 doPartialTask( );
 turnLeft( );
 // encerrar
 turnOff ( );
 } // end doTask( )
}; // end class MyRobot

int main ( )
{
// definir o contexto
// criar o ambiente e decorar com objetos
// OBS.: executar pelo menos uma vez,
// antes de qualquer outra coisa
// (depois de criado, podera' ser comentado)
 world->create ( "" ); // criar o mundo
 decorateWorld ( "Guia0112.txt" );
 world->show ( );
// preparar o ambiente para uso
 world->reset ( ); // limpar configuracoes
 world->read ( "Guia0112.txt" );// ler configuracao atual para o ambiente
 world->show ( ); // mostrar a configuracao atual
 set_Speed ( 5 ); // definir velocidade padrao
// criar robo
 MyRobot *robot = new MyRobot( );
// posicionar robo no ambiente (situacao inicial):
// posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
 robot->create ( 1, 1, EAST, 0, "Karel" );
// executar tarefa
 robot->doPartialTask ( );
// encerrar operacoes no ambiente
 world->close ( );
// encerrar programa
 getchar ( );
 return ( 0 );
}
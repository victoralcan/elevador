package rx
import scala.io.Source

object Main extends App {
  
  def leArquivo:String = {
    val linhas : String = Source.fromFile("sample.txt").mkString
    linhas 
  }
  
  println(leArquivo)
  
  val rx = new CaesarCipher(3)
  val t2 = new RotationCipher(3)
  var retorno = ""
  println(rx.codificaString("Rosca!"))
  println(rx.decodificarString("Urvfd!"))
  retorno = t2.codificaString("Rosca do Vitao!")
  println(retorno + " " + t2.decodificarString(retorno) )
  retorno = t2.codificaString("Rosca do Vitao!")
  println(retorno + " " + t2.decodificarString(retorno) )
 }
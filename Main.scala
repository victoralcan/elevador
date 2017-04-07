package ex2

import scala.io.Source

object Main extends App {
  
  def leArquivo= {
    var retorno = ""
    val linhas : String = Source.fromFile("sample").mkString
    retorno  =  teste.codificaString(linhas)
    println(retorno)
    println(teste.decodificarString(retorno))
  }
  val teste = new Rotationcipher(3)
  leArquivo
}

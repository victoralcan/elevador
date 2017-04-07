package ex2

class Rotationcipher(private val chave : Int) {
  
  private val indiceInicial = 'a'.toInt
  private val indiceFinal = 'z'.toInt
  private val indIMaiusculo = 'A'.toInt
  private val indFMaiusculo = 'Z'.toInt
  private var contaChave = chave-1
  
  /* tamanho do alfabeto: quantidade de letras minusculas */ 
  private val alfabeto = 1 + indiceFinal - indiceInicial
  
  /* Codifica um caracter usando o algoritmos CaesarCipher
   *  @param c caracter a ser codificado
   *  @return caracter cifrado com o  algoritmo
   */
  private def codificar(c : Char) : Char = {
    
    if(c.toInt >= 97 && c.toInt <= 122)
      return (indiceInicial + ((c.toInt + this.contaChave - indiceInicial) % alfabeto)).toChar
    else if(c.toInt > 64 && c.toInt < 91)
      return (indIMaiusculo + ((c.toInt + this.contaChave - indIMaiusculo) % alfabeto)).toChar
    else
      return c
  }

  /* Decodifica um caracter usando o algoritmo CaesarCipher
   * @param c caracter a ser decifrado
   * @return caracter decifrado usando o algoritmo
   */
  private def decodificar(c : Char) : Char = {
    
    if(c.toInt >= 97 && c.toInt <= 122)
      return (indiceFinal - ((indiceFinal - (c.toInt - this.contaChave)) % alfabeto)).toChar
    else if(c.toInt > 64 && c.toInt < 91)
      return (indFMaiusculo - ((indFMaiusculo - (c.toInt - this.contaChave)) % alfabeto)).toChar
    else
      return c
  }
  
  /** Codifica uma string de acordo com o algoritmo CaesarCipher
   *  @param texto : texto a ser cifrado
   *  @return texto codificado de acordo com o algoritmo
   */
  def codificaString(texto : String) : String = {
    contaChave = rotaciona(contaChave)
    texto.map(c => codificar(c))
    
  }
  
  def rotaciona(x: Int) : Int = x+1 
  
  def decodificarString(texto : String) : String ={
    texto.map(c => decodificar(c))
  }
 
}

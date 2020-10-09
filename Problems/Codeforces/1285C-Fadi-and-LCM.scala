import scala.io.StdIn.readLong

object Main extends App {
  val mod: Long = 1000000007
  val n: Long = readLong()
  val a: Long = loop(0, 1)
  println(a + " " + n / a)

  def loop(a: Long, i: Long): Long =
    if(i * i > n) a
    else if(n % i == 0 && gcd(i, n / i) == 1) loop(i, i + 1)
    else loop(a, i + 1)

  def gcd(a: Long, b: Long): Long =
    if(b == 0) a
    else gcd(b, a % b)
}